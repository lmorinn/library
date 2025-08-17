vector<int> MP(const string &s) {
  // longest border
  int n = int(s.size());
  vector<int> lb(n + 1);
  lb[0] = -1;
  int j = -1;
  for (int i = 0; i < n; i++) {
    while (j >= 0 and s[i] != s[j]) j = lb[j];
    j++;
    lb[i + 1] = j;
  }
  return lb;
}