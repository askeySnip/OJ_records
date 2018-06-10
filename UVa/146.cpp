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
char s[60];
int c[26];
int len;
int main() {
	while(scanf("%s", s) == 1 && s[0] != '#'){
		memset(c, 0, sizeof c);
		len = strlen(s);
		bool flag = true;
		int i;
		for(i=len-1; i>0; i--){
			if(s[i]>s[i-1]) {
				flag = false;
				break;
			}
		}
		if(flag) printf("No Successor\n");
		else {
			for(int j=i-1; j<len; j++){
				c[s[j]-'a']++;
			}
			for(int j=s[i-1]+1-'a'; j<26; j++){
				if(c[j]) {
					s[i-1] = j+'a';
					c[j]--;
					break;
				}
			}
			for(int j=0; j<26; j++){
				if(c[j]){
					while(c[j]){
						s[i++] = j+'a';
						c[j]--;
					}
				}
			}
			printf("%s\n", s);
		}
	}
	return 0;
}