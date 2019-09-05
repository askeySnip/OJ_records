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
int np[300024];
const int mod = 998244353;
vii ab;

int multi(int a, int b) {
  return ((ll)a * b) % mod;
}

int sum(int a, int b) {
  return (a + b) % mod;
}

bool cmp(ii a, ii b) {
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  np[0] = 1;
  REP(i, 1, n+1) {
    np[i] = multi(np[i-1], i);
  }
  ab.resize(n);
  REP(i, 0, n) {
    cin >> ab[i].first >> ab[i].second;
  }
  int ans = np[n];
  sort(ab.begin(), ab.end());
  int l = 0;
  int d = 1;
  while(l < n) {
    int r = l + 1;
    while(r < n && ab[l].first == ab[r].first) r++;
    d = multi(d, np[r - l]);
    l = r;
  }
  ans = sum(ans, mod - d);
  l = 0, d = 1;
  while(l < n) {
    int r = l + 1;
    while(r < n && ab[l].first == ab[r].first) r++;
    map<int, int> mp;
    REP(i, l, r) mp[ab[i].second]++;
    for(auto p : mp) d = multi(d, np[p.second]);
    l = r;
  }
  for(int i=1; i<n; i++) {
    if(ab[i].second < ab[i-1].second) d = 0;
  }
  ans = sum(ans, d);
  sort(ab.begin(), ab.end(), cmp);
  l = 0; d = 1;
  while(l < n) {
    int r = l + 1;
    while(r < n && ab[l].second == ab[r].second) r++;
    d = multi(d, np[r - l]);
    l = r;
  }
  ans = sum(ans, mod - d);
  cout << ans << endl;
  return 0;
}
