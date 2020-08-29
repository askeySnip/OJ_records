// BEGIN CUT HERE

// END CUT HERE
#line 5 "StarsInTheSky.cpp"
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

class StarsInTheSky {
 public:
  int countPictures(int N, vector<int> X, vector<int> Y) {
    int ans = 0;
    REP(i, 1, (1 << N)) {
      int minx = inf, maxx = -1, miny = inf, maxy = -1;
      REP(j, 0, N) {
        if (bit(i, j)) {
          minx = min(minx, X[j]);
          maxx = max(maxx, X[j]);
          miny = min(miny, Y[j]);
          maxy = max(maxy, Y[j]);
        }
      }
      int k = 0;
      REP(j, 0, N) {
        if (LINR(X[j], minx, maxx) && LINR(Y[j], miny, maxy)) {
          k += (1 << j);
        }
      }
      if (k == i) {
        ans++;
      }
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
    int Arg0 = 4;
    int Arr1[] = {1, 2, 3, 4};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 1, 1, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 10;
    verify_case(0, Arg3, countPictures(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 4;
    int Arr1[] = {100, 200, 200, 100};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {100, 100, 200, 200};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 9;
    verify_case(1, Arg3, countPictures(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 3;
    int Arr1[] = {10000, 11000, 12000};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {52000, 50000, 51000};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 7;
    verify_case(2, Arg3, countPictures(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    int Arg0 = 7;
    int Arr1[] = {0, 6, 2, 3, 4, 0, 6};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {0, 0, 4, 5, 6, 10, 10};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 45;
    verify_case(3, Arg3, countPictures(Arg0, Arg1, Arg2));
  }
  void test_case_4() {
    int Arg0 = 15;
    int Arr1[] = {3,         141592653, 589793238, 462643383, 279502884,
                  197169399, 375105820, 974944592, 307816406, 286208998,
                  628034825, 342117067, 982148086, 513282306, 647093844};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1,         414213562, 373095048, 801688724, 209698078,
                  569671875, 376948073, 176679737, 990732478, 462107038,
                  850387534, 327641572, 735013846, 230912297, 24924836};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 613;
    verify_case(4, Arg3, countPictures(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  StarsInTheSky ___test;
  ___test.run_test(-1);
}
// END CUT HERE
