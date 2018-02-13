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
	for(int i=0; i<t; i++){
		char s[1000+2];
		int k;
		scanf("%s", s);
		cout << s;
//		scanf("%d", &k);
//		cout << k;
		int ans = 0;
		for(int j=0; j<=strlen(s)-k; j++){
			if(s[j] == '-'){
				int l = 0;
				while(l < k){
					s[j+l] = s[j+l] == '-'? '+':'-';
					l++;
				}
				ans++;
			}
		}
		bool f = true;
		while(k){
			if(s[strlen(s)-k] == '-'){
				f = false;
				break;
			}
		}
		if(!f){
			printf("Case #%d: IMPOSSIBLE\n", i+1);
		}else{
			printf("Case #%d: %d\n", i+1, ans);
		}
	}
	return 0;
}