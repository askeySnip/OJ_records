/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

class BIT {
 private:
  vi ft;

 public:
  BIT(int n) { ft.assign(n + 1, 0); }
  int rsq(int b) {
    int sum = 0;
    for (; b; b -= (b & (-b))) {
      sum += ft[b];
    }
    return sum;
  }
  void add(int k) {
    for (; k < (int)ft.size(); k += (k & (-k))) {
      ft[k]++;
    }
  }
};

int n;
int a[100010];

void solve() {
  vi ans;
  ans.push_back(0);
  BIT b(100010);
  REP(i, 0, n) {
    b.add(a[i]);
    int tmp = ans.back();
    if (b.rsq(100009) - b.rsq(tmp) >= tmp + 1) {
      ans.push_back(tmp + 1);
    } else {
      ans.push_back(tmp);
    }
  }
  REP(i, 1, ans.size()) { printf(" %d", ans[i]); }
  printf("\n");
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &a[i]);
    printf("Case #%d:", ++kase);
    solve();
  }
  return 0;
}
