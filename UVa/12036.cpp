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


int main() {
  int t, n;
  scanf("%d", &t);
  int counts[103];
  int kase = 0;
  while(t--) {
    memset(counts, 0, sizeof counts);
    scanf("%d", &n);
    int a;
    REP(i, 0, n) {
      REP(j, 0, n) {
        scanf("%d", &a);
        counts[a]++;
      }
    }
    bool flag = true;
    REP(i, 0, 103) {
      if(counts[i] > n) flag = false;
    }

    if(flag) printf("Case %d: yes\n", ++kase);
    else printf("Case %d: no\n", ++kase);
  }
  return 0;
}
