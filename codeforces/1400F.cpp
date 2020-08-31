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
#define bit(x, i) (x & (1 << i))
#define IN(i, l, r) (l < i && i < r)
#define LINR(i, l, r) (l <= i && i <= r)
#define LIN(i, l, r) (l <= i && i < r)
#define INR(i, l, r) (l < i && i <= r)
#define getI(a) scanf("%d", &a)
#define getII(a, b) scanf("%d%d", &a, &b)
#define getIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x)
#define clr(a, x) memset(a, x, sizeof(a))
#define char2Int(c) (c - '0')
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// for debug
inline void pisz(int n) { printf("%d\n", n); }
#define DBG(vari) cerr << #vari << " = " << (vari) << endl;
#define printA(a, L, R) FE(i, L, R) cout << a[i] << (i == R ? '\n' : ' ')
#define printV(a) printA(a, 0, a.size() - 1)
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// AC automaton

// struct
const int K = 9;
struct Vertex {
  int next[K];
  bool leaf = false;
  int p = -1;
  char pch;
  int link = -1;
  int go[K];

  Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
    fill(begin(next), end(next), -1);
    fill(begin(go), end(go), -1);
  }
};

// data
string s;
int x;
vector<Vertex> trie(1);

void add_string(const string& a) {
  int v = 0;
  for (auto ch : a) {
    int cc = ch - '1';
    if (trie[v].next[cc] == -1) {
      trie[v].next[cc] = trie.size();
      trie.emplace_back(v, ch);
    }
    v = trie[v].next[cc];
  }
  trie[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v) {
  if (trie[v].link == -1) {
    if (v == 0 || trie[v].p == 0)
      trie[v].link = 0;
    else
      trie[v].link = go(get_link(trie[v].p), trie[v].pch);
  }
  return trie[v].link;
}

int go(int v, char ch) {
  int c = ch - '1';
  if (trie[v].go[c] == -1) {
    if (trie[v].next[c] != -1) {
      trie[v].go[c] = trie[v].next[c];
    } else {
      trie[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
  }
  return trie[v].go[c];
}

string t;
void brute(int i, int sum) {
  if (sum == x) {
    bool ok = true;
    REP(l, 0, t.size()) {
      int cur = 0;
      REP(r, l, t.size()) {
        cur += (t[r] - '0');
        if (x % cur == 0 && cur != x) ok = false;
      }
    }
    if (ok) {
      add_string(t);
    }
    return;
  }
  REP(j, 1, min(x - sum, 9) + 1) {
    t += '0' + j;
    brute(i + 1, sum + j);
    t.pop_back();
  }
}

int main() {
  cin >> s >> x;
  brute(0, 0);
  vector<vi> dp(s.size() + 1, vi(trie.size(), inf));
  dp[0][0] = 0;
  REP(i, 0, s.size()) REP(j, 0, trie.size()) if (dp[i][j] != inf) {
    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
    int nxt = go(j, s[i]);
    if (!trie[nxt].leaf) dp[i + 1][nxt] = min(dp[i + 1][nxt], dp[i][j]);
  }
  printf("%d\n", *min_element(dp[s.size()].begin(), dp[s.size()].end()));
  return 0;
}
