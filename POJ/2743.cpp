#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	char s1[300], s2[300];
	fgets(s1, 280, stdin);
	fgets(s2, 200, stdin);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i, j;
	for(i=0, j=0; i<len1 && j<len2;i++,j++){
		while(i<len1 && s1[i] == ' ') i++;
		while(j<len2 && s2[j] == ' ') j++;
		if(i==len1 || j==len2 || tolower(s1[i]) != tolower(s2[j])){
			cout << "NO" << endl;
			return 0;
		}
		
	}
	cout << "YES" << endl;
	return 0;
}