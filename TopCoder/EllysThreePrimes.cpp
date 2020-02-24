// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysThreePrimes.cpp"
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

class EllysThreePrimes {
 public:
  vi primes;
  bitset<100000> bs;
  void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < 100000; i++) {
      if (bs[i]) {
        if (i >= 10000) primes.push_back(i);
        for (ll j = 1LL * i * i; j < 100000; j += i) bs[j] = 0;
      }
    }
  }
  vector<int> getPrimes(vector<int> sums) {
    primes.clear();
    sieve();
    cout << primes.size();
    REP(i, 0, primes.size()) {
      REP(j, i + 1, primes.size()) {
        int a0 =
            sums[4] - primes[i] % 100000 / 10000 - primes[j] % 100000 / 10000;
        if (a0 <= 0 || a0 > 9) continue;
        int a1 = sums[3] - primes[i] % 10000 / 1000 - primes[j] % 10000 / 1000;
        if (a1 < 0 || a1 > 9) continue;
        int a2 = sums[2] - primes[i] % 1000 / 100 - primes[j] % 1000 / 100;
        if (a2 < 0 || a2 > 9) continue;
        int a3 = sums[1] - primes[i] % 100 / 10 - primes[j] % 100 / 10;
        if (a3 < 0 || a3 > 9) continue;
        int a4 = sums[0] - primes[i] % 10 - primes[j] % 10;
        if (a4 < 0 || a4 > 9) continue;
        int num = a0 * 10000 + a1 * 1000 + a2 * 100 + a3 * 10 + a4;
        if (bs[num] && num != primes[i] && num != primes[j])
          return {num, primes[i], primes[j]};
      }
    }
    return {};
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
    int Arr0[] = {19, 12, 15, 11, 14};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {20533, 87119, 44987};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(0, Arg1, getPrimes(Arg0));
  }
  void test_case_1() {
    int Arr0[] = {22, 19, 3, 8, 23};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(1, Arg1, getPrimes(Arg0));
  }
  void test_case_2() {
    int Arr0[] = {13, 17, 0, 25, 20};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {27011, 99083, 99089};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(2, Arg1, getPrimes(Arg0));
  }
  void test_case_3() {
    int Arr0[] = {11, 12, 13, 14, 15};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {47221, 23789, 94421};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(3, Arg1, getPrimes(Arg0));
  }
  void test_case_4() {
    int Arr0[] = {14, 27, 6, 12, 15};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(4, Arg1, getPrimes(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  EllysThreePrimes ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
