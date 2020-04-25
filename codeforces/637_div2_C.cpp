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
int n;
int p[100010];

bool check() {
  REP(i, 0, n-1) {
    if(p[i] < p[i+1] && p[i]+1 != p[i+1]) return false; 
  }
  return true;
}

void solve() {
  if(check()) printf("Yes\n");
  else printf("No\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &p[i]);
    solve();
  }
  return 0;
}
