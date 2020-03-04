// BEGIN CUT HERE

// END CUT HERE
#line 5 "MaxCutFree.cpp"
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

// great problem.
class MaxCutFree {
 public:
  vector<vi> adj;
  vi dfs_low, dfs_num, vist;
  vii bridge;
  int cnt;
  void dfs(int u, int p) {
    dfs_low[u] = dfs_num[u] = cnt++;
    for (int v : adj[u]) {
      if (dfs_num[v] == -1) {
        dfs(v, u);
        if (dfs_low[v] > dfs_num[u]) {
          bridge.push_back(ii(u, v));
        }
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      } else if (v != p) {
        dfs_low[u] = min(dfs_low[u], dfs_num[v]);
      }
    }
  }
  void build_tree() {
    for (ii p : bridge) {
      adj[p.first].push_back(p.second);
      adj[p.second].push_back(p.first);
    }
  }
  ii dfs_dp(int u, int p) {
    vist[u] = 1;
    ii ret = ii(0, 1);  // first: do not choose the vertex, second: can choose
                        // the vertex(the optimal ans of this subtree);
    for (auto v : adj[u]) {
      if (v != p) {
        ii t = dfs_dp(v, u);
        ret.first += t.second;
        ret.second += t.first;
      }
    }
    ret.second = max(ret.second, ret.first);
    return ret;
  }
  int solve(int n, vector<int> a, vector<int> b) {
    adj.assign(n, vi(0));
    dfs_num.assign(n, -1);
    dfs_low.assign(n, 0);
    bridge.clear();
    cnt = 0;
    REP(i, 0, a.size()) {
      adj[a[i]].push_back(b[i]);
      adj[b[i]].push_back(a[i]);
    }
    REP(i, 0, n) {
      if (dfs_num[i] == -1) {
        dfs(i, -1);
      }
    }
    adj.assign(n, vi(0));
    build_tree();
    vist.assign(n, 0);
    int ans = 0;
    REP(i, 0, n) {
      if (!vist[i]) {
        ans += dfs_dp(i, -1).second;
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
    int Arg0 = 4;
    int Arr1[] = {0, 1, 2, 0};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 2, 0, 3};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 3;
    verify_case(0, Arg3, solve(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 6;
    int Arr1[] = {0, 1, 2, 3, 3};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {2, 2, 3, 4, 5};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 4;
    verify_case(1, Arg3, solve(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 7;
    int Arr1[] = {0, 2, 4};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 3, 5};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 4;
    verify_case(2, Arg3, solve(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    int Arg0 = 4;
    int Arr1[] = {0, 0, 0, 1, 1, 2};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 2, 3, 2, 3, 3};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 4;
    verify_case(3, Arg3, solve(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  MaxCutFree ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
