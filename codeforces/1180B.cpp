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


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  int a[100024];
  cin >> n;
  REP(i, 0, n) cin >> a[i];
  REP(i, 0, n) {
    if(a[i] >= 0) a[i] = -a[i] - 1;
  }
  if(n%2){
    int minid = 0;
    REP(i, 0, n) {
      if(a[i] < a[minid]) {
        minid = i;
      }
    }
    a[minid] = -a[minid] - 1;
  }
  REP(i, 0, n) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
