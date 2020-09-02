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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
struct node{
  int val;
  node* left;
  node* right;
  node(int v) {
    val = v;
    left = nullptr;
    right = nullptr;
  }
};

void insert(node* root, int val) {
  if(root->val > val) {
    if(root->left) insert(root->left, val);
    else root->left = new node(val);
  }
  else {
    if(root->right) insert(root->right, val);
    else root->right = new node(val);
  }
}

void preorder(node* root, vector<int>& ans) {
  if(!root->left && !root->right) {
    ans.push_back(root->val);
    return;
  }
  if(root->left) preorder(root->left, ans);
  if(root->right) preorder(root->right, ans);
}

int main() {
  vector<int> t;
  int v;
  while(scanf("%d", &v)) t.push_back(v);
  node* root = new node(t[0]);
  for(int i=1; i<t.size(); i++) {
    insert(root, t[i]);
    cout << t[i] << endl;
  }
  vector<int> ans;
  preorder(root, ans);
  for(int i=0; i<ans.size(); i++) {
    if(i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
