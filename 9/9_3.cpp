#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
  ifstream f("input1_1.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  string s;
  vector<pair<long long, long long>> mmv;
  unordered_map<long long, set<long long>> ux;
  unordered_map<long long, set<long long>> uy;
  set<pair<long long, long long>> se;
  long long maxx = LLONG_MIN;
  long long maxy = LLONG_MIN;

  while (getline(f, s)) {
    stringstream ss(s);
    string k;
    vector<long long> vec;
    while (getline(ss, k, ',')) {
      vec.push_back(stoll(k));
    }
    long long x = vec[1];
    long long y = vec[0];
    mmv.push_back({x, y});
    maxx = max(maxx, x);
    maxy = max(maxy, y);
  }

  vector<vector<char>> grid(maxx + 1, vector<char>(maxy + 1, '.'));
  for (size_t i = 0; i < mmv.size(); i++) {
    long long x1 = (mmv[i].first);
    long long y1 = (mmv[i].second);
    ux[x1].insert(y1);
    uy[y1].insert(x1);
    grid[x1][y1] = '#';
  }
  for (int i = 0; i < maxx + 1; i++) {
    for (int j = 0; j < maxy + 1; j++) {
      cout << grid[i][j];
    }
    cout << "\n";
  }
  cout << "\n";

  // for (auto it : ux) {
  //   for (auto elem : it.second) {
  //     se.insert({it.first, elem});
  //     grid[it.first][elem] = 'x';
  //   }
  // }

  for (auto it : ux) {
    long long start = *it.second.begin();
    long long end = *it.second.rbegin();
    for (long long j = start; j <= end; j++) {
      se.insert({it.first, j});
      grid[it.first][j] = 'x';
    }
  }

  // for (auto it : uy) {
  //   for (auto elem : it.second) {
  //     se.insert({elem, it.first});
  //     grid[elem][it.first] = 'x';
  //   }
  // }
  //
  for (auto it : uy) {
    long long start = *it.second.begin();
    long long end = *it.second.rbegin();
    for (long long j = start; j <= end; j++) {
      se.insert({j, it.first});
      grid[j][it.first] = 'x';
    }
  }
  for (int i = 0; i < maxx + 1; i++) {
    for (int j = 0; j < maxy + 1; j++) {
      cout << grid[i][j];
    }
    cout << "\n";
  }
  cout << "\n";

  unordered_map<long long, set<long long>> lmap;
  unordered_map<long long, set<long long>> umap;
  for (auto elem : se) {
    long long x1 = elem.first;
    long long y1 = elem.second;
    lmap[x1].insert(y1);
    umap[y1].insert(x1);
  }

  unordered_map<long long, long long> colMin;
  unordered_map<long long, long long> colMax;
  for (auto &it : lmap) {
    colMin[it.first] = *it.second.begin();
    colMax[it.first] = *it.second.rbegin();
  }

  long long maxi = LLONG_MIN;
  for (size_t i = 0; i < mmv.size(); i++) {
    for (size_t j = i + 1; j < mmv.size(); j++) {
      long long x1 = (mmv[i].first);
      long long y1 = (mmv[i].second);
      long long x2 = (mmv[j].first);
      long long y2 = (mmv[j].second);
      long long p1 = *lmap[x1].begin();
      long long p2 = *lmap[x1].rbegin();
      long long p3 = *lmap[x2].begin();
      long long p4 = *lmap[x2].rbegin();
      // long long area = (abs(y2 - y1) + 1) * (abs(x2 - x1) + 1);
      //  if (area == 72) {
      //    cout << p1 << " " << p2 << endl;
      //    cout << p3 << " " << p4 << endl;
      //    cout << x1 << y1 << x2 << y2 << endl;
      //  }
      long long Xlo = min(x1, x2);
      long long Xhi = max(x1, x2);
      long long Ylo = min(y1, y2);
      long long Yhi = max(y1, y2);

      bool ok = true;

      for (long long X = Xlo; X <= Xhi; X++) {
        if (!colMin.count(X)) {
          ok = false;
          break;
        }
        if (colMin[X] > Ylo || colMax[X] < Yhi) {
          ok = false;
          break;
        }
      }

      if (ok) {
        long long area = (abs(y2 - y1) + 1) * (abs(x2 - x1) + 1);
        maxi = max(maxi, area);
      }

      // if (y2 >= p1 && y2 <= p2 && y1 >= p3 && y1 <= p4) {
      //   long long area = (abs(y2 - y1) + 1) * (abs(x2 - x1) + 1);
      //   if (area == 120) {
      //     // y1 to y2 ke beech
      //     // har ek row main x1 to x2
      //     // kya y ke map main saara interval exist karta hai
      //     cout << x1 << y1 << x2 << y2 << endl;
      //   }
      //   maxi = max(maxi, (abs(y2 - y1) + 1) * (abs(x2 - x1) + 1));
      // }
    }
  }
  cout << maxi << endl;

  f.close();

  return 0;
}
