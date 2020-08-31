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
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data

vector<int> a;

struct node {
  node* nxt[2];
  node() { nxt[0] = nxt[1] = nullptr; }
};

node* root;

void insert(int x) {
  node* p = root;
  for (int i = 20; i >= 0; i--) {
    if (x & (1 << i)) {
      if (!p->nxt[1]) p->nxt[1] = new node();
      p = p->nxt[1];
    } else {
      if (!p->nxt[0]) p->nxt[0] = new node();
      p = p->nxt[0];
    }
  }
}

void preorder(node* l, node* r) {
  if (l == nullptr) return;
  if (l->nxt[0]) {
    if (!r->nxt[0]) r->nxt[0] = new node();
    preorder(l->nxt[0], r->nxt[0]);
  }
  if (l->nxt[1]) {
    if (!r->nxt[1]) r->nxt[1] = new node();
    preorder(l->nxt[1], r->nxt[1]);
  }
}

void cp(node* p) {
  if (!p) return;
  cp(p->nxt[0]);
  cp(p->nxt[1]);
  node* l = p->nxt[0];
  if (!p->nxt[1]) p->nxt[1] = new node();
  node* r = p->nxt[1];
  preorder(l, r);
}

bool search(int x) {
  node* p = root;
  for (int i = 20; i >= 0; i--) {
    if (x & (1 << i)) {
      if (!p->nxt[0]) return false;
      p = p->nxt[0];
    } else {
      if (!p->nxt[1]) return false;
      p = p->nxt[1];
    }
  }
  return true;
}

void solve() {
  root = new node();
  for (int i = 0; i < a.size(); i++) {
    insert(a[i]);
  }
  node* p = root;
  cp(p);
  for (int i = 0; i < a.size(); i++) {
    cout << search(a[i]) << " ";
  }
}

int main() {
  a = {1, 3, 5, 6, 7, 8, 9};
  solve();
  return 0;
}
