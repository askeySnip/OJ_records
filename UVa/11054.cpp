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

// data
int n;

int main() {
  while(scanf("%d", &n), n){
    int t;
    ll ans = 0, last = 0;;
    for(int i=0; i<n; i++) {
      ans += abs(last);
      scanf("%d", &t);
      last += t;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
