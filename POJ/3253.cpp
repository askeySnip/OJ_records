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
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
int n;
int p[20024];

int main() {
  scanf("%d", &n);
  REP(i, 0, n) scanf("%d", &p[i]);
  priority_queue<int, vi, greater<int> > pq;
  REP(i, 0, n) pq.push(p[i]);
  ll ans = 0;
  while(pq.size() > 1) {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    ans += a + b;
    pq.push(a+b);
  }
  printf("%lld\n", ans);
  return 0;
}
