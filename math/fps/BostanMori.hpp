#include "FormalPowerSeries.hpp"

template <class S>
S bostan_mori(FPS<S> p, FPS<S> q, long long n) {
  auto filter = [&](const FPS<S>& p, int start) {
    FPS<S> ret((p.size() + 1) / 2);
    for (int i = 0; i * 2 + start < int(p.size()); i++) ret[i] = p[i * 2 + start];
    return ret;
  };

  while (n > 0) {
    FPS<S> q_ = q;
    for (int i = 1; i < int(q_.size()); i += 2) q_[i] = -q_[i];
    auto pq = convolution(p, q_);
    auto qq = convolution(q, q_);
    p = filter(FPS<S>(pq.begin(), pq.end()), n & 1);
    q = filter(FPS<S>(qq.begin(), qq.end()), 0);
    n >>= 1;
  }
  return p[0] / q[0];
}