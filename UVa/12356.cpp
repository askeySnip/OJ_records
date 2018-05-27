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
int l[100000+20];
int r[100000+20];
int dead[100000+20];
int main() {
	int s, b;
	while(scanf("%d%d", &s, &b) == 2 && s && b){
		for(int i=1; i<=s; i++) l[i] = i-1;
		for(int i=0; i<s; i++) r[i] = i+1;
		r[s] = 0;
		memset(dead, 0, sizeof(dead));
		int lm = 1, rm = s;
		int le, ri;
		for(int i=0; i<b; i++){
			scanf("%d%d", &le, &ri);
			for(int j=le; j<=ri; j++){
				dead[j] = 1;
			}
			for(int j=le; j<=ri; j++){
				l[j] = l[le];
				r[j] = r[ri];
				while(dead[l[j]]) l[j] = l[l[j]];
				while(dead[r[j]]) r[j] = r[r[j]];
			}
			r[le-1] = r[ri];
			l[ri+1] = l[le];
			int tl = l[le], tr = r[ri];
			if(tl == 0) printf("* ");
			else printf("%d ", tl);
			if(tr == 0) printf("*\n");
			else printf("%d\n", tr);
		}
		printf("-\n");
	}
	return 0;
}