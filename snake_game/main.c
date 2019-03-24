#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "snakequeue.h"
#define _CRT_NONSTDC_NO_WARNINGS

/*
typedef struct headPosType {
    int xpos;
    int ypos;
} headPos;
*/

typedef enum Direction {LEFT = 0, RIGHT, UP, DOWN} DIR;

void gotoxy(int x, int y);


void paintHead(headPos* pHeadPos){
    gotoxy(pHeadPos->xpos, pHeadPos->ypos);
    printf("0");
}

void paintBody(headPos* pBodyPos){
    gotoxy(pBodyPos->xpos, pBodyPos->ypos);
    printf("o");
}

void paintMap(){
	for(int i = 0; i <= 20; i++){
		gotoxy(i, 0);
		printf("#");
	}
	for(int j = 1; j <= 19; j++){
		gotoxy(0, j);
		printf("#");
		gotoxy(20,j);
		printf("#");
	}
	for(int i = 0; i <= 20; i++){
		gotoxy(i, 20);
		printf("#");
	}
}

void moveHead(headPos* pHeadPos, char direction){

    if(direction == 'a'){
        pHeadPos->xpos--;
        paintHead(pHeadPos);
    }
    else if(direction == 'd'){
        pHeadPos->xpos++;
        paintHead(pHeadPos);
    }
    else if(direction == 'w'){
        pHeadPos->ypos--;
        paintHead(pHeadPos);
    }
    else {
        pHeadPos->ypos++;
        paintHead(pHeadPos);
    }
}
/*
void moveWithDir(headPos* pHeadPos){
    char key;

        key = getch();
        switch(key){
        case 'w':
            moveHead(pHeadPos, UP);
            break;
        case 'a':
            moveHead(pHeadPos, LEFT);
            break;
        case 's':
            moveHead(pHeadPos, DOWN);
            break;
        case 'd':
            moveHead(pHeadPos, RIGHT);
        }

}
*/
void paintEmpty(headPos* pHeadPos){
    gotoxy(pHeadPos->xpos, pHeadPos->ypos);
    printf(" ");
}

void paintBeforeUpdate(headPos* pHeadPos, LinkedQueue* pQueue){
    headPos* pNode = pHeadPos;
    paintMap();
    for(int i = 0; i < pQueue->currentElementCount - 1; i++){
        paintBody(pNode);
        pNode = pNode->pLink;
    }
    paintBody(pNode);
}
/*
void paintAfterUpdate(headPos* pHeadPos, LinkedQueue* pQueue){
    headPos* pNode = pHeadPos->pLink;
    while(pNode != NULL){

    }
}
*/
int main(void){

    headPos* pHeadPos = NULL;
    pHeadPos = (headPos *)malloc((sizeof(headPos)));
    pHeadPos->xpos = 10;
    pHeadPos->ypos = 10;
    char key;

    int x_pos[100];
    int y_pos[100];
    int size;



    headPos* pbody1 = (headPos *)malloc(sizeof(headPos));
    pbody1->xpos = 11;
    pbody1->ypos = 10;

    headPos* pbody2 = (headPos *)malloc(sizeof(headPos));
    pbody2->xpos = 12;
    pbody2->ypos = 10;

    headPos* pbody3 = (headPos *)malloc(sizeof(headPos));
    pbody3->xpos = 13;
    pbody3->ypos = 10;




    paintMap();
    paintHead(pHeadPos);
    paintBody(pbody1);
    paintBody(pbody2);
    key = getch();

    while(1){
        if(kbhit()){
            key = getch();
        }

        paintMap();
        paintHead(pHeadPos);
        paintBody(pbody1);
        paintBody(pbody2);

        //paintBeforeUpdate(pHeadPos, pSnakeQueue);
        Sleep(100);

        paintEmpty(pbody2);
        pbody2->xpos = pbody1->xpos;
        pbody2->ypos = pbody1->ypos;
        paintEmpty(pbody1);
        pbody1->xpos = pHeadPos->xpos;
        pbody1->ypos = pHeadPos->ypos;
        paintEmpty(pHeadPos);
        moveHead(pHeadPos, key);
        paintBody(pbody1);
        paintBody(pbody2);

    }

	return 0;
}

void gotoxy(int x, int y)
{

    COORD Pos = { 2 * x, y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}
