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

// struct
#define inf 1e6

// data
int n;
int dist1[26][26], dist2[26][26];

int main() {
  while(scanf("%d", &n), n) {
    if(n == 0) break;
    getchar();
    for(int i=0; i<26; i++) {
      for(int j=0; j<26; j++) {
        if(i == j) {dist1[i][j] = 0; dist2[i][j] = 0;}
        else {dist1[i][j] = dist1[j][i] = inf; dist2[i][j] = dist2[j][i] = inf;}
      }
    }
    char a, b, c, d;
    int cost;
    for(int i=0; i<n; i++) {
      scanf("%c %c %c %c %d", &a, &b, &c, &d, &cost);
      if(a == 'M'){
        if(b == 'U') dist2[c-'A'][d-'A'] = min(dist2[c-'A'][d-'A'], cost);
        else {
          dist2[c-'A'][d-'A'] = min(dist2[c-'A'][d-'A'], cost);
          dist2[d-'A'][c-'A'] = min(dist2[d-'A'][c-'A'], cost);
        }
      }else {
        if(b == 'U') dist1[c-'A'][d-'A'] = min(dist1[c-'A'][d-'A'], cost);
        else {
          dist1[c-'A'][d-'A'] = min(dist1[c-'A'][d-'A'], cost);
          dist1[d-'A'][c-'A'] = min(dist1[d-'A'][c-'A'], cost);
        }
      }
      getchar();
    }

    for(int k=0; k<26; k++) {
      for(int i=0; i<26; i++) {
        for(int j=0; j<26; j++) {
          dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
          dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]);
        }
      }
    }
    scanf("%c %c", &a, &b); getchar();
    int s = a-'A', e = b-'A';
    int ans = inf;
    vi printlist;
    for(int i=0; i<26; i++) {
      if(dist1[s][i] + dist2[e][i] < ans) {
        ans = dist1[s][i] + dist2[e][i];
        printlist.clear();
        printlist.push_back(i);
      }else if(dist1[s][i] + dist2[e][i] == ans) {
        printlist.push_back(i);
      }
    }
    if(ans == inf) printf("You will never meet.\n");
    else {
      printf("%d", ans);
      sort(printlist.begin(), printlist.end());
      for(int i=0; i<(int)printlist.size(); i++) {
        printf(" %c", printlist[i]+'A');
      }
      printf("\n");
    }
  }
  return 0;
}
