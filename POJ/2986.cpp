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
int n,a[1100],b[1100],ma,mi;
int f(int a[],int b[]){
	int ans=0;
	int l1=1,r1=n,l2=1,r2=n;
	while(l1<=r1&&l2<=r2){
		if(b[r2]>a[r1]){r2--;r1--;ans+=3;}
		else if(b[l2]>a[l1]){l1++;l2++;ans+=3;}
		else if(b[l2]==a[r1]){l2++;r1--;ans+=2;}
		else{r1--;l2++;ans++;}
	}
	return ans;
}
int main(int argc, char *argv[]) {
	while(cin>>n){
		if(n==0)break;
		ma=0;mi=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		ma=f(a,b);
		mi=4*n-f(b,a);
		cout<<ma<<" "<<mi<<endl;
	}
	return 0;
}