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
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
bool ex[1<<18];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  ex[0] = 1;
  vector<int> v;
  v.push_back(0);
  REP(i, 1, 1<<n) {
    if(ex[i ^ x]) continue;
    v.push_back(i);
    ex[i] = 1;
  }
  printf("%d\n", (int)v.size()-1);
  REP(i, 1, v.size()) {
    printf("%d ", v[i] ^ v[i-1]);
  }
  return 0;
}
