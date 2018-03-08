#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main(){
	char str[81];
	char change[81];
	int a[81],b[81],c[81];
	int i,len;
	int k1,k2,k3,num1,num2,num3;

	while(scanf("%d %d %d",&k1,&k2,&k3) && k1 && k2 && k3){
		num1 = num2 = num3 = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(change,0,sizeof(change));

		scanf("%s",str);
		len = strlen(str);
		for( i = 0 ; i < len ; i++ ){
			if( str[i] >= 'a' && str[i] <= 'i' )
				a[num1++] = i;
			else if( str[i] >= 'j' && str[i] <= 'r')
				b[num2++] = i;
			else 
				c[num3++] = i;
		}

		for( i = 0 ; i < num1 ; i++)
			change[a[(i+k1)%num1]] = str[a[i]];
		for( i = 0 ; i < num2 ; i++)
			change[b[(i+k2)%num2]] = str[b[i]];
		for( i = 0 ; i < num3 ; i++)
			change[c[(i+k3)%num3]] = str[c[i]];

		change[len] = '\0';
		puts(change);		
	}
	
	return 0;
}