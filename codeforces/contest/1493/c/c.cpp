/*
AUTHOR: lz.askey
CREATED: 19.03.2021 00:32:15
LANG: C++11
*/
#include <assert.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <new>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define bit(x, i) (x & (1 << i))
#define in(i, l, r) (l < i && i < r)
#define linr(i, l, r) (l <= i && i <= r)
#define lin(i, l, r) (l <= i && i < r)
#define inr(i, l, r) (l < i && i <= r)
#define gi(a) scanf("%d", &a)
#define gii(a, b) scanf("%d%d", &a, &b)
#define giii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define gs(x) scanf("%s", x)
#define clr(a, x) memset(a, x, sizeof(a))
#define c2i(c) (c - '0')
#define sz(x) ((int)((x).size()))
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
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

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data
int n, k;
string s;

void solve() {
  vi cnt(26, 0);
  REP(i, 0, n)++ cnt[s[i] - 'a'];
  int sum = 0;
  REP(i, 0, 26) sum += (k - cnt[i] % k) % k;
  if (sum == 0) {
    cout << s << "\n";
    return;
  }
  if (n % k) {
    cout << "-1\n";
    return;
  }
  for (int i = n - 1; i >= 0; i--) {
    sum -= (k - cnt[s[i] - 'a'] % k) % k;
    cnt[s[i] - 'a']--;
    sum += (k - cnt[s[i] - 'a'] % k) % k;
    for (int j = s[i] - 'a' + 1; j < 26; j++) {
      int lst_sum = sum;
      sum -= (k - cnt[j] % k) % k;
      cnt[j]++;
      sum += (k - cnt[j] % k) % k;

      if (i + sum + 1 <= n) {
        REP(pos, 0, i) cout << s[pos];
        cout << char(j + 'a');
        string add = "";
        REP(w, 0, 26) {
          int f = (k - cnt[w] % k) % k;
          while (f) {
            --f;
            add += char(w + 'a');
          }
        }
        while ((int)add.size() + i + 1 < n) {
          add += 'a';
        }

        sort(all(add));
        cout << add << "\n";
        return;
      }
      sum = lst_sum;
      cnt[j]--;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> s;
    solve();
  }
  return 0;
}
