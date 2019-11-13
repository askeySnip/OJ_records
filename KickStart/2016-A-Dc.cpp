#include <bits/stdc++.h>
using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX / 3
#define mod 1000000007ll
#define PI acos(-1.0)
#define linf (1ll << 60) - 1
#define FOR(I, A, B) for (int I = (A); I < (B); ++I)
#define REP(I, N) FOR(I, 0, N)
#define ALL(A) ((A).begin(), (A).end())
#define set0(ar) memset(ar, 0, sizeof ar)
#define vsort(v) sort(v.begin(), v.end())
#define setinf(ar) memset(ar, 126, sizeof ar)

// cout << fixed << setprecision(20) << p << endl;

template <class T>
inline T bigmod(T p, T e, T M) {
  LL ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}

int K[13], L[13];
vector<LL> A[13], C[13];
vector<int> vc[2];

vector<pair<LL, LL> > vp[2];

void bctrack(int f, int c, LL lvl, LL cst) {
  if (c == 4) {
    vp[f].pb(mp(cst, lvl));
    return;
  }

  LL s = 0, p;
  for (int i = L[vc[f][c]]; i <= K[vc[f][c]]; i++) {
    p = A[vc[f][c]][i];

    bctrack(f, c + 1, lvl + p, cst + s);

    if (i == K[vc[f][c]]) break;
    s += C[vc[f][c]][i];
  }
}

void go(int f) {
  vp[f].clear();
  bctrack(f, 0, 0, 0);
  vsort(vp[f]);
  FOR(i, 1, vp[f].size()) vp[f][i].yy = max(vp[f][i].yy, vp[f][i - 1].yy);
}

int main() {
  // freopen("a.in", "r", stdin);
  // freopen("a.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  FOR(ts, 1, T + 1) {
    REP(i, 13) {
      A[i].clear();
      C[i].clear();
      A[i].pb(0);
      C[i].pb(0);
    }

    LL n, m;
    cin >> m >> n;
    REP(i, n) {
      cin >> K[i] >> L[i];
      FOR(j, 1, K[i] + 1) {
        LL v;
        cin >> v;
        A[i].pb(v);
      }
      FOR(j, 1, K[i]) {
        LL v;
        cin >> v;
        C[i].pb(v);
      }
    }

    LL res = 0;
    REP(i, 1 << n) {
      if (__builtin_popcount(i) != 8) continue;
      vc[0].clear();
      vc[1].clear();

      int cnt = 0;
      REP(j, n) {
        if (i & 1 << j) {
          cnt++;
          if (cnt <= 4)
            vc[0].pb(j);
          else
            vc[1].pb(j);
        }
      }

      go(0);
      go(1);

      int k = vp[1].size() - 1;

      REP(j, vp[0].size()) {
        if (vp[0][j].xx > m) break;
        while (k >= 0 && vp[0][j].xx + vp[1][k].xx > m) k--;
        if (k >= 0)
          res = max(res, vp[0][j].yy + vp[1][k].yy);
        else
          res = max(res, vp[0][j].yy);
      }
      REP(j, vp[1].size()) {
        if (vp[1][j].xx <= m) res = max(res, vp[1][j].yy);
      }
    }

    cout << "Case #" << ts << ": " << res << endl;
  }
}
