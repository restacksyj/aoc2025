#include <bits/stdc++.h>
#include <climits>
#include <queue>
using namespace std;

int main() {
  ifstream f("input2.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  string s;
  long long res = 0;
  vector<pair<long, long>> mainvec;

  while (getline(f, s)) {
    stringstream ss(s);
    string k;
    vector<long long> vec;
    while (getline(ss, k, ',')) {
      vec.push_back(stoll(k));
    }
    mainvec.push_back({vec[0], vec[1]});
  }

  long long maxi = LLONG_MIN;
  for (size_t i = 0; i < mainvec.size(); i++) {
    for (size_t j = i + 1; j < mainvec.size(); j++) {
      long long xi = (mainvec[i].first - mainvec[j].first) + 1;
      long long yi = (mainvec[i].second - mainvec[j].second) + 1;
      maxi = max(maxi, xi * yi);
    }
  }

  cout << maxi << endl;

  f.close();

  return 0;
}
