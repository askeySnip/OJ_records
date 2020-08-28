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

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

// struct

// // data
// int n, q;
// int d[100010];
// int f[100010][20];
// int root;
// // child[i][0] i's left child; child[i][1] i's right child;
// int child[100010][2];
// vi sz;
// vi l, r;

// void dfs(int u) {
//   sz[u] = 1;
//   for (int v : child[u]) {
//     if (v == -1) continue;
//     dfs(v);
//     sz[u] += sz[v];
//   }
// }

// void solve() {
//   REP(i, 1, n + 1) child[i][0] = child[i][1] = -1;
//   sz.assign(n + 1, 0);
//   l.assign(n + 1, -1), r.assign(n + 1, -1);
//   REP(i, 1, n + 1) REP(j, 0, 20) f[i][j] = -1;
//   stack<int> stk;
//   REP(i, 1, n) {
//     while (!stk.empty() && d[stk.top()] < d[i]) {
//       r[stk.top()] = i;
//       stk.pop();
//     }
//     if (!stk.empty()) l[i] = stk.top();
//     stk.push(i);
//   }
//   REP(i, 1, n) {
//     int j = -1;
//     int lr = 0;
//     if (l[i] != -1 && r[i] != -1) {
//       if (d[l[i]] < d[r[i]]) {
//         j = l[i];
//         lr = 1;
//       } else {
//         j = r[i];
//         lr = 0;
//       }
//     } else if (l[i] != -1) {
//       j = l[i];
//       lr = 1;
//     } else if (r[i] != -1) {
//       j = r[i];
//       lr = 0;
//     }
//     f[i][0] = j;
//     if (j == -1)
//       root = i;
//     else
//       child[j][lr] = i;
//   }
//   dfs(root);
//   REP(i, 1, n) {
//     REP(j, 1, 20) {
//       int k = f[i][j - 1];
//       if (k == -1) break;
//       f[i][j] = f[k][j - 1];
//     }
//   }
//   vi ans;
//   REP(i, 0, q) {
//     int s, k;
//     scanf("%d%d", &s, &k);
//     int x, lr;
//     --k;
//     if (s == 1)
//       x = 1, lr = 1;
//     else if (s == n)
//       x = n - 1, lr = 0;
//     else {
//       if (d[s - 1] < d[s]) {
//         x = s - 1;
//         lr = 0;
//       } else {
//         x = s;
//         lr = 1;
//       }
//     }
//     if (sz[x] >= k) {
//       if (lr) {
//         ans.push_back(s + k);
//       } else {
//         ans.push_back(s - k);
//       }
//     } else {
//       int y = x;
//       for (int i = 19; i >= 0; i--) {
//         if (f[y][i] == -1) continue;
//         int t = f[y][i];
//         if (sz[t] < k) y = t;
//       }
//       y = f[y][0];
//       if (x < y)
//         ans.push_back(y + k - (child[y][0] == -1 ? 0 : sz[child[y][0]]));
//       else
//         ans.push_back(y + 1 - (k - (child[y][1] == -1 ? 0 :
//         sz[child[y][1]])));
//     }
//   }
//   REP(i, 0, q) {
//     if (i) printf(" ");
//     printf("%d", ans[i]);
//   }
//   printf("\n");
// }

// data
const int K = 18;
int n, q;
int d[100010];

void solve() {
  d[0] = inf, d[n] = inf;
  vi lf(n + 1, -1), rf(n + 1, n + 1);
  vector<vi> sparse(n + 1, vi(K));
  REP(i, 0, n + 1) sparse[i][0] = i;
  REP(k, 1, K) {
    REP(i, 0, n + 1) {
      sparse[i][k] = sparse[i][k - 1];
      int right = i + (1 << (k - 1));
      if (right <= n && d[sparse[right][k - 1]] > d[sparse[i][k]])
        sparse[i][k] = sparse[right][k - 1];
    }
  }
  stack<int> st;
  REP(i, 0, n + 1) {
    while (!st.empty() && d[st.top()] < d[i]) {
      rf[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  st = stack<int>();
  for (int i = n; i >= 0; i--) {
    while (!st.empty() && d[st.top()] < d[i]) {
      lf[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }

  auto query_sparse = [&](int l, int r) {
    if (l == r) return l;
    int len = r - l + 1;
    int half = trunc(log2(len - 1));
    int ans = sparse[l][half];
    if (d[sparse[r - (1 << half) + 1][half]] > d[ans])
      ans = sparse[r - (1 << half) + 1][half];
    return ans;
  };

  while (q--) {
    int s, k;
    read(s), read(k);
    auto output = [&](int ans) { printf("%d ", ans); };
    if (rf[s - 1] - (s - 1) > k - 1) {
      int ans = s + k - 1;
      if (ans > n) ans = n - k + 1;
      output(ans);
      continue;
    }
    if (s - lf[s] > k - 1) {
      int ans = s - k + 1;
      if (ans < 1) ans = k;
      output(ans);
      continue;
    }
    int l = 1, r = min(k - 2, s);
    while (l <= r) {
      int mid = (l + r) / 2;
      int ma = query_sparse(s - mid, s - 1);
      int right = rf[ma];
      int tot = right - (s - mid);
      if (tot > k - 1) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    int lmost = s - r;
    int rmost = s - r + k - 2;
    int ans;
    if (rmost > n)
      ans = n - k + 1;
    else {
      int hi = query_sparse(lmost, rmost);
      if (hi >= s)
        ans = rmost + 1;
      else
        ans = lmost;
    }
    output(ans);
  }
  printf("\n");
}

int main() {
  int t, kase = 0;
  read(t);
  while (t--) {
    read(n);
    read(q);
    REP(i, 1, n) read(d[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
