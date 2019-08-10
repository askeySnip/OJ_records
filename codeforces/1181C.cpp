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
int n, m;
char blanket[1024][1024];
int dpl[1024][1024];
int dps[1024][1024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  REP(i, 0, n) cin >> blanket[i];
  memset(dpl, 0, sizeof dpl);
  memset(dps, 0, sizeof dps);
  REP(i, 1, n-1) {
    REP(j, 0, m) {
      if(blanket[i-1][j] == blanket[i][j]) continue;
      else {
        int t = i+1;
        while(t < n && blanket[t][j] == blanket[i][j]) t++;
        int lm = t - i;
        if(lm > i || lm * 2 + i > n) continue;
        int tt = t+1;
        while(tt < n && blanket[t][j] == blanket[tt][j]) tt++;
        int lb = tt - t;
        if(lb < lm) continue;
        int tp = i - 2;
        while(tp >= 0 && blanket[tp][j] == blanket[i-1][j]) tp--;
        int lt = i - tp - 1;
        if(lt < lm) continue;
        dpl[i][j] = lm;
        dps[i][j] = (blanket[i-1][j] - 'a') + (blanket[i][j] - 'a') * 27 + (blanket[t][j] - 'a') * 27 * 27;
      }
    }
  }
  int ans = 0;
  int w = 1;
  REP(i, 1, n-1) {
    for(int j=0; j<m;) {
      if(dpl[i][j]) {
        int t = j+1;
        ans+=w;
        while(t < m && dpl[i][j] == dpl[i][t] && dps[i][j] == dps[i][t]) t++, w++, ans+=w;
        j = t;
        w = 1;
      } else {
        j++;
      }
      //cout << i << " " << j << " " << ans << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
