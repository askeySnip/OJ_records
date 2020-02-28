// BEGIN CUT HERE

// END CUT HERE
#line 5 "OneHandRoadPainting.cpp"
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

class OneHandRoadPainting {
 public:
  long long fastest(vector<int> dStart, vector<int> dEnd, int paintPerBrush) {
    ll ans = 0;
    int n = dStart.size();
    int i = n - 1;
    while (i >= 0) {
      ll fullrun = (dEnd[i] - dStart[i]) / paintPerBrush;
      if (fullrun > 0) {
        ans += (2LL * dEnd[i] - (fullrun - 1) * paintPerBrush) * fullrun;
        dEnd[i] -= fullrun * paintPerBrush;
      }
      if (dStart[i] == dEnd[i]) {
        --i;
        continue;
      }
      ans += 2LL * dEnd[i];
      ll paintRemaining = paintPerBrush;
      while (true) {
        ll paintNeeded = dEnd[i] - dStart[i];
        if (paintNeeded <= paintRemaining) {
          paintRemaining -= paintNeeded;
          --i;
          if (i == -1) break;
        } else {
          dEnd[i] -= paintRemaining;
          break;
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
  void verify_case(int Case, const long long &Expected,
                   const long long &Received) {
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
    int Arr0[] = {3, 7};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {4, 9};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 1;
    long long Arg3 = 42LL;
    verify_case(0, Arg3, fastest(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arr0[] = {3, 7};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {4, 9};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 5;
    long long Arg3 = 18LL;
    verify_case(1, Arg3, fastest(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arr0[] = {1, 10, 20};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {4, 13, 22};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 2;
    long long Arg3 = 98LL;
    verify_case(2, Arg3, fastest(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  OneHandRoadPainting ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
