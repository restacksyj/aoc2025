#include <bits/stdc++.h>
#include <climits>
using namespace std;

long long result = LLONG_MAX;

vector<int> modify2(vector<int> ip, vector<int> move) {
  for (int m : move) {
    ip[m]++;
  }
  return ip;
}

bool checkvecmatch(vector<int> ip, vector<int> dst) {
  for (int i = 0; i < ip.size(); i++) {
    if (ip[i] != dst[i]) {
      return false;
    }
  }
  return true;
}

unordered_map<string, long long> u;
string encode(vector<int> &k) {
  string res;
  for (auto el : k) {
    res += to_string(el) + ',';
  }
  return res;
}
void helper2(vector<int> ip, vector<int> powers, vector<vector<int>> moves,
             int moveidx, long long currm) {
  if (checkvecmatch(ip, powers)) {
    result = min(currm, result);
    return;
  }
  for (int i = 0; i < ip.size(); i++)
    if (ip[i] > powers[i])
      return;
  if (currm >= result)
    return;
  string coded = encode(ip) + '#' + to_string(moveidx);
  if (u.count(coded) && u[coded] <= currm) {
    return;
  }
  u[coded] = currm;
  if (moveidx >= (int)moves.size()) {
    return;
  }
  int count = 0;
  for (int m : moves[moveidx]) {
    if (ip[m] == powers[m]) {
      count++;
    }
  }
  bool aligned = (count == (int)moves[moveidx].size());
  if (!aligned) {
    vector<int> newvec = modify2(ip, moves[moveidx]);
    helper2(newvec, powers, moves, moveidx, currm + 1);
  }
  helper2(ip, powers, moves, moveidx + 1, currm);
}

int main() {
  vector<vector<int>> moves = {
      {0, 3, 4, 5},
      {1, 4, 6},
      {2, 9},
      {0, 4},
      {2, 4, 7, 8},
      {0, 2, 3, 4, 5, 6, 7, 8, 9},
      {1, 6},
      {1, 2, 5, 6, 7},
      {0, 4, 7, 8},
      {0, 1, 2, 3, 5, 8, 9},
      {0, 3, 4, 5, 6, 7, 8, 9},
      {4, 6, 9},
  };
  vector<int> powers = {56, 51, 67, 27, 82, 44, 70, 56, 49, 58};
  vector<int> ip(powers.size(), 0);
  // helper2(ip, powers, moves, 0, 0);
  cout << result << endl;

  queue<vector<int>> q;
  unordered_set<string> se;
  u[encode(ip)] = 0;
  q.push(ip);
  se.insert(encode(ip));
  auto valid = [&powers](vector<int> c) {
    for (int i = 0; i < c.size(); i++) {
      if (c[i] > powers[i]) {
        return false;
      }
    }
    return true;
  };

  while (!q.empty()) {
    vector<int> curr = q.front();
    q.pop();
    for (auto it : curr) {
      cout << it << " ";
    }
    cout << endl;
    if (curr == powers) {
      cout << u[encode(curr)] << endl;
      break;
    }
    for (auto m : moves) {
      vector<int> newvec = modify2(curr, m);
      if (valid(newvec) && se.count(encode(newvec)) == 0) {
        q.push(newvec);
        u[encode(newvec)] = u[encode(curr)] + 1;
        se.insert(encode(newvec));
      }
    }
  }

  return 0;
}
