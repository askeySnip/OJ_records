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
  int q, b, w;
  cin >> q;
  while(q--) {
    cin >> b >> w;
    if(b * 3 + 1 < w || w * 3 + 1 < b) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    if(b > w) {
      for(int i=3; i<=1e9; i++) {
        cout << "2 " << i << endl;
        if(i%2 == 0) {
          w--;
          if(b == 0) break;
        } else {
          b--;
          if(w == 0) break;
        }
      }
      if(b > 0) {
        for(int i=4; i<=1e9; i+=2) {
          cout << "1 " << i << endl;;
          b--;
          if(b == 0) break;
          cout << "3 " << i << endl;
          b--;
          if(b==0) break;
        }
      } else {
        for(int i=3; i<=1e9; i+=2) {
          if(w == 0) break;
          cout << i << " 1" << endl;
          w--;
          if(w == 0) break;
          cout << i << " 3" << endl;
          w--;
          if(w == 0) break;
        }
      }
    } else {
      for(int i=3; i<=1e9; i++) {
        cout << "3 " << i << endl;
        if(i%2 == 0) {
          b--;
          if(w == 0) break;
        } else {
          w--;
          if(b == 0) break;
        }
      }
      if(b > 0) {
        for(int i=3; i<=1e9; i+=2) {
          cout << "2 " << i << endl;
          b--;
          if(b == 0) break;
          cout << "4 " << i << endl;
          b--;
          if(b == 0) break;
        }
      } else {
        for(int i=4; i<=1e9; i+=2) {
          if(w == 0) break;
          cout << "2 " << i << endl;
          w--;
          if(w == 0) break;
          cout << "4 " << i << endl;
          w--;
          if(w == 0) break;
        }
      }
    }
  }
  return 0;
}
