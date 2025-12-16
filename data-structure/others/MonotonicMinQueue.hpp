template <class T>
class MonotonicMinQueue {
 private:
  queue<T> que;
  deque<T> deq;

 public:
  void push(const T& x) {
    que.push(x);
    while (deq.size() > 0 and deq.back() > x) deq.pop_back();
    deq.push_back(x);
  }

  void pop() {
    if (que.front() == deq.front()) deq.pop_front();
    que.pop();
  }

  const T& front() const {
    return que.front();
  }

  bool empty() const {
    return que.empty();
  }

  const T& minimum() const {
    return deq.front();
  }
};docs/MonotonicMinQueue.md