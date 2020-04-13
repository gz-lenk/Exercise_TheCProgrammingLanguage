#include<stdio.h>
#define MAXLEN 10

/*�����ռ�����
	ʵ����
		��ǰ�ַ�c
		��ǰ���ʳ���wordlen
		������axis_x 
		������axis_y
		Ƶ������ freq[MAXLEN+1]
		��󳤶�
		ѭ������ 
	״̬����
		�Ƿ��ڵ�����inspace 
		�Ƿ������ַ�infirstl
		�Ƿ���ɶ�ȡ done
		
	δ��ɶ�ȡ��
		��ȡ 
		�հ׷���
			���ڵ�����(�ոն���һ�����ʣ���
				inspace=1; 
				
				���ȺϷ���
					��ӦƵ�ʼ�һ
					����󻹴�
						���=��ǰ
						������=��ǰ 
				���ȹ���
					��ӦƵ�ʼ�һ
					���=��ǰ
					����󻹴�
						���=��ǰ
						������=��ǰ
			EOF��
				��ɶ�ȡ
		���ڵ����⣨û����һ�����ʣ���
			�տ�ʼ��
				��ʼ��wordlen
				����������ĸ
				�ڵ�����
			���ȼ�һ 
					 
  ͼ���ӡ����
    ��������Ϊ������axis_y �����ݼ���0
		��ӡ������|
		axis_x ��0��MAXLEN 
			�����ӦƵ�ʴ��ڵ�ǰy
				��ӡ*
			����
				��ӡ�ո�
		��ӡ�س�
	��ӡ������
	��ӡ������ֵ 
    
*/

int main(){
	int c,i,wordlen=0,axis_x=0,axis_y=0,freq[MAXLEN+1],maxfreq=0;
	int inspace=0,infirstl=1,done=0; 
	
	for(i=0;i<=MAXLEN;i++){
		freq[i]=0;
	}
	
	while(done=0)
	{ 
		c=getchar();
		if(c==' '||c=='\t'||c==EOF){
			if(inspace==0){
				infirstl=0;
				inspace=1;
				
				if(wordlen<=MAXLEN&&wordlen>0){
					axis_y=++freq[wordlen-1];
					if(axis_y>maxfreq){
						maxfreq=axis_y;
					}
				}else{
					axis_y=++freq[wordlen];
					if(axis_y>maxfreq){
						maxfreq=axis_y;
					}
				}
			}
			if(c==EOF){
				done=1;
			}
			
		}else{
			if(inspace==1||infirstl==1){
				wordlen=0;
				inspace=0;
				infirstl=0;
			}
			++wordlen;
		}
	}
	
	for(axis_y=maxfreq;axis_y>0;axis_y--){
		printf("%4d  |",axis_y);
		for(axis_x=0;axis_x<=MAXLEN;axis_x++){
			if(freq[axis_x]>=axis_y){
				printf("*  ");
			}else{
				printf("   ");
			}
		}
		printf("\n");
	}
	printf("       +");
	for(axis_x=0;axis_x<=MAXLEN;axis_x++){
		printf("---");
	}
	printf("\n        ");
	for(axis_x=0;axis_x<MAXLEN;axis_x++){
		printf("%2d ",axis_x+1);
	}
	printf(">%d",MAXLEN);
	
	return 0; 
}

//û������ 
 
