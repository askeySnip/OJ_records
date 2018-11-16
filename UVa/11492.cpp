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
int m;
// vector<string> dict;
map<string, int> mp;
vector<pair<char, ii> > edges[4003];
int dis[27][4003];

int main() {
  char s1[60], s2[60], w[60];
  while(scanf("%d", &m), m) {
    for(int i=0; i<4003; i++) edges[i].clear();
    memset(dis, -1, sizeof dis);
    mp.clear();
    scanf("%s %s", s1, s2);
    int size = 2;
    mp[s1] = 0; mp[s2] = 1;
    for(int i=0; i<m; i++) {
      scanf("%s %s %s", s1, s2, w);
      int a, b, c = strlen(w);
      if(mp.find(s1) == mp.end()) {
        mp[s1] = size; size++;
      }
      if(mp.find(s2) == mp.end()) {
        mp[s2] = size; size++;
      }
      a = mp[s1]; b = mp[s2];
      edges[a].push_back(make_pair(w[0], ii(b, c)));
      edges[b].push_back(make_pair(w[0], ii(a, c)));
    }
    priority_queue<pair<ii, char>, vector<pair<ii, char> >, greater<pair<ii, char> > > pq;
    pq.push(make_pair(ii(0, 0), 'z'+1));
    while(!pq.empty()) {
      ii p = pq.top().first; char tc = pq.top().second; pq.pop();
      if(dis[tc-'a'][p.second] != -1) continue;
      dis[tc-'a'][p.second] = p.first;
      if(p.second == 1) break;
      for(int i=0; i<(int)edges[p.second].size(); i++) {
        int u = edges[p.second][i].second.first;
        if(dis[edges[p.second][i].first-'a'][u] == -1 && tc != edges[p.second][i].first) pq.push(make_pair(ii(p.first + edges[p.second][i].second.second, u), edges[p.second][i].first));
      }
    }
    int ans = 1e9;
    for(int i=0; i<26; i++) if(dis[i][1] != -1) ans = min(ans, dis[i][1]);
    if(ans == 1e9) printf("impossivel\n");
    else printf("%d\n", ans);
  }
  return 0;
}
