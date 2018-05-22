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
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
int main() {
	char s[1000];
	int c = 1;
	while(gets(s)){
		int len = strlen(s);
		for(int i=0; i<len; i++){
			if(s[i] == '\"') {
				if(c%2) printf("``");
				else printf("''");
				c++;
			}
			else printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}