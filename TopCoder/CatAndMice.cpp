// BEGIN CUT HERE

// END CUT HERE
#line 5 "CatAndMice.cpp"
#include <algorithm>
#include <bitset>
#include <cassert>
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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

class CatAndMice {
 public:
  long long countDirections(int N, int C) {
    vi phi(N + 1, 0);
    phi[1] = 1;
    REP(i, 2, N + 1) {
      if (!phi[i]) {
        for (int j = i; j < N + 1; j += i) {
          if (!phi[j]) phi[j] = j;
          phi[j] = phi[j] / i * (i - 1);
        }
      }
    }
    if (C == N) return 8;
    ll ans = 0;
    REP(i, 2, N + 1) {
      if (1LL * i * C <= 1LL * N && 1LL * i * (C + 1) > 1LL * N)
        ans += phi[i] * 8;
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
  void verify_case(int Case, const long long& Expected,
                   const long long& Received) {
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
    int Arg1 = 2;
    long long Arg2 = 8LL;
    verify_case(0, Arg2, countDirections(Arg0, Arg1));
  }
  void test_case_1() {
    int Arg0 = 2;
    int Arg1 = 1;
    long long Arg2 = 8LL;
    verify_case(1, Arg2, countDirections(Arg0, Arg1));
  }
  void test_case_2() {
    int Arg0 = 19;
    int Arg1 = 3;
    long long Arg2 = 48LL;
    verify_case(2, Arg2, countDirections(Arg0, Arg1));
  }
  void test_case_3() {
    int Arg0 = 1234;
    int Arg1 = 3;
    long long Arg2 = 180608LL;
    verify_case(3, Arg2, countDirections(Arg0, Arg1));
  }
  void test_case_4() {
    int Arg0 = 1234;
    int Arg1 = 1212;
    long long Arg2 = 0LL;
    verify_case(4, Arg2, countDirections(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  CatAndMice ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
