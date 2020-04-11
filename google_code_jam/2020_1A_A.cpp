/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n;
string p[60];

int check() {
  REP(i, 0, n) {
    bool f = true;
    REP(j, 0, p[i].length()) {
      if (p[i][j] == '*') f = false;
    }
    if (f) return i;
  }
  return -1;
}

bool match(const string& a, const string& b) {
  if (b == "*" || (a.empty() && b.empty())) return true;
  int i = 0, j = 0;
  while (i < a.length() && j < b.length()) {
    if (a[i] == b[j]) {
      i++, j++;
      continue;
    }
    if (b[j] == '*') {
      bool f = false;
      REP(k, i, a.length()) {
        f |= match(a.substr(i), b.substr(j + 1));
        if (f) return true;
      }
      return false;
    }
    return false;
  }
  return false;
}

void solve1(int f) {
  REP(i, 0, n) {
    bool ret = match(p[f], p[i]);
    if (!ret) {
      cout << "*\n";
      return;
    }
  }
  cout << p[f] << "\n";
}

void solve() {
  int f = check();
  if (f >= 0) {
    solve1(f);
    return;
  }
  bitset<60> pre;
  REP(i, 0, n) if (p[i][0] != '*') pre[i] = 1;
  string pre_ans;
  REP(i, 0, 110) {
    if (pre.none()) break;
    char c;
    REP(j, 0, n) {
      if (pre[j]) {
        if (p[j][i] == '*')
          pre[j] = 0;
        else {
          c = p[j][i];
          break;
        }
      }
    }
    REP(j, 0, n) {
      if (pre[j]) {
        if (p[j][i] == '*')
          pre[j] = 0;
        else {
          if (c != p[j][i]) {
            cout << "*\n";
            return;
          }
        }
      }
    }
    pre_ans += c;
  }
  bitset<60> tail;
  REP(i, 0, n) if (p[i].back() != '*') tail[i] = 1;
  string tail_ans;
  REP(i, 0, 110) {
    if (tail.none()) break;
    char c;
    REP(j, 0, n) {
      if (tail[j]) {
        if (p[j][p[j].length() - 1 - i] == '*')
          tail[j] = 0;
        else {
          c = p[j][p[j].length() - 1 - i];
          break;
        }
      }
    }
    REP(j, 0, n) {
      if (tail[j]) {
        if (p[j][p[j].length() - 1 - i] == '*')
          tail[j] = 0;
        else if (p[j][p[j].length() - 1 - i] != c) {
          cout << "*\n";
          return;
        }
      }
    }
    tail_ans = c + tail_ans;
  }
  string mid_ans;
  REP(i, 0, n) {
    int l = p[i].find('*');
    int r = p[i].rfind('*');
    REP(j, l, r) {
      if (p[i][j] != '*') mid_ans += p[i][j];
    }
  }
  cout << pre_ans << mid_ans << tail_ans << "\n";
}

int main() {
  ios::basic_ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, kase = 0;
  cin >> t;

  while (t--) {
    cin >> n;
    REP(i, 0, n) cin >> p[i];
    // printf("Case #%d: ", ++kase);
    cout << "Case #" << ++kase << ": ";
    solve();
  }
  return 0;
}
