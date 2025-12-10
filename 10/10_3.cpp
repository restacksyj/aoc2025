#include <bits/stdc++.h>
#include <z3++.h>
using namespace std;

int solver(vector<vector<int>> &moves, vector<int> &powers) {
  z3::context c;
  int psize = (int)powers.size();
  int msize = (int)moves.size();

  z3::optimize opt(c);
  vector<z3::expr> expressions;
  for (int i = 0; i < msize; i++) {
    string st = "x" + to_string(i);
    expressions.push_back(c.int_const(st.c_str()));
    opt.add(expressions[i] >= 0);
  }

  for (int i = 0; i < psize; i++) {
    z3::expr sum = c.int_val(0);
    for (int j = 0; j < msize; j++) {
      for (auto it : moves[j]) {
        if (it == i) {
          sum = sum + expressions[j];
        }
      }
    }
    opt.add(sum == powers[i]);
  }

  z3::expr total = c.int_val(0);
  for (auto t : expressions)
    total = total + t;
  opt.minimize(total);
  int val = 0;
  if (opt.check() == z3::sat) {
    auto m = opt.get_model();
    for (auto e : expressions) {
      val += m.eval(e).get_numeral_int();
    }
  } else {
    cout << "error" << endl;
  }
  return val;
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
    res += solver(moves, powers);
  }
  cout << res << endl;
}
