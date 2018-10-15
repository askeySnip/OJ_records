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

int nodes[30];
int graph[30];
int vist[30];
int printlist[30];
int n;
bool flag;

void solve(int id) {
  if(id == n) {
    for(int i=0; i<n; i++) {
      if(i) printf(" ");
      printf("%c", printlist[i]+'A');
    }
    printf("\n");
    return;
  }
  if(!flag) return;
  int tgraph[30];
  bool f = false;
  for(int i=0; i<30; i++) {
    if(!nodes[i] || vist[i]) continue;
    int t = 0;
    for(int j=0; j<30; j++) {
      if((graph[j]&(1<<i))) t++;
    }
    if(t) continue;
    f = true;
    memcpy(tgraph, graph, sizeof graph);
    printlist[id] = i;
    for(int k=0; k<30; k++) {
      if(graph[i] & (1<<k))
      // for(int j=0; j<30; j++) {
      //   graph[j] &= (~(1<<k));
      // }
        graph[i] &= (~(1<<k));
    }
    
    vist[i] = 1;
    solve(id+1);
    memcpy(graph, tgraph, sizeof graph);
    vist[i] = 0;
  }
  if(!f) flag = false;
}
int main() {
  int t;
  scanf("%d", &t);
  getchar();
  while(t--) {
    getchar();
    char buf[300];
    gets(buf);
    int l = strlen(buf);
    n = l/2 + 1;
    for(int i=0; i<30; i++) nodes[i] = 0;
    for(int i=0; i<l; i+=2) nodes[buf[i]-'A'] = 1;
    gets(buf);
    int ln = strlen(buf);
    for(int i=0; i<30; i++) graph[i] = 0;
    for(int i=0; i<ln; i+=4) {
      graph[buf[i]-'A'] |= (1<<(buf[i+2]-'A'));
    }
    for(int i=0; i<30; i++) vist[i] = 0;
    flag = true;
    solve(0);
    if(!flag) printf("NO\n");
    if(t) printf("\n");
  }
  return 0;
}
