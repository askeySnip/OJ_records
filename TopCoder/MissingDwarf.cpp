// BEGIN CUT HERE

// END CUT HERE
#line 5 "MissingDwarf.cpp"
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

class MissingDwarf {
 public:
  int getHeight(vector<int> otherHeights) {
    int v = *max_element(otherHeights.begin(), otherHeights.end());
    v++;
    int s = accumulate(otherHeights.begin(), otherHeights.end(), 0);
    for (int i = v; i < 70000; i++) {
      if ((i + s) % 7 == 0) return i;
    }
    return 0;
  }

  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
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
    int Arr0[] = {1, 2, 3, 4, 5, 6};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 7;
    verify_case(0, Arg1, getHeight(Arg0));
  }
  void test_case_1() {
    int Arr0[] = {6, 5, 4, 3, 2, 1};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 7;
    verify_case(1, Arg1, getHeight(Arg0));
  }
  void test_case_2() {
    int Arr0[] = {10, 10, 20, 20, 30, 30};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 34;
    verify_case(2, Arg1, getHeight(Arg0));
  }
  void test_case_3() {
    int Arr0[] = {7, 7, 7, 7, 7, 7};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 14;
    verify_case(3, Arg1, getHeight(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  MissingDwarf ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
