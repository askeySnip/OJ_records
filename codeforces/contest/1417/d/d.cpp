/*
AUTHOR: lz.askey
CREATED: 08.10.2020
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
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
    int s = 0;
    rep(i, 0, n) s += a[i];
    if (s % n) {
      cout << -1 << '\n';
      continue;
    }
    int avg = s / n;
    vector<pair<ii, int>> ans;
    rep(i, 1, n) {
      if (a[i] % (i + 1)) {
        ans.push_back({{1, i + 1}, i + 1 - (a[i] % (i + 1))});
      }
      ans.push_back({{i + 1, 1}, (a[i] + i) / (i + 1)});
      a[0] += a[i];
    }
    rep(i, 1, n) { ans.push_back({{1, i + 1}, avg}); }
    cout << ans.size() << endl;
    rep(i, 0, ans.size()) {
      cout << ans[i].first.first << " " << ans[i].first.second << " "
           << ans[i].second << "\n";
    }
  }
  return 0;
}
