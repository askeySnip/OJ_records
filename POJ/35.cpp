#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
bool same(char c1, char c2){
	if(c1>='a' && c2 >='a' && c1 <='z' && c2 <= 'z') return true;
	if(c1 >='0' && c2 >='0' && c1<='9' && c2<='9') return true;
	if(c1 >='A' && c2>='A' && c1 <='Z' && c2 <='Z') return true;
	return false;
}
int main() {
	int p1, p2, p3;
	scanf("%d%d%d", &p1, &p2, &p3);
	char s[103];
	scanf("%s", s);
	int len = strlen(s);
	char out[10003];
	int j = 0;;
	for(int i=0; i<len; i++){
		if(s[i] == '-' && (i!=0||i!=len-1) && (same(s[i+1], s[i-1]))){
			int n = s[i+1] - s[i-1];
			if(n <= 0){
				out[j++] = s[i];
			}else if(n==1){
				continue;
			}else{
//				out[j++] = s[i];
				if(p3 == 2){
					if(p1 == 3){
						int t = (n-1)*p2;
						while(t--) out[j++] = '*';
					}else if(p1 == 2){
						if(s[i+1] >= 'a' && s[i+1] <='z'){
							for(char k=s[i+1]-1; k>s[i-1]; k--){
								for(int l=0; l<p2; l++) out[j++]=k-'a'+'A';
							}
						}else{
							for(char k=s[i+1]-1; k>s[i-1]; k--){
								for(int l=0; l<p2; l++) out[j++]=k;
							}
						}
					}else{
						if(s[i+1] >= 'A' && s[i+1] <='Z'){
							for(char k=s[i+1]-1; k>s[i-1]; k--){
								for(int l=0; l<p2; l++) out[j++]=k-'A'+'a';
							}
						}else{
							for(char k=s[i+1]-1; k>s[i-1]; k--){
								for(int l=0; l<p2; l++) out[j++]=k;
							}
						}
					}
				}else{
					if(p1 == 3){
						int t = (n-1)*p2;
						while(t--) out[j++] = '*';
					}else if(p1 == 2){
						if(s[i+1] >= 'a' && s[i+1] <='z'){
							for(char k=s[i-1]+1; k<s[i+1]; k++){
								for(int l=0; l<p2; l++) out[j++]=k-'a'+'A';
							}
						}else{
							for(char k=s[i-1]+1; k<s[i+1]; k++){
								for(int l=0; l<p2; l++) out[j++]=k;
							}
						}
					}else{
						if(s[i+1] >= 'A' && s[i+1] <='Z'){
							for(char k=s[i-1]+1; k<s[i+1]; k++){
								for(int l=0; l<p2; l++) out[j++]=k-'A'+'a';
							}
						}else{
							for(char k=s[i-1]+1; k<s[i+1]; k++){
								for(int l=0; l<p2; l++) out[j++]=k;
							}
						}
					}
				}
				
			}
		}else{
			out[j++] = s[i];
		}
	}
	cout << out << endl;
}