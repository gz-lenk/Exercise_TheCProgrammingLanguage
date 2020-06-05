#include<stdio.h>

#define MAX_BUFFER 1024
#define SPACE ' '
#define TAB '\t'

//ͨ����¼�ַ��������4���������ж�Ҫ�����ٿ�ȱ 

int getline(char s[],int lim){
	int c,i;
	
	for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';++i)
		s[i]=c;
	if(c='\n'){
		s[i]=c;
		++i;
	}
	s[i]='\0';
	
	return i;
}

int CalculateNumOfSpace(int Offset, int Tabsize){
	return Tabsize-(Offset%Tabsize);
}

int main(void){
	char line[MAX_BUFFER];
	int tabsize=8;
	int i,j,k,l;
	
	while(getline(line,MAX_BUFFER)>0){
		for(i=0,l=0;line[i]!='\0';i++){
			if(line[i]==TAB){
				j=CalculateNumOfSpace(l,tabsize);
				for(k=0;k<j;k++){
					putchar(SPACE);
					l++; 
				}
			}
			else{
				putchar(line[i]);
				l++;
			}
		}
	}
	return 0;
} 
