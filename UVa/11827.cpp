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
int a[103];

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  int n;
  scanf("%d", &n);
  REP(i, 0, n) {
    int cnt = 0;
    char c;
    // scanf("%d", &a[cnt++]);
    // while((c=getchar()) != '\n') {
    //   scanf("%d", &a[cnt++]);
    // }
    while(true) {
      scanf("%d", &a[cnt++]);
      while((c=getchar()) == ' ');
      ungetc(c, stdin);
      if(c == 10 || c == -1) break;
    }
    int ans = 0;
    REP(j, 0, cnt) {
      REP(k, j+1, cnt) {
        ans = max(ans, gcd(a[j], a[k]));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
