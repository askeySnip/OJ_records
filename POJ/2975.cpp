#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char s[400];
	while(fgets(s, 300, stdin)){
		if(strlen(s) > 7) break;
		fgets(s, 300, stdin);
		for(int i=0; i<strlen(s); i++){
			if(s[i] >='A' && s[i] <= 'Z'){
				printf("%c", (s[i]-'A'+21)%26+'A');
			}else{
				printf("%c", s[i]);
			}
		}
		fgets(s, 300, stdin);
	}
	return 0;
}