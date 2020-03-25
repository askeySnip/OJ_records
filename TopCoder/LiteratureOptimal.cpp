// BEGIN CUT HERE

// END CUT HERE
#line 5 "LiteratureOptimal.cpp"
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

class LiteratureOptimal {
 public:
  int minTurns(int N, vector<int> Teja, vector<int> history) {
    set<int> s1, s2;
    int a0[10000];
    REP(i, 0, Teja.size()) a0[Teja[i]] = 1;
    REP(i, 0, history.size()) {
      if (i % 3 == 1 && a0[history[i]] == 0) {
        s1.insert(history[i]);
      } else if (i % 3 == 2 && a0[history[i]] == 0) {
        s2.insert(history[i]);
      }
    }
    int l1 = N - s1.size();
		int l2 = N - s2.size();
		if(l1 == 0 || l2 == 0) return 0;
		int t = history.size(), x = 0;
    while (true) {
      x++;
			if(t%3 == 1) l1--;
			else if(t%3==2) l2--;
			if(l1 == 0 || l2 == 0) return x;
			t++;
    }
    return 0;
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
    int Arg0 = 2;
    int Arr1[] = {1, 4};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 5;
    verify_case(0, Arg3, minTurns(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 2;
    int Arr1[] = {1, 4};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {6, 6, 2, 3, 5, 1, 5, 6};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 0;
    verify_case(1, Arg3, minTurns(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 2;
    int Arr1[] = {3, 6};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 3, 3, 1, 3, 3, 1, 3, 6, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 4;
    verify_case(2, Arg3, minTurns(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  LiteratureOptimal ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
