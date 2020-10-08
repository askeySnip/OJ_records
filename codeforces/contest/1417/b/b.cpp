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
    int n, t;
    cin >> n >> t;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vi order(n);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) { return a[i] < a[j]; });
    vi ans(n, 0);
    if (t & 1) {
      int v = t / 2;
      rep(i, 0, n) {
        int j = order[i];
        if (a[j] <= v)
          ans[j] = 1;
        else
          break;
      }
    } else {
      int v = t / 2;
      vi e;
      rep(i, 0, n) {
        int j = order[i];
        if (a[j] < v)
          ans[j] = 1;
        else if (a[j] == v)
          e.push_back(j);
        else
          ans[j] = 0;
      }
      for (int i = 0; i < (int)e.size(); i += 2) {
        ans[e[i]] = 1;
      }
    }
    rep(i, 0, n) {
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << "\n";
  }
  return 0;
}
