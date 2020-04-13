#include<stdio.h>
#define MAXLINE 102

//����������discardnewline()��/n�ų��ڵ��ö�����
//getline()��ȡһ��
//reverse()���� 

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
