/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

//        1
//   2        3
// 4    5    6  7
//     8  9

// struct Node {
//   Node* left;
//   Node* right;
//   Node* parent;
//   Node() { left = right = parent = nullptr; }
// };

// Node* Next(Node* p) {
//   if (p == nullptr) return nullptr;
//   if (p->right) {
//     p = p->right;
//     if (p->left) {
//       while (p->left) {
//         p = p->left;
//       }
//     }
//     return p;
//   }
//   Node* t = p->parent;
//   while (t) {
//     if (t->left == p)
//       return t;
//     else {
//       p = t;
//       t = p->parent;
//     }
//   }
//   return nullptr;
// }

bool f;
int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

void dfs(vector<vector<int>>& h, vector<vector<int>>& vist, int x, int y) {
  vist[x][y] = 1;
  if (f) return;
  if (x == 0 || x == h.size() - 1 || y == 0 || y == h[0].size() - 1) {
    f = true;
    return;
  }
  for (int i = 0; i < 4; i++) {
    int tx = x + dirx[i], ty = y + diry[i];
    if (tx >= 0 && tx < h.size() && ty >= 0 && ty < h[0].size()) {
      if (vist[tx][ty] || h[tx][ty] > h[x][y]) continue;
      dfs(h, vist, tx, ty);
      if (f) return;
    }
  }
}

bool flow(vector<vector<int>> h, int sx, int sy) {
  vector<vector<int>> vist(h.size(), vector<int>(h[0].size(), 0));
  f = false;
  dfs(h, vist, sx, sy);
  return f;
}

int r, c;
vector<vector<int>> all_flow(vector<vector<int>> h) {
  r = h.size(), c = h[0].size();
  vector<vector<int>> ans(r, vector<int>(c, 0));
  for (int i = 0; i < c; i++) ans[0][i] = 1;
  for (int i = 0; i < r; i++) ans[i][0] = 1;
  for (int i = 1; i < r; i++) {
    for (int j = 1; j < c; j++) {
      if (h[i - 1][j] <= h[i][j]) ans[i][j] |= ans[i - 1][j];
      if (h[i][j - 1] <= h[i][j]) ans[i][j] |= ans[i][j - 1];
    }
  }

  for (int i = 0; i < c; i++) ans[r - 1][i] = 1;
  for (int i = 0; i < r; i++) ans[i][c - 1] = 1;
  for (int i = r - 2; i > 0; i--) {
    for (int j = c - 2; j > 0; j--) {
      ans[i][j] = ans[i + 1][j] || ans[i][j + 1];
    }
  }
  return ans;
}

struct Node {
  bool leaf;
  map<string, Node*> nxt;
  Node() {
    leaf = false;
    nxt.clear();
  }
};
Node* root;

void insert(string& s) {
  Node* p = root;
  int start = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '/') {
      if (p->nxt.find(s.substr(start, i - start)) == p->nxt.end()) {
        p->nxt[s.substr(start, i - start)] = new Node();
      }
      p = p->nxt[s.substr(start, i - start)];
      start = i + 1;
    }
  }
  if (p->nxt.find(s.substr(start)) == p->nxt.end()) {
    p->nxt[s.substr(start)] = new Node();
  }
  p = p->nxt[s.substr(start)];
  p->leaf = true;
}

bool check(string& s) {
  Node* p = root;
  int start = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '/') {
      p = p->nxt[s.substr(start, i - start)];
      if (p->leaf) return false;
      start = i + 1;
    }
  }
  return true;
}
vector<string> folder(vector<string> vs) {
  root = new Node();
  for (int i = 0; i < vs.size(); i++) {
    insert(vs[i]);
  }
  vector<string> ans;
  for (int i = 0; i < vs.size(); i++) {
    if (check(vs[i])) ans.push_back(vs[i]);
  }
  return ans;
}

bool cmp(string& a, string& b) { return a.length() < b.length(); }

vector<string> folder(vector<string> vs) {
  sort(vs.begin(), vs.end(), cmp);
  vector<int> flag(vs.size(), 1);
  for (int i = 0; i < vs.size(); i++) {
    if (flag[i] == 0) continue;
    for (int j = i + 1; j < vs.size(); j++) {
      if (flag[j] == 0) continue;
      if (vs[j].find(vs[i]) != string::npos) {
        int t = vs[j].find(vs[i]);
        int l = vs[i].size();
        if (vs[j][t + l] == '/') flag[j] = 0;
      }
    }
  }
  vector<string> ans;
  for (int i = 0; i < vs.size(); i++) {
    if (flag[i]) ans.push_back(vs[i]);
  }
  return ans;
}

vector<string> folder(vector<string> vs) {
  if (vs.empty()) return {};
  sort(vs.begin(), vs.end());
  vector<string> ans;
  ans.push_back(vs[0]);
  int cur = 0;
  for (int i = 1; i < vs.size(); i++) {
    if (vs[i].find(vs[cur]) != string::npos) {
      int t = vs[i].find(vs[cur]);
      int l = vs[cur].length();
      if (t == 0 && vs[i][t + l] == '/')
        continue;
      else {
        ans.push_back(vs[i]);
        cur = i;
      }
    }
  }
  return ans;
}

// input :
// a/b/c
// a/b
// c/d/e
// c/d/e/f

// output:
// a/b
// c/d/e

// subfolder: a/b/c 为 a/b的subfolder

// 输出所有 不是其他元素subfolder的元素

// a/b/c 和 b/c没有关系
// 不需要考虑folder string的合法性

// struct Node {
//   bool leaf;
//   map<string, Node*> nxt;
//   Node() {
//     leaf = false;
//     nxt.clear();
//   }
// };

// Node* root;

// void insert(string& s) {
//   Node* p = root;
//   int start = 0;
//   for (int i = 0; i < s.length(); i++) {
//     if (s[i] == '/') {
//       if (p->nxt.find(s.substr(start, i - start)) == p->nxt.end()) {
//         p->nxt[s.substr(start, i - start)] = new Node();
//       }
//       p = p->nxt[s.substr(start, i - start)];
//       start = i + 1;
//     }
//   }
//   if (p->nxt.find(s.substr(start)) == p->nxt.end()) {
//     p->nxt[s.substr(start)] = new Node();
//   }
//   p = p->nxt[s.substr(start)];
//   p->leaf = true;
// }

// bool check(string& s) {
//   Node* p = root;
//   int start = 0;
//   for (int i = 0; i < s.length(); i++) {
//     if (s[i] == '/') {
//       p = p->nxt[s.substr(start, i - start)];
//       if (p->leaf) return false;
//       start = i + 1;
//     }
//   }
//   return true;
// }
// vector<string> folder(vector<string> vs) {
//   root = new Node();
//   for (int i = 0; i < vs.size(); i++) {
//     insert(vs[i]);
//   }
//   vector<string> ans;
//   for (int i = 0; i < vs.size(); i++) {
//     if (check(vs[i])) ans.push_back(vs[i]);
//   }
//   return ans;
// }

vector<string> folder(vector<string> vs) {
  sort(vs.begin(), vs.end(), cmp);
  vector<int> flag(vs.size(), 1);
  for (int i = 0; i < vs.size(); i++) {
    if (flag[i] == 0) continue;
    for (int j = i + 1; j < vs.size(); j++) {
      if (flag[j] == 0) continue;
      if (vs[j].find(vs[i]) != string::npos) {
        int t = vs[j].find(vs[i]);
        int l = vs[i].size();
        if (t == 0 && vs[j][l] == '/') flag[j] = 0;
      }
    }
  }
  vector<string> ans;
  for (int i = 0; i < vs.size(); i++) {
    if (flag[i]) ans.push_back(vs[i]);
  }
  return ans;
}

vector<string> folder(vector<string> vs) {
  if (vs.empty()) return {};
  sort(vs.begin(), vs.end());
  vector<string> ans;
  ans.push_back(vs[0]);
  int cur = 0;
  for (int i = 1; i < vs.size(); i++) {
    if (vs[i].find(vs[cur]) != string::npos) {
      int t = vs[i].find(vs[cur]);
      int l = vs[cur].length();
      if (t == 0 && vs[i][t + l] == '/')
        continue;
      else {
        ans.push_back(vs[i]);
        cur = i;
      }
    }
  }
  return ans;
}


// 1 + 3 + 5 * 3 / 10
// 1 + 3 + 4
// 1. + 3. + 4
// 5 / 4 + 3 * 2
// 1 * 3 * 5+6-6

// 15 - - 13
// double parse(string& s) {
//   int i = 0;
//   while (i < s.length() && s[i] == ' ') i++;
//   if (s[i] != '-' || s[i] != '+' || s[i] < '0' || s[i] > '9') {
//     throw "invalid";
//   }
//   int j = i;
//   if (s[j] == '-' || s[j] == '+') j++;
//   while (j < s.length() && s[j] >= '0' && s[j] <= '9') {
//     j++;
//   }
//   if (s[j] == '.') {
//     j++;
//     while (j < s.length() && s[j] >= '0' && s[j] <= '9') {
//       j++;
//     }
//     if (s[j] == '.') {
//       throw "invalid";
//     }
//   }
//   double ret = stod(s.substr(i, j - i));
//   s = s.substr(j);
//   return ret;
// }

// double helper(string& s) {
//   char op = '+';
//   stack<pair<char, double>> stk;
//   double cur = parse(s);
//   while (!s.empty()) {
//     int i = 0;
//     while (i < s.length() && s[i] == ' ') i++;
//     switch (op) {
//       case '+':
//         stk.push({'+', num});
//         break;
//       case '-':
//         stk.push({'-', num});
//         break;
//       case '*':
        
//         break;
//       case '/'
//       default:
//         throw "invaild";
//     }
//     if (s[i] == '-') {
//       return num -
//     }
//   }
// }
// double cacul(string s) {
//   if (s == "") return 0.0;
//   bool flag = true;
//   double ret = helper(s, flag);
//   if (!flag) throw "invaild";
//   return ret;
// }

int main() {}