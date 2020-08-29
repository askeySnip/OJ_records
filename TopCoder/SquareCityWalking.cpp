// BEGIN CUT HERE

// END CUT HERE
#line 5 "SquareCityWalking.cpp"
#include <bits/stdc++.h>
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

class SquareCityWalking {
 public:
  int largestGCD(int N, vector<int> A) {
    vector<int> f(A.size(), 0);
    for (int v = 100; v > 0; v--) {
      fill(f.begin(), f.end(), 0);
      if (A[0] % v) continue;
      f[0] = 1;
      REP(i, 1, N) f[i] = f[i - 1] && (A[i] % v == 0);
      REP(i, 1, N) f[i * N] = f[(i - 1) * N] && (A[i * N] % v == 0);
      REP(i, 1, N) {
        REP(j, 1, N) {
          f[i * N + j] = (f[(i - 1) * N + j] || f[i * N + j - 1]) &&
                         (A[i * N + j] % v == 0);
        }
      }
      // REP(i, 0, N) {
      //   REP(j, 0, N) { cout << f[i * N + j] << " "; }
      //   cout << endl;
      // }
      if (f.back()) return v;
    }
    return 1;
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
    int Arr1[] = {6, 2, 1, 1, 3, 6, 4, 1, 1, 4, 6, 3, 1, 1, 2, 6};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 2;
    verify_case(0, Arg2, largestGCD(Arg0, Arg1));
  }
  void test_case_1() {
    int Arg0 = 3;
    int Arr1[] = {4, 9, 2, 3, 5, 7, 8, 1, 6};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 1;
    verify_case(1, Arg2, largestGCD(Arg0, Arg1));
  }
  void test_case_2() {
    int Arg0 = 4;
    int Arr1[] = {54, 81, 27, 36, 48, 64, 96, 72,
                  84, 60, 45, 99, 80, 90, 40, 63};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 9;
    verify_case(2, Arg2, largestGCD(Arg0, Arg1));
  }
  void test_case_3() {
    int Arg0 = 1;
    int Arr1[] = {47};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 47;
    verify_case(3, Arg2, largestGCD(Arg0, Arg1));
  }
  void test_case_4() {
    int Arg0 = 5;
    int Arr1[] = {100, 80, 64, 48, 36, 75, 10, 10, 10, 48, 50, 10, 10,
                  10,  64, 25, 10, 10, 10, 80, 5,  25, 50, 75, 100};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 10;
    verify_case(4, Arg2, largestGCD(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  SquareCityWalking ___test;
  ___test.run_test(-1);
}
// END CUT HERE
