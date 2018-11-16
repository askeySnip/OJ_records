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
#define inf 1e6

// data
int nc, ne, nm;
int dist[404][404];
char e[2][10];
vector<string> vstr;
map<string, int> mpsi;

int main() {
  int kase = 0;
  while(scanf("%d", &nc), nc) {
    mpsi.clear();
    vstr.clear();
    for(int i=0; i<404; i++) {
      for(int j=0; j<404; j++) {
        if(i == j) dist[i][j] = 0;
        else dist[i][j] = inf;
      }
    }
    for(int i=0; i<nc; i++) {
      scanf("%d", &ne);
      scanf("%s", e[0]);
      if(mpsi.find(e[0]) == mpsi.end()) {
        vstr.push_back(e[0]);
        mpsi[e[0]] = vstr.size()-1;
      }
      int last = 0;
      for(int j=1; j<ne; j++) {
        scanf("%s", e[1-last]);
        if(mpsi.find(e[1-last]) == mpsi.end()) {
          mpsi[e[1-last]] = vstr.size();
          vstr.push_back(e[1-last]);
        }
        dist[mpsi[e[last]]][mpsi[e[1-last]]] = 1;
        last = 1-last;
      }
    }
    scanf("%d", &nm);
    for(int i=0; i<nm; i++) {
      scanf("%s %s", e[0], e[1]);
      dist[mpsi[e[0]]][mpsi[e[1]]] = 1;
    }

    int n = vstr.size();

    for(int k=0; k<n; k++) {
      for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
          if(dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }

    vii ans;
    for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
        if(dist[i][j] == inf && dist[j][i] == inf) ans.push_back(ii(i, j));
      }
    }
    if(ans.empty())printf("Case %d, no concurrent events.\n", ++kase);
    else {
      printf("Case %d, %d concurrent events:\n", ++kase, (int)ans.size());
      if((int)ans.size() == 1) {
        printf("(%s,%s) \n", vstr[ans[0].first].c_str(), vstr[ans[0].second].c_str());
      }
      else {
        printf("(%s,%s) (%s,%s) \n", vstr[ans[0].first].c_str(), vstr[ans[0].second].c_str(), vstr[ans[1].first].c_str(), vstr[ans[1].second].c_str());
      }
    }
  }
  return 0;
}
