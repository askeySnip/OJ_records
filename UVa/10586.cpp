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


int main() {
  int n, k;
  while(scanf("%d %d", &n, &k), n!=-1 && k!=-1) {
    int a[10024];
    REP(i, 0, n+1) {
      scanf("%d", &a[i]);
    }
    for(int i=n; i>=0; i--) {
      if(i < k) break;
      if(a[i] == 0) continue;
      a[i-k] -= a[i];
      a[i] = 0;
    }
    vi ans;
    bool flag = true;
    for(int i=k-1; i>=0; i--) {
      if(a[i] == 0 && flag) continue;
      if(a[i] && flag) {
        flag = false;
      }
      if(!flag) ans.push_back(a[i]);
    }
    if(ans.empty()) ans.push_back(0);
    reverse(ans.begin(), ans.end());
    REP(i, 0, ans.size()) {
      if(i) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
