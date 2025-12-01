#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream f("input2.txt");

  if (!f.is_open()) {
    cerr << " error opening file" << endl;
    return 1;
  }

  string s;

  int zero_count = 0;
  int start = 50;
  while (getline(f, s)) {
    stringstream ss(s);
    char dir = s[0];
    int value = stoi(s.substr(1));
    if (dir == 'L') {
      int i = start;
      start -= value;
      while (i != start) {
        i--;
        if (i % 100 == 0)
          zero_count++;
      }
    } else {
      int i = start;
      start += value;
      while (i != start) {
        i++;
        if (i % 100 == 0)
          zero_count++;
      }
    }
  }

  f.close();
  cout << zero_count << endl;

  return 0;
}
