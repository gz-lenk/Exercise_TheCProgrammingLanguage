#include<stdio.h>

//htoi 
int main(){
	
} 

int atoi(char s[]){
	int i,n;
	
	i=2;
	n=0;
	while(i<LIM){
		if(s[i]=='\0')
			break;
		else if(s[i]>='0'&&s[i]<='9'){
			n=16*n+(s[i]-'0');
		}
		else if(s[i]>='A'&&s[i]<='F'){
			n=16*n+(s[i]-'A'+10);
		}
		else if(s[i]>='a'&&s[i]<='f'){
			n=16*n+(s[i]-'a'+10);
		}
		i++;
	}
	return n;
}
