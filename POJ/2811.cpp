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
int status[6][8];
int step[6][8];
bool check(){
	int last[8];
	memset(last, 0, sizeof(last));
//	cout << endl;
	for(int i=1; i<=6; i++){
		last[i] = step[1][i] ^ status[1][i] ^ step[1][i-1] ^ step[1][i+1];
//		cout << last[i] << " ";
	}
//	cout << endl;
	for(int i=2; i<=4; i++){
		for(int j=1; j<=6; j++){
			step[i][j] = last[j];
			last[j] = step[i][j] ^ status[i][j] ^ step[i][j-1] ^ step[i-1][j] ^ last[j+1];
//			cout << last[j] << " ";
		}
//		cout << endl;
	}
	for(int i=1; i<=6; i++){
		step[5][i] = last[i];
		last[i] = step[5][i] ^ status[5][i] ^ step[5][i-1] ^ step[4][i] ^ last[i+1];
	}
	for(int i=1; i<=6; i++){
		if(last[i]) return false;
	}
	return true;
}
void print(){
	for(int i=1; i<=5; i++){
		for(int j=1; j<=6; j++){
			printf("%d", step[i][j]);
			if(j!=6) printf(" ");
		}
		printf("\n");
	}
}
int main() {
	for(int i=1; i<=5; i++){
		for(int j=1; j<=6; j++){
			scanf("%d", &status[i][j]);
		}
	}
//	cout << endl;
//	check();
//	print();
	for(int i=0; i<(1<<6); i++){
		memset(step, 0, sizeof(0));
		int t = i;
		for(int j=1; j<=6; j++){
			step[1][j] = t&1;
			t = t >> 1;
		}
		if(check()){
//			cout << endl;
			print();
		}
	}
	return 0;
}