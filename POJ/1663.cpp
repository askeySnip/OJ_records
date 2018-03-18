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
#include <cmath>

using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int pos[1000000];
	memset(pos, 0, sizeof(pos));
	pos[0] = 0;
	pos[1] = 1;
	for(int i=1; i<1000000-1; i+=2){
		pos[i] = pos[i-1]+1;
		pos[i+1] = pos[i]+3;
	}
	while(n--){
		int x, y;
		scanf("%d%d", &x, &y);
		if(x != y && x != y+2){
			printf("No Number\n");
		}else{
			if(x == y){
				printf("%d\n", pos[x]);
			}else{
				printf("%d\n", pos[x]-2);
			}
		}
	}
	return 0;
}