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
	while(t--){
		int n;
		scanf("%d", &n);
		int a[100003];
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		int f1[100003], f2[100003];
		memset(f1, 0, sizeof(f1));
		memset(f2, 0, sizeof(f2));
		int minn = a[1];
		for(int i=2; i<=n; i++){
			f1[i] = max(f1[i-1], a[i]-minn);
			if(a[i] < minn) minn = a[i];
		}

		int maxn = a[n];
		for(int i=n-1; i>=1; i--){
			f2[i] = max(f2[i+1], maxn-a[i]);

			if(a[i] > maxn) maxn = a[i];
		}
		int ans = 0;
		for(int i=2; i<n; i++){
			if(f1[i] + f2[i+1] > ans) ans = f1[i] + f2[i+1];
		}
		printf("%d\n", ans);
	}
	return 0;
}