/*
ID: leezhen1
TASK: S-Trees
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
int n;
int orders[10];
char leveas[300];
char query[10];
char check(){
	int ans = 1;
	for(int i=0; i<n; i++){
		char ch = query[orders[i]];
		if(ch == '0') ans *= 2;
		else ans = ans * 2 + 1;
	}
	ans -= (1<<n);
	return leveas[ans];
}
int main() {
	int kase = 0;
	while(scanf("%d", &n) == 1 && n){
		char xi[10];
		int t;
		for(int i=0; i<n; i++){
			scanf("%s", xi);
			orders[i] = xi[1]-'0'-1;
//			cout << xi[1] << endl;
		}
		scanf("%s", leveas);
		scanf("%d", &t);
		printf("S-Tree #%d:\n", ++kase);
		for(int i=0; i<t; i++){
			scanf("%s", query);
			printf("%c", check());
		}
		printf("\n\n");
	}
	return 0;
}