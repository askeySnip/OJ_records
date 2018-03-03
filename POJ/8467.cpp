#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	int f[13][13];
	memset(f, 0, sizeof(f));
	for(int i=0; i<=10; i++) f[0][i] = 1;
	for(int i=0; i<=10; i++) f[i][1] = 1;
	for(int i=1; i<=10; i++){
		for(int j=1; j<=10; j++){
			if(i >= j) f[i][j] = f[i][j-1] + f[i-j][j];
			else f[i][j] = f[i][i];
		}
	}
	while(t--){
		int m, n;
		scanf("%d%d", &m, &n);
		printf("%d\n", f[m][n]);
	}
	return 0;
}