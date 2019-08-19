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
ll before(ll n) {
  ll ret = 0;
  int cnt = to_string(n).length();
  int a = 1;
  ll t = 9, tt = 1;
  while(cnt > a) {
    ret += a * t;
    a++;
    t *= 10;
    tt *= 10;
  }
  ret += (n - tt) * cnt;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll k;
  cin >> k;
  ll l = 1, h = k, mid;
  while(l < h) {
    mid = (l + h) / 2;
    if(before(mid+1) >= k) h = mid;
    else l = mid+1;
  }
  ll s = before(l+1) - k;
  while(s > 0) {
    l/=10;
    s--;
  }
  cout << l%10 << endl;
  return 0;
}
