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
const ll x_max = ((ll)1<<32) - 1;
int l, i;

ll read() {
  ll ret = 0;
  string s;
  int n;
  while(i < l) {
    i++;
    cin >> s;
    if(ret < 0) {
      return -inf;
    }
    if(s[0] == 'a') ret++;
    else if(s[0] == 'f') {
      cin >> n;
      ll inner = read();
      ret += inner * n;
      if(ret > x_max) return -inf;
    } else {
      return ret;
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> l;
  ll ans = 0;
  i = 0;
  ans = read();
  if(ans < 0 || ans > x_max) printf("OVERFLOW!!!\n");
  else printf("%lld\n", ans);
  return 0;
}
