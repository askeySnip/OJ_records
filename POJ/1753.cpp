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
int status[6][6];
int last[6];
int step[6];
int tmp[6];
int check(int d, int c){
	memcpy(tmp, step, sizeof(tmp));
//	memset(last, d, sizeof(last));
    last[0] = d; last[5] = d;
    tmp[0] = 0; tmp[5] = 0;
	for(int i=1; i<=4; i++){
		last[i] = status[1][i] ^ tmp[i] ^ tmp[i+1] ^ tmp[i-1];
//		cout << last[i] << " ";
	}
//	cout << last[5] << endl;
	for(int i=2; i<=4; i++){
		for(int j=1; j<=4; j++){
//			tmp[j] = last[j] ^ d;
//			if(tmp[j] == 1) c++;
//			last[j] = status[i][j] ^ tmp[j] ^ last[j+1]^d ^ tmp[j-1] ^ last[j] ^ d;
			int t = last[j] ^ d;
			last[j] = status[i][j] ^ tmp[j] ^ last[j+1] ^ tmp[j-1] ^ last[j];
			tmp[j] = t;
			if(tmp[j] == 1) c++;
//			cout << last[j] << " ";
		}
//		cout << endl;
	}
//	cout << d << " " << c << endl;
	for(int i=1; i<=4; i++){
		if(last[i] != d) return 1000;
	}
//	cout << c << endl;
	return c;
}
int main() {
	char s[6];
	memset(status, 0, sizeof(status));
	for(int i=1; i<=4; i++){
		scanf("%s", s);
		for(int j=0; j<4; j++){
			if(s[j] == 'b') status[i][j+1] = 0;
			else status[i][j+1] = 1;
		}
	}
	int ans = 1000;
	memset(step, 0, sizeof(step));
	for(int i=0; i<(1<<4); i++){
		int t = i;
		int c = 0;
//		cout << i << endl;
		for(int j=1; j<=4; j++){
			step[j] = t&1;
			if(step[j]) c++;
			t= t >> 1;
		}
//		cout << c << endl;
		int ret = min(check(0, c), check(1, c));
//		int ret = check(1, c);
		ans = min(ret, ans);
	}
	if(ans != 1000) cout << ans << endl;
	else cout << "Impossible" << endl;
	return 0;
}