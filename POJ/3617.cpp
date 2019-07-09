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
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
int n;
char s[2048];
char ans[2048];

void solve() {
  int l = 0, r = n-1;
  int c = 0;
  while(l <= r) {
    bool left = false;
    for(int i=0; i+l<=r; i++) {
      if(s[l+i] < s[r-i]) {
        left = true;
        break;
      }else if(s[l+i] > s[r-i]) {
        left = false;
        break;
      }
    }
    if(left) ans[c++] = s[l++];
    else ans[c++] = s[r--];
  }
  REP(i, 0, n) {
    if(i && (i)%80 == 0) cout << endl;
    cout << ans[i];
  }
  if(n%80) cout << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  REP(i, 0, n) cin >> s[i];
  solve();
  return 0;
}
