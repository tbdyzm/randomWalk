#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLENGTH 10
#define DIRECTION 4

char map[MAXLENGTH][MAXLENGTH];

struct direction{
    int x;
    int y;
};

struct direction d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int inMap(int x, int y){
    if(x >= 0 && x < MAXLENGTH && y >= 0 && y < MAXLENGTH)
	return 1;
    else
	return 0; 
}

int canMove(int x, int y, struct direction dir, char m[][MAXLENGTH]){
    if(m[y+dir.y][x+dir.x] == '.')
	return 1;
    else
	return 0;
}

void randomWalk(int x, int y, char *cur_char){
    for(int i = 0; i < 25; ){
        int r = rand()%4;
	if(inMap(x+d[r].x, y+d[r].y) && canMove(x, y, d[r], map)){
	    *cur_char = *cur_char + 1;
	    map[y+d[r].y][x+d[r].x] = *cur_char;
	    x = x + d[r].x;
	    y = y + d[r].y;
	    i++;
	}
	for(int j = 0; j < DIRECTION; j++){
	    if(inMap(x+d[j].x, y+d[j].y) && canMove(x, y, d[j], map))
		break;
	    if(j == 3) return;
	}
    }
    return;
}

void initMap(char m[][MAXLENGTH]){
    for(int i = 0; i < MAXLENGTH; i++){
        for(int j = 0; j < MAXLENGTH; j++){
	    if(i == 0 && j == 0) m[i][j] = 'A';
	    else m[i][j] = '.';
	}
    }
}

void print(){
    for(int i = 0; i < MAXLENGTH; i++){
        for(int j = 0; j < MAXLENGTH; j++)
	{
	    if(j > 0) putchar(' ');
	    printf("%c", map[i][j]);
	}
	printf("\n");
    }
}

int main(void){
    srand((unsigned)time(NULL));

    initMap(map);
    char cur_char = 'A';
    randomWalk(0, 0, &cur_char);
    print();

    return 0;
}
