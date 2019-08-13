#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int d,x=0,y=0,z=1,i,j;
	
	char a[10][10]={{'A','.','.','.','.','.','.','.','.','.'},
               {'.','.','.','.','.','.','.','.','.','.'},
               {'.','.','.','.','.','.','.','.','.','.'},
               {'.','.','.','.','.','.','.','.','.','.'},
			   {'.','.','.','.','.','.','.','.','.','.'},
			   {'.','.','.','.','.','.','.','.','.','.'},
			   {'.','.','.','.','.','.','.','.','.','.'},
			   {'.','.','.','.','.','.','.','.','.','.'},
			   {'.','.','.','.','.','.','.','.','.','.'},
			   {'.','.','.','.','.','.','.','.','.','.'}},
         b[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
               
    srand((int)time(0));
    
    while(z!=26){
	  d=rand()%4;	
      if(d==0&&x!=9) {if(a[x+1][y]=='.'){a[x+1][y]=b[z];x++;z++;}
                      else continue;}
      else if(d==1&&y!=9) {if(a[x][y+1]=='.'){a[x][y+1]=b[z];y++;z++;}
	                       else continue;}
      else if(d==2&&x!=0) {if(a[x-1][y]=='.'){a[x-1][y]=b[z];x--;z++;}
	                       else continue;}
      else if(d==3&&y!=0) {if(a[x][y-1]=='.'){a[x][y-1]=b[z];y--;z++;}
	                       else continue;}
      else if(a[x+1][y]!='.'&&a[x][y+1]!='.'&&a[x-1][y]!='.'&&a[x][y-1]!='.') break;
      
      if(x==0){if(y==0){if(a[0][1]!='.'&&a[1][0]!='.')break;else continue;}
	           else if(y==9){if(a[0][8]!='.'&&a[1][9]!='.')break;else continue;}
			   else if(a[0][y-1]!='.'&&a[0][y+1]!='.'&a[1][y]!='.')break;else continue;}
      else if(x==9){if(y==0){if(a[9][1]!='.'&&a[8][0]!='.')break;else continue;}
	                else if(y==9){if(a[9][8]!='.'&&a[8][9]!='.')break;else continue;}
			        else if(a[9][y-1]!='.'&&a[9][y+1]!='.'&a[8][y]!='.')break;else continue;}
      else if(y==0){if(a[0][y-1]!='.'&&a[0][y+1]!='.'&a[1][y]!='.')break;else continue;}
      else if(x==0){if(a[0][y-1]!='.'&&a[0][y+1]!='.'&a[1][y]!='.')break;else continue;}
    }
   for(i=0;i<10;i++){
     for(j=0;j<10;j++){if(j==9)printf("%c\n",a[i][9]);
	                   else printf("%c ",a[i][j]);}}
   
   return 0;
}
