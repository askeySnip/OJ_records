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
const int maxn = 5e5+10;

int main() {
  ll n, k;
  char a[maxn], b[maxn];
  scanf("%lld %lld", &n, &k);
  scanf("%s", a);
  scanf("%s", b);
  ll ans = 0, sum = 1L;
  int cur = 0;
  while(cur < n && a[cur] == b[cur]) ans++, cur++;
  REP(i, cur, n) {
    sum = sum * 2;
    if(a[i] == 'b') sum--;
    if(b[i] == 'a') sum--;
    ans += sum;
    if(sum >= k) {
      ans -= sum - k;
      ans += (n-(ll)i-1L) * k;  // notice: if n and k isn't long long type, (n-i-1) * k probably overflow!!!
      break;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
