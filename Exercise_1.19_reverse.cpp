#include<stdio.h>
#define MAXLINE 102

//三个函数，discardnewline()将/n排除在倒置对象外
//getline()读取一行
//reverse()倒置 

void discardnewline(char s[]);
int reverse(char s[]);
int getline(char s[] ,int lim); 

int main(){
	char line[MAXLINE];
	
	while(getline(line,sizeof line)>0){
		discardnewline(line);
		reverse(line);
		printf("%s\n",line);
	}
	return 0;
} 

void discardnewline(char s[]){
	int i;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='\n')
			s[i]='\0';
	}
}

int reverse(char s[]){
	char temp;
	int i,j;
	
	for(i=0;s[i]!='\0';i++)
		;
	i--;
	
	for(j=0;j<i;j++){
		temp=s[j];
		s[j]=s[i];
		s[i--]=temp;
	}
	
	return 0;
}

int getline(char s[],int lim){
	int i,c;
	
	for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';i++){
		s[i]=c;
	}
	if(c=='\n'){
		s[i++]=c;
	}
	s[i]='\0';
	
	return i;
}
