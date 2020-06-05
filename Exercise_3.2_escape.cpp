#include<stdio.h>

void escape(char *s, char *t);
void unescape(char *s, char *t);

int main(void){
	char text1[50];
	char text2[50];
	
	printf("Original string:\n%s\n",text1);
	
	escape(text2, text1);
	printf("Escaped string:\n%s\n",text2);
	
	unescape(text1,text2);
	printf("Escaped string:\n%s\n",text1);
	
	return 0;
}

void escape(char *s, char *t){
	int i,j;
	i=j=0;
	
	while(t[i]){
		switch( t[i] ) {         
		case '\n':             
			s[j++] = '\\';             
			s[j] = 'n';             
			break;                      
		case '\t':         
		    s[j++] = '\\';         
		    s[j] = 't';             
			break;                      
		case '\a':         
		    s[j++] = '\\';         
		    s[j] = 'a';             
			break;                      
		case '\b':         
		    s[j++] = '\\';         
			s[j] = 'b';         
			break;                 
		case '\f':          
		    s[j++] = '\\';         
		    s[j] = 'f';             
			break;                      
		case '\r':         
		    s[j++] = '\\';         
		    s[j] = 'r';             
			break;                  
		case '\v':             
			s[j++] = '\\';             
			s[j] = 'v';             
			break;                  
		case '\\':             
			s[j++] = '\\';             
			s[j] = '\\';             
			break;                      
		case '\"':             
			s[j++] = '\\';             
			s[j] = '\"';             
			break;                      
		default: 
			s[j] = t[i];             
			break; 
		}
		++i;
		++j;
	}
	s[j]=t[i];	
}
