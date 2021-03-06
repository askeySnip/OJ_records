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
int n;
int a[100010];

void solve() {
  sort(a, a + n);
  vi ans;
  int i = 0, j = n - 1;
  while (i <= j) {
    if (ans.size() % 2 == 0)
      ans.push_back(a[j--]);
    else
      ans.push_back(a[i++]);
  }
  for (int i = n - 1; i >= 0; i--) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &a[i]);
    solve();
  }
  return 0;
}
