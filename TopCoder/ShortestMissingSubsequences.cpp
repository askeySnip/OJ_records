// BEGIN CUT HERE

// END CUT HERE
#line 5 "ShortestMissingSubsequences.cpp"
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

int A[2000024];
int L[2000024], C[2000024];
class ShortestMissingSubsequences {
 public:
  vector<int> count(int G, int N, vector<int> Aprefix) {
    ll state = Aprefix.back();
    copy(Aprefix.begin(), Aprefix.end(), A);
    int i = Aprefix.size();
    while (i < N) {
      state = (state * 1103515245 + 12345) % (1 << 31);
      A[i++] = state % G;
    }
    vector<int> ans;
    if (G > N) {
      ans.push_back(1);
      set<int> s;
      REP(j, 0, N) { s.insert(A[j]); }
      ans.push_back(G - (int)s.size());
    } else {
      set<int> x, next_x;
      REP(j, 0, G) {
        L[j] = 1;
        C[j] = 1;
        x.insert(j);
      }
      int cur_min_l = 1;
      ll small_sum = G, big_sum = 0;
      for (int j = N - 1; j >= 0; j--) {
        if (x.empty()) {
          x = next_x;
          next_x.clear();
          cur_min_l += 1;
          small_sum = big_sum;
          big_sum = 0;
        }
        if (L[A[j]] == cur_min_l) {
          int t = C[A[j]];
          C[A[j]] = small_sum;
          small_sum -= t;
          if (small_sum < 0) small_sum += mod;
          big_sum += C[A[j]];
          big_sum %= mod;
          x.erase(A[j]);
          next_x.insert(A[j]);
          L[A[j]] = cur_min_l + 1;
        } else {
          big_sum -= C[A[j]] - small_sum;
          if (big_sum < 0) big_sum += mod;
          C[A[j]] = small_sum;
        }
        // REP(k, 0, G) cout << L[k] << " " << C[k] << endl;
      }
      if (x.empty()) {
        x = next_x;
        next_x.clear();
        cur_min_l += 1;
        small_sum = big_sum;
        big_sum = 0;
      }
      ans.push_back(cur_min_l);
      ans.push_back(small_sum);
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
    int Arg0 = 2;
    int Arg1 = 4;
    int Arr2[] = {1, 0, 0, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {3, 5};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(0, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 5;
    int Arg1 = 4;
    int Arr2[] = {1, 0, 0, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1, 3};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(1, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 7;
    int Arg1 = 7;
    int Arr2[] = {0, 1, 2, 3, 4, 5, 6};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {2, 28};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(2, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    int Arg0 = 7;
    int Arg1 = 14;
    int Arr2[] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {2, 21};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(3, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_4() {
    int Arg0 = 3;
    int Arg1 = 10;
    int Arr2[] = {1, 2, 0};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {3, 6};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(4, Arg3, count(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  ShortestMissingSubsequences ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
