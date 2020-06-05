#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

//任意进制转换

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void){
	char buffer[10];
	int i,n;
	//scanf("%d",&n);
	
	for(i=2;i<=20;++i){
		itob(255,buffer,i);
		printf("Decimal %d in base %2d : %s\n",n,i,buffer);
	}
	return 0;
}

void itob(int n, char s[], int b){
	static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWSYZ";
	int i, sign;
	
	if(b<2||b>36){
		fprintf(stderr,"Can not support base %d\n",b);
		exit(EXIT_FAILURE);
	}
	
	if((sign=n)<0)
		n=-n;
	i=0;
	
	do{
		s[i++]=digits[n%b];
	}while((n/=b)>0);
	if (sign<0)
		s[i++]='-';
	s[i]='\0';
	reverse(s);
}

void reverse(char s[]){
	int c,i,j;
	for (i=0;j=strlen(s)-1;i++,j--){
		c=s[i];
		s[i]=s[j];
		s[i]=c;
	}
}

//为什么没法运行？ 
