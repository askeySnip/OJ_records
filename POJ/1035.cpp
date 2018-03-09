#include<cstring>  
#include<cstdio>  
using namespace std;  
char dic[10005][18];  
char s[18];  
int n = 0;  
bool del(char * s1, char * s2){  
	int dif = 0;  
	while(*s1){  
		if(*(s1++) != *s2){  
			if(++dif > 1) return false;  
		}else{  
			s2++;  
		}  
	}  
	return true;  
}  
bool add(char * s1, char * s2){  
	int dif = 0;  
	while(*s2){  
		if(*s1 != *(s2++)){  
			if(++dif > 1) return false;  
		}else{  
			s1++;  
		}  
	}  
	return true;  
}  
bool replace(char * s1, char * s2){  
	int dif = 0;  
	while(*s1){  
		if(*(s1++) != *(s2++)){  
			if(++dif > 1) return false;  
		}  
	}  
	return true;  
}  
int main(){  
	while(scanf("%s",dic[n])&&dic[n][0]!='#')n++;  
	while(scanf("%s",s)&&s[0]!='#'){  
		bool flag = false;  
		for(int i = 0; i < n; ++i){  
			if(strcmp(dic[i], s) == 0){  
				printf("%s is correct\n",s);  
				flag = true;  
				break;  
			}  
		}  
		if(flag) continue;  
		printf("%s:",s);  
		int len1 = strlen(s), len2;  
		for(int i = 0; i < n; ++i){  
			if((len2 = strlen(dic[i])) - len1 == 1){  
				if(del(dic[i],s)) printf(" %s",dic[i]);  
			}else if(len2 - len1 == -1){  
				if(add(dic[i], s)) printf(" %s",dic[i]);  
			}else if(len2 == len1){  
				if(replace(dic[i],s)) printf(" %s", dic[i]);  
			}  
		}  
		putchar('\n');  
	}  
	return 0;  
}  