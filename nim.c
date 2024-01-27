#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
// declare functions
void printGame(int, int, int);

int gameEnd(int, int, int);

void computerMove(char*, int*, int*, int*, int*);

void validInput(char, int, int*, int*, int*);

void printWinner(char);


int condition = 0;


int main(void)
{

    int rocksofA = 8; // number of rocks for each row in the game
    int rocksofB = 5;
    int rocksofC = 3; 

    char rowTaken;
    int rockTaken;

    int turn; 

    // might need a do while loop

    printf("***************************\n");
    printf("WELCOME TO THE GAME OF NIM\n");
    printf("Do not be the last player to go!\n");
    printf("***************************\n");
    printGame( rocksofA, rocksofB, rocksofC);

    do
    {
        loop:
        char trash;
        printf("Player please enter a ROW(A-C): ");
        scanf("%c", &rowTaken);
        scanf("%c", &trash);
        rowTaken = toupper(rowTaken);
        printf("Player please enter the number of rocks you want remove: ");
        scanf("%d", &rockTaken);
        scanf("%c", &trash); 
        validInput( rowTaken, rockTaken, &rocksofA, &rocksofB, &rocksofC);
        turn = 0; // indicates player's turn
        if(condition == 0)
        {
            goto loop;
        }
        else if(rocksofA == 0 && rocksofB == 0 && rocksofC == 0)
        {
            break;
        } 
        computerMove(&rowTaken, &rockTaken, &rocksofA, &rocksofB, &rocksofC);
        turn = 1; // indicates computers turn
        validInput( rowTaken, rockTaken, &rocksofA, &rocksofB, &rocksofC);

    }while(gameEnd(rocksofA, rocksofB, rocksofC) == 0); // checks if you still need to keep playing the game
    printWinner(turn); 


    return 0;

}


void printGame( int rocksofA, int rocksofB, int rocksofC )
{
    printf("ROW A: ");
    for(int i = 0; i < rocksofA; i++)
    {
        printf("O");
    }
    printf("\nROW B: ");
    for(int j = 0; j < rocksofB; j++)
    {
        printf("O");
    }
    printf("\nROW C: ");
    for(int k = 0; k < rocksofC; k++)
    {
        printf("O");
    }
    printf("\n");
}


void validInput(char rowTaken, int rockTaken, int *rocksofA, int *rocksofB, int *rocksofC)
{ 
    int newA = *rocksofA;
    int newB = *rocksofB;
    int newC = *rocksofC; 


    if(rowTaken == ' ' || rowTaken == '\n' || rockTaken == 0 || rockTaken > 8)
    {
        printf("Invalid input please try again!\n");
        printGame( newA, newB, newC);
        condition = 0; 
        goto label;
    }

    if (rowTaken == 'A' && rockTaken <= newA )
    {
        condition = 1;
        *rocksofA = newA - rockTaken; 
        printGame( *rocksofA, *rocksofB, *rocksofC);
    }
    else if(rowTaken == 'B' && rockTaken <= newB )
    {
        condition = 1;
        *rocksofB = newB - rockTaken;
        printGame( *rocksofA, *rocksofB, *rocksofC);
    }
    else if (rowTaken == 'C' && rockTaken <= newC )
    {
        condition = 1;
        *rocksofC = newC - rockTaken;
        printGame( *rocksofA, *rocksofB, *rocksofC);

    }
    else
    {
        printf("Invalid input please try again!\n");
        printGame( newA, newB, newC);
        condition = 0; 
            
    }
    label:

}


void computerMove(char *rowTaken, int *rockTaken, int *rocksofA, int *rocksofB, int *rocksofC)
{

    printf("\nComputer's Turn...\n"); 
    srand(time(0));
    char x[] = {'A', 'B', 'C'};
    int i;
    int delay = 0;
    int comCondition = 0;
    for (int j = 0; j <= 2000; j++)
    {
        delay++;  // used to delay computer's turn 
        
    }

    do{
    i = rand() % 3; // gives you possible values from zero to 2 (not including 3)
    *rowTaken = x[i];
    *rockTaken = (rand() % 8) + 1; // this gives you possible values from 1 to 8 
    if (*rowTaken == 'A' && *rockTaken <= *rocksofA)
    {
        break;
    }
    if (*rowTaken == 'B' && *rockTaken <= *rocksofB)
    {
        break;
    }
    if (*rowTaken == 'C' && *rockTaken <= *rocksofC)
    {
        break;
    }

   }while(comCondition == 0); 


}

int gameEnd(int rocksofA, int rocksofB, int rocksofC)
{
    int gameend = 0;
    if(rocksofA == 0 && rocksofB == 0 && rocksofC == 0) // checks if there's no more rocks in the game
    {
        gameend++;
    }
    return gameend;

}

void printWinner(char turn)
{
    if(turn == 0)
    {
        printf("COMPUTER WON THE GAME OF NIM!!!!\n");
    }
    else if (turn == 1)
    {
        printf("PLAYER WON THE GAME OF NIM!!!"); 
    }
}
        







