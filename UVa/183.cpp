/*
ID: leezhen
TASK: practice
LANG: C++11                
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

char type, line[55];
int r, c;
char bitmaps[224][224];

bool check_same(int tlr, int tlc, int rbr, int rbc) {
	char check_c = bitmaps[tlr][tlc];
	for(int i=tlr; i<=rbr; i++) {
		for(int j=tlc; j<=rbc; j++) {
			if(bitmaps[i][j] != check_c) return false;
		}
	}
	return true;
}

int ans_len = 0;
char ans[1000000];
void B2D(int tlr, int tlc, int rbr, int rbc) {
	if(tlr > rbr || tlc > rbc) return;
	if(check_same(tlr, tlc, rbr, rbc)) ans[ans_len++] = bitmaps[tlr][tlc];
	else {
		ans[ans_len++] = 'D';
		B2D(tlr, tlc, (rbr+tlr)/2, (rbc+tlc)/2);
		B2D(tlr, (tlc+rbc)/2+1, (rbr+tlr)/2, rbc);
		B2D((tlr+rbr)/2+1, tlc, rbr, (tlc+rbc)/2);
		B2D((rbr+tlr)/2+1, (rbc+tlc)/2+1, rbr, rbc);
	}
}

void read_data_B() {
	int cur_row = 0, cur_col = 0;
	while(1) {
		gets(line);
		if(line[0] =='#') return;
		int len = strlen(line);
		for(int i=0; i<len; i++) {
			if(line[i] == ' ') return;
		}
		for(int i=0; i<len; i++) {
			bitmaps[cur_row][cur_col] = line[i];
			cur_col++;
			if(cur_col == c) {cur_row++; cur_col=0;}
		}
	}
}
char D_bitmap[1000000];
int len_d = 0, cur_p = 0;
void read_data_D() {
	len_d = 0;
	while(1) {
		gets(line);
		if(line[0] == '#') return;
		int len = strlen(line);
		for(int i=0; i<len; i++) {
			if(line[i] == ' ') return;
		}
		for(int i=0; i<len; i++) {
			D_bitmap[len_d++] = line[i];
		}
	}
}

void D2B(int tlr, int tlc, int rbr, int rbc) {
	if(tlr > rbr || tlc > rbc) return;
//	cout << tlr << " " << tlc << " " << rbr << " " << rbc << endl;
	if(D_bitmap[cur_p] == 'D') {
		cur_p++;
		D2B(tlr, tlc, (rbr+tlr)/2, (rbc+tlc)/2);
		D2B(tlr, (tlc+rbc)/2+1, (rbr+tlr)/2, rbc);
		D2B((tlr+rbr)/2+1, tlc, rbr, (tlc+rbc)/2);
		D2B((rbr+tlr)/2+1, (rbc+tlc)/2+1, rbr, rbc);
	}else {
		for(int i=tlr; i<=rbr; i++) {
			for(int j=tlc; j<=rbc; j++) {
				bitmaps[i][j] = D_bitmap[cur_p];
			}
		}
		cur_p++;
	}
}
int main() {
	gets(line);
	while(line[0] != '#') {
		sscanf(line, "%c %d %d", &type, &r, &c);
		if(type == 'B') {
			read_data_B();
			ans_len = 0;
			printf("D%4d%4d\n", r, c);
			B2D(0, 0, r-1, c-1);
			for(int i=0; i<ans_len; i++) {
				printf("%c", ans[i]);
				if(i%50 == 49) printf("\n");
			}
			if((ans_len-1)%50 != 49) printf("\n");
		}else {
			read_data_D();
			cur_p = 0;
			D2B(0, 0, r-1, c-1);
			int cur = 0;
			printf("B%4d%4d\n", r, c);
			for(int i=0; i<r; i++) {
				for(int j=0; j<c; j++) {
					printf("%c", bitmaps[i][j]);
					cur++;
					if(cur%50 == 0) printf("\n");
				}
			}
			if(cur%50) printf("\n");
		}
	}
	return 0;
}