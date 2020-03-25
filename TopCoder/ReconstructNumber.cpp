// BEGIN CUT HERE

// END CUT HERE
#line 5 "ReconstructNumber.cpp"
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

class ReconstructNumber {
 public:
  string s;
  int dp[2020][10], nxt[2020][10];
  int solve(int pos, int dig) {
    if (pos == s.length()) return 1;
    if (dp[pos][dig] != -1) return dp[pos][dig];
    for (int i = 0; i < 10; i++) {
      if (s[pos] == '=' && dig == i) {
        if (solve(pos + 1, i)) {
          dp[pos][dig] = 1;
          nxt[pos][dig] = i;
          return 1;
        }
      }
      if (s[pos] == '>' && dig > i) {
        if (solve(pos + 1, i)) {
          dp[pos][dig] = 1;
          nxt[pos][dig] = i;
          return 1;
        }
      }
      if (s[pos] == '<' && dig < i) {
        if (solve(pos + 1, i)) {
          dp[pos][dig] = 1;
          nxt[pos][dig] = i;
          return 1;
        }
      }
      if (s[pos] == '!' && dig != i) {
        if (solve(pos + 1, i)) {
          dp[pos][dig] = 1;
          nxt[pos][dig] = i;
          return 1;
        }
      }
    }
		return dp[pos][dig] = 0;
  }
  string printans(int c) {
		string ans = "";
		for(int i=0; i<=s.length(); i++) {
			ans += char(c + '0');
			c = nxt[i][c];
		}
		return ans;
	}
  string smallest(string comparisons) {
    s = comparisons;
    memset(dp, -1, sizeof dp);
    memset(nxt, -1, sizeof nxt);
    for (int i = 1; i < 10; i++) {
      if (solve(0, i)) {
        return printans(i);
      }
    }
		return "";
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
  void verify_case(int Case, const string &Expected, const string &Received) {
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
    string Arg0 = ">=!<";
    string Arg1 = "10012";
    verify_case(0, Arg1, smallest(Arg0));
  }
  void test_case_1() {
    string Arg0 = "====!====";
    string Arg1 = "1111100000";
    verify_case(1, Arg1, smallest(Arg0));
  }
  void test_case_2() {
    string Arg0 = "";
    string Arg1 = "1";
    verify_case(2, Arg1, smallest(Arg0));
  }
  void test_case_3() {
    string Arg0 = ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    string Arg1 = "";
    verify_case(3, Arg1, smallest(Arg0));
  }
  void test_case_4() {
    string Arg0 = "><<>><=<=>=>";
    string Arg1 = "1012101122110";
    verify_case(4, Arg1, smallest(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  ReconstructNumber ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
