#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream f("input1.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  string s;
  long long res = 0;

  while (getline(f, s, ',')) {
    stringstream ss(s);
    string curr;
    vector<string> v;
    while (getline(ss, curr, '-')) {
      v.push_back(curr);
    }
    long long id1 = stoll(v[0]);
    long long id2 = stoll(v[1]);
    for (long long i = id1; i <= id2; i++) {
      string k = to_string(i);
      int sz = (int)k.size();
      for (int j = (int)sz / 2; j >= 1; j--) {
        int m = 0;
        string comp = k.substr(m, j);
        m += j;
        bool flag = true;
        while (m < sz) {
          if (m < sz && comp != k.substr(m, j)) {
            flag = false;
            break;
          }
          m += j;
        }
        if (flag) {
          res += i;
          break;
        }
      }
    }
  }

  cout << res << endl;
  f.close();

  return 0;
}
