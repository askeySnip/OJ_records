// BEGIN CUT HERE

// END CUT HERE
#line 5 "SteelMill.cpp"
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

class SteelMill {
 public:
  long long cheapest(int goal, vector<int> shipmentCost,
                     vector<int> shipmentSize, vector<int> costPerKg) {
    vector<ll> dp(goal + 1, (1L << 62));
    dp[0] = 0;
    vi order(shipmentCost.size());
    for (int i = 0; i < shipmentCost.size(); i++) order[i] = i;
    sort(order.begin(), order.end(),
         [&](int a, int b) { return costPerKg[a] > costPerKg[b]; });
    REP(i, 0, order.size()) {
      int v = order[i];
      for (int j = goal; j >= 1; j--) {
        ll take = min(j, shipmentSize[v]);
        ll pay = costPerKg[v] * take + shipmentCost[v];
        dp[j] = min(dp[j], dp[j - take] + pay);
      }
    }
    return dp[goal];
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
  void verify_case(int Case, const long long &Expected,
                   const long long &Received) {
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
    int Arg0 = 30;
    int Arr1[] = {100, 200, 300};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {10, 10, 10};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1, 2, 3};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    long long Arg4 = 660LL;
    verify_case(0, Arg4, cheapest(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_1() {
    int Arg0 = 20;
    int Arr1[] = {1234567, 50, 50};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {20, 11, 13};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1, 12345, 23456};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    long long Arg4 = 346999LL;
    verify_case(1, Arg4, cheapest(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_2() {
    int Arg0 = 20;
    int Arr1[] = {1234567, 50, 50};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {20, 11, 13};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1, 123456789, 234567890};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    long long Arg4 = 1234587LL;
    verify_case(2, Arg4, cheapest(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_3() {
    int Arg0 = 1000000;
    int Arr1[] = {1000000000};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1000000};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1000000000};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    long long Arg4 = 1000001000000000LL;
    verify_case(3, Arg4, cheapest(Arg0, Arg1, Arg2, Arg3));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  SteelMill ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
