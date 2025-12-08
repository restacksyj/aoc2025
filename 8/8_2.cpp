#include <bits/stdc++.h>
#include <queue>
using namespace std;

class DSU {
public:
  vector<int> parent;
  vector<int> size;
  int comp;
  DSU(int n) {
    parent.resize(n);
    size.resize(n);
    comp = n;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int findParent(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = findParent(parent[x]);
  }

  void Union(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);
    if (xp == yp)
      return;
    if (size[xp] < size[yp]) {
      parent[xp] = yp;
      size[yp] += size[xp];
    } else if (size[xp] > size[yp]) {
      parent[yp] = xp;
      size[xp] += size[yp];
    } else {
      parent[xp] = yp;
      size[yp] += size[xp];
    }
    comp--;
  }
};

int main() {
  ifstream f("input2.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  string s;
  long long res = 0;
  int n = 0;
  vector<vector<int>> mainv;
  unordered_map<string, int> id;
  unordered_map<int, string> rid;

  while (getline(f, s)) {
    stringstream ss(s);
    string k;
    vector<int> vec;
    while (getline(ss, k, ',')) {
      vec.push_back(stoi(k));
    }
    string key =
        to_string(vec[0]) + '-' + to_string(vec[1]) + '-' + to_string(vec[2]);
    id[key] = n;
    rid[n] = key;
    n++;
    mainv.push_back(vec);
  }

  vector<pair<vector<int>, vector<int>>> pairs;
  for (int i = 0; i < (int)mainv.size(); i++) {
    for (int j = i + 1; j < (int)mainv.size(); j++) {
      pairs.push_back({mainv[i], mainv[j]});
    }
  }

  sort(begin(pairs), end(pairs),
       [&](pair<vector<int>, vector<int>> a, pair<vector<int>, vector<int>> b) {
         long long x1 = a.first[0];
         long long y1 = a.first[1];
         long long z1 = a.first[2];
         long long x2 = a.second[0];
         long long y2 = a.second[1];
         long long z2 = a.second[2];

         long long x3 = b.first[0];
         long long y3 = b.first[1];
         long long z3 = b.first[2];
         long long x4 = b.second[0];
         long long y4 = b.second[1];
         long long z4 = b.second[2];
         return (abs(x2 - x1) * abs(x2 - x1)) + (abs(y2 - y1) * abs(y2 - y1)) +
                    (abs(z2 - z1) * abs(z2 - z1)) <
                (abs(x3 - x4) * abs(x3 - x4)) + (abs(y3 - y4) * abs(y3 - y4)) +
                    (abs(z3 - z4) * abs(z3 - z4));
       });

  // int nsize = 20;
  int nsize = 1000;
  DSU dsu(nsize);
  for (auto a : pairs) {
    long long x1 = a.first[0];
    long long y1 = a.first[1];
    long long z1 = a.first[2];
    long long x2 = a.second[0];
    long long y2 = a.second[1];
    long long z2 = a.second[2];
    string first = to_string(x1) + '-' + to_string(y1) + '-' + to_string(z1);
    string second = to_string(x2) + '-' + to_string(y2) + '-' + to_string(z2);
    int id1 = id[first];
    int id2 = id[second];
    dsu.Union(id1, id2);
    if (dsu.comp == 1) {
      cout << x1 * x2 << endl;
      break;
    }
  }
  f.close();

  return 0;
}
