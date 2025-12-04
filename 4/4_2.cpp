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
  while (true) {
    vector<pair<int, int>> convert;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (vec[i][j] == '.')
          continue;
        int count = 0;
        for (auto dir : dirs) {
          int nr = i + dir.first;
          int nc = j + dir.second;
          if (nr >= 0 && nr < m && nc >= 0 && nc < n && vec[nr][nc] == '@') {
            count++;
          }
        }
        if (count < 4) {
          convert.push_back({i, j});
          res++;
        }
      }
    }
    if (convert.size() == 0) {
      break;
    }
    for (auto c : convert) {
      vec[c.first][c.second] = '.';
    }
  }

  cout << res << endl;
  f.close();

  return 0;
}
