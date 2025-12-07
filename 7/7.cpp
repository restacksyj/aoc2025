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

  vector<pair<int, int>> dirs = {{0, 1},   {1, 0},  {-1, 0}, {0, -1},
                                 {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

  int m = (int)vec.size();
  int n = (int)vec[0].size();
  // for (int i = 0; i < m; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << vec[i][j];
  //   }
  //   cout << "\n";
  // }

  vector<vector<bool>> vis(m, vector<bool>(n, false));
  auto start = [&](int row, int col, const auto &dfs) -> void {
    if (row >= m) {
      return;
    }
    int nr = row + 1;
    while (nr < m && vec[nr][col] == '.') {
      vec[nr][col] = 'x';
      nr++;
    }
    if (nr < m && vec[nr][col] == '^') {
      if (col - 1 >= 0) {
        vec[nr][col - 1] = 'x';
        dfs(nr, col - 1, dfs);
      }
      if (col + 1 < n) {
        vec[nr][col + 1] = 'x';
        dfs(nr, col + 1, dfs);
      }
      res++;
    }
  };

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (vec[i][j] == 'S') {
        start(i, j, start);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << vec[i][j];
    }
    cout << "\n";
  }
  cout << res << endl;

  f.close();

  return 0;
}
