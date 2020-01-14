// BEGIN CUT HERE

// END CUT HERE
#line 5 "QueenMeetup.cpp"
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

class QueenMeetup {
 public:
  vector<int> move(int d, vector<int> r, vector<int> c) {
    vi order(r.size());
    for (int i = 0; i < r.size(); i++) {
      order[i] = i;
    }
    sort(order.begin(), order.end(), [&](int a, int b) {
      if (r[a] == r[b]) return c[a] < c[b];
      return r[a] < r[b];
    });
    vector<int> ans;
    int row = 0, col = 0;
    REP(i, 0, r.size()) {
      if (i && r[order[i]] != r[order[i - 1]]) {
        row++;
        col = 0;
      }
      if (r[order[i]] != row) {
        ans.push_back(order[i]);
        ans.push_back(row);
        ans.push_back(c[order[i]]);
      }
      if (c[order[i]] != col) {
        ans.push_back(order[i]);
        ans.push_back(row);
        ans.push_back(col);
      }
      col++;
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
    int Arg0 = 5;
    int Arr1[] = {0, 1, 3};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {0, 1, 3};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {0, 2, 0, 0, 2, 2};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(0, Arg3, move(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 5;
    int Arr1[] = {0, 0, 4, 4};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {0, 4, 4, 0};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {2, 1, 1, 3, 2, 0, 1, 0, 1};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(1, Arg3, move(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 1000;
    int Arr1[] = {42};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {47};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(2, Arg3, move(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    int Arg0 = 1234567;
    int Arr1[] = {123456, 123457, 123456};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {654321, 654322, 654323};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(3, Arg3, move(Arg0, Arg1, Arg2));
  }
  void test_case_4() {
    int Arg0 = 100;
    int Arr1[] = {4, 2, 10, 5, 1, 3, 9, 17};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {0, 0, 0, 1, 0, 1, 2, 0, 2, 3, 0, 3,
                  4, 0, 4, 5, 0, 5, 6, 0, 6, 7, 0, 7};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(4, Arg3, move(Arg0, Arg1, Arg2));
  }
  void test_case_5() {
    int Arg0 = 6;
    int Arr1[] = {0, 1, 3};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {0, 1, 3};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {2, 2, 2};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(5, Arg3, move(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  QueenMeetup ___test;
  ___test.run_test(-1);
}
// END CUT HERE
