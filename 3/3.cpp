#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

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
    vector<int> vec;
    for (auto ch : s) {
      vec.push_back(ch - '0');
    }
    int maxi = -1;
    for (int i = 0; i < vec.size(); i++) {
      int num = vec[i] * 10;
      for (int j = i + 1; j < vec.size(); j++) {
        if (num + vec[j] > maxi) {
          maxi = num + vec[j];
        }
      }
    }
    res += maxi;
  }

  cout << res << endl;
  f.close();

  return 0;
}
