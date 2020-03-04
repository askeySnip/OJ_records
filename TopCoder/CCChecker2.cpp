// BEGIN CUT HERE

// END CUT HERE
#line 5 "CCChecker2.cpp"
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

class CCChecker2 {
 public:
  string check(int n, vector<int> startRow, vector<int> startCol,
               vector<int> destRow, vector<int> destCol,
               vector<int> moveStartRow, vector<int> moveStartCol,
               vector<int> moveDestRow, vector<int> moveDestCol) {
    map<ii, int> mp;
    REP(i, 1, n + 1) REP(j, 1, n + 1) mp[ii(i, j)] = -1;
    REP(i, 0, startRow.size()) { mp[ii(startRow[i], startCol[i])] = i; }
    REP(i, 0, moveStartRow.size()) {
      int msr = moveStartRow[i], msc = moveStartCol[i];
      int mdr = moveDestRow[i], mdc = moveDestCol[i];
      if (msr < 1 || msr > n || msc < 1 || msr > n || mdr < 1 || mdr > n ||
          mdc < 1 || mdr > n)
        return "invalid";
      if (mp[ii(moveStartRow[i], moveStartCol[i])] == -1 ||
          mp[ii(moveDestRow[i], moveDestCol[i])] != -1)
        return "invalid";
      if (abs(msr - mdr) + abs(msc - mdc) != 1) return "invalid";
      swap(mp[ii(moveStartRow[i], moveStartCol[i])],
           mp[ii(moveDestRow[i], moveDestCol[i])]);
    }
    REP(i, 0, startRow.size()) {
      if (mp[ii(destRow[i], destCol[i])] != i) return "invalid";
    }
    return "valid";
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
    if ((Case == -1) || (Case == 6)) test_case_6();
    if ((Case == -1) || (Case == 7)) test_case_7();
    if ((Case == -1) || (Case == 8)) test_case_8();
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
    int Arg0 = 2;
    int Arr1[] = {1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {2};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {2};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {1, 1};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arr6[] = {1, 2};
    vector<int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
    int Arr7[] = {1, 2};
    vector<int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
    int Arr8[] = {2, 2};
    vector<int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
    string Arg9 = "valid";
    verify_case(0, Arg9,
                check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
  }
  void test_case_1() {
    int Arg0 = 2;
    int Arr1[] = {1, 2};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 2};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1, 2};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {2, 1};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {2, 1, 2, 1, 2, 1, 2, 2};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arr6[] = {2, 1, 1, 2, 2, 1, 1, 2};
    vector<int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
    int Arr7[] = {1, 2, 2, 1, 1, 2, 2, 2};
    vector<int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
    int Arr8[] = {2, 1, 2, 1, 2, 1, 2, 1};
    vector<int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
    string Arg9 = "valid";
    verify_case(1, Arg9,
                check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
  }
  void test_case_2() {
    int Arg0 = 6;
    int Arr1[] = {};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arr6[] = {};
    vector<int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
    int Arr7[] = {};
    vector<int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
    int Arr8[] = {};
    vector<int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
    string Arg9 = "valid";
    verify_case(2, Arg9,
                check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
  }
  void test_case_3() {
    int Arg0 = 3;
    int Arr1[] = {1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {1};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {-47};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arr6[] = {-42};
    vector<int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
    int Arr7[] = {125216547};
    vector<int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
    int Arr8[] = {125216547};
    vector<int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
    string Arg9 = "invalid";
    verify_case(3, Arg9,
                check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
  }
  void test_case_4() {
    int Arg0 = 3;
    int Arr1[] = {1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {3};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {1};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arr6[] = {1};
    vector<int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
    int Arr7[] = {1};
    vector<int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
    int Arr8[] = {3};
    vector<int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
    string Arg9 = "invalid";
    verify_case(4, Arg9,
                check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
  }
  void test_case_5() {
    int Arg0 = 6;
    int Arr1[] = {1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {2};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {2};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {1};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arr6[] = {1};
    vector<int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
    int Arr7[] = {2};
    vector<int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
    int Arr8[] = {2};
    vector<int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
    string Arg9 = "invalid";
    verify_case(5, Arg9,
                check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
  }
  void test_case_6() {
    int Arg0 = 3;
    int Arr1[] = {1, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 2};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1, 1};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {3, 2};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {1, 1};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arr6[] = {1, 2};
    vector<int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
    int Arr7[] = {1, 1};
    vector<int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
    int Arr8[] = {2, 3};
    vector<int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
    string Arg9 = "invalid";
    verify_case(6, Arg9,
                check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
  }
  void test_case_7() {
    int Arg0 = 3;
    int Arr1[] = {1, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 2};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1, 1};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {3, 2};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {1, 1};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arr6[] = {2, 1};
    vector<int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
    int Arr7[] = {1, 1};
    vector<int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
    int Arr8[] = {3, 2};
    vector<int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
    string Arg9 = "invalid";
    verify_case(7, Arg9,
                check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
  }
  void test_case_8() {
    int Arg0 = 3;
    int Arr1[] = {1, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 2};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1, 1};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {3, 2};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arr5[] = {1, 1, 1, 2};
    vector<int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    int Arr6[] = {2, 1, 2, 2};
    vector<int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
    int Arr7[] = {2, 1, 1, 1};
    vector<int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
    int Arr8[] = {2, 2, 3, 2};
    vector<int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
    string Arg9 = "valid";
    verify_case(8, Arg9,
                check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  CCChecker2 ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
