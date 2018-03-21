/*
ID: leezhen1
TASK: practice
LANG: C++14                 
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
const int maxn = 100000+5;
int last, cur, nnext[maxn];
char s[maxn];
int main() {
	while(scanf("%s", s+1) == 1){
		int n = strlen(s+1);
		last = cur = 0;
		nnext[cur] = 0;
		for(int i=1; i<=n; i++){
			char ch = s[i];
			if(ch == '[') cur = 0;
			else if(ch == ']') cur = last;
			else{
				nnext[i] = nnext[cur];
				nnext[cur] = i;
				if(cur == last) last = i;
				cur = i;
			}
		}
		for(int i=nnext[0]; i!=0; i=nnext[i]){
			printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}