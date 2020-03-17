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
int a[10024];
map<int, int> cnt;
int f[10024];

int main() {
  cnt.clear();
  scanf("%d", &n);
  REP(i, 0, n) scanf("%d", &a[i]);
  REP(i, 0, n) {
    for (int j = 1; j <= (int)sqrt(a[i]); j++) {
      if (a[i] % j == 0) {
        cnt[j]++;
        if (j * j != a[i]) cnt[a[i] / j]++;
      }
    }
  }
  for (auto it : cnt) {
    // cout << it.first << " " << it.second << endl;
    f[it.second] = max(f[it.second], it.first);
  }
  for (int i = n; i > 0; i--) {
    f[i] = max(f[i], f[i + 1]);
  }
  REP(i, 1, n + 1) printf("%d\n", f[i]);
  return 0;
}
