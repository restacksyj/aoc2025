#include <bits/stdc++.h>
#include <climits>
using namespace std;

long long result = LLONG_MAX;

string modify(string initial, string dest, vector<int> move) {
  for (int m : move) {
    initial[m] = initial[m] == '#' ? '.' : '#';
  }
  return initial;
}

void helper(string initial, string dest, vector<vector<int>> moves, int moveidx,
            long long currm) {
  if (initial == dest) {
    result = min(currm, result);
    return;
  }
  if (moveidx >= (int)moves.size()) {
    return;
  }
  string newstring = modify(initial, dest, moves[moveidx]);
  helper(newstring, dest, moves, moveidx + 1, currm + 1);
  helper(initial, dest, moves, moveidx + 1, currm);
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

  while (getline(f, s, '\n')) {
    stringstream ss(s);
    string k;
    vector<string> elems;
    while (getline(ss, k, ' ')) {
      elems.push_back(k);
    }
    string dest = elems[0].substr(1, elems[0].size() - 2);
    elems.erase(elems.begin());
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
    string initial = "";
    for (int i = 0; i < (int)dest.size(); i++) {
      initial.push_back('.');
    }
    helper(initial, dest, moves, 0, 0);
    mainres += result;
    result = LLONG_MAX;
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
