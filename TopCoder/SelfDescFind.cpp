// BEGIN CUT HERE

// END CUT HERE
#line 5 "SelfDescFind.cpp"
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

class SelfDescFind {
 public:
  vector<vi> part;
  void gen(int sum, int len, vi &cur) {
    if (len == 0 && sum == 0) {
      part.push_back(cur);
      return;
    }
    if (sum < 0 || len == 0) return;
    for (int i = 1; i < 10; i++) {
      if (sum < len + i - 1) break;
      cur.push_back(i);
      gen(sum - i, len - 1, cur);
      cur.pop_back();
    }
  }
  string construct(vector<int> digits) {
    part.clear();
    vi cur;
    int n = digits.size();
    gen(2 * n, n, cur);
    string ans = "99999999999999999999";
    for (auto &v : part) {
      int cnt[10]{0};
      for (auto d : v) cnt[d]++;
      for (auto d : digits) cnt[d]++;
      bool f = true;
      REP(i, 0, n) {
        if (cnt[digits[i]] != v[i]) {
          f = false;
          break;
        }
      }
      if (f) {
        vii p(n);
        REP(i, 0, n) p[i] = ii(v[i], digits[i]);
        sort(p.begin(), p.end());
        string t;
        REP(i, 0, n) t = t + to_string(p[i].first) + to_string(p[i].second);
        ans = min(ans, t);
      }
    }
    if (ans == "99999999999999999999") ans = "";
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
    int Arr0[] = {1};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "";
    verify_case(0, Arg1, construct(Arg0));
  }
  void test_case_1() {
    int Arr0[] = {2};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "22";
    verify_case(1, Arg1, construct(Arg0));
  }
  void test_case_2() {
    int Arr0[] = {0, 1, 3, 4};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "10143133";
    verify_case(2, Arg1, construct(Arg0));
  }
  void test_case_3() {
    int Arr0[] = {0, 1, 2, 4, 5, 6, 8, 9};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "";
    verify_case(3, Arg1, construct(Arg0));
  }
  void test_case_4() {
    int Arr0[] = {0, 1, 2, 3, 5, 6, 8, 9};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "1016181923253251";
    verify_case(4, Arg1, construct(Arg0));
  }
  void test_case_5() {
    int Arr0[] = {4};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arg1 = "";
    verify_case(5, Arg1, construct(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  SelfDescFind ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
