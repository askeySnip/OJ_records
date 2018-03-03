#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
char s[1003];
bool check(int x, int y){
	while(x < y){
		if(s[x] != s[y]) return false;
		else {x++; y--;}
	}
	return true;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		scanf("%s", s+1);
		int f[1003];
		memset(f, 999999, sizeof(f));
		int n = strlen(s+1);
		for(int i=1; i<=n; i++){
			if(check(1, i)) f[i] = 0;
			else {
				for(int j=1; j<i; j++){
					if(check(j+1, i)) f[i] = min(f[i], f[j]+1);
				}
			}
		}
		cout << f[n] << endl;
	}
	return 0;
}