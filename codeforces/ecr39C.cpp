#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
char s[100010];
int main() {
	scanf("%s", s);
	int n = strlen(s);
	char c = 'a';
	string out;
	for(int i=0; i<n; i++){
		if(c>'z' || s[i] > c) continue;
		s[i] = c++;
	}
	if(c>'z') cout << s << endl;
	else cout << "-1" << endl;
	return 0;
}