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
  int ans[5843] = {0, 1};
  int p2=1, p3=1, p5=1, p7=1;
  REP(i, 1, 5842) {
    while(ans[p2]*2<=ans[i]) p2++;
    while(ans[p3]*3<=ans[i]) p3++;
    while(ans[p5]*5<=ans[i]) p5++;
    while(ans[p7]*7<=ans[i]) p7++;
    int nxt = ans[p2]*2;
    nxt = min(nxt, ans[p3]*3);
    nxt = min(nxt, ans[p5]*5);
    nxt = min(nxt, ans[p7]*7);
    ans[i+1] = nxt;
  }
  int n;
  char str[4][3] = { "th", "st", "nd", "rd" };
  while(scanf("%d", &n), n) {
    int m = 0, ten = n%10, hundred = n%100;
    if(hundred != 11 && hundred != 12 && hundred != 13) m = ten;
    printf("The %d%s humble number is %d.\n", n, str[m<4? m:0], ans[n]);
  }
  return 0;
}
