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
int n;
int phi[41000];
void phi_table(int n) {
  REP(i, 2, n + 1) phi[i] = 0;
  phi[1] = 1;
  REP(i, 2, n + 1) {
    if (!phi[i]) {
      for (int j = i; j <= n; j += i) {
        if (!phi[j]) phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  phi_table(n);
  ll ans = 0;
  REP(i, 2, n) { ans += phi[i]; }
  ans *= 2;
  ans += 3;
  if(n == 1) ans = 0;
  printf("%lld\n", ans);
  return 0;
}
