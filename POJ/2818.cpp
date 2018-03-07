#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n;
	int a[203];
	int d[203];
	while(cin >> n){
		if(!n) break;
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
			a[i]--;
		}
		for(int i=0; i<n; i++){
			int j;
			j = a[i];
			int c = 1;
			while(j!=i){
				j = a[j];
				c++;
			}
			d[i] = c;
//			cout << d[i] << endl;
		}
		int k;
		while(cin >> k){
			if(!k) break;
			getchar();
			char s[203];
			gets(s);
			int len = strlen(s);
			for(int i=len; i<n; i++) s[i] = ' ';
			s[n] = '\0';
//			cout << s << endl;
			char out[203];
			strcpy(out, s);
			for(int i=0; i<n; i++){
				int t = k%d[i];
				int p=i;
				while(t--){
					p = a[p];
				}
//				cout << i << " " << p << endl;
				out[p] = s[i];
			}
			printf("%s\n", out);
		}
		cout << endl;
	}
	return 0;
}