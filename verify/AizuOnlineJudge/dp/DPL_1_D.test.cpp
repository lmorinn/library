#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_D"
#include <bits/stdc++.h>

using namespace std;
#include "../../../dp/LongestIncreasingSubsequence.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << lis(a) << "\n";
}