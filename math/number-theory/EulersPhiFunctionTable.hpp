vector<int> Eulers_phi_function_table(int n) {
  vector<int> table(n + 1);
  iota(table.begin(), table.end(), 0);

  for (int i = 2; i <= n; i++) {
    if (table[i] == i) {
      for (int j = i; j <= n; j += i) {
        table[j] = table[j] / i * (i - 1);
      }
    }
  }
  return table;
}