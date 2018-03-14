/*
ID: leezhen1
TASK: practice
LANG: C++14                 
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
#include <cmath>

using namespace std;
int main(){  
	int k,n1,n2,n3,n4,n5;  
	int a,b,c,d,e,len;  
	cin>>k>>n1>>n2>>n3>>n4>>n5;  
	for(len=1;len<=k*100;len++){  
		for(a=1;a<=len;a++){  
			b=len-a*n1;  
			c=len-b*n2;  
			d=len-c*n3;  
			e=len-d*n4;  
			if(a==b||a==c||a==d||a==e||b==c||b==d||b==e||c==d||c==e||d==e)continue;  
			if(e*n5+a==len){  
				printf("%d %d %d %d %d %d",len,a,b,c,d,e);  
				return 0;  
			}  
		}  
	}  
	printf("not found");  
	return 0; 
}