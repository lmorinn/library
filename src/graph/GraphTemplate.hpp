#include "../assert/DebugAssert.cpp"

struct Graph {
public:
	Graph() : Graph(0) {}
	Graph(int N) : n_(N), g(N) {}
	void add_directed_edge(int u, int v) {
		assertf(0 <= u && u < n_ && 0 <= v && v < n_,
			"Graph::add_directed_edge: invalid vertex index (u={}, v={}, n={})",
			u, v, n_);
		g[u].push_back(v);
	}	
	void add_undirected_edge(int u, int v) {
		assertf(0 <= u && u < n_ && 0 <= v && v < n_,
			"Graph::add_undirected_edge: invalid vertex index (u={}, v={}, n={})",
			u, v, n_);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>& operator[](int u) {
		return g[u];
	}
	const vector<int>& operator[](int u) const {
		return g[u];
	}
	int size() const {
		return n_;
	}
private:
	int n_;
	vector<vector<int>> g;
};

template<class T>
struct WeightedGraph {
public:
	WeightedGraph() : WeightedGraph(0) {}
	WeightedGraph(int N) : n_(N), g(N) {}
	void add_directed_edge(int u, int v, T w) {
		assertf(0 <= u && u < n_ && 0 <= v && v < n_,
			"WeightedGraph::add_directed_edge: invalid vertex index (u={}, v={}, n={})",
			u, v, n_);
		g[u].push_back(make_pair(v, w));
	}
	void add_undirected_edge(int u, int v, T w) {
		assertf(0 <= u && u < n_ && 0 <= v && v < n_,
			"WeightedGraph::add_undirected_edge: invalid vertex index (u={}, v={}, n={})",
			u, v, n_);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	vector<pair<int, T>>& operator[](int u) {
		return g[u];
	}
	const vector<pair<int, T>>& operator[](int u) const {
		return g[u];
	}
	int size() const {
		return n_;
	}
private:
	int n_;
	vector<vector<pair<int, T>>> g;
};

using Tree = Graph;
