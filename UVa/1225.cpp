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
vi nums;

void deal(int n) {
  while(n) {
    nums[n%10]++;
    n/=10;
  }
}

int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    nums.assign(10, 0);
    REP(i, 1, n+1) {
      deal(i);
    }
    REP(i, 0, 10) {
      if(i) printf(" ");
      printf("%d", nums[i]);
    }
    printf("\n");
  }
  return 0;
}
