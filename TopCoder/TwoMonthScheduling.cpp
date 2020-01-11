// BEGIN CUT HERE

// END CUT HERE
#line 5 "TwoMonthScheduling.cpp"
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

class TwoMonthScheduling {
 public:
  int minimumMonths(int workers, vector<int> firstMonth0,
                    vector<int> firstMonth1, vector<int> secondMonth0,
                    vector<int> secondMonth1) {
    int l0 = firstMonth0.size(), l1 = firstMonth1.size();
    vector<int> firstMonth(l0 * l1), secondMonth(l0 * l1);
    REP(i, 0, l1) {
      REP(j, 0, l0) {
        firstMonth[i * l0 + j] = min(workers, firstMonth0[j] ^ firstMonth1[i]);
        secondMonth[i * l0 + j] =
            min(workers, secondMonth0[j] ^ secondMonth1[i]);
      }
    }
    int n = firstMonth.size();
    // solution 1:
    // vector<ll> fm_ps(n + 1, 0), sm_ps(n + 1, 0);
    // REP(i, 0, n) fm_ps[i + 1] = fm_ps[i] + firstMonth[i];
    // REP(i, 0, n) sm_ps[i + 1] = sm_ps[i] + secondMonth[i];
    // vector<vi> dp(n + 1, vi(2 * n + 2, workers + 1));
    // dp[0][0] = 0;
    // REP(i, 0, n) {
    //   REP(m, 0, 2 * n + 1) {
    //     if (dp[i][m] <= workers) {
    //       // i : first unassigned job
    //       // m : first unassigned month
    //       // dp[i][m]: min. # of workers already used on month m
    //       dp[i][m + 1] = 0;
    //       REP(j, i + 1, n + 1) {
    //         if (dp[i][m] + fm_ps[j] - fm_ps[i] <= workers) {
    //           dp[j][m + 1] = min(1LL * dp[j][m + 1], sm_ps[j] - sm_ps[i]);
    //         }
    //       }
    //       if (dp[i][m] == 0) break;
    //     }
    //   }
    // }
    // int ret = 0;
    // while (dp[n][ret] > workers) ret++;
    // return ret + 1;

    // solution 2:
    vii dp(n + 1, ii(2 * n + 1, 0));
    dp[0] = ii(1, 0);
    REP(i, 0, n) {
      int months = dp[i].first;
      int a = 0, b = 0;
      REP(j, i, n) {
        a += firstMonth[j];
        b += secondMonth[j];
        if (a > workers || b > workers) break;
        if (dp[i].second + a <= workers) {
          dp[j + 1] = min(dp[j + 1], ii(months + 1, b));
        } else {
          dp[j + 1] = min(dp[j + 1], ii(months + 2, b));
        }
      }
    }
    return dp[n].first;
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
  string print_array(const vector<T>& V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
         ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const int& Expected, const int& Received) {
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
    int Arg0 = 1000;
    int Arr1[] = {900, 150, 300, 200};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {0};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {400, 300, 600, 150};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {0};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arg5 = 4;
    verify_case(0, Arg5, minimumMonths(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_1() {
    int Arg0 = 1000;
    int Arr1[] = {900, 150, 300, 200};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {0};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {400, 600, 300, 150};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {0};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arg5 = 5;
    verify_case(1, Arg5, minimumMonths(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_2() {
    int Arg0 = 1000;
    int Arr1[] = {350, 172, 24};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {998, 54};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {513, 119, 0};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {24, 118};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arg5 = 7;
    verify_case(2, Arg5, minimumMonths(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_3() {
    int Arg0 = 47;
    int Arr1[] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    int Arg5 = 2;
    verify_case(3, Arg5, minimumMonths(Arg0, Arg1, Arg2, Arg3, Arg4));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  TwoMonthScheduling ___test;
  ___test.run_test(-1);
}
// END CUT HERE
