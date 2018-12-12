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

// data
int n;
vii edges[60];
int c[60];
list<int> cyc;

void EulerTour(list<int>::iterator it, int u) {
  for(int j=0; j<(int)edges[u].size(); j++) {
    ii& v = edges[u][j];
    if(v.second) {
      v.second = 0;
      for(int k=0; k<(int)edges[v.first].size(); k++){
        ii& uu = edges[v.first][k];
        if(uu.first == u && uu.second) {
          uu.second = 0;
          break;
        }
      }
      EulerTour(cyc.insert(it, u), v.first);
    }
  }
}

int main() {
  int t, kase = 0;;
  scanf("%d", &t);
  while(t--) {
    if(kase) printf("\n");
    scanf("%d", &n);
    for(int i=0; i<60; i++) edges[i].clear();
    memset(c, 0, sizeof c);
    int a, b;
    for(int i=0; i<n; i++) {
      scanf("%d %d", &a, &b);
      edges[a].push_back(ii(b, 1));
      edges[b].push_back(ii(a, 1));
      c[a]++; c[b]++;
    }
    bool flag = true;
    for(int i=1; i<=50; i++) {
      if(c[i]&1) {
        flag = false; break;
      }
    }
    printf("Case #%d\n", ++kase);
    if(flag) {
      cyc.clear();
      EulerTour(cyc.begin(), a);
      vi anslist;
      for(list<int>::iterator it = cyc.begin(); it!= cyc.end(); it++) {
        anslist.push_back(*it);
      }
      anslist.push_back(anslist[0]);
      for(int i=0; i<(int)anslist.size()-1; i++) {
        printf("%d %d\n", anslist[i], anslist[i+1]);
      }
    }else {
      printf("some beads may be lost\n");
    }
  }
  return 0;
}
