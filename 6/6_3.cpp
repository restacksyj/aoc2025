#include <bits/stdc++.h>
#include <cctype>
#include <string>
using namespace std;

std::vector<std::string> process(const std::string &input) {
  std::string s = input;

  // Step 1: convert "  " → "0"
  s = std::regex_replace(s, std::regex(" {2}"), "0");

  // Step 2: convert " " → "0"
  s = std::regex_replace(s, std::regex(" "), "0");

  // Step 3: split into digit tokens
  std::vector<std::string> tokens;
  std::string current;

  for (char c : s) {
    if (isdigit(c)) {
      current.push_back(c);
    } else {
      if (!current.empty()) {
        tokens.push_back(current);
        current.clear();
      }
    }
  }

  if (!current.empty())
    tokens.push_back(current);

  return tokens;
}

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
  int m = 4;
  int n = 4;
  int r = 0;
  while (getline(f, s, '\n')) {
    stringstream ss(s);
    string k;
    vector<string> temp;
    vector<string> rest = process(s);
    for (auto it : rest) {
      cout << it << " ";
    }
    cout << "\n";
  }

  cout << res << endl;

  f.close();

  return 0;
}
