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
int n, k;
double s[10024];

bool check(double t) {
  int cnt = 0;
  REP(i, 0, n) {
    cnt += (int)(s[i] / t);
  }
  return cnt >= k;
}

int main() {
  scanf("%d %d", &n, &k);
  REP(i, 0, n) {
    scanf("%lf", &s[i]);
  }
  double l = 0, h = inf, mid;
  while(h - l > 0.0000001) {
    mid = (l + h) / 2;
    if(check(mid)) l = mid;
    else h = mid;
  }
  printf("%.2f\n", floor(h*100)/100); // 向下取整
  return 0;
}
