#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
  ifstream f("input2.txt");
  ifstream f2("input2_1.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  if (!f2.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  string s;
  long long res = 0;
  vector<vector<char>> vec;

  vector<vector<long long>> intervals;
  while (getline(f, s)) {
    stringstream ss(s);
    string t;
    vector<string> q;
    while (getline(ss, t, '-')) {
      q.push_back(t);
    }
    intervals.push_back({stoll(q[0]), stoll(q[1])});
  }

  sort(begin(intervals), end(intervals));
  vector<vector<long long>> merged;
  for (int i = 0; i < (int)intervals.size(); i++) {
    if (merged.empty() || merged.back()[1] < intervals[i][0]) {
      merged.push_back(intervals[i]);
    } else {
      merged.back()[1] = max(merged.back()[1], intervals[i][1]);
    }
  }

  for (auto it : merged) {
    res += it[1] - it[0] + 1;
  }

  cout << res << endl;

  f.close();

  return 0;
}
