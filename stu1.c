#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
#define M 10
int main(){
	char ch, s[10][10];
	int i,j,m;
	for(i=0;i<10;++i){
		for(j=0;j<10;++j){
			s[i][j]='.';
		}
	}
	ch=s[0][0]='A';
	srand((unsigned) time(NULL) );
	for(i=0,j=0; ch<'Z';){
       ++ch;
       m=rand()%4;
       if((s[i][j+1])!='.' && (s[i-1][j])!='.' && (s[i][j-1])!='.' && (s[i+1][j])!='.')break;
       switch (m){
       	case 0: {
	       	if(i==0){--ch;break;}
	       	else{if(s[i-1][j]!='.'){--ch; break;}
			   else {i -= 1; s[i][j] = ch;}} break; }
       	case 1: {
       		if(i==(N-1)){--ch; break;}
       		else{if(s[i+1][j]!='.') {--ch;break;}
			   else{i += 1; s[i][j] = ch;}} break; }
	    case 2: {
    		if(j==0) {--ch;break;}
    		else{if(s[i][j-1]!='.'){--ch;break;}
			else{j -= 1; s[i][j] = ch;}} break; }
   		case 3: {
		   	if(j==(M-1)) {--ch;break;}
		   	else{if(s[i][j+1]!='.'){--ch;break;}
			   else{j += 1; s[i][j] = ch;}} break; }
       default: {--ch;break;} 
       }
   }
    for(i=0; i<10; i++){
        for(j=0; j<10; j++)
           printf("%-2c",s[i][j]);
       putchar('\n');
    }
}
