#include <bits/stdc++.h>
using namespace std;

long long res = 0;
unordered_set<string> vis;
void helper(string s, string d, unordered_map<string, vector<string>> &u) {
  if (s == d) {
    res++;
    return;
  }
  vis.insert(s);
  for (auto it : u[s]) {
    if (vis.count(it) == 0) {
      helper(it, d, u);
    }
  }
  vis.erase(s);
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

  string source = "you";
  string dest = "out";
  helper(source, dest, u);
  cout << res << endl;

  f.close();

  return 0;
}
