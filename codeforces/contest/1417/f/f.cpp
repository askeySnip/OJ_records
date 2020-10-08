/*
AUTHOR: lz.askey
CREATED: 08.10.2020 13:10:$%S%$
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define sz(x) ((int)((x).size()))
#define all(c) (c).begin(), (c).end()
// for debug
#define what_is(x) \
  cerr << "Line " << __LINE__ << ": " << #x << " is " << (x) << endl;
#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct
const int N = 700000 + 8;

int n, m, q;
ii t[N * 2], e[N], que[N];
vi adj[N];
int par[N], tin[N], tout[N], arr[N], timer = 0;
bool del[N];

int getParent(int x) {
  if (x != par[x]) par[x] = getParent(par[x]);
  return par[x];
}

void dsu_union(int x, int y) {
  x = getParent(x);
  y = getParent(y);

  if (x == y) return;

  ++n;
  par[n] = n;
  par[x] = n;
  par[y] = n;

  adj[n].push_back(x);
  adj[n].push_back(y);
}

void dfs(int x) {
  tin[x] = ++timer;
  for (int y : adj[x]) dfs(y);
  tout[x] = timer;
}

ii segMax(int l, int r) {
  r++;
  ii ans(0, 0);
  for (l += timer, r += timer; l < r; l /= 2, r /= 2) {
    if (l & 1) ans = std::max(ans, t[l++]);
    if (r & 1) ans = std::max(ans, t[--r]);
  }

  return ans;
}

void updatePos(int x, ii value) {
  x += timer;
  t[x] = value;
  while (x > 1) {
    x /= 2;
    t[x] = std::max(t[x * 2], t[x * 2 + 1]);
  }
}

void solve() {
  cin >> n >> m >> q;

  for (int i = 1; i <= n; ++i) cin >> arr[i];

  for (int i = 1; i <= m; ++i) cin >> e[i].first >> e[i].second;

  for (int i = 1; i <= q; ++i) cin >> que[i].first >> que[i].second;

  for (int i = 1; i <= q; ++i)
    if (que[i].first == 2) del[que[i].second] = true;

  for (int i = 1; i <= n; ++i) par[i] = i;

  for (int i = 1; i <= m; ++i) {
    if (!del[i]) dsu_union(e[i].first, e[i].second);
  }

  for (int i = q; i >= 1; --i) {
    int type = que[i].first;
    if (type == 2) {
      int id = que[i].second;
      dsu_union(e[id].first, e[id].second);
    } else {
      que[i].second = getParent(que[i].second);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (getParent(i) == i) dfs(i);
  }

  for (int i = 1; i <= n; ++i) updatePos(tin[i], ii(arr[i], tin[i]));

  for (int i = 1; i <= q; ++i) {
    int type = que[i].first;
    if (type == 2) continue;

    int v = que[i].second;
    ii mx = segMax(tin[v], tout[v]);
    cout << mx.first << '\n';
    if (mx.first) updatePos(mx.second, ii(0, 0));
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
