// BEGIN CUT HERE

// END CUT HERE
#line 5 "MeanMedianCount.cpp"
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

class MeanMedianCount {
 public:
  int getCount(int N, int needMean, int needMedian) {
    int dp[55][550][55];
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 550; j++) {
        for (int k = 0; k < 55; k++) {
          for (int d = 0; d <= 10; d++) {
            if (d >= needMedian)
              dp[i + 1][j + d][k + 1] += dp[i][j][k],
                  dp[i + 1][j + d][k + 1] %= mod;
            else
              dp[i + 1][j + d][k] += dp[i][j][k], dp[i + 1][j + d][k] %= mod;
          }
        }
      }
    }
    int v = needMean * N;
    int ans = 0;
    for (int i = v; i < 550; i++) {
      for (int j = N / 2 + 1; j < 55; j++) {
        ans += dp[N][i][j];
        ans %= mod;
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
    if ((Case == -1) || (Case == 5)) test_case_5();
    if ((Case == -1) || (Case == 6)) test_case_6();
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
    int Arg0 = 3;
    int Arg1 = 9;
    int Arg2 = 10;
    int Arg3 = 10;
    verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 3;
    int Arg1 = 7;
    int Arg2 = 8;
    int Arg3 = 162;
    verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 5;
    int Arg1 = 10;
    int Arg2 = 8;
    int Arg3 = 1;
    verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    int Arg0 = 5;
    int Arg1 = 7;
    int Arg2 = 1;
    int Arg3 = 14874;
    verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2));
  }
  void test_case_4() {
    int Arg0 = 49;
    int Arg1 = 0;
    int Arg2 = 0;
    int Arg3 = 21051900;
    verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2));
  }
  void test_case_5() {
    int Arg0 = 1;
    int Arg1 = 4;
    int Arg2 = 8;
    int Arg3 = 3;
    verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2));
  }
  void test_case_6() {
    int Arg0 = 1;
    int Arg1 = 9;
    int Arg2 = 5;
    int Arg3 = 2;
    verify_case(6, Arg3, getCount(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  MeanMedianCount ___test;
  ___test.run_test(-1);
}
// END CUT HERE
