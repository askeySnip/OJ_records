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
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
	int n;
	scanf("%d", &n);
	char s[1024];
	scanf("%s", s);
	int len = strlen(s);
	bool flag = false;
	REP(i, 1, len) {
		if(s[i] != s[i-1]) {
			printf("YES\n");
			printf("%c%c\n", s[i-1], s[i]);
			flag = true;
			break;
		}
	}
	if(!flag) printf("NO\n");
	
	return 0;
}