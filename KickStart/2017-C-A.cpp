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
#include <climits>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const ll inf = 1e9;
const int mod = 1e9+7;

char s[60];

void solve() {
    char ans[60];
    memset(ans, 0, sizeof ans);
    int len = strlen(s+1);
    s[0] = 'A'; s[len+1] = 'A';
    ans[2] = s[1];
    bool f = true;
    for(int i=3; i<=len; i+=2) {
        char tmp = 0;
        if(ans[i+1] != tmp) tmp = ans[i+1];
        ans[i+1] = (s[i] - 'A' + 26 - (ans[i-1] - 'A'))%26 + 'A';
        if(tmp && ans[i+1] != tmp) {
            f = false;
            break;
        }
    }
    if(!f) {
        printf("AMBIGUOUS\n");
        return;
    }
    if(ans[len-1] && ans[len-1] != s[len]) f = false;
    ans[len-1] = s[len];
    for(int i=len-2; i>=1; i-=2) {
        char tmp = 0;
        if(ans[i-1] != tmp) tmp = ans[i+1];
        ans[i-1] = (s[i] -'A' + 26 - (ans[i+1] - 'A'))%26 + 'A';
        if(tmp && ans[i+1] != tmp) {
            f = false;
            break;
        }
    }
    if(!ans[1] && !ans[len]) f = false;
    if(!f) {
        printf("AMBIGUOUS\n");
    } else {
        ans[len + 1] = '\0';
        printf("%s\n", ans+1);
    }
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    // t = 1;
    while(t--) {
        scanf("%s", s+1);
        printf("Case #%d: ", ++kase);
        solve();
    }
	return 0;
}

