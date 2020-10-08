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
struct node {
  ll sz, x, left, right;
  node() {
    sz = 0, x = 0;
    left = right = -1;
  }
};
// data

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi a(n);
  rep(i, 0, n) cin >> a[i];
  vector<node> tr(1);
  for(int i=n-1; i>=0; i--) {
    int cur = 0;
    for(int j=30; j>=0; j--) {
      if(a[i]&(1<<j)) {
        if(tr[cur].right == -1) {
          tr[cur].right = tr.size();
          tr.push_back({});
        }
        int nxt = tr[cur].right;
        tr[nxt].x += tr[cur].left == -1 ? 0 : tr[tr[cur].left].sz;
        tr[nxt].sz+=1;
        cur = nxt;
      } else {
        if(tr[cur].left == -1) {
          tr[cur].left = tr.size();
          tr.push_back({});
        }
        int nxt = tr[cur].left;
        tr[nxt].x += tr[cur].right == -1 ? 0 : tr[tr[cur].right].sz;
        tr[nxt].sz += 1;
        cur = nxt;
      }
    }
  }
  ll invb = 0, x = 0;
  queue<int> q;
  q.push(0);
  while(!q.empty()) {
    ll z = 0, o = 0;
    int levelsz = q.size();
    rep(i, 0, levelsz) {
      int u = q.front(); q.pop();
      o += tr[u].left == -1 ? 0 : tr[tr[u].left].x;
      z += tr[u].right == -1 ? 0 : tr[tr[u].right].x;
      if(tr[u].left != -1) q.push(tr[u].left);
      if(tr[u].right != -1) q.push(tr[u].right);
    }
    x <<= 1;
    if(z <= o) x += 0;
    else x += 1;
    invb += min(z, o);
  }
  x >>= 1;
  cout << invb << " " << x << "\n";
  return 0;
}
