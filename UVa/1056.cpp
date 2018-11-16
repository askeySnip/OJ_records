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
int p, r;
vector<string> vstr;
map<string, int> mp;
int dist[52][52];
char a[100], b[100];

int main() {
  int kase = 0;
  while(scanf("%d %d", &p, &r), p || r) {
    for(int i=0; i<p; i++) {
      for(int j=0; j<p; j++) {
        if(i == j) dist[i][j] = 0;
        else dist[i][j] = inf;
      }
    }
    mp.clear();
    vstr.clear();

    for(int i=0; i<r; i++) {
      scanf("%s%s", a, b);
      if(mp.find(a) == mp.end()) {
        mp[a] = vstr.size();
        vstr.push_back(a);
      }
      if(mp.find(b) == mp.end()) {
        mp[b] = vstr.size();
        vstr.push_back(b);
      }
      dist[mp[a]][mp[b]] = dist[mp[b]][mp[a]] = 1;
    }

    for(int k=0; k<p; k++) {
      for(int i=0; i<p; i++) {
        for(int j=0; j<p; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    int ans = -1;
    for(int i=0; i<p; i++) {
      for(int j=0; j<p; j++) {
        ans = max(ans, dist[i][j]);
      }
    }
    if(ans == inf) printf("Network %d: DISCONNECTED\n", ++kase);
    else printf("Network %d: %d\n", ++kase, ans);
    printf("\n");
  }
  return 0;
}
