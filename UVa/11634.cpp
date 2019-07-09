/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data


int main() {
  int vis[10000];
  int a;
  while(scanf("%d", &a), a) {
    memset(vis, 0, sizeof vis);
    int count = 0;
    while(vis[a] == 0) {
      count++;
      vis[a] = 1;
      a = (a * a / 100) % 10000;
    }
    printf("%d\n", count);
  }
  return 0;
}
