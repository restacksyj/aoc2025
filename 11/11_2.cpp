#include <bits/stdc++.h>
using namespace std;

long long res = 0;
unordered_map<string, unordered_map<int, unordered_map<int, long long>>> memo;
unordered_set<string> vis;

long long newhelper(string s, unordered_map<string, vector<string>> &u,
                    bool has_fft, bool has_dac) {
  if (s == "out") {
    if (has_fft && has_dac) {
      return 1;
    }
    return 0;
  }
  if (memo[s][has_dac][has_fft])
    return memo[s][has_dac][has_fft] - 1;
  long long total = 0;
  for (auto it : u[s]) {
    bool has_d = ((it == "dac") || has_dac);
    bool has_f = ((it == "fft") || has_fft);
    total += newhelper(it, u, has_d, has_f);
  }
  return memo[s][has_dac][has_fft] = total + 1;
}

long long helper(string s, string d, unordered_map<string, vector<string>> &u,
                 bool has_fft, bool has_dac) {

  if (s == "fft")
    has_fft = true;
  if (s == "dac")
    has_dac = true;

  if (s == d) {
    return (has_fft && has_dac) ? 1 : 0;
  }

  if (memo[s][has_fft][has_dac]) {
    return memo[s][has_fft][has_dac] - 1;
  }

  vis.insert(s);
  long long total = 0;

  for (auto &next : u[s]) {
    if (!vis.count(next)) {
      total += helper(next, d, u, has_fft, has_dac);
    }
  }

  vis.erase(s);

  memo[s][has_fft][has_dac] = total + 1;
  return total;
}

int main() {
  ifstream f("input2.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  string s;
  unordered_map<string, vector<string>> u;

  while (getline(f, s, '\n')) {
    stringstream ss(s);
    string k;
    vector<string> temp;
    while (getline(ss, k, ':')) {
      temp.push_back(k);
    }
    stringstream sss(temp[1]);
    string edge;
    vector<string> edges;
    while (sss >> edge) {
      edges.push_back(edge);
    }
    u[temp[0]] = edges;
  }

  string source = "svr";
  string dest = "out";
  cout << helper(source, dest, u, false, false) << endl;
  cout << newhelper(source, u, false, false) << endl;
  f.close();

  return 0;
}
