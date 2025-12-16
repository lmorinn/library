#include "../data-structure/others/MonotonicMinQueue.hpp"
#include "LCPArray.hpp"
vector<pair<int, int>> longest_common_substring(const vector<string>& v) {
  int siz = int(v.size());
  if (siz < 2) return {};
  string concat = "";
  for (int i = 0; i < siz; i++) {
    concat += v[i];
    if (i + 1 != siz) concat += '$';
  }
  MonotonicMinQueue<int> que;
  vector<int> sa = suffixArray(concat);
  vector<int> lcp = LCPArray(concat, sa);
  int concat_n = int(concat.size());
  int lcs_len = 0;
  int best_l = -1, best_r = -1;
  if (siz == 2) {
    int cnt_s1 = 0, cnt_s2 = 0;
    int l = 0, r = 0;
    int s1_siz = v.front().size();
    while (1) {
      while (r < concat_n and (cnt_s1 == 0 or cnt_s2 == 0)) {
        if (sa[r] < s1_siz) {
          cnt_s1++;
        } else if (sa[r] > s1_siz) {
          cnt_s2++;
        }
        if (r > 0) que.push(lcp[r - 1]);
        r++;
      }
      while (l < concat_n and (cnt_s1 > 1 or cnt_s2 > 1)) {
        if (sa[l] < s1_siz) {
          if (cnt_s1 == 1) break;
          cnt_s1--;
        } else if (sa[l] > s1_siz) {
          if (cnt_s2 == 1) break;
          cnt_s2--;
        }
        l++;
        if (!que.empty()) que.pop();
      }

      if (cnt_s1 >= 1 and cnt_s2 >= 1 and !que.empty()) {
        if (lcs_len < que.minimum()) {
          lcs_len = que.minimum();
          best_l = l;
          best_r = r;
        }
      }

      if (r == concat_n) break;
      if (sa[l] < s1_siz) {
        cnt_s1--;
      } else if (sa[l] > s1_siz) {
        cnt_s2--;
      }
      l++;
      if (!que.empty()) que.pop();
    }

    vector<pair<int, int>> res(2, {0, 0});
    if (best_l == -1) return res;
    for (int i = best_l; i < best_r; i++) {
      if (sa[i] < s1_siz) {
        res[0] = {sa[i], sa[i] + lcs_len};
      } else if (sa[i] > s1_siz) {
        res[1] = {sa[i] - s1_siz - 1, sa[i] - s1_siz - 1 + lcs_len};
      }
    }
    return res;
  } else {
    vector<pair<int, int>> res(2, {0, 0});
    // todo
    return res;
  }
}