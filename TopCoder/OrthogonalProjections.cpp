// BEGIN CUT HERE

// END CUT HERE
#line 5 "OrthogonalProjections.cpp"
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

class OrthogonalProjections {
 public:
  vector<int> generate(int n) {
    if (n == 1) {
      return {0, 0};
    } else if (n == 2) {
      return {0, 0, 1, 1};
    } else if (n == 4 || n % 2 == 1) {
      return {};
    } else {
      n /= 2;
      vi ans;
      int t = 1;
      while ((t + 1) * (t + 1) < n) {
        t++;
      }
      for (int i = 0; i < t; i++) {
        ans.insert(end(ans), {0, i});
      }
      int cur = 0;
      ans.insert(end(ans), {1, 0});
      n -= 1 + t;
      while (n) {
        int step = min(n, t);
        cur += step;
        n -= step;
        ans.insert(end(ans), {1, cur});
      }
      return ans;
    }
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
    int Arg0 = 6;
    int Arr1[] = {0, 0, 0, 1, 1, 2};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(0, Arg1, generate(Arg0));
  }
  void test_case_1() {
    int Arg0 = 47;
    int Arr1[] = {};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(1, Arg1, generate(Arg0));
  }
  void test_case_2() {
    int Arg0 = 8;
    int Arr1[] = {0, 0, 0, 2, 7, 1, 14, 0, 14, 2};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(2, Arg1, generate(Arg0));
  }
  void test_case_3() {
    int Arg0 = 100;
    int Arr1[] = {70, 30, 16, 85, 51, 41, 29, 72, 47, 6,  15,
                  45, 71, 30, 45, 18, 22, 58, 79, 45, 58, 17};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(3, Arg1, generate(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  OrthogonalProjections ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
