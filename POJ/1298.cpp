#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;
char s[100000];  
int flag = 0;  
int main()  
{  
	while(gets(s)!=NULL)  
	{  
		//puts(s);  
		if(strcmp(s,"ENDOFINPUT")==0)   
		{  
			break;  
		}   
		if(strcmp(s,"START")==0)  
		{  
			flag = 1;  
			continue;  
		}  
		if(strcmp(s,"END")==0)   
		{  
			flag=0;   
			continue;   
		}   
	  
		if(flag==1)  
		{  
			for(int i=0;i<strlen(s);i++)  
			{  
				if(s[i]>='A'&&s[i]<='Z')  
				{  
					if(s[i]<'F')  
					{  
						s[i] = 'Z' -(4-(s[i]-'A')) ;  
						continue;  
					}  
					s[i] = (s[i]-'A'-5)+'A';      
				}   
			}  
			puts(s);  
			continue;  
		}  
		  
	  
		  
	}  
	  
	return 0;  
}   