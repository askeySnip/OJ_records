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
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct
int n;
char s[60], t[60];

// data

void solve() {
  vii op;
  REP(i, 0, n) {
    if (s[i] != t[i]) {
      bool f = false;
      REP(j, i + 1, n) {
        if (s[j] != t[j]) {
          if (s[j] == s[i]) {
            swap(s[j], t[i]);
            op.push_back(ii(j, i));
            f = true;
            break;
          } else if (t[j] == s[i]) {
            swap(s[j], t[j]);
            op.push_back(ii(j, j));
            swap(s[j], t[i]);
            op.push_back(ii(j, i));
            f = true;
            break;
          }
        }
      }
      if (!f) {
        printf("No\n");
        return;
      }
    }
  }
  printf("Yes\n");
  printf("%d\n", (int)op.size());
  REP(i, 0, op.size()) { printf("%d %d\n", op[i].first + 1, op[i].second + 1); }
}

int main() {
  int k, kase = 0;
  scanf("%d", &k);
  // k = 1;
  while (k--) {
    scanf("%lld", &n);
    scanf("%s", s);
    scanf("%s", t);
    solve();
  }

  return 0;
}
