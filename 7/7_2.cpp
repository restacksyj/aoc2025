#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream f("input2.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  string s;
  long long res = 0;
  vector<vector<char>> vec;

  while (getline(f, s)) {
    stringstream ss(s);
    vector<char> temp;
    for (auto ch : s) {
      temp.push_back(ch);
    }
    vec.push_back(temp);
  }

  int m = (int)vec.size();
  int n = (int)vec[0].size();

  vector<vector<long long>> dp(m, vector<long long>(n, -1));
  auto start = [&](int row, int col, const auto &dfs) -> long long {
    if (row >= m || row + 1 >= m || col < 0 || col >= n || row < 0) {
      return 1;
    }
    if (dp[row][col] != -1)
      return dp[row][col];
    int nr = row + 1;
    while (nr < m && vec[nr][col] == '.') {
      nr++;
    }
    if (nr >= m) {
      return 1;
    }
    return dp[row][col] = dfs(nr, col - 1, dfs) + dfs(nr, col + 1, dfs);
  };

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (vec[i][j] == 'S') {
        cout << start(i, j, start) << endl;
      }
    }
  }

  f.close();

  return 0;
}
