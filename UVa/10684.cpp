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
  int n;
  int a;
  while(scanf("%d", &n), n) {
    int ans = 0, t = 0;
    for(int i=0; i<n; i++) {
      scanf("%d", &a);
      t += a;
      ans = max(t, ans);
      if(t < 0) t = 0;
    }
    if(ans > 0) printf("The maximum winning streak is %d.\n", ans);
    else printf("Losing streak.\n");
  }
}
