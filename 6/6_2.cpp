#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
  ifstream f("input1.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }
  long long res = 0;

  string s;
  // int m = 4;
  // int n = 1001;
  int m = 3;
  int n = 4;
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
  auto noofds = [&](long long n) {
    long long v = n;
    int c = 0;
    while (n != 0) {
      n = n / 10;
      c++;
    }
    return v * (long long)pow(10, 5 - c);
  };

  for (int j = 0; j < n; j++) {
    bool ismul = false;
    long long temp = 0;
    if (ch[n - j] == "*") {
      ismul = true;
      temp = 1;
    }
    // vector<string> temps;
    vector<long long> temps;
    for (int i = 0; i < m; i++) {
      temps.push_back(v[i][j]);
      // temps.push_back(to_string(noofds(v[i][j])));
    }
    for (auto it : temps) {
      cout << it << " ";
    }
    cout << "\n";
    // vector<long long> newtemps;
    // for (int x = 0; x < 5; x++) {
    //   long long num = 0;
    //   int power = m - 1;
    //   for (auto it : temps) {
    //     long long t = it[x] - '0';
    //     num += t * (long long)pow(10, power);
    //     power--;
    //   }
    //   newtemps.push_back(num);
    // }
    // for (auto it : newtemps) {
    //   cout << it << endl;
    //   if (ismul)
    //     temp *= it;
    //   else {
    //     temp += it;
    //   }
    // }
    // res += temp;
  }

  cout << res << endl;

  f.close();

  return 0;
}
