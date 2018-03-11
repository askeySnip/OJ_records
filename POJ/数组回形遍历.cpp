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
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
int main() {
	int row, col;
	scanf("%d%d", &row, &col);
	int array[103][103];
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			scanf("%d", &array[i][j]);
		}
	}
	int px=0, py=0, i=1, rl=0, rh=row, cl=0, ch=col;
	cout << array[px][py] << endl;
	while(1){
		for(int j=0; j<4; j++){
			px+=x[j];
			py+=y[j];
			while(px<rh && px>=rl && py>=cl && py<ch){
				cout << array[px][py] << endl;
				i++;
				if(i == row * col) return 0;
				px+=x[j];
				py+=y[j];
			}
			switch (j) {
				case 0: rl++; break;
				case 1: ch--; break;
				case 2: rh--; break;
				case 3: cl++; break;
			}
			px-=x[j];
			py-=y[j];
//			cout << "rlchrhcl" << rl <<" " << ch << " " << rh << " " <<rl <<endl;
		}
	}
	return 0;
}