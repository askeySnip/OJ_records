#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned int uint;

#define MAX 64
#define NW 1
#define NE 2
#define SW 3
#define SE 4

void code_to_img(int n);
void img_to_code(int n);
void divide(int code,int len, int i, int j);
bool pure(int len, int i, int j);
void pour(int len, int i, int j);
int rev(int code);
int five_to_ten(int num);
int ten_to_five(int num);

int img[MAX][MAX];
vector<int> ans;

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	bool first=true;
	int count=0;
	int n;
	while(cin >> n) {
		if(n==0) break;

		if(n>0) {
			if(first==false) printf("\n\n");
			else first=false;
			printf("Image %d\n",++count);
			img_to_code(n);
		} else {
			if(first==false) printf("\n");
			else first=false;
			printf("Image %d\n",++count);
			code_to_img(n);
		}
	}
	printf("\n");
	return 0;
}

void code_to_img(int n) {
	n=-n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			img[i][j]=0;
		}
	}
	int temp;
	while(cin >> temp) {
		if(temp==-1) break;
		temp=ten_to_five(temp);
		int len=n;
		int i=0,j=0;
		while(temp!=0) {
			len/=2;
			switch(temp%10) {
			case SW:
				i+=len;
				break;
			case NE:
				j+=len;
				break;
			case SE:
				i+=len;
				j+=len;
				break;
			case NW:
				break;
			}
			temp/=10;
		}
		pour(len,i,j);
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(img[i][j]==1) printf("*");
			else if(img[i][j]==0) printf(".");
			else printf("x");
		}
		if(i!=n-1) printf("\n");
	}
}

void img_to_code(int n) {
	ans.erase(ans.begin(),ans.end());

	char c;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> c;
			img[i][j]=c-48;
		}
	}

	divide(0, n, 0,0);
	sort(ans.begin(),ans.end());
	for(uint i=0; i<ans.size(); i++) {
		if(i%12==0&&i!=0) printf("\n");
		if(i!=(ans.size()-1) && (i%12!=11)) printf("%d ",ans[i]);
		else printf("%d",ans[i]);
	}
	if(ans.size()!=0) printf("\n");
	printf("Total number of black nodes = %d\n", ans.size());
}

void divide(int code,int len, int i, int j) {
	if(pure(len,i,j)==1) {
		if(img[i][j]==1) {
			ans.push_back(five_to_ten(rev(code)));
		}
		return;
	}
	divide(code*10+SE,len/2,i+len/2,j+len/2);
	divide(code*10+SW,len/2,i+len/2,j);
	divide(code*10+NE,len/2,i,j+len/2);
	divide(code*10+NW,len/2,i,j);
}

bool pure(int len, int i, int j) {
	bool first=img[i][j];
	for(int m=i; m<len+i; m++) {
		for(int n=j; n<len+j; n++) {
			if(img[m][n]!=first) return false;
		}
	}
	return true;
}

void pour(int len, int i, int j) {
	for(int m=i; m<len+i; m++) {
		for(int n=j; n<len+j; n++) {
			img[m][n]=1;
		}
	}
}

int rev(int code) {
	int temp=0;
	while(code/10!=0) {
		temp=temp+(code%10);
		temp*=10;
		code/=10;
	}
	temp+=code;
	return temp;
}

int five_to_ten(int num) {
	int temp=0;
	int power=0;
	while(num/10!=0) {
		temp+=((num%10)*pow(5,power));
		power++;
		num/=10;
	}
	temp+=((num%10)*pow(5,power));
	return temp;
}

int ten_to_five(int num) {
	int lastbit;
	int out=0;
	lastbit = num%5;
	if(num/5>0) {
		out = ten_to_five(num/5);
	}
	out = out*10+lastbit;
	return out;
}