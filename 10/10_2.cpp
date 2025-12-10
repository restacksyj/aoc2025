#include <bits/stdc++.h>
#include <climits>
#include <string>
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

// void helper2(vector<int> ip, vector<int> powers, vector<vector<int>> moves,
//              int moveidx, long long currm) {
//   if (checkvecmatch(ip, powers)) {
//     result = min(currm, result);
//     return;
//   }
//   for (int i = 0; i < ip.size(); i++)
//     if (ip[i] > powers[i])
//       return;
//   if (moveidx >= (int)moves.size()) {
//     return;
//   }
//   int count = 0;
//   for (int m : moves[moveidx]) {
//     if (ip[m] == powers[m]) {
//       count++;
//     }
//   }
//   bool aligned = (count == (int)moves[moveidx].size());
//   if (!aligned) {
//     vector<int> newvec = modify2(ip, moves[moveidx]);
//     helper2(newvec, powers, moves, moveidx, currm + 1);
//   }
//   helper2(ip, powers, moves, moveidx + 1, currm);
// }
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

long long mainres = 0;

int main() {
  ifstream f("input2.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  string s;
  long long res = 0;
  int i = 0;

  while (getline(f, s, '\n')) {
    stringstream ss(s);
    string k;
    vector<string> elems;
    vector<int> powers;
    while (getline(ss, k, ' ')) {
      elems.push_back(k);
    }
    string dest = elems[0].substr(1, elems[0].size() - 2);
    elems.erase(elems.begin());
    string powerstr = *elems.rbegin();
    powerstr = powerstr.substr(1, powerstr.size() - 2);
    stringstream powerstream(powerstr);
    string l;
    while (getline(powerstream, l, ',')) {
      powers.push_back(stoi(l));
    }
    elems.pop_back();
    vector<vector<int>> moves;
    for (auto m : elems) {
      string movestr = m.substr(1, m.size() - 2);
      vector<int> move;
      stringstream news(movestr);
      string temp;
      while (getline(news, temp, ',')) {
        move.push_back(stoi(temp));
      }
      moves.push_back(move);
    }

    vector<int> ip(dest.size(), 0);
    helper2(ip, powers, moves, 0, 0);
    // helper(initial, dest, moves, 0, 0);
    mainres += result;
    cout << result << endl;
    result = LLONG_MAX;
    u.clear();
    // for (auto it : moves) {
    //   for (auto t : it) {
    //     cout << t << " ";
    //   }
    //   cout << "\n";
    // }
  }

  cout << mainres << endl;

  f.close();

  return 0;
}
