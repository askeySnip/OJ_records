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
int n, k;
int a[200024];
int cnt[200024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  int nmx = 0;
  REP(i, 0, n) cin >> a[i], cnt[a[i]]++, nmx = max(nmx, a[i]);
  REP(i, 0, 200001) if(cnt[i] >= k) {
    cout << 0 << endl;
    return 0;
  }
  REP(i, 1, 200001) {
    cnt[i] += cnt[i-1];
  }
  int ans = inf;
  REP(i, 1, 100001) {
    int t = cnt[i] - cnt[i-1];
    int ocnt = 0;
    int j = 1;
    while(i * (1 << j) <= 200000) {
      int tt = (i+1) * (1 << j) - 1;
      int ss = i * (1 << j) - 1;
      int nn = cnt[tt > 200000 ? 200000 : tt] - cnt[ss];
      if(nn + t >= k) {
        ocnt += j * (k - t);
        ans = min(ans, ocnt);
        break;
      } else {
        ocnt += j * nn;
        t += nn;
      }
      j++;
      if(tt > 200000) break;
    }
  }
  int t = cnt[1];
  int ocnt = cnt[1] - cnt[0];
  int j=1;
  while((1 << j) <= 200000) {
    int tt = 2 * (1 << j) - 1;
    int ss = (1 << j) - 1;
    int nn = cnt[tt > 200000 ? 200000 : tt] - cnt[ss];
    if(nn + t >= k) {
      ocnt += (j + 1) * (k - t);
      ans = min(ans, ocnt);
      break;
    } else {
      ocnt += (j + 1) * nn;
      t += nn;
    }
    j++;
    if(tt > 200000) break;
  }
  cout << ans << endl;
  return 0;
}
