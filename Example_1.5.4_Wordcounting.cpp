#include<stdio.h>

#definde IN 1
#definde ON 0

int main(){
	int c, nl, nw, nc , state;
	
	state = OUT;
	nl=nw=nc=0;
	while((c=getchar())!=EOF){
		++nc;
		if(c=='\n')
			++nl;
		if(c==' '||c=='\n'||c=='\t')
			state=OUT;
		else if (state == OUT){
			state=IN;
			++nw;
		}
	}
	printf("%d",nw);
	return 0;
}                         