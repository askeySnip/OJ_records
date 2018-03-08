#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;
int main() {
	char s[60];
	map<string, string> mp;
	while(fgets(s, 50, stdin), s[0]!='\n'){
		char s1[60], s2[60];
		sscanf(s, "%s%s", s1, s2);
		string d(s1);
		string p(s2);
		mp[p] = d;
	}
	while(scanf("%s", s) == 1){
		string t(s);
		if(mp.find(t) != mp.end())
			printf("%s\n", mp[t].c_str());
		else 
			printf("eh\n");
	}
	return 0;
}