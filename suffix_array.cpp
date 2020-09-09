/*
ID: leezhen
TASK: practice
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

#define MAX_N 100010

char T[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int RA[MAX_N], tempRA[MAX_N];
int n;
int c[MAX_N];

void countSorting(int k) {
  int i, sum, maxi = max(300, n);
  memset(c, 0, sizeof c);
  for (i = 0; i < n; i++) {
    c[i + k < n ? RA[i + k] : 0]++;
  }
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i];
    c[i] = sum;
    sum += t;
  }
  for (i = 0; i < n; i++) {
    tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
  }
  for (i = 0; i < n; i++) {
    SA[i] = tempSA[i];
  }
}

void constructSA() {
  int i, k, r;
  for (i = 0; i < n; i++) SA[i] = i;
  for (i = 0; i < n; i++) RA[i] = T[i];
  for (k = 1; k < n; k <<= 1) {
    countSorting(k);
    countSorting(0);
    tempRA[SA[0]] = r = 0;
    for (i = 1; i < n; i++) {
      tempRA[SA[i]] =
          (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k])
              ? r
              : ++r;
    }
    for (i = 0; i < n; i++) {
      RA[i] = tempRA[i];
    }
    if (RA[n - 1] == n - 1) break;  // optimization trick
  }
}

int main() {
  scanf("%s", T);
  n = (int)strlen(T);
  T[n++] = '$';
  constructSA();
  for (int i = 0; i < n; i++) {
    printf("%2d\t%s\n", SA[i], T + SA[i]);
  }
}
