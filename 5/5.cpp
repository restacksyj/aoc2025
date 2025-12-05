#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
  ifstream f("input1.txt");
  ifstream f2("input1_1.txt");

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

  // unordered_set<long long> v;
  vector<long long> starts;
  vector<long long> ends;
  unordered_map<long long, long long> u;
  while (getline(f, s)) {
    stringstream ss(s);
    string t;
    vector<string> q;
    while (getline(ss, t, '-')) {
      q.push_back(t);
    }
    starts.push_back(stoll(q[0]));
    if (u.count(stoll(q[0])) > 0) {
      u[stoll(q[0])] = max(u[stoll(q[0])], stoll(q[1]));
    } else {
      u[stoll(q[0])] = stoll(q[1]);
    }
  }

  sort(begin(starts), end(starts));
  string s1;
  while (getline(f2, s1)) {
    stringstream ss(s1);
    vector<long long> checks;
    for (auto it : starts) {
      if (stoll(s1) < it) {
        break;
      }
      checks.push_back(it);
    }
    if (checks.size() == 0)
      continue;
    bool flag = false;
    for (auto it : checks) {
      long long start = it;
      long long end = u[it];
      if (stoll(s1) >= start && stoll(s1) <= end) {
        flag = true;
        break;
      }
    }
    if (flag)
      res++;
  }

  cout << res << endl;

  f.close();

  return 0;
}
