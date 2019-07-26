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
char a[1000100];
char b[1000100];
int cnt[1000100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> (a+1) >> (b+1);
  memset(cnt, 0, sizeof cnt);
  int lena = strlen(a+1), lenb = strlen(b+1);
  for(int i=1; i<=lena; i++) {
    if(a[i] == '1') cnt[i] = cnt[i-1] + 1;
    else cnt[i] = cnt[i-1];
  }
  int cntb = 0;
  for(int i=1; i<=lenb; i++) {
    if(b[i] == '1') cntb++;
  }
  int ans = 0;
  for(int i=lenb; i<=lena; i++) {
    if((cnt[i] - cnt[i-lenb])%2 == cntb%2) ans++;
  }
  cout << ans << endl;
  return 0;
}
