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
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct

// data
int n;
string s;

int solve(int b, int e) {
  int l = 0;
  while (b < e && s[b] == 'w') b++, l++;
  int j = b;
  while (j < e) {
    if (s[j] == s[b] || s[j] == 'w')
      j++, l++;
    else
      break;
  }
  int r = 0;
  while (e > j && s[e - 1] == 'w') e--, r++;
  int t = e - 1;
  while (t >= j) {
    if (s[t] == s[e - 1] || s[t] == 'w')
      t--, r++;
    else
      break;
  }
  return l + r;
}

int main() {
  cin >> n;
  cin >> s;
  s += s;
  int ans = 0;
  REP(i, 0, n) { ans = max(ans, solve(i, i + n)); }
  cout << ans << endl;
  return 0;
}
