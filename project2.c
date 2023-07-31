/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 5
#define WALL 1
#define SPACE 0
#define EXIT 2
#define PLAYER 3
#define HOLE 4
#define TREASURE 5
#define BOULDER 6


// Task One: InitialiseStory
void InitialiseStory(char* paragraph)
{
	char sentence[1000] = "A little rascal decided to steal gold from the cave! \n help this rascal steal the treasure and then escape! \n";
	strcpy(paragraph, sentence);
}

// Task Two: PrintCave
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
int i,j;

for(i=0;i<CAVE_SIZE;i++){
    for(j=0;j<CAVE_SIZE;j++){
        if (cave[i][j] == SPACE){
			printf(" ");
        }
        else if (cave[i][j] == WALL){
				printf("#");
    }
	else if(cave[i][j]==EXIT){
		printf(" ");
	}
	else if(cave[i][j]==PLAYER){
		printf("X");
		}
	else if(cave[i][j]==HOLE){
		printf("*");
	}
	else if(cave[i][j]==TREASURE){
		printf("+");
	}
	else if(cave[i][j]==BOULDER){
		printf("O");
	}
	}
	printf("\n");
}
}

// Task Three: InitialiseCave
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout){
	int counter=0;
	for(int i=0;i<CAVE_SIZE;i++){
		for(int j=0;j<CAVE_SIZE;j++){
			if(layout[counter]== '1'){
				cave[i][j]=WALL;
			}
			else if(layout[counter]== '0'){
				cave[i][j]=SPACE;
		}
			else if(layout[counter]== 'E'){
			cave[i][j]=EXIT;
}
counter++;
}
}
}


// As you work on the other tasks, remove the comments below
int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
	for(int i=0;i<CAVE_SIZE;i++){
		for(int j=0;j<CAVE_SIZE;j++){
			if((i==0)||(i==(CAVE_SIZE-1)||(j==CAVE_SIZE-1)||(j==0))){
				if((cave[i][j]!=(WALL))&&(cave[i][j]!=(EXIT))){
					return 0;
				}
			}
			}
}
	return 1;
}

int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int counter=0;
	for(int i=0;i<CAVE_SIZE;i++){
		for(int j=0;j<CAVE_SIZE;j++){
			if(cave[i][j]==EXIT)
				counter++;
}
	}
	if(counter==1){
		return 1;
	}
		else{ return 0;}
}

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int counter=0;
	for(int i=0;i<CAVE_SIZE;i++){
		for(int j=0;j<CAVE_SIZE;j++){
			if((cave[i][j]==EXIT)&&(cave[0][0]!=EXIT)&&(cave[0][(CAVE_SIZE-1)]!=EXIT)&&(cave[(CAVE_SIZE-1)][0]!=EXIT)&&(cave[(CAVE_SIZE-1)][(CAVE_SIZE-1)]!=EXIT)){
				if((i==0)||(i==(CAVE_SIZE-1)||(j==(CAVE_SIZE-1))||(j==0))){
					counter++;
				}
}
		}
	}
	if(counter==1){
		return 1;
	}
	else{return 0; }
}


void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element)
{
	int counter=0;
	if((row<CAVE_SIZE)&&(col<CAVE_SIZE)){
	if((strcmp(element,"player")==0)&&(cave[row][col]==SPACE)){
		for(int i=0;i<CAVE_SIZE;i++){
			for(int j=0;j<CAVE_SIZE;j++){
				if(cave[i][j]==3){
					counter++;
				}
			}
		}
		if(counter==0){
		cave[row][col]=3;
		}
	}

	if((strcmp(element,"hole")==0)&&(cave[row][col]==SPACE)){
		cave[row][col]=4;
			}
			else if((strcmp(element,"treasure")==0)&&(cave[row][col]==SPACE)){
		cave[row][col]=5;
			}
			else if((strcmp(element,"boulder")==0)&&(cave[row][col]==SPACE)){
		cave[row][col]=6;
			}
	}

}

void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int temp[CAVE_SIZE][CAVE_SIZE];
		for(int i=0;i<CAVE_SIZE;i++){
			for(int j=0;j<CAVE_SIZE;j++){
				temp[i][j]=cave[(CAVE_SIZE-1)-j][i];
			}
		}
	for(int i=0;i<CAVE_SIZE;i++){
		for(int j=0;j<CAVE_SIZE;j++){
			cave[i][j]=temp[i][j];
		}
	}
}

void FindX(int cave[CAVE_SIZE][CAVE_SIZE], int *rowPos, int *colPos)
{
int i,j;

for(i=0;i<CAVE_SIZE;i++){
    for(j=0;j<CAVE_SIZE;j++){
        if (cave[i][j] == PLAYER){
            *rowPos = i;
            *colPos = j;
        }
    }
    
}
}
int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{
	int ReturnValue;
	int rowX, colX;
	int i=2;
	int j=1;
	int rotation;

	if(move=='w'){
	rotation=0;
	}
	else if(move=='a'){
	rotation=1;
	}
	else if(move=='s'){
	rotation=2;
	}
	else if(move=='d'){
	rotation=3;
	}

	if(rotation==1){
		RotateCave(cave);
	}else if(rotation==2){
		RotateCave(cave);
		RotateCave(cave);
	}else if(rotation==3){
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave); }

		FindX(cave, &rowX, &colX);
		if(cave[rowX-1][colX]==SPACE){    
			cave[rowX-1][colX]=PLAYER;
			cave[rowX][colX]=SPACE;
			ReturnValue=0;
		}
		else if(cave[rowX-1][colX]==BOULDER){
			while((cave[rowX-i][colX]==SPACE)||(cave[rowX-i][colX]==HOLE)){
   				if(cave[rowX-i][colX]==SPACE){
				cave[rowX-1-j][colX]=BOULDER;
    			cave[rowX-j][colX]=SPACE;
				}
				else if(cave[rowX-i][colX]==HOLE){
				cave[rowX-1-j][colX]=SPACE;
    			cave[rowX-j][colX]=SPACE;
				break;
				}
				i++;
				j++;

			}
			ReturnValue=0;
		}

	else if(cave[rowX-1][colX]==TREASURE){
			cave[rowX-1][colX]=PLAYER;
			cave[rowX][colX]=SPACE;
			ReturnValue=0;
	}
	else if(cave[rowX-1][colX]==HOLE){
			cave[rowX][colX]=SPACE;
		ReturnValue=1;
	}
	else if(cave[rowX-1][colX]==EXIT){
			cave[rowX-1][colX]=PLAYER;
			cave[rowX][colX]=SPACE;
			ReturnValue=2;
	}

	if(rotation==1){
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave);
	}else if(rotation==2){
		RotateCave(cave);
		RotateCave(cave);
	}else if(rotation==3){
		RotateCave(cave);
}
return ReturnValue;
}



/***********************************************************/
/***********************************************************/
/******* A SIMPLE MAIN FUNCTION TO TEST YOUR PROGRESS ******/
/***********************************************************/
/***********************************************************/

/* You should add your own tests in here */
int main(void){
char layout[200] = "111111000110001100011E111";
int cave[CAVE_SIZE][CAVE_SIZE];
InitialiseCave(cave, layout);
AddItem(cave, 1, 1, "player");
AddItem(cave, 2, 2, "boulder");
AddItem(cave, 3, 1, "hole");

MakeMove(cave, 'd');
MakeMove(cave, 'd');
MakeMove(cave, 's');
MakeMove(cave, 'a');
MakeMove(cave, 'a');
MakeMove(cave, 'w');
MakeMove(cave, 'a');
MakeMove(cave, 's');
MakeMove(cave, 's');
MakeMove(cave, 's');

PrintCave(cave);
}