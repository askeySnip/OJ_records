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

class UnionFind {
 private:
  vi p, rank;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
  }
  int findSet(int i) { return (i == p[i] ? i : findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

class BIT {
 private:
  vi ft;

 public:
  BIT(int n) { ft.assign(n + 1, 0); }
  void add(int k) {
    for (; k < ft.size(); k += (k & (-k))) ft[k]++;
  }
  int sum(int k) {
    int ret = 0;
    for (; k; k -= (k & (-k))) ret += ft[k];
    return ret;
  }
};

// data

// void hello(const string& a) { cout << a << endl; }

int tree_sum(int n) {
  int ans = 0, m;
  if (scanf(" (%d", &m)) {
    ans = tree_sum(n - m) + tree_sum(n - m);
    if (ans < 2) ans = 0;
  } else
    ans = !n;
  scanf(" )");
  return ans;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    if (tree_sum(n))
      printf("yes\n");
    else
      printf("no\n");
  }
}