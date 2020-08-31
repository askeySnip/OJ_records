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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
ll n;

void solve() {
  string s = to_string(n);
  int len = s.length();
  reverse(s.begin(), s.end());
  int f[20][2]{0};
  f[0][0] = s[0] - '0';
  if(s[0] != '9') f[0][1] = s[0] - '0' + 10;
  else f[0][1] = 0;
  for(int i=1; i<len; i++) {
    f[i][1] = max(s[i] == '9' ? 0 : f[i-1][0] + s[i] - '0' + 10, f[i-1][1] + s[i] - '0' + 9);
    f[i][0] = max(f[i-1][0] + s[i] - '0', s[i] == '0' ? 0 : f[i-1][1] + s[i] - '0' - 1);
  }
  printf("%d\n", f[len-1][0]);
}

int main() {
  int t;
  scanf("%d", &t);
  // t = 1;
  while (t--) {
    scanf("%lld", &n);
    solve();
  }
  return 0;
}
