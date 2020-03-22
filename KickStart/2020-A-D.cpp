/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

struct Node {
  int cnt;
  int cnt_end;
  Node* nxt[26];
  Node() {
    cnt = cnt_end = 0;
    for (int i = 0; i < 26; i++) nxt[i] = nullptr;
  }
};

int n, k, a;
char s[2000010];
Node* root;

void insert() {
  int l = strlen(s);
  Node* p = root;
  for (int i = 0; i < l; i++) {
    p->cnt++;
    int v = s[i] - 'A';
    if (!p->nxt[v]) p->nxt[v] = new Node();
    p = p->nxt[v];
  }
  p->cnt++;
  p->cnt_end++;
}

int get(Node* cur, int len) {
  if (!cur) return 0;
  if (cur->cnt < k) return 0;
  int ret = 0;
  for (int i = 0; i < 26; i++) {
    ret += get(cur->nxt[i], len + 1);
  }
  int left = cur->cnt_end;
  for (int i = 0; i < 26; i++) {
    if (cur->nxt[i]) left += cur->nxt[i]->cnt;
  }
  ret += (left / k) * len;
  cur->cnt = left - (left / k) * k;
  // cout << len << " " << ret << endl;
  return ret;
}

void solve() {
  root = new Node();
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    insert();
  }
  a = n / k;
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    ans += get(root->nxt[i], 1);
  }
  printf("%d\n", ans);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d%d", &n, &k);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
