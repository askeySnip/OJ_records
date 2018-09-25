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
int main() {
  int a[100024], order[100024];
  int n = 0;
  vi v;
  memset(order, 0, sizeof order);
  while(scanf("%d", &a[n]) != EOF) {
    auto it = lower_bound(v.begin(), v.end(), a[n]);
    if(it == v.end()) {order[n] = v.size(); v.push_back(a[n]);}
    else {*it = a[n]; order[n] = it-v.begin();}
    n++;
  }

  int len = v.size();
  printf("%d\n-\n", len);
  stack<int> stk;
  for(int i=n-1; i>=0; i--) {
    if(order[i] == len-1) {
      stk.push(a[i]);
      len--;
    }
  }
  while(!stk.empty()) {
    printf("%d\n", stk.top());
    stk.pop();
  }
  return 0;
}
