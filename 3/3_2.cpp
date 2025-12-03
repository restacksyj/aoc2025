#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

long long maxi = -1;
long long helper(vector<int> &num, int i, int k,
                 vector<vector<long long>> &dp) {
  if (k == 12) {
    return 0;
  }

  if (dp[i][k] != -1)
    return dp[i][k];
  int remaining = num.size() - i;
  int needed = 12 - k;
  if (remaining < needed)
    return LLONG_MIN / 4;

  long long take = num[i] * pow(10, 11 - k) + helper(num, i + 1, k + 1, dp);
  long long nottake = helper(num, i + 1, k, dp);
  return dp[i][k] = max(take, nottake);
}

void helper2(vector<int> &num, int i, int k, vector<int> &path) {
  if (k == 12) {
    long long n = 0;
    for (int z = 0; z < 12; z++) {
      n += (long long)(path[z] * pow(10, 11 - z));
    }
    maxi = max(n, maxi);
  }
  if (i >= num.size() || k > 12) {
    return;
  }
  path.push_back(num[i]);
  helper2(num, i + 1, k + 1, path);
  path.pop_back();
  helper2(num, i + 1, k, path);
}

int main() {
  ifstream f("input2.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  string s;
  long long res = 0;

  // int i = 0;
  while (getline(f, s, '\n')) {
    stringstream ss(s);
    vector<int> vec;
    for (auto ch : s) {
      vec.push_back(ch - '0');
    }
    vector<int> path;
    vector<vector<long long>> dp(vec.size() + 1,
                                 vector<long long>(vec.size() + 1, -1));
    res += helper(vec, 0, 0, dp);
  }

  cout << res << endl;
  f.close();

  return 0;
}
