// BEGIN CUT HERE

// END CUT HERE
#line 5 "WebSpider.cpp"
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

class WebSpider {
 public:
  struct Node {
    map<string, Node *> next;
    Node *parent;
    bool leaf;
    Node() {
      next.clear();
      parent = nullptr;
      leaf = false;
    }
  };
  Node *root;
  set<Node *> ans;
  int countPages(vector<string> firstPass, vector<string> secondPass,
                 vector<string> thirdPass) {
    root = new Node();
    ans.clear();
    vector<Node *> l1;
    for (auto &s : firstPass) {
      l1.push_back(insert(root, s));
    }
    vector<Node *> l2;
    for (auto &s : secondPass) {
      int i = 0;
      while (s[i] != ' ') i++;
      int id = stoi(s.substr(0, i));
      l2.push_back(insert(l1[id]->parent, s.substr(i + 1)));
    }
    for (auto &s : thirdPass) {
      int i = 0;
      while (s[i] != ' ') i++;
      int id = stoi(s.substr(0, i));
      insert(l2[id]->parent, s.substr(i + 1));
    }
    return ans.size();
  }
  Node *insert(Node *r, const string &s) {
    vector<string> vs;
    string::size_type p = s.find('/');
    string::size_type p2 = 0;
    while (p != string::npos) {
      vs.push_back(s.substr(p2, p - p2));
      p2 = p + 1;
      p = s.find('/', p2);
    }
    vs.push_back(s.substr(p2));
    REP(i, 0, vs.size()) {
      if (vs[i] == "..") {
        r = r->parent;
      } else {
        if (r->next.find(vs[i]) == r->next.end()) {
          r->next[vs[i]] = new Node();
          r->next[vs[i]]->parent = r;
        }
        r = r->next[vs[i]];
      }
    }
    r->leaf = true;
    ans.insert(r);
    return r;
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
    if ((Case == -1) || (Case == 6)) test_case_6();
    if ((Case == -1) || (Case == 7)) test_case_7();
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
    string Arr0[] = {"home.htm", "sitemap.htm", "contact.htm",
                     "support/login.jsp"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"2 locations.htm", "3 ../home.htm"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {"0 contact.htm"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 5;
    verify_case(0, Arg3, countPages(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    string Arr0[] = {"index.html", "products/all/INDEX.HTML",
                     "images/products/A101.GIF"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"1 ../../index.html", "1 ../../products"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 4;
    verify_case(1, Arg3, countPages(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    string Arr0[] = {".rc"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 1;
    verify_case(2, Arg3, countPages(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    string Arr0[] = {"a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"0 a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {"0 ../a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a", "0 ..a/a",
                     "0 a../a.."};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 5;
    verify_case(3, Arg3, countPages(Arg0, Arg1, Arg2));
  }
  void test_case_4() {
    string Arr0[] = {"abc/ccba", "ab/cba", "..a"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"0 cba", "1 ccba"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {"0 cba", "1 ccba"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 5;
    verify_case(4, Arg3, countPages(Arg0, Arg1, Arg2));
  }
  void test_case_5() {
    string Arr0[] = {"a", "ab/ab", "ab/ab/abc", "abc/abc"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"0 ab/ab", "1 ab", "1 ../ab/ab", "2 ../../ab/abc"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {"0 ../ab/ab", "2 ../abc/abc", "1 ab/ab"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 6;
    verify_case(5, Arg3, countPages(Arg0, Arg1, Arg2));
  }
  void test_case_6() {
    string Arr0[] = {"a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"0 ../../../../../../../../a/a/a/a/a/a/a/a/a"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {"0 ../../../../../../../../a/a/a/a/a/a/a/a/a"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 1;
    verify_case(6, Arg3, countPages(Arg0, Arg1, Arg2));
  }
  void test_case_7() {
    string Arr0[] = {"index.asp",
                     "contact.asp",
                     "about/index.asp",
                     "users/support.asp",
                     "company/executiveteam.asp",
                     "products/catalog.asp"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {
        "1 index.asp",    "1 requestinfo.asp",      "2 ../index.asp",
        "2 history.asp",  "3 ../index.asp",         "3 helpdesk.asp",
        "4 ../index.asp", "4 boardofdirectors.asp", "4 location.asp",
        "5 ../index.asp", "5 new/index.asp",        "5 ../index.asp",
        "5 sale.asp"};
    vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    string Arr2[] = {"10 ../../index.asp", "11 products/index.asp",
                     "11 products/catalog.asp"};
    vector<string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 14;
    verify_case(7, Arg3, countPages(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  WebSpider ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
