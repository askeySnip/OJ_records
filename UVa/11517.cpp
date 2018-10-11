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

int price, n;
int coins[128];
int dp[20048];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &price);
    scanf("%d", &n);
    int sum = 0;
    for(int i=0; i<n; i++) {
      scanf("%d", &coins[i]);
      if(sum < price) sum += coins[i];
    }
    for(int i=0; i<=sum; i++) dp[i] = n;
    dp[0] = 0;
    for(int i=0; i<n; i++) {
      for(int j=sum; j>=coins[i]; j--) {
        if(dp[j] > dp[j-coins[i]] + 1) dp[j] = dp[j-coins[i]]+1;
      }
    }
    int s = price;
    while(dp[s] == n && s < sum) s++;
    printf("%d %d\n", s, dp[s]);
  }
  return 0;
}
