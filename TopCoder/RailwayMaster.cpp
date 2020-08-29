// BEGIN CUT HERE

// END CUT HERE
#line 5 "RailwayMaster.cpp"
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
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

class RailwayMaster {
 public:
  class UnionFind {
   private:
    vi p, rank;

   public:
    UnionFind(int n) {
      p.assign(n, 0);
      rank.assign(n, 0);
      REP(i, 0, n) p[i] = i;
    }
    int findSet(int i) { return i == p[i] ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
      if (!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) {
          p[y] = x;
        } else {
          p[x] = y;
          if (rank[x] == rank[y]) rank[y]++;
        }
      }
    }
  };
  int maxProfit(int N, int M, int K, vector<int> a, vector<int> b,
                vector<int> v) {
    UnionFind uf(N);
    vector<int> ids(M);
    REP(i, 0, M) ids[i] = i;
    sort(ids.begin(), ids.end(), [&](int a, int b) { return v[a] < v[b]; });
    vi path;
    REP(i, 0, M) {
      if (uf.isSameSet(a[ids[i]], b[ids[i]])) {
        path.push_back(ids[i]);
        continue;
      }
      uf.unionSet(a[ids[i]], b[ids[i]]);
    }
    K = min(K, (int)path.size());
    int ans = 0;
    while (K--) {
      ans += v[path.back()];
      path.pop_back();
    }
    return ans;
  }

  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
  }

 private:
  template <typename T>
  string print_array(const vector<T> &V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
         ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const int &Expected, const int &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: \"" << Expected << '\"' << endl;
      cerr << "\tReceived: \"" << Received << '\"' << endl;
    }
  }
  void test_case_0() {
    int Arg0 = 3;
    int Arg1 = 3;
    int Arg2 = 3;
    int Arr3[] = {0, 1, 2};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {1, 2, 0};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {224, 258, 239};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arg6 = 258;
    verify_case(0, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_1() {
    int Arg0 = 4;
    int Arg1 = 6;
    int Arg2 = 2;
    int Arr3[] = {0, 0, 0, 1, 1, 2};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {1, 2, 3, 2, 3, 3};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {500, 900, 600, 700, 800, 100};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arg6 = 1700;
    verify_case(1, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_2() {
    int Arg0 = 5;
    int Arg1 = 7;
    int Arg2 = 1;
    int Arr3[] = {0, 1, 2, 3, 3, 0, 1};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {1, 2, 3, 4, 0, 2, 3};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {100, 100, 100, 900, 100, 100, 100};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arg6 = 100;
    verify_case(2, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_3() {
    int Arg0 = 5;
    int Arg1 = 7;
    int Arg2 = 3;
    int Arr3[] = {0, 0, 0, 0, 1, 2, 3};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {1, 1, 1, 1, 2, 3, 4};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {926, 815, 777, 946, 928, 634, 999};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arg6 = 2687;
    verify_case(3, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_4() {
    int Arg0 = 5;
    int Arg1 = 7;
    int Arg2 = 6;
    int Arr3[] = {0, 1, 2, 3, 4, 1, 3};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {1, 2, 3, 4, 0, 4, 0};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {118, 124, 356, 480, 625, 767, 911};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arg6 = 2303;
    verify_case(4, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_5() {
    int Arg0 = 10;
    int Arg1 = 15;
    int Arg2 = 3;
    int Arr3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {1, 2, 3, 4, 0, 6, 7, 8, 9, 5, 5, 6, 7, 8, 9};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {220284, 869120, 787788, 980412, 133333,
                  314159, 256312, 192916, 298575, 931110,
                  175353, 926778, 201513, 202729, 155136};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arg6 = 2838300;
    verify_case(5, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  RailwayMaster ___test;
  ___test.run_test(-1);
}
// END CUT HERE
