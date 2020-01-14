// BEGIN CUT HERE

// END CUT HERE
#line 5 "Alibi.cpp"
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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

class Alibi {
 public:
  string findMurderer(string murderRoom, int murderTime, vector<int> eventTime,
                      vector<string> eventPerson, vector<string> eventRoom) {
    map<string, map<string, int>> mp;
    if (eventTime.empty()) return "";
    vector<string> suspects{"White", "Green",    "Peacock",
                            "Plum",  "Scarlett", "Mustard"};
    for (int i = 0; i < 6; i++) {
      mp[suspects[i]]["Hall"] = 0;
    }
    for (int i = 0; i < eventTime.size(); i++) {
      if (eventTime[i] > murderTime) break;
      mp[eventPerson[i]].clear();
      mp[eventPerson[i]][eventRoom[i]] = eventTime[i];
    }
    vector<string> ans;
    for (int i = 0; i < 6; i++) {
      if (mp[suspects[i]].find(murderRoom) != mp[suspects[i]].end()) {
        ans.push_back(suspects[i]);
      }
    }
    if (ans.size() != 1) return "";
    return ans[0];
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
    string Arg0 = "Library";
    int Arg1 = 10;
    int Arr2[] = {5, 7, 9};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    string Arr3[] = {"Plum", "Scarlett", "Plum"};
    vector<string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    string Arr4[] = {"Library", "Library", "Cellar"};
    vector<string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    string Arg5 = "Scarlett";
    verify_case(0, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_1() {
    string Arg0 = "Library";
    int Arg1 = 10;
    int Arr2[] = {};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    string Arr3[] = {};
    vector<string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    string Arr4[] = {};
    vector<string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    string Arg5 = "";
    verify_case(1, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_2() {
    string Arg0 = "Library";
    int Arg1 = 8;
    int Arr2[] = {5, 7, 9};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    string Arr3[] = {"Plum", "Scarlett", "Plum"};
    vector<string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    string Arr4[] = {"Library", "Library", "Cellar"};
    vector<string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    string Arg5 = "";
    verify_case(2, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_3() {
    string Arg0 = "Hall";
    int Arg1 = 11;
    int Arr2[] = {2, 4, 6, 8, 10, 12};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    string Arr3[] = {"White", "Green",    "Peacock",
                     "Plum",  "Scarlett", "Mustard"};
    vector<string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    string Arr4[] = {"Kitchen", "Ballroom", "Conservatory",
                     "Library", "Lounge",   "Study"};
    vector<string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    string Arg5 = "Mustard";
    verify_case(3, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_4() {
    string Arg0 = "Library";
    int Arg1 = 10;
    int Arr2[] = {3, 7};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    string Arr3[] = {"Plum", "Plum"};
    vector<string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    string Arr4[] = {"Library", "Library"};
    vector<string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
    string Arg5 = "Plum";
    verify_case(4, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  Alibi ___test;
  ___test.run_test(-1);
}
// END CUT HERE
