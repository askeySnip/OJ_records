#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;
int main() {
	char s[1003];
	scanf("%s", s);
	int len = strlen(s);
	for(int i=0; i<len; i++) s[i] = toupper(s[i]);
	char last = s[0];
	int c = 1;
	for(int i=1; i<len; i++){
		if(s[i] != last){
			printf("(%c,%d)", last, c);
			c = 1;
			last = s[i];
		}else{
			c++;
		}
	}
	printf("(%c,%d)", last, c);
	return 0;
}