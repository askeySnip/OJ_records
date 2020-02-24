// BEGIN CUT HERE

// END CUT HERE
#line 5 "WildSequence.cpp"
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

class WildSequence {
 public:
  vector<int> construct(int head, vector<int> rest) {
    if (rest.empty()) return {head};
    sort(rest.begin(), rest.end());
    vi ans;
    ans.push_back(head);
    int f = 0, e = rest.size() - 1;
    if (head > rest[0]) {
      while (f <= e) {
        ans.push_back(rest[f++]);
        if (f > e) break;
        ans.push_back(rest[e--]);
      }
    } else {
      while (f <= e) {
        ans.push_back(rest[e--]);
        if (f > e) break;
        ans.push_back(rest[f++]);
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
    int Arg0 = 20;
    int Arr1[] = {10, 30};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {20, 10, 30};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(0, Arg2, construct(Arg0, Arg1));
  }
  void test_case_1() {
    int Arg0 = 20;
    int Arr1[] = {10, 30, 40};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {20, 10, 40, 30};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(1, Arg2, construct(Arg0, Arg1));
  }
  void test_case_2() {
    int Arg0 = 4;
    int Arr1[] = {1, 2, 3, 6, 7, 5};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {4, 7, 5, 6, 1, 3, 2};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    verify_case(2, Arg2, construct(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  WildSequence ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
