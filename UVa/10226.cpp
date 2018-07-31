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
map<string, int> mp;
int tot = 0;
void solve() {
	for(auto it = mp.begin(); it != mp.end(); it++) {
		printf("%s %.4f\n", it->first.c_str(), it->second*100.0/tot);
	}
}
int main() {
	char s[30];
	int c;
	gets(s);
	sscanf(s, "%d", &c);
	gets(s);
	while(gets(s)) {
		if(s[0] == '\0') {
			solve();
			printf("\n");
			mp.clear();
			tot = 0;
			continue;
		}
		string spe(s);
		mp[spe]++;
		tot++;
	}
	solve();
	return 0;
}