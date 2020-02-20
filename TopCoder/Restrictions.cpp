// BEGIN CUT HERE

// END CUT HERE
#line 5 "Restrictions.cpp"
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

class Restrictions {
 public:
  vector<int> exist(int n, int m, vector<int> type, vector<int> l,
                    vector<int> r, vector<int> val) {
    vi ge(n, 1);
    vi se(n, inf);
    REP(i, 0, m) {
      if (type[i] == 1) {
        REP(j, l[i], r[i] + 1) { ge[j] = max(ge[j], val[i]); }
      } else {
        REP(j, l[i], r[i] + 1) { se[j] = min(se[j], val[i]); }
      }
    }
    REP(i, 0, n) {
      if (ge[i] > se[i]) return {-1};
    }
    return ge;
  }

  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
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
  void verify_case(int Case, const vector<int> &Expected,
                   const vector<int> &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: " << print_array(Expected) << endl;
      cerr << "\tReceived: " << print_array(Received) << endl;
    }
  }
  void test_case_0() {
    int Arg0 = 6;
    int Arg1 = 5;
    int Arr2[] = {1, 1, 2, 2, 2};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {0, 1, 2, 1, 2};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {5, 3, 3, 4, 2};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {10, 18, 25, 26, 16};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arr6[] = {-1};
    vector<int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
    verify_case(0, Arg6, exist(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }
  void test_case_1() {
    int Arg0 = 2;
    int Arg1 = 3;
    int Arr2[] = {1, 2, 2};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {0, 1, 0};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {1, 1, 0};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {3, 4, 4};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arr6[] = {3, 3};
    vector<int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
    verify_case(1, Arg6, exist(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  Restrictions ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
