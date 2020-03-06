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
int n, M, T;
int m[110], t[110];
int dp[220][220];

int main() {
  scanf("%d%d%d", &n, &M, &T);
  REP(i, 0, n) scanf("%d%d", &m[i], &t[i]);
  memset(dp, 0, sizeof dp);
  REP(i, 0, n) {
    for (int j = M; j >= m[i]; j--) {
      for (int k = T; k >= t[i]; k--) {
        dp[j][k] = max(dp[j][k], dp[j - m[i]][k - t[i]] + 1);
      }
    }
  }
  printf("%d\n", dp[M][T]);
  return 0;
}
