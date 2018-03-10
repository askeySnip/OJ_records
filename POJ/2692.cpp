#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>

using namespace std;
char Left[3][10];
char Right[3][10];
char Result[3][10];
bool mask[30];//硬币状态存储
bool is_fake(char c, bool light){
	char *pleft = nullptr, *pright = nullptr;
	for(int i=0; i<3; i++){
		pleft = Left[i];
		pright = Right[i];
		switch (Result[i][0]) {
			case 'u': 
				if((light && strchr(pright, c)==nullptr) || (!light && strchr(pleft, c)==nullptr)) 
					return false;
				break;
			case 'd':
				if((light && strchr(pleft, c)==nullptr) || (!light && strchr(pright, c)==nullptr))
					return false;
				break;
			case 'e':
				if(strchr(pleft, c) || strchr(pright, c))
					return false;
				break;
		}
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	while(n--){
		memset(Left, '\0', sizeof(Left));
		memset(Right, '\0', sizeof(Right));
		memset(Result, '\0', sizeof(Result));
		memset(mask, false, sizeof(mask));
		for(int i=0; i<3; i++){
			scanf("%s%s%s", Left[i], Right[i], Result[i]);
			if(!strcmp(Result[i], "even")){
				for(int j=0; j<strlen(Left[i]); j++){
					mask[Left[i][j] - 'A'] = mask[Right[i][j] - 'A'] = true;
				}
			}
		}
		for(int i=0; i<12; i++){
			if(mask[i]) continue;
			char t = i + 'A';
			if(is_fake(t, true)){
				printf("%c is the counterfeit coin and it is light.\n", t);
				break;
			}
			if(is_fake(t, false)){
				printf("%c is the counterfeit coin and it is heavy.\n", t);
				break;
			}
		}
	}
	return 0;
}