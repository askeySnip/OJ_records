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

const int mod = 998244353;
// data
int n;
vector<ll> a;
vector<ll> b;
vector<ll> ab;
vector<ll> f;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  a.resize(n); b.resize(n); ab.resize(n); f.resize(n);
  REP(i, 0, n) cin >> a[i];
  REP(i, 0, n) cin >> b[i];
  REP(i, 0, n) f[i] = (ll)(i+1) * (n-i) * a[i];
  sort(f.begin(), f.end());
  sort(b.begin(), b.end());
  ll ans = 0;
  REP(i, 0, n) {
    ans += (f[i]%mod) * (b[n-i-1]%mod)%mod;
    ans %=mod;
  }
  cout << ans << endl;
  return 0;
}
