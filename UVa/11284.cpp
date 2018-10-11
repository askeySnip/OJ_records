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

const double inf = 1000000000;
int n, m, p;
//double graph[52][52];
double dis[52][52];
int store[13];
double price[13], tempprice[52];
double dp[1<<13][13];
double best;

void deal_graph(){
  //  for(int i=0; i<=n; i++) for(int j=0; j<n; j++) dis[i][j] = inf;
  for(int i=0; i<=n; i++) dis[i][i] = 0.0;
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=n; j++) {
      for(int k=0; k<=n; k++) {
        if(dis[j][k] > dis[j][i] + dis[i][k]) {
          dis[j][k] = dis[j][i] + dis[i][k];
        }
      }
    }
  }
}

double tsp(int id, int choosen) {
  if(choosen == (1<<p)-1) return price[id] - dis[store[id]][0];
  if(dp[id][choosen] != -inf) return dp[id][choosen];
  double val = price[id] - dis[store[id]][0];
  for(int i=0; i<p; i++) {
    if(choosen&(1<<i)) continue;
    val = max(tsp(i, choosen|(1<<i)) - dis[store[id]][store[i]] + price[id], val);
  }
  dp[id][choosen] = val;
  return dp[id][choosen];
}

double tsp(int state, int n, int last) {
  if(state == 0) return 0;
  if(dp[state][last] != -inf) return dp[state][last];
  double max = -inf, tmp;
  for(int i=0; i<=n; i++) {
    if((state&(1<<i)) && last != i) {
      tmp = tsp(state-(1<<last), n, i);
      tmp -= dis[store[i]][store[last]];
      tmp += price[last];
      if(max < tmp) max = tmp;
    }
  }
  if(state == (1<<last)) max = -dis[store[last]][0] + price[last];
  if(best < max-dis[store[last]][0]) best = max-dis[store[last]][0];

  dp[state][last] = max;
  return max;
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &m);
    int a, b;
    double d;
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) dis[i][j] = inf;
    for(int i=0; i<m; i++) {
      scanf("%d %d %lf", &a, &b, &d);
      dis[a][b] = dis[b][a] = min(dis[a][b], d);
    }
    deal_graph();
    scanf("%d", &p);
    int st;
    double pp;
    for(int i=0; i<52; i++) tempprice[i] = 0.0;
    for(int i=0; i<p; i++) {
      scanf("%d %lf", &st, &pp);
      tempprice[st] += pp;
    }
    int newp = 0;
    for(int i=1; i<=n; i++) {
      if(tempprice[i] > 0) {
        newp++;
        store[newp] = i;
        price[newp] = tempprice[i];
      }
    }
    p = newp;
    int final = (1<<(p+1)) - 1;
    for(int i=0; i<= final; i++) for(int j=0; j<=p; j++) dp[i][j] = -inf;
    best = 0;
    tsp(final, p, 0);
    if(best > 0.0) printf("Daniel can save $%.2lf\n", best);
    else printf("Don't leave the house\n");
  }
  return 0;
}
