// BEGIN CUT HERE

// END CUT HERE
#line 5 "MojisBag.cpp"
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

struct Node {
  Node *left;
  Node *right;
  int val, cnt;
  Node() {
    left = right = nullptr;
    val = cnt = 0;
  }
};
Node *root;
class MojisBag {
 public:
  int ans, e1, e2;
  void update(int x) {
    int cur = 0;
    Node *p = root;
    for (int i = 30; i >= 0; i--) {
      if (x & (1 << i)) {
        if (p->left) {
          p = p->left;
          cur += (1 << i);
        } else {
          p = p->right;
        }
      } else {
        if (p->right) {
          p = p->right;
          cur += (1 << i);
        } else {
          p = p->left;
        }
      }
    }
    if (cur > ans) {
      ans = cur;
      e1 = x, e2 = p->val;
    }
    // cout << "sdadf " << cur << "sdafsd" << endl;
  }
  void insert(int x) {
    Node *p = root;
    for (int i = 30; i >= 0; i--) {
      if (x & (1 << i)) {
        if (!p->right) p->right = new Node();
        p = p->right;
      } else {
        if (!p->left) p->left = new Node();
        p = p->left;
      }
      p->cnt++;
    }
    p->val = x;
  }
  void remove(int x) {
    Node *p = root;
    for (int i = 30; i >= 0; i--) {
      if (x & (1 << i)) {
        if (p->right->cnt == 1) {
          p->right = nullptr;
          break;
        } else {
          p = p->right;
          p->cnt--;
        }
      } else {
        if (p->left->cnt == 1) {
          p->left = nullptr;
          break;
        } else {
          p = p->left;
          p->cnt--;
        }
      }
    }
  }
  int maximumXor(int Q, int base, int add, int rate) {
    vi x(Q);
    x[0] = add;
    REP(i, 1, Q) x[i] = (1LL * x[i - 1] * base + add) % mod;
    vi y(Q);
    int cnt = 0;
    root = new Node();
    map<int, int> s;
    ans = 0, e1 = -1, e2 = -1;
    REP(i, 0, Q) {
      if (x[i] % rate) {
        s[cnt] = x[i];
        cnt++;
        insert(x[i]);
        update(x[i]);
        y[i] = ans;
      } else {
        if (cnt == 0) {
          y[i] = 0;
          continue;
        }
        int idx = x[i] % cnt;
        if (s.find(idx) == s.end()) {
          y[i] = ans;
        } else {
          int val = s[idx];
          s.erase(idx);
          if (val != e1 && val != e2) {
            y[i] = ans;
            remove(val);
          } else {
            ans = 0, e1 = 0, e2 = 0;
            root = new Node();
            for (auto it : s) {
              insert(it.second);
              update(it.second);
            }
            y[i] = ans;
          }
        }
      }
      // cout << ans << ", " << e1 << ", " << e2 << ". ";
    }
    // cout << endl;
    int z = y[0];
    REP(i, 1, Q) { z = (1LL * z * base + y[i]) % mod; }
    return z;
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
    int Arg0 = 10;
    int Arg1 = 4747;
    int Arg2 = 7;
    int Arg3 = 3;
    int Arg4 = 871911884;
    verify_case(0, Arg4, maximumXor(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_1() {
    int Arg0 = 5;
    int Arg1 = 47;
    int Arg2 = 7;
    int Arg3 = 3;
    int Arg4 = 34911440;
    verify_case(1, Arg4, maximumXor(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_2() {
    int Arg0 = 3;
    int Arg1 = 429;
    int Arg2 = 3558;
    int Arg3 = 2;
    int Arg4 = 0;
    verify_case(2, Arg4, maximumXor(Arg0, Arg1, Arg2, Arg3));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  MojisBag ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
