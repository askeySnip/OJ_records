/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct

// data
int n, s, a, b;

int main() {
  scanf("%d%d%d%d", &n, &s, &a, &b);
  int x, y;
  vi ya;
  REP(i, 0, n) {
    scanf("%d%d", &x, &y);
    if (x <= a + b) ya.push_back(y);
  }
  int dp[1024]{0};
  REP(i, 0, ya.size()) {
    for (int j = s; j >= ya[i]; j--) {
      dp[j] = max(dp[j], dp[j - ya[i]] + 1);
    }
  }
  printf("%d\n", dp[s]);
  return 0;
}
