namespace debug_assert {

template<class T>
std::string to_string_any(const T& value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

inline void collect_args(std::vector<std::string>&) {}

template<class T, class... Rest>
void collect_args(std::vector<std::string>& out, T&& head, Rest&&... rest) {
	out.push_back(to_string_any(std::forward<T>(head)));
	collect_args(out, std::forward<Rest>(rest)...);
}

template<class... Args>
std::string format(std::string_view fmt, Args&&... args) {
	std::vector<std::string> vals;
	vals.reserve(sizeof...(Args));
	collect_args(vals, std::forward<Args>(args)...);

	std::string out;
	out.reserve(fmt.size() + vals.size() * 8);

	size_t arg_idx = 0;
	for (size_t i = 0; i < fmt.size(); ++i) {
		if (fmt[i] == '{' && i + 1 < fmt.size() && fmt[i + 1] == '{') {
			out.push_back('{');
			++i;
			continue;
		}
		if (fmt[i] == '}' && i + 1 < fmt.size() && fmt[i + 1] == '}') {
			out.push_back('}');
			++i;
			continue;
		}
		if (fmt[i] == '{' && i + 1 < fmt.size() && fmt[i + 1] == '}') {
			if (arg_idx >= vals.size()) {
				throw std::invalid_argument("format: missing argument for '{}' placeholder");
			}
			out += vals[arg_idx++];
			++i;
			continue;
		}
		out.push_back(fmt[i]);
	}

	if (arg_idx != vals.size()) {
		throw std::invalid_argument("format: too many arguments for format string");
	}

	return out;
}

[[noreturn]] inline void fail(const char* expr, const char* file, int line, const char* func, const std::string& msg) {
	std::ostringstream oss;
	oss << "Assertion failed: (" << expr << ")\n"
		<< "Location: " << file << ':' << line << " in " << func;
	if (!msg.empty()) {
		oss << "\nMessage: " << msg;
	}
	throw std::runtime_error(oss.str());
}

}  // namespace debug_assert

#define assertf(cond, fmt, ...) \
	do { \
		if (!(cond)) { \
			::debug_assert::fail(#cond, __FILE__, __LINE__, __func__, ::debug_assert::format((fmt), ##__VA_ARGS__)); \
		} \
	} while (0)

#define panic(fmt, ...) \
	do { \
		::debug_assert::fail("PANIC", __FILE__, __LINE__, __func__, ::debug_assert::format((fmt), ##__VA_ARGS__)); \
	} while (0)
