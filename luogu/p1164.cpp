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
int n, m;
int a[110];
int dp[1024];

int main() {
  scanf("%d%d", &n, &m);
  REP(i, 0, n) scanf("%d", &a[i]);
  dp[0] = 1;
  REP(i, 0, n) {
    for (int j = m; j >= a[i]; j--) {
      dp[j] += dp[j - a[i]];
    }
  }
  printf("%d\n", dp[m]);
  return 0;
}
