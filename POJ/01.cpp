#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	char s[256];
	gets(s);
	int len = strlen(s);
	int ans = 0;
	for(int i=0; i<len; i++){
		if(s[i]>='0' && s[i] <='9') ans++;
	}	
	cout << ans << endl;
	return 0;
}