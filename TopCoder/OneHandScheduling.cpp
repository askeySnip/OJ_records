// BEGIN CUT HERE

// END CUT HERE
#line 5 "OneHandScheduling.cpp"
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

class OneHandScheduling {
 public:
  string checkSchedule(vector<int> tStart, vector<int> tEnd) {
    int n = tStart.size();
    REP(i, 0, n) {
      REP(j, 0, n) {
        if (i == j) continue;
        if ((tStart[i] >= tStart[j] && tStart[i] <= tEnd[j]) ||
            (tEnd[i] >= tStart[j] && tEnd[i] <= tEnd[j]))
          return "impossible";
      }
    }
    return "possible";
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
  void verify_case(int Case, const string &Expected, const string &Received) {
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
    int Arr0[] = {10, 100, 236};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {47, 235, 347};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arg2 = "possible";
    verify_case(0, Arg2, checkSchedule(Arg0, Arg1));
  }
  void test_case_1() {
    int Arr0[] = {100, 236, 10};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {235, 347, 47};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arg2 = "possible";
    verify_case(1, Arg2, checkSchedule(Arg0, Arg1));
  }
  void test_case_2() {
    int Arr0[] = {10, 20};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {20, 30};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arg2 = "impossible";
    verify_case(2, Arg2, checkSchedule(Arg0, Arg1));
  }
  void test_case_3() {
    int Arr0[] = {10, 400000, 500000};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {20, 600000, 700000};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arg2 = "impossible";
    verify_case(3, Arg2, checkSchedule(Arg0, Arg1));
  }
  void test_case_4() {
    int Arr0[] = {1, 40, 50, 60};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {1000000, 41, 51, 61};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arg2 = "impossible";
    verify_case(4, Arg2, checkSchedule(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  OneHandScheduling ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
