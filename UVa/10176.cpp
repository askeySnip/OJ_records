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
string s, t;
const int mod = 131071;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  while(cin>>s) {
    t = "";
    while(s.back() != '#') {t+=s; cin >> s;}
    t+=s;
    int n = 0;
    int i = t.length()-2;
    int base = 1;
    for(; i>=0; i--) {
      if(t[i] == '1') n += base;
      base = base << 1;
      base %= mod;
      n %= mod;
    }
    if(n%mod == 0) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
