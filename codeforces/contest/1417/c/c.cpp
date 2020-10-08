/*
AUTHOR: lz.askey
CREATED: 08.10.2020
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

// data

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vi> pos(n + 1);
    rep(i, 1, n + 1) pos[i].push_back(-1);
    rep(i, 0, n) { pos[a[i]].push_back(i); }
    rep(i, 1, n + 1) pos[i].push_back(n);
    vi dis(n + 1, n + 1);
    rep(i, 1, n + 1) {
      if (pos[i].size() > 2) {
        int d = 0;
        rep(j, 1, pos[i].size()) { d = max(pos[i][j] - pos[i][j - 1], d); }
        dis[i] = d;
      }
    }
    vi order(n + 1);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) { return dis[i] < dis[j]; });
    set<int> s;
    int j = 0;
    rep(i, 1, n + 1) {
      if (i > 1) cout << " ";
      while (j < n + 1 && dis[order[j]] <= i) s.insert(order[j]), j++;
      if (s.empty())
        cout << -1;
      else
        cout << *s.begin();
    }
    cout << "\n";
  }
  return 0;
}
