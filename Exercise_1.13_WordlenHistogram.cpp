#include<stdio.h>
#define MAXLEN 10

/*数据收集部分
	实变量
		当前字符c
		当前单词长度wordlen
		横坐标axis_x 
		纵坐标axis_y
		频率数组 freq[MAXLEN+1]
		最大长度
		循环变量 
	状态变量
		是否在单词外inspace 
		是否在首字符infirstl
		是否完成读取 done
		
	未完成读取：
		读取 
		空白符：
			不在单词外(刚刚读完一个单词）：
				inspace=1; 
				
				长度合法：
					相应频率加一
					比最大还大：
						最大=当前
						纵坐标=当前 
				长度过大：
					相应频率加一
					最大=当前
					比最大还大：
						最大=当前
						纵坐标=当前
			EOF：
				完成读取
		不在单词外（没读完一个单词）：
			刚开始：
				初始化wordlen
				不再是首字母
				在单词内
			长度加一 
					 
  图像打印部分
    以纵坐标为线索，axis_y 从最大递减至0
		打印坐标与|
		axis_x 从0至MAXLEN 
			如果相应频率大于当前y
				打印*
			否则
				打印空格
		打印回车
	打印横坐标
	打印横坐标值 
    
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

//没法输入 
 
