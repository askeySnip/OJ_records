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

const int maxn = 1e6+5;
const int mod = 1e9+7;

int n;
long long ans = 0;
int a[maxn];
int dp[maxn];
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  scanf("%d", &n);
  dp[0] = 1;
  for(int i=1; i<=n; i++) {
    scanf("%d", &a[i]);
    vector<int> cur;
    for(int j=1; j*j<=a[i]; j++) {
      if(a[i]%j == 0){
        cur.push_back(j);
        if(j != a[i]/j) cur.push_back(a[i]/j);
      }
    }
    sort(cur.begin(), cur.end());
    reverse(cur.begin(), cur.end());
    for(auto &it: cur) {
      dp[it] += dp[it-1];
      dp[it] %= mod;
    }
  }
  for(int i=1; i<=n; i++) ans += dp[i];
  ans %= mod;
  cout << ans;
  return 0;
}