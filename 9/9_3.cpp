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
  vector<pair<long long, long long>> mmv;
  unordered_map<long long, vector<long long>> ux;
  unordered_map<long long, vector<long long>> uy;
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
    // se.insert({x, y});
    mmv.push_back({x, y});
    maxx = max(maxx, x);
    maxy = max(maxy, y);
  }

  // vector<vector<char>> grid(maxx + 1, vector<char>(maxy + 1, '.'));
  //  auto printGrid = [&]() {
  //    for (int i = 0; i < maxx + 1; i++) {
  //      for (int j = 0; j < maxy + 1; j++) {
  //        cout << grid[i][j];
  //      }
  //      cout << "\n";
  //    }
  //    cout << "\n";
  //  };

  for (size_t i = 0; i < mmv.size(); i++) {
    long long x1 = (mmv[i].first);
    long long y1 = (mmv[i].second);
    ux[x1].push_back(y1);
    uy[y1].push_back(x1);
  }

  cout << "came here" << ux.size() << endl;
  for (auto it : ux) {
    sort(begin(it.second), end(it.second));
    long long end = it.second[(int)it.second.size() - 1];
    long long start = it.second[0];
    for (long long j = start; j <= end; j++) {
      se.insert({it.first, j});
    }
  }

  cout << "came here 2 " << uy.size() << endl;
  for (auto it : uy) {
    sort(begin(it.second), end(it.second));
    long long end = it.second[(int)it.second.size() - 1];
    long long start = it.second[0];
    for (long long j = start; j <= end; j++) {
      se.insert({j, it.first});
    }
  }
  unordered_map<long long, set<long long>> lmap;
  // unordered_map<long long, set<long long>> lmap2;
  cout << "came here 3 " << se.size() << endl;
  for (auto elem : se) {
    long long x1 = elem.first;
    long long y1 = elem.second;
    lmap[x1].insert(y1);
    // lmap2[y1].insert(x1);
    // lmap[y1].insert(x1);
  }

  cout << "came here 4 " << ux.size() << endl;
  // for (auto it : ux) {
  //   sort(begin(it.second), end(it.second));
  //   long long end = it.second[(int)it.second.size() - 1];
  //   long long start = it.second[0];
  //   for (long long j = start; j <= end; j++) {
  //     se.insert({it.first, j});
  //   }
  // }
  // for (auto it : lmap) {
  //   cout << it.first << endl;
  //   for (auto k : it.second) {
  //     cout << k << " ";
  //   }
  //   cout << endl;
  // }
  // for (auto it : lmap2) {
  //   for (auto k : it.second) {
  //     cout << k << " ";
  //   }
  //   cout << endl;
  // }

  // for (auto k : se) {
  //   grid[k.first][k.second] = 'x';
  // }
  // printGrid();

  cout << "came here 5" << endl;
  long long maxi = LLONG_MIN;
  for (size_t i = 0; i < mmv.size(); i++) {
    for (size_t j = i + 1; j < mmv.size(); j++) {
      long long x1 = (mmv[i].first);
      long long x2 = (mmv[j].first);
      long long y1 = (mmv[i].second);
      long long y2 = (mmv[j].second);
      // cout << x1 << "," << y1 << " " << x2 << "," << y2 << endl;
      long long p1 = *lmap[x1].begin();
      long long p2 = *lmap[x1].end();
      long long p3 = *lmap[x2].begin();
      long long p4 = *lmap[x2].end();
      if (y2 >= p1 && y2 <= p2 && y1 >= p3 && y1 <= p4) {
        maxi = max(maxi, (abs(y2 - y1) + 1) * (abs(x2 - x1) + 1));
      }
      // if (lmap[x1].count(y2) > 0 && lmap[x2].count(y1) > 0) {
      //   maxi = max(maxi, (abs(y2 - y1) + 1) * (abs(x2 - x1) + 1));
      // }
      // if (se.count({x1, y2}) > 0 && se.count({x2, y1}) > 0) {
      //   maxi = max(maxi, (abs(y2 - y1) + 1) * (abs(x2 - x1) + 1));
      // }
    }
  }
  cout << maxi << endl;

  f.close();

  return 0;
}
