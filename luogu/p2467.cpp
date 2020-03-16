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
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int n, p;
int f[4210][4210][2];
int s[4210][2];

int main() {
  scanf("%d%d", &n, &p);
  if (n == 1) {
    printf("%d\n", 1 % p);
    return 0;
  }
  f[2][1][0] = 0, f[2][1][1] = 1;
  f[2][2][0] = 1, f[2][2][1] = 0;
  s[1][0] = 0, s[1][1] = 1, s[2][0] = 1, s[2][1] = 1;
  for (int i = 3; i <= n; i++) {
    f[i][1][0] = 0;
    f[i][1][1] = s[i - 1][0];
    for (int j = 2; j < i; j++) {
      f[i][j][0] = (s[j - 1][1] + p) % p;
      f[i][j][1] = (s[i - 1][0] - s[j - 1][0] + p) % p;
    }
    f[i][i][0] = s[i-1][1];
    f[i][i][1] = 0;
    s[1][0] = f[i][1][0], s[1][1] = f[i][1][1];
    for (int j = 2; j <= i; j++) {
      s[j][0] = (s[j - 1][0] + f[i][j][0]) % p;
      s[j][1] = (s[j - 1][1] + f[i][j][1]) % p;
    }
  }
  printf("%d\n", (s[n][0] + s[n][1]) % p);
  return 0;
}
