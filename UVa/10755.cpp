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
#include <climits>
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

int a, b, c;
ll pieces[23][23][23];
ll maxV(ll tmp[23], int n) {
  ll ret = LLONG_MIN, sum = 0;
  for(int i=0; i<n; i++) {
    if(sum <= 0) sum = tmp[i];
    else sum += tmp[i];
    if(sum > ret) ret = sum;
  }
  return ret;
}
int main() {
  int t;
  scanf("%d", &t);
  // int a, b, c;
  // int pieces[23][23][23];
  memset(pieces, 0, sizeof pieces);
  while(t--) {
    scanf("%d %d %d", &a, &b, &c);
    ll ans = LLONG_MIN;
    ll t1[23][23], t2[23];
    for(int i=0; i<a; i++) {
      for(int j=0; j<b; j++) {
        for(int k=0; k<c; k++) {
          scanf("%lld", &pieces[i][j][k]);
        }
      }
    }
    for(int i=0; i<a; i++) {
      memset(t1, 0, sizeof t1);
      for(int k=i; k<a; k++) {
        for(int l = 0; l<b; l++) {
          for(int m=0; m<c; m++) {
            t1[l][m] += pieces[k][l][m];
          }
        }

        for(int p=0; p<b; p++) {
          memset(t2, 0, sizeof t2);
          for(int l=p; l<b; l++) {
            for(int m=0; m<c; m++) {
              t2[m] += t1[l][m];
            }
            ll maxv = maxV(t2, c);
            if(maxv > ans) {
              ans = maxv;
            }
          }
        }
      }
    }
    printf("%lld\n", ans);
    if(t) printf("\n");
  }
  return 0;
}
