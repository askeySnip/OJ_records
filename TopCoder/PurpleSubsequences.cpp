// BEGIN CUT HERE

// END CUT HERE
#line 5 "PurpleSubsequences.cpp"
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

int nxt[65][25];
ll dp[65][22000];
vector<vi> V[6];
map<vi, int> id;

class PurpleSubsequences {
 public:
  long long count(vector<int> A, int L) {
    int n = A.size();
    V[0].clear();
    V[0].push_back({});
    REP(i, 0, L - 1) {
      V[i + 1].clear();
      for (auto &v : V[i]) {
        for (int j = (v.empty() ? 1 : v.back() + 1); j <= 20; j++) {
          v.push_back(j);
          V[i + 1].push_back(v);
          v.pop_back();
        }
      }
    }
    sort(V[L - 1].begin(), V[L - 1].end());
    id.clear();
    REP(i, 0, V[L - 1].size()) id[V[L - 1][i]] = i;
    REP(i, 0, 22) nxt[n + 1][i] = n + 1;
    for (int i = n; i >= 0; i--) {
      REP(j, 0, 21) nxt[i][j] = nxt[i + 1][j];
      if (i < n) nxt[i][A[i]] = i + 1;
    }
		memset(dp, 0, sizeof dp);
		int T = V[L-1].size();
		dp[0][T-1] = 1;
		ll ret = 0;
		REP(i, 0, n+1) {
			REP(j, 0, T) {
				if(dp[i][j]) {
					REP(x, 1, 21) {
						if(nxt[i][x] <= n) {
							vi cv = V[L-1][j];
							int y = lower_bound(cv.begin(), cv.end(), x) - cv.begin();
							if(y == L-1) {
								dp[nxt[i][x]][T] += dp[i][j];
							} else {
								cv[y] = x;
								dp[nxt[i][x]][id[cv]] += dp[i][j];
							}
						}
					}
				}
			}
			ret += dp[i][T];
			REP(x, 1, 21) dp[nxt[i][x]][T] += dp[i][T];
		}
		return ret;
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
    int Arr0[] = {4, 7, 4, 7};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 1;
    long long Arg2 = 11LL;
    verify_case(0, Arg2, count(Arg0, Arg1));
  }
  void test_case_1() {
    int Arr0[] = {1, 1, 2, 2, 3, 3};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 3;
    long long Arg2 = 8LL;
    verify_case(1, Arg2, count(Arg0, Arg1));
  }
  void test_case_2() {
    int Arr0[] = {1, 2, 3, 1, 2, 3};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 3;
    long long Arg2 = 17LL;
    verify_case(2, Arg2, count(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  PurpleSubsequences ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
