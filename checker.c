#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIRECTION 4
#define MAXLENGTH 10
#define SCORE 5

struct direction{
    int x;
    int y;
};

struct direction d[4], direction[4], td[4];
int flag[4] = {0};
struct direction pos[26];
int seed = 0;
int step = 0;
char map1[MAXLENGTH][MAXLENGTH];
char map2[MAXLENGTH][MAXLENGTH];
char map3[MAXLENGTH][MAXLENGTH];
int r[1000];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int read(){
    for(int i = 0; i < 26; i++)
	memset(&pos[i], -1, sizeof(pos[i]));
    scanf("%d", &seed);
    for(int i = 0; i < MAXLENGTH; i++){
        for(int j = 0; j < MAXLENGTH; j++){
	    if(scanf(" %c ", &map1[i][j]) == EOF)  return 0;
	    if(map1[i][j] >= 'A' && map1[i][j] <= 'Z'){
	        pos[map1[i][j]-65].x = j;
		pos[map1[i][j]-65].y = i;
		step++;
	    }
	}
    }
    for(int i = 0; i < 26; i++){
        if(pos[i].x == -1){
	    step = i;
	    break;
	}
    }
    return 1;
}

void print(){
    for(int i = 0; i < MAXLENGTH; i++){
        for(int j = 0; j < MAXLENGTH; j++)
	{
	    if(j > 0) putchar(' ');
	    printf("%c", map1[i][j]);
	}
	printf("\n");
    }
}

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

void getRandom(){
    for(int i = 0; i < 1000; i++){
        r[i] = rand()%4;
    }
}

void initDirection(){
    for(int i = 0; i < DIRECTION; i++){
        direction[i].x = dx[i];
	direction[i].y = dy[i];
    }
}

void initMap(char m[][MAXLENGTH]){
    for(int i = 0; i < MAXLENGTH; i++){
        for(int j = 0; j < MAXLENGTH; j++){
	    if(i == 0 && j == 0) m[i][j] = 'A';
	    else m[i][j] = '.';
	}
    }
}

int match(int x, int y, char cur_char, struct direction dir[]){
    initMap(map2);
    for(int i = 0, j = 1; i < 1000 && j <= step; i++){
	if(inMap(x+dir[r[i]].x, y+dir[r[i]].y) && canMove(x, y, dir[r[i]], map2) && map1[y+dir[r[i]].y][x+dir[r[i]].x] != cur_char+1)
            return 0;
        if(inMap(x+dir[r[i]].x, y+dir[r[i]].y) && map1[y+dir[r[i]].y][x+dir[r[i]].x] == cur_char+1 ){
	    j++;
	    x = x+dir[r[i]].x;
	    y = y+dir[r[i]].y;
	    cur_char = cur_char+1;
	    map2[y][x] = cur_char;
	}
	if(j == step) return j;  
    }
}

void reverse(int x, int y, char cur_char, struct direction dir[], int begin, int end){
    int i;
    if(begin >= end){
        for(i = 0; i < end; i++)
	    td[i] = dir[i];
	int j = match(x, y, cur_char, td);
	if(j){
	     for(int i = 0; i < DIRECTION; i++){
	         d[i] = td[i];
	     }
	}
    }
    else{
        for(i = begin; i < end; i++){
	    struct direction tmp;
	    memset(&tmp, 0, sizeof(tmp));
	    if(begin != i){
	        tmp = dir[i];
		dir[i] = dir[begin];
		dir[begin] = tmp;
		memset(&tmp, 0, sizeof(tmp));
	    }
	    reverse(x, y, cur_char, dir, begin+1, end);
	    if(begin != i){
	        tmp = dir[i];
		dir[i] = dir[begin];
		dir[begin] = tmp;
		memset(&tmp, 0, sizeof(tmp));
	    }
	}
    }
}

int randomWalk(int x, int y, char *cur_char){
    int maxStep = 0;
    if(*cur_char == 'A') maxStep = 1;
    else return 0;
    for(int i = 0; i < 25; ){
        int r = rand()%4;
	if(inMap(x+d[r].x, y+d[r].y) && canMove(x, y, d[r], map3)){
	    *cur_char = *cur_char + 1;
	    map3[y+d[r].y][x+d[r].x] = *cur_char;
	    x = x + d[r].x;
	    y = y + d[r].y;
	    i++;
	    maxStep++;
	}
	for(int j = 0; j < DIRECTION; j++){
	    if(inMap(x+d[j].x, y+d[j].y) && canMove(x, y, d[j], map3))
		break;
	    if(j == 3) return maxStep;
	}
    }
    return maxStep;
}

int main(void){
    char cur_char1 = 'A';
    char cur_char2 = 'A';
    if(read() == 0){
        printf("stu.o endless loop!\n");
	return 0;
    }
    printf("stu.o\n");
    print();
    srand(seed);
    getRandom();
    initDirection();
    initMap(map3);
    reverse(0, 0, cur_char1, direction, 0, 4);
    srand(seed);
    int maxStep = randomWalk(0, 0, &cur_char2);
    printf("checker.o\n");
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j ++){
	    if(j > 0) putchar(' ');
	    printf("%c", map3[i][j]);
	}
	printf("\n");
    }
    if(step == maxStep){
	char ch = step + 64;
        printf("end at %c('.' means not end properly) with step #%d\n", ch, step);
    }
    else{
        printf("end at .('.' means not end properly) with step #%d\n", step);
    }
    return step*SCORE/maxStep;
}
