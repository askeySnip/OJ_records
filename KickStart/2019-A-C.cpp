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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

int n, q;
int l[30024], r[30024], bias[30024];
vii book;

bool check(int k) {
  REP(i, 0, q)
  l[i] = book[i].first,
  r[i] = -book[i].second, bias[i] = book[i].first;

  REP(i, 0, q) {
    int st = bias[i];
    int ed = r[i];
    int cnt = 0;
    REP(j, i + 1, q) {
      if (r[j] <= r[i]) {
        if (l[j] <= st) {
          st = max(st, r[j] + 1);
        } else {
          cnt += l[j] - st;
          st = max(st, r[j] + 1);
          if (cnt >= k) {
            ed = l[j] - (cnt - k);
            break;
          }
        }
      }
    }
    if (cnt < k) {
      cnt += r[i] - st + 1;
      if (cnt < k) return 0;
      ed = r[i] - (cnt - k) + 1;
    }
    REP(j, i + 1, q) {
      if (l[j] >= ed) break;
      if (r[j] > r[i]) {
        bias[j] = max(bias[j], r[i] + 1);
      }
    }
  }
  return 1;
}

int solve() {
  sort(book.begin(), book.end());
  int low = 0, high = n + 1;
  while (low < high - 1) {
    int mid = (low + high) / 2;
    if (check(mid))
      low = mid;
    else
      high = mid;
  }
  return low;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &q);
    book.clear();
    REP(i, 0, q) {
      scanf("%d%d", &l[i], &r[i]);
      book.push_back(ii(l[i], -r[i]));
    }
    printf("Case #%d: %d\n", ++kase, solve());
  }
  return 0;
}
