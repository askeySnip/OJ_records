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
int p[300024];
vii ans;

void ex(int a, int b) {
  if(a > b) swap(a, b);
  if((b - a) * 2 >= n) {
    ans.push_back(ii(a, b));
  } else {
    if(b <= n / 2) {
      ans.push_back(ii(b, n));
      ans.push_back(ii(a, n));
      ans.push_back(ii(b, n));
    } else if(a > n / 2) {
      ans.push_back(ii(1, a));
      ans.push_back(ii(1, b));
      ans.push_back(ii(1, a));
    } else {
      ans.push_back(ii(a, n));
      ans.push_back(ii(1, n));
      ans.push_back(ii(1, b));
      ans.push_back(ii(1, n));
      ans.push_back(ii(a, n));
    }
  }
  swap(p[a], p[b]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  REP(i, 1, n+1) cin >> p[i];
  REP(i, 1, n+1) {
    while(p[i] != i) {
      ex(i, p[i]);
    }
  }
  cout << ans.size() << endl;
  REP(i, 0, ans.size()) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
