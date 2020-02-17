// BEGIN CUT HERE

// END CUT HERE
#line 5 "FixedPointReversals.cpp"
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

class FixedPointReversals {
 public:
  vector<int> sort(vector<int> A, int fixed) {
    int n = A.size();
    vi tmp = A;
    std::sort(tmp.begin(), tmp.end());
    if (tmp[fixed] != A[fixed]) return {-1};
    vi ans;
    if (fixed >= n - fixed - 1) {
      for (int i = n - 1; i > fixed; i--) {
        if (tmp[i] != A[i]) {
          int j = i - 1;
          while (A[j] != tmp[i] || j == fixed) j--;
          if (j > fixed) {
            ans.push_back(j);
            ans.push_back(i + 1);
            reverse(A.begin() + j, A.begin() + i + 1);
          } else {
            if (j + i != 2 * fixed) {
              int p = 2 * fixed - i;
              ans.push_back(min(j, p));
              ans.push_back(max(j, p) + 1);
              reverse(A.begin() + min(j, p), A.begin() + max(j, p) + 1);
            }
            ans.push_back(2 * fixed - i);
            ans.push_back(i + 1);
            reverse(A.begin() + 2 * fixed - i, A.begin() + i + 1);
          }
        }
      }
      for (int i = fixed - 1; i >= 0; i--) {
        if (tmp[i] != A[i]) {
          int j = i - 1;
          while (A[j] != tmp[i]) j--;
          ans.push_back(j);
          ans.push_back(i + 1);
          reverse(A.begin() + j, A.begin() + i + 1);
        }
      }
    } else {
      for (int i = 0; i < fixed; i++) {
        if (tmp[i] != A[i]) {
          int j = i + 1;
          while (A[j] != tmp[i] || j == fixed) j++;
          if (j < fixed) {
            ans.push_back(i);
            ans.push_back(j + 1);
            reverse(A.begin() + i, A.begin() + j + 1);
          } else {
            if (j + i != 2 * fixed) {
              int p = 2 * fixed - i;
              ans.push_back(min(p, j));
              ans.push_back(max(p, j) + 1);
              reverse(A.begin() + min(p, j), A.begin() + max(p, j) + 1);
            }
            ans.push_back(i);
            ans.push_back(2 * fixed - i + 1);
            reverse(A.begin() + i, A.begin() + 2 * fixed - i + 1);
          }
        }
      }
      for (int i = fixed + 1; i < n; i++) {
        if (tmp[i] != A[i]) {
          int j = i + 1;
          while (A[j] != tmp[i]) j++;
          ans.push_back(i);
          ans.push_back(j + 1);
          reverse(A.begin() + i, A.begin() + j + 1);
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
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
  }

 private:
  template <typename T>
  string print_array(const vector<T>& V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
         ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const vector<int>& Expected,
                   const vector<int>& Received) {
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
    int Arr0[] = {10, 20, 30, 40, 50};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 2;
    int Arr2[] = {};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(0, Arg2, sort(Arg0, Arg1));
  }
  void test_case_1() {
    int Arr0[] = {10, 20, 40, 30, 50};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 2;
    int Arr2[] = {-1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(1, Arg2, sort(Arg0, Arg1));
  }
  void test_case_2() {
    int Arr0[] = {20, 10, 10, 10, 10, 10};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 4;
    int Arr2[] = {0, 6};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(2, Arg2, sort(Arg0, Arg1));
  }
  void test_case_3() {
    int Arr0[] = {1, 50, 40, 30, 20, 10};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 0;
    int Arr2[] = {1, 6};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(3, Arg2, sort(Arg0, Arg1));
  }
  void test_case_4() {
    int Arr0[] = {20, 10, 30, 50, 40};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 2;
    int Arr2[] = {0, 2, 3, 5};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(4, Arg2, sort(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  FixedPointReversals ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
