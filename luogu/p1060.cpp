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
int v[30], p[30];
int dp[30010];

int main() {
  scanf("%d%d", &n, &m);
  REP(i, 0, m) scanf("%d%d", &v[i], &p[i]);
  REP(i, 0, m) {
    for (int j = n; j >= v[i]; j--) {
      dp[j] = max(dp[j], dp[j - v[i]] + v[i] * p[i]);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
