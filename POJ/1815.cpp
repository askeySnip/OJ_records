#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cmath>

using namespace std;
int n, ans = 10000;
int status[20][20];
int last[20], step[20];
int check(int c){
	memset(last, 0, sizeof(last));
//	cout << "!";
//	step[0] = 0;
	for(int i=1; i<=n; i++){
//		cout << "!";
		last[i] = status[1][i] ^ step[i] ^ step[i-1] ^ step[i+1];
//		cout << last[i] << " ";
	}
	for(int i=2; i<=n; i++){
		for(int j=1; j<=n; j++){
			int t = last[j];
//			if(step[j]) c++;
			last[j] = step[j-1] ^ step[j] ^ status[i][j] ^ last[j+1] ^ last[j];
			step[j] = t;
			if(t) c++;
		}
	}
	for(int i=1; i<=n; i++){
		if(last[i]) return 10000;
	}
	return c;
}
int main() {
	scanf("%d", &n);
	memset(status, 0, sizeof(status));
	char s[20];
	for(int i=1; i<=n; i++){
		scanf("%s", s+1);
		for(int j=1; j<=n; j++){
			if(s[j] == 'w') status[i][j] = 1;
		}
	}
	memset(step, 0, sizeof(step));
	for(int i=0; i<(1<<n); i++){
		int t = i, c=0;
		for(int i=1; i<=n; i++){
			step[i] = t&1;
			if(step[i]) c++;
			t = t >> 1;
		}
		int w = check(c);
//		cout << i << " " << w << " ";
		ans = min(w, ans);
	}
	if(ans == 10000) cout << "inf" << endl;
	else cout << ans << endl;
	return 0;
}