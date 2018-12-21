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
	int t;
	scanf("%d", &t);
	while(t--) {
		char s[1024];
		scanf("%s", s);
		int len = strlen(s);
		bool flag = false;
		REP(i, 1, len) {
			if(s[i] != s[0]) {
				swap(s[i], s[len-1]);
				flag = true;
				break;
			}
		}
		if(flag == false || len == 1) printf("-1\n");
		else printf("%s\n", s);
	}
	return 0;
}