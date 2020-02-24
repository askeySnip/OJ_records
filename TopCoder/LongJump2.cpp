// BEGIN CUT HERE

// END CUT HERE
#line 5 "LongJump2.cpp"
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

class LongJump2 {
 public:
  int countNewLeaders(int N, vector<int> jumpLengths) {
    int leader = 0;
    int ans = 1;
    REP(i, 0, 3 * N) {
      if (jumpLengths[i] > jumpLengths[leader]) {
        if (i % N != leader % N) ans++;
        leader = i;
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
    int Arg0 = 1;
    int Arr1[] = {812, 780, 815};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 1;
    verify_case(0, Arg2, countNewLeaders(Arg0, Arg1));
  }
  void test_case_1() {
    int Arg0 = 2;
    int Arr1[] = {0, 0, 0, 0, 0, 0};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 1;
    verify_case(1, Arg2, countNewLeaders(Arg0, Arg1));
  }
  void test_case_2() {
    int Arg0 = 2;
    int Arr1[] = {810, 811, 812, 813, 814, 815};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 6;
    verify_case(2, Arg2, countNewLeaders(Arg0, Arg1));
  }
  void test_case_3() {
    int Arg0 = 3;
    int Arr1[] = {800, 10, 20, 810, 30, 40, 50, 830, 830};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 2;
    verify_case(3, Arg2, countNewLeaders(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  LongJump2 ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
