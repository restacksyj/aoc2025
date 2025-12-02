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
      if (k.size() % 2 == 0) {
        if (k.substr(0, k.size() / 2) == k.substr((k.size() / 2))) {
          cout << i << endl;
          res += i;
        }
      }
      //   else {
      //   long long num = 1;
      //   for (int j = 0; j < (int)k.size() - 1; j++) {
      //     num = num * 10 + 1;
      //   }
      //   if ((long long)i % (num) == 0) {
      //     cout << i << endl;
      //     res += i;
      //   }
      // }
    }
  }

  cout << res << endl;
  f.close();

  return 0;
}
