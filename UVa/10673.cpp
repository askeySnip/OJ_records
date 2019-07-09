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
int n, k;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &k);
    if(n%k == 0) {
      printf("%d 0\n", k);
    } else {
      printf("%d %d\n", -n, n);
    }
  }
  return 0;
}
