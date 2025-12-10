#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// POINT-IN-POLYGON for orthogonal simple polygon
// Using ray casting against vertical edges only
// ---------------------------------------------------------
bool inside(long long x, long long y,
            const vector<tuple<long long, long long, long long>> &vertical) {
  int cnt = 0;
  for (auto &[vx, vy1, vy2] : vertical) {
    if (y >= vy1 && y < vy2 && vx > x) {
      cnt++;
    }
  }
  return cnt % 2 == 1;
}

// ---------------------------------------------------------

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ifstream f("input2.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  // read input as (y, x)
  vector<pair<long long, long long>> red;
  string s;

  while (getline(f, s)) {
    if (s.empty())
      continue;
    stringstream ss(s);
    string a, b;
    getline(ss, a, ',');
    getline(ss, b, ',');
    long long y = stoll(a);
    long long x = stoll(b);
    red.push_back({x, y});
  }

  int n = red.size();
  if (n < 2) {
    cout << 0 << "\n";
    return 0;
  }

  // ---------------------------------------------------------
  // Build polygon edges
  // ---------------------------------------------------------
  vector<tuple<long long, long long, long long>> vertical;   // (x, y1, y2)
  vector<tuple<long long, long long, long long>> horizontal; // (y, x1, x2)

  for (int i = 0; i < n; i++) {
    auto [x1, y1] = red[i];
    auto [x2, y2] = red[(i + 1) % n];

    if (x1 == x2) {
      if (y1 > y2)
        swap(y1, y2);
      vertical.push_back({x1, y1, y2});
    } else {
      if (x1 > x2)
        swap(x1, x2);
      horizontal.push_back({y1, x1, x2});
    }
  }

  // ---------------------------------------------------------
  // MAIN LOGIC: Try all pairs of red points as corner candidates
  // ---------------------------------------------------------
  long long best = 0;

  for (int i = 0; i < n; i++) {
    auto [x1, y1] = red[i];
    for (int j = i + 1; j < n; j++) {
      auto [x2, y2] = red[j];

      long long Xlo = min(x1, x2);
      long long Xhi = max(x1, x2);
      long long Ylo = min(y1, y2);
      long long Yhi = max(y1, y2);

      // four corners:
      bool ok = inside(Xlo, Ylo, vertical) && inside(Xlo, Yhi, vertical) &&
                inside(Xhi, Ylo, vertical) && inside(Xhi, Yhi, vertical);

      if (ok) {
        long long area = (Xhi - Xlo + 1) * (Yhi - Ylo + 1);
        best = max(best, area);
      }
    }
  }

  cout << best << "\n";
  return 0;
}
