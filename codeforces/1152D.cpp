/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
const int mod = 1e9+7;
int n;
ii mem[2048][2048];

int add(int a, int b) {
  int c = a + b;
  if(c >= mod) c -= mod;
  return c;
}

ii dp(int d, int b) {
  if(d == 0) return ii(0, 1);
  if(mem[d][b].first) return mem[d][b];
  int s = 0;
  bool f = false;
  if(b != 0) {
    ii t = dp(d-1, b-1);
    s = add(s, t.first);
    f = f || t.second;
  }
  if(b+1 <= d - 1) {
    ii t = dp(d-1, b+1);
    s = add(s, t.first);
    f = f || t.second;
  }
  if(f) {
    s = add(s, 1);
    mem[d][b] = ii(s, false);
  } else {
    mem[d][b] = ii(s, true);
  }
  return mem[d][b];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  n *= 2;
  mem[0][0] = ii(0, 1);
  cout << dp(n, 0).first << endl;
  return 0;
}
