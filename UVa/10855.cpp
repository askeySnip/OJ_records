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
int bn, sn;
char bs[400][400];
char ss[400][400];
bool eq(int r, int c){
	for(int i=0; i<sn; i++){
		for(int j=0; j<sn; j++){
			if(ss[i][j] != bs[i+r][j+c]) return false;
		}
	}
	return true;
}
int check(){
	int ret = 0;
	for(int i=0; i+sn<=bn; i++){
		for(int j=0; j+sn<=bn; j++){
			if(eq(i, j)) ret++;
		}
	}
	return ret;
}
void rotate90(){
	char ts[400][400];
	memcpy(ts, ss, sizeof ss);
	for(int i=0; i<sn; i++){
		for(int j=0; j<sn; j++){
			ss[j][sn-1-i] = ts[i][j];
		}
	}
}
int main() {
	while(scanf("%d%d", &bn, &sn) == 2 && bn && sn){
		for(int i=0; i<bn; i++){
			scanf("%s", bs[i]);
		}
		
		for(int i=0; i<sn; i++){
			scanf("%s", ss[i]);
		}
		printf("%d ", check());
		rotate90();
		printf("%d ", check());
		rotate90();
		printf("%d ", check());
		rotate90();
		printf("%d\n", check());
	}
	return 0;
}