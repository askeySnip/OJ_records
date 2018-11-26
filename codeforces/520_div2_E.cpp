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
typedef long long ll;

// struct
#define inf 1e9

// data
int n, q;
vi p;


int main() {
  scanf("%d %d", &n, &q);
  p.resize(n+1);

  int t;
  for(int i=2; i<=n; i++) {
    scanf("%d", &t);
    p[i] = t;

  }
  p[1] = 0;

  return 0;
}
