// BEGIN CUT HERE

// END CUT HERE
#line 5 "RectangleHunt.cpp"
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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

class RectangleHunt {
 public:
  vi x, y;
  int dist(int a, int b) {
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
  }
  double largest(vector<int> _x, vector<int> _y) {
    x = _x, y = _y;
    int n = x.size();
    double ans = -1;
    REP(i, 0, n) {
      REP(j, 0, n) {
        if (i == j) continue;
        REP(k, 0, n) {
          if (k == i || k == j) continue;
          if (dist(i, j) + dist(j, k) != dist(i, k)) continue;
          int tx = x[i] + x[k] - x[j], ty = y[i] + y[k] - y[j];
          REP(l, 0, n) {
            if (x[l] == tx && y[l] == ty) {
              ans =
                  max(ans, sqrt(1.0 * dist(i, j)) * sqrt(1.0 * dist(j, k)));
            }
          }
        }
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
  void verify_case(int Case, const double &Expected, const double &Received) {
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
    int Arr0[] = {0, 1, 0, 1};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {0, 2, 2, 0};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    double Arg2 = 2.0;
    verify_case(0, Arg2, largest(Arg0, Arg1));
  }
  void test_case_1() {
    int Arr0[] = {0, 1, 0, 1};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {0, 2, 2, 3};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    double Arg2 = -1.0;
    verify_case(1, Arg2, largest(Arg0, Arg1));
  }
  void test_case_2() {
    int Arr0[] = {0, 5, 6, 11};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {5, 2, 15, 12};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    double Arg2 = 68.0;
    verify_case(2, Arg2, largest(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  RectangleHunt ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
