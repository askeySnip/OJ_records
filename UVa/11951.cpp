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
  int t;
  scanf("%d", &t);
  long long n, m, k;
  long long p[103][103];
  int kase = 0;
  while(t--) {
    scanf("%lld %lld %lld", &n, &m, &k);
    for(long long i=0; i<n; i++) {
      for(long long j=0; j<m; j++) {
        scanf("%lld", &p[i][j]);
        if(i > 0) p[i][j] += p[i-1][j];
        if(j > 0) p[i][j] += p[i][j-1];
        if(i > 0 && j > 0) p[i][j] -= p[i-1][j-1];
      }
    }
    // for(long long i=0; i<n; i++) {
    //   for(long long j=0; j<m; j++) {
    //     cout << p[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    long long ans = 0L, price = 0L;
    for(long long i=0; i<n; i++) {
      for(long long j=0; j<m; j++) {
        for(long long w=1; i+w-1<n; w++) {
          for(long long h=1; j+h-1<m; h++) {
            if(w*h < ans) continue;
            long long t = p[i+w-1][j+h-1];
            if(i > 0) t -= p[i-1][j+h-1];
            if(j > 0) t -= p[i+w-1][j-1];
            if(i > 0 && j > 0) t += p[i-1][j-1];
            if(t > k) break;
            if(ans < w * h || (ans == w*h && t < price)) {
              ans = w * h;
              price = t;
              // cout << w << " " << h << " " << i << " " << j << " " << price << endl;
            }
          }
        }
      }
    }
    printf("Case #%d: %lld %lld\n", ++kase, ans, price);
  }
}
