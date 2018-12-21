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
// int pi[1024];

// int main() {
//   int n, k;
//   while(scanf("%d %d", &n, &k) == 2) {
//     REP(i, 0, 1024) pi[i] = 1;
//     priority_queue<pair<double, ii>, vector<pair<double, ii> >, greater<pair<double, ii> > > pq;
//     ii ans;
//     REP(i, 1, n+1) {
//       pq.push(make_pair(pi[i]*1.0/i*1.0, ii(pi[i], i)));
//     }
//     REP(i, 0, k) {
//       ans = pq.top().second;
//       double t = pq.top().first;
//       while(!pq.empty() && t == pq.top().first) {
//         ii p = pq.top().second;
//         pi[p.second]++;
//         pq.push(make_pair(pi[p.second]*1.0/p.second*1.0, ii(pi[p.second], p.second)));
//         pq.pop();
//       }
//       pi[ans.second]++;
//       pq.push(make_pair(pi[ans.second]*1.0/ans.second*1.0, ii(pi[ans.second], ans.second)));
//     }
//     printf("%d/%d\n", ans.first, ans.second);
//   }
//   return 0;
// }

// a better solvetion

int main() {
  int n, k;
  while(scanf("%d %d", &n, &k) == 2) {
    int a0 = 0, b0 = 1, a1 = 1, b1 = n;
    REP(i, 1, k) {
      int k = (n+b0)/b1;
      int c = k * a1 - a0;
      int d = k * b1 - b0;
      a0 = a1, a1 = c;
      b0 = b1, b1 = d;
    }
    printf("%d/%d\n", a1, b1);
  }
  return 0;
}
