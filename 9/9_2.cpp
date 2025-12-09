#include <bits/stdc++.h>
#include <climits>
#include <queue>
using namespace std;

int main() {
  ifstream f("input1.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  string s;
  long long res = 0;
  set<pair<long long, long long>> mainvec;
  vector<pair<long long, long long>> mmv;
  long long maxx = LLONG_MIN;
  long long maxy = LLONG_MIN;

  while (getline(f, s)) {
    stringstream ss(s);
    string k;
    vector<long long> vec;
    while (getline(ss, k, ',')) {
      vec.push_back(stoll(k));
    }
    mainvec.insert({vec[0], vec[1]});
    mmv.push_back({vec[0], vec[1]});
    maxx = max(maxx, vec[0]);
    maxy = max(maxy, vec[1]);
  }
  cout << maxx << " " << maxy << endl;
  vector<vector<char>> grid(maxy + 1, vector<char>(maxx + 1, '.'));
  unordered_map<int, vector<int>> ux;
  unordered_map<int, vector<int>> uy;
  for (int i = 0; i < maxy + 1; i++) {
    for (int j = 0; j < maxx + 1; j++) {
      if (mainvec.count({j, i}) > 0) {
        grid[i][j] = '#';
        // uy[i].push_back({i, j});
        ux[j].push_back(i);
        uy[i].push_back(j);
      }
      // cout << grid[i][j];
    }
    // cout << "\n";
  }
  // cout << "\n";

  cout << "I am here" << endl;
  unordered_map<int, vector<int>> tx;
  unordered_map<int, vector<int>> ty;
  for (auto it : ux) {
    int end = it.second[(int)it.second.size() - 1];
    int start = it.second[0];
    for (int j = start + 1; j <= end - 1; j++) {
      grid[j][it.first] = 'x';
      tx[j].push_back(it.first);
    }
  }

  for (auto it : uy) {
    int end = it.second[(int)it.second.size() - 1];
    int start = it.second[0];
    for (int j = start + 1; j <= end - 1; j++) {
      grid[it.first][j] = 'x';
      ty[it.first].push_back(j);
    }
  }
  for (int i = 0; i < maxy + 1; i++) {
    for (int j = 0; j < maxx + 1; j++) {
      cout << grid[i][j];
    }
    cout << "\n";
  }
  cout << "\n";

  unordered_map<int, vector<int>> xxmap;
  for (int i = 0; i < maxy + 1; i++) {
    vector<int> temp;
    for (int j = 0; j < maxx + 1; j++) {
      if (grid[i][j] == 'x') {
        temp.push_back(j);
      }
    }
    xxmap[i] = temp;
  }
  for (auto it : xxmap) {
    if (it.second.empty())
      continue;
    int start = it.second[0];
    int end = it.second[(int)it.second.size() - 1];
    for (int j = start; j <= end; j++) {
      if (grid[it.first][j] == '.') {
        grid[it.first][j] = 'x';
      }
    }
  }

  // cout << "\n";
  // for (int i = 0; i < maxy + 1; i++) {
  //   for (int j = 0; j < maxx + 1; j++) {
  //     cout << grid[i][j];
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  // for (int i = 0; i < maxy + 1; i++) {
  //   for (int j = 0; j < maxx + 1; j++) {
  //     if (grid[i][j] == '.') {
  //       // down up
  //       if (i - 1 >= 0 && grid[i - 1][j] == 'x' && i + 1 < maxy + 1 &&
  //           grid[i + 1][j] == 'x') {
  //         grid[i][j] = 'x';
  //       }
  //       // left right
  //       if (j - 1 >= 0 && grid[i][j - 1] == 'x' && j + 1 < maxx + 1 &&
  //           grid[i][j + 1] == 'x') {
  //         grid[i][j] = 'x';
  //       }
  //     }
  //   }
  // }
  long long maxi = LLONG_MIN;
  for (size_t i = 0; i < mmv.size(); i++) {
    for (size_t j = i + 1; j < mmv.size(); j++) {
      long long x1 = (mmv[i].first);
      long long x2 = (mmv[j].first);
      long long y1 = (mmv[i].second);
      long long y2 = (mmv[j].second);
      // cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
      bool flag = true;
      for (long long row = min(y1, y2); row <= max(y1, y2); row++) {
        for (long long col = min(x1, x2); col <= max(x1, x2); col++) {
          if (grid[row][col] == '.') {
            flag = false;
            break;
          }
        }
      }
      if (flag) {
        maxi = max(maxi, (abs(y2 - y1) + 1) * (abs(x2 - x1) + 1));
      }
    }
  }
  cout << maxi << endl;

  f.close();

  return 0;
}
