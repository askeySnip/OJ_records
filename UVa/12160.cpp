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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

// struct


// data
int l, u, r;
int rv[13];
int vist[10024];

int main() {
  int kase = 0;
  while(scanf("%d %d %d", &l, &u, &r), l || u || r) {
    for(int i=0; i<r; i++) {
      scanf("%d", &rv[i]);
    }
    memset(vist, 0, sizeof vist);
    queue<ii> q;
    q.push(ii(l, 0));
    bool flag = false;
    while(!q.empty()) {
      ii p = q.front(); q.pop();
      if(vist[p.first]) continue;
      if(p.first == u) {
        flag = true;
        printf("Case %d: %d\n", ++kase, p.second);
        break;
      }
      vist[p.first] = 1;
      for(int i=0; i<r; i++) {
        int t = (p.first + rv[i]) % 10000;
        if(vist[t]) continue;
        q.push(ii(t, p.second+1));
      }
    }
    if(!flag) printf("Case %d: Permanently Locked\n", ++kase);
  }
  return 0;
}
