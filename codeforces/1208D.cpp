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
ll BIT[200024], s[200024];
int ans[200024];

void update(int x, int delta) {
  for(; x<=n; x += x&(-x)) {
    BIT[x] += delta;
  }
}

int searchNum(ll preSum) {
  int num = 0;
  ll sum = 0;
  for(int i=21; i>=0; i--) {
    if(num + (1 << i) <= n && sum + BIT[num + (1 << i)] <= preSum) {
      num +=(1 << i);
      sum += BIT[num];
    }
  }
  return num + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  REP(i, 1, n+1) {
    update(i, i);
    cin >> s[i];
  }
  for(int i=n; i>0; i--) {
    ans[i] = searchNum(s[i]);
    update(ans[i], -ans[i]);
  }
  REP(i, 1, n+1) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
