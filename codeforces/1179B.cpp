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
  int n, m;
  cin >> n >> m;
  REP(i, 0, n/2) {
    REP(j, 0, m) {
      // cout << i+1 << " " << j+1 << endl;
      // cout << n - i << " " << m - j << endl;
      printf("%d %d\n", i+1, j+1);
      printf("%d %d\n", n-i, m-j);
    }
  }
  if(n%2) {
    int t = n/2+1;
    deque<int> dq;
    REP(i, 0, m) {
      dq.push_back(i+1);
    }
    while(!dq.empty()) {
      //cout << n/2+1 << " " << dq.front() << endl;
      printf("%d %d\n", t, dq.front());
      dq.pop_front();
      if(!dq.empty()){
        //cout << n/2+1 << " " << dq.back() << endl;
        printf("%d %d\n", t, dq.back());
        dq.pop_back();}
    }
  }
  return 0;
}
