/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int mod = 1e9 + 7;

// data
int n;
vector<string> vs;

void solve() {
  sort(vs.begin(), vs.end());
  string ans;
  int cnt = 0;
  REP(i, 0, n) {
    string t = vs[i];
    set<int> letter;
    REP(j, 0, t.length()) {
      if (t[j] >= 'A' && t[j] <= 'Z') {
        letter.insert(t[j]);
      }
    }
    if (cnt < letter.size()) {
      cnt = letter.size();
      ans = t;
    }
  }
  printf("%s\n", ans.c_str());
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d\n", &n);
    vs.clear();
    string s;
    REP(i, 0, n) getline(cin, s), vs.push_back(s);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
