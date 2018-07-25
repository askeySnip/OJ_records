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
char s[120];

int main() {
	vector<vector<char> > stacks(30);
	int ks = 1;
	while(gets(s), s[0] != 'e') {
		int ans = 1;
		int len = strlen(s);
		stacks.clear();
		stacks[ans-1].push_back(s[0]);
		for(int i=1; i<len; i++) {
			bool flag = false;
			for(int j=0; j<ans; j++) {
				if(stacks[j].back() >= s[i]) {
					stacks[j].push_back(s[i]);
					flag = true;
					break;
				}
			}
			if(!flag) {
				stacks[ans++].push_back(s[i]);
			}
		}
		printf("Case %d: %d\n", ks++, ans);
	}
	
	return 0;
}