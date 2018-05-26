/*
ID: leezhen1
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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
char s[10500];
int main() {
	int t;
	gets(s);
	sscanf(s, "%d", &t);
	while(t--){
		int n;
		gets(s);
		sscanf(s, "%d", &n);
		map<char, int> mp;
		char c;
		int v;
		for(int i=0; i<n; i++){
			gets(s);
			sscanf(s, "%c %d", &c, &v);
			mp[c] = v;
		}
		gets(s);
		sscanf(s, "%d", &n);
		int tot = 0;
		for(int i=0; i<n; i++){
			gets(s);
			int len = strlen(s);
			for(int j=0; j<len; j++){
				if(mp.find(s[j]) != mp.end()) tot+=mp[s[j]];
			}
		}
		printf("%d.", tot/100);
		int r = tot%100;
		if(0<r && r < 10) printf("0%d$\n", r);
		else if(r == 0) printf("00$\n");
		else printf("%d$\n", r);
	}
	return 0;
}