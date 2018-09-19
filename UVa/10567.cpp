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
int main() {
	char s[1000024];
	scanf("%s", s);
	int len = strlen(s);
	vi v[100];
	for(int i=0; i<len; i++) {
		v[s[i]-'A'].push_back(i);
	}
	int q;
	scanf("%d", &q);
	char ss[103];
	for(int i=0; i<q; i++) {
		scanf("%s", ss);
		int lenss = strlen(ss);
		bool match = true;
		int id = -1;
		int start = 0;
		for(int i=0; i<lenss; i++) {
			auto it = upper_bound(v[ss[i]-'A'].begin(), v[ss[i]-'A'].end(), id);
			if(it == v[ss[i]-'A'].end()) {
				match = false;
				break;
			}
			id = (*it);
			if(!i) start = id;
		}
		if(!match) printf("Not matched\n");
		else printf("Matched %d %d\n", start, id);
	}
	return 0;
}