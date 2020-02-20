// BEGIN CUT HERE

// END CUT HERE
#line 5 "LexicographicPartition.cpp"
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

// for i = 0 .. len(Aprefix)-1:
//     A[i] = Aprefix[i]

// state = seed
// for i = len(Aprefix) .. n-1:
//     state = (1103515245 * state + 12345)
//     A[i] = state modulo (2*Arange+1)
//     A[i] = A[i] - Arange
//     state = state modulo 2^31
class LexicographicPartition {
 public:
  vi A;
  vector<int> positiveSum(int n, vector<int> Aprefix, int seed, int Arange) {
    A = Aprefix;
    ll state = seed;
    REP(i, A.size(), n) {
      state = (1103515245 * state + 12345);
      int a = state % (2 * Arange + 1);
      a = a - Arange;
      A.push_back(a);
      state = state % (1 << 31);
    }
    ll s = 0;
    REP(i, 0, n) s += A[i];
    if (s <= 0) return {-1};
    ll cur = 0;
    int l = 0;
    vi ans(1, 0);
    REP(i, 0, n) {
      s -= A[i];
      cur += A[i];
      l++;
      if (cur > 0 && s > 0) {
        ans[0]++;
        ans.push_back(l);
        cur = 0;
        l = 0;
      }
    }
    if (l > 0) ans[0]++, ans.push_back(l);
    if (ans.size() > 201) ans.resize(201);
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
    int Arg0 = 3;
    int Arr1[] = {3, -7, 8};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 1;
    int Arg3 = 1;
    int Arr4[] = {2, 1, 2};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    verify_case(0, Arg4, positiveSum(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_1() {
    int Arg0 = 5;
    int Arr1[] = {0, 1, 0, 1, 2};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 42;
    int Arg3 = 47;
    int Arr4[] = {3, 2, 2, 1};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    verify_case(1, Arg4, positiveSum(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_2() {
    int Arg0 = 5;
    int Arr1[] = {-1, 2, -3, 4, -5};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 777;
    int Arg3 = 4747;
    int Arr4[] = {-1};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    verify_case(2, Arg4, positiveSum(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_3() {
    int Arg0 = 1;
    int Arr1[] = {0};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 12;
    int Arg3 = 34;
    int Arr4[] = {-1};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    verify_case(3, Arg4, positiveSum(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_4() {
    int Arg0 = 10;
    int Arr1[] = {4, -7, 4, -7};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 123456789;
    int Arg3 = 5447;
    int Arr4[] = {6, 1, 5, 1, 1, 1, 1};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    verify_case(4, Arg4, positiveSum(Arg0, Arg1, Arg2, Arg3));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  LexicographicPartition ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
