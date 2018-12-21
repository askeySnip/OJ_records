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
  const int kmax = 1000003;
  int move[5][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, -1}, {1,0}};
  int mapping[kmax][2] = {}, n;
  for(int count=2, cycle=1; count < kmax; cycle++) {
    for(int i=0; i<5 && count < kmax; i++) {
      if(i == 1) {
        for(int j=0; j<cycle-1 && count < kmax; j++, count++) {
          mapping[count][0] = mapping[count-1][0] - 1;
          mapping[count][1] = mapping[count-1][1] + 1;
        }
      }
      for(int j=0; j<cycle && count<kmax; j++, count++) {
        mapping[count][0] = mapping[count-1][0] + move[i][0];
        mapping[count][1] = mapping[count-1][1] + move[i][1];
      }
    }
  }
  while(scanf("%d", &n) == 1) {
    printf("%d %d\n", mapping[n][0], mapping[n][1]);
  }
  return 0;
}
