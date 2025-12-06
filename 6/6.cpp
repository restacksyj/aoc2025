#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
  ifstream f("input2.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }
  long long res = 0;

  string s;
  int m = 4;
  int n = 1001;
  // int m = 3;
  // int n = 4;
  vector<vector<long long>> v(m, vector<long long>(n));
  vector<string> ch;
  int r = 0;
  while (getline(f, s)) {
    stringstream ss(s);
    string k;
    int c = 0;
    if (r == m) {
      while (getline(ss, k, ' ')) {
        if (k.empty()) {
          continue;
        }
        ch.push_back(k);
      }
    } else {
      while (getline(ss, k, ' ')) {
        if (k.empty()) {
          continue;
        }
        v[r][c] = stoll(k);
        c++;
      }
    }
    r++;
  }

  // for (int j = 0; j < n; j++) {
  //   for (int i = 0; i < m; i++) {
  //     cout << v[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  for (int j = 0; j < n; j++) {
    bool ismul = false;
    long long temp = 0;
    if (ch[j] == "*") {
      ismul = true;
      temp = 1;
    }
    for (int i = 0; i < m; i++) {
      if (ismul) {
        temp *= v[i][j];
      } else {
        temp += v[i][j];
      }
    }
    res += temp;
  }

  cout << res << endl;

  f.close();

  return 0;
}
