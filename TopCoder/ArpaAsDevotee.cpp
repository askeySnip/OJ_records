// BEGIN CUT HERE

// END CUT HERE
#line 5 "ArpaAsDevotee.cpp"
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

class ArpaAsDevotee {
 public:
  vector<string> solve(int n, int q, vector<int> a, vector<int> lastSeen,
                       vector<int> t) {
    if (a.size() < n) return {};
    for (int i = 0; i < n; i++) {
      if (a[i] < lastSeen[i]) return {};
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      if (mp.find(a[i]) == mp.end())
        mp[a[i]] = lastSeen[i];
      else if (mp[a[i]] != lastSeen[i])
        return {};
    }
    vector<int> ts(86401, 0);
    vii p(mp.begin(), mp.end());
    REP(i, 1, p.size()) {
      if (p[i - 1].second == p[i].second || p[i].second > p[i - 1].first)
        continue;
      return {};
    }
    ts[p[0].second] = 1;
    int ls = p[0].second;
    for (int i = ls + 1; i <= p[0].first; i++) ts[i] = 2;
    for (int i = 1; i < p.size(); i++) {
      if (p[i].second == ls) {
        for (int j = p[i - 1].first + 1; j <= p[i].first; j++) ts[j] = 2;
      } else {
        ls = p[i].second;
        ts[ls] = 1;
        for (int j = ls + 1; j <= p[i].first; j++) ts[j] = 2;
      }
    }
    vector<string> ans;
    for (int i = 0; i < q; i++) {
      if (ts[t[i]] == 0)
        ans.emplace_back("Not Sure");
      else if (ts[t[i]] == 1)
        ans.emplace_back("Yes");
      else
        ans.emplace_back("No");
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
  string print_array(const vector<T> &V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
         ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const vector<string> &Expected,
                   const vector<string> &Received) {
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
    int Arg0 = 5;
    int Arg1 = 7;
    int Arr2[] = {11, 13, 17, 25, 29};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {11, 13, 15, 15, 29};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {11, 12, 13, 14, 15, 16, 17};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    string Arr5[] = {"Yes", "Not Sure", "Yes", "Not Sure", "Yes", "No", "No"};
    vector<string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    verify_case(0, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_1() {
    int Arg0 = 2;
    int Arg1 = 1;
    int Arr2[] = {1, 10};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {5, 3};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {6};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    string Arr5[] = {};
    vector<string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    verify_case(1, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_2() {
    int Arg0 = 3;
    int Arg1 = 1;
    int Arr2[] = {7, 7, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {3, 5, 1};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {4};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    string Arr5[] = {};
    vector<string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    verify_case(2, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_3() {
    int Arg0 = 2;
    int Arg1 = 3;
    int Arr2[] = {5, 5};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {2, 2};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {1, 2, 3};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    string Arr5[] = {"Not Sure", "Yes", "No"};
    vector<string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    verify_case(3, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_4() {
    int Arg0 = 2;
    int Arg1 = 1;
    int Arr2[] = {7, 10};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {5, 7};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arr4[] = {1};
    vector<int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    string Arr5[] = {};
    vector<string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
    verify_case(3, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  ArpaAsDevotee ___test;
  ___test.run_test(-1);
}
// END CUT HERE
