// BEGIN CUT HERE

// END CUT HERE
#line 5 "CalkinWilf.cpp"
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

class CalkinWilf {
 public:
  vector<int> findRational(string path) {
		vector<int> ans{1, 1};
		REP(i, 0, path.length()) {
			if(path[i] == 'L') {
				ans[1] += ans[0];
			} else {
				ans[0] += ans[1];
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
    string Arg0 = "";
    int Arr1[] = {1, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(0, Arg1, findRational(Arg0));
  }
  void test_case_1() {
    string Arg0 = "R";
    int Arr1[] = {2, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(1, Arg1, findRational(Arg0));
  }
  void test_case_2() {
    string Arg0 = "LRR";
    int Arr1[] = {5, 2};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(2, Arg1, findRational(Arg0));
  }
  void test_case_3() {
    string Arg0 = "LRLRLRLRLRLRLRLRLRLRLRLRLRLRLR";
    int Arr1[] = {2178309, 1346269};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(3, Arg1, findRational(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  CalkinWilf ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
