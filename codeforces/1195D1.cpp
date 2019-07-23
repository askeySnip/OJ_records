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
int n;
vi a;
int cnt[11];
int pw10[30];
const int mod = 998244353;

int mult(int a, int b) {
  return (ll) a * b % mod;
}

void add(int& a, int b) {
  a += b;
  if(a > mod) a -= mod;
}

int f(int a) {
  int res = 0;
  int pos = 0;
  while(a > 0) {
    int cur = a % 10;
    a /= 10;
    add(res, mult(cur, pw10[pos*2]));
    add(res, mult(cur, pw10[pos*2+1]));
    ++pos;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  int v;
  pw10[0] = 1;
  for(int i=1; i<30; i++) {
    pw10[i] = mult(pw10[i-1], 10);
  }
  for(int i=0; i<n; i++) {
    scanf("%d", &v);
    a.push_back(v);
  }
  int ans = 0;
  for(int i=0; i<n; i++) {
    add(ans, mult(n, f(a[i])));
  }
  printf("%d\n", ans);
  return 0;
}
