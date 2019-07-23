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
const int mod = 998244353;

int mult(int a, int b) {
  return (ll) a * b % mod;
}

void add(int& a, int b) {
  a += b;
  if(a > mod) a -= mod;
}

int f(vi& digits, int l) {
  int res = 0;
  int p = 1;
  for(int i=0; i<max((int)digits.size(), l); i++) {
    if(i < l) p = mult(p, 10);
    if(i < (int)digits.size()) {
      add(res, mult(digits[i], p));
      p = mult(p, 10);
    }
  }
  return res;
}

int f(int l, vi& a) {
  int res = 0;
  int p = 1;
  for(int i=0; i<max((int)a.size(), l); i++) {
    if(i < (int)a.size()) {
      add(res, mult(a[i], p));
      p = mult(p, 10);
    }
    if(i < l) p = mult(p, 10);
  }
  return res;
}

int main() {
  scanf("%d", &n);
  int v;
  memset(cnt, 0, sizeof cnt);
  for(int i=0; i<n; i++) {
    scanf("%d", &v);
    a.push_back(v);
    int l = (int)to_string(v).size();
    cnt[l]++;
  }
  int ans = 0;
  for(int i=0; i<n; i++) {
    vi digits;
    int t = a[i];
    while(t) {
      digits.push_back(t%10);
      t/=10;
    }
    for(int l=1; l<11; l++) {
      int sum = f(digits, l);
      add(ans, mult(sum, cnt[l]));

      sum = f(l, digits);
      add(ans, mult(sum, cnt[l]));
    }
  }
  printf("%d\n", ans);
  return 0;
}
