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
ll a, b, m;


void solve() {
  int k_num = 2;
  ll cur = a + m;
  for(; k_num<=50; k_num++) {
    if(cur >= b) break;
    cur <<= 1;
  }
  if(k_num > 50) {
    cout << "-1" << endl;
    return;
  }
  ll d = b - ((ll)1 << (k_num-2)) * (a + 1);
  if(d < 0) {
    cout << "-1" << endl;
    return;
  }
  vector<ll> ans;
  ans.push_back(0);
  for(int i = k_num-3; i>=0; i--) {
    ll step = (ll)1 << i;
    ans.push_back(min(d / step + 1, m));
    d -= (ans.back()-1) * step;
  }
  if(d) ans.push_back(d + 1);
  else ans.push_back(1);
  cout << k_num << " " << a;
  ll sum = a;
  for(int i=1; i<k_num; i++) {
    cout << " " << sum + ans[i];
    sum = sum * 2 + ans[i];
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;

  while(q--) {
    cin >> a >> b >> m;
    if(a == b) {
      cout << "1 " << a << endl;
    } else {
      solve();
    }
  }
  return 0;
}
