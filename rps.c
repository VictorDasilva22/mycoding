#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char printGame();
char computerMove(); 
void compareItem(char, char, int*);



int main ()
{
    int rounds = 0;
    int totalWins = 0;
    char delay = 0;
    char question;
    char trash;

    printf("################################\n");
    printf("Welocome To Rock Paper Scissors\n");
    printf("################################\n");

    do
    {
    char choice = printGame(); 
    char computerItem = computerMove(); 
    rounds++;
    compareItem(choice, computerItem, &totalWins);
    printf("\nWould you like to play another round(Y/N)? ");
    scanf("%c", &question); 
    scanf("%c", &trash);
    }while(question == 'Y');

    printf("\n*****THE GAME HAS ENDED*****");
    printf("\nYOU WON %d out of %d games!", totalWins, rounds); 
    return 0; 
}


char printGame() 
{
    char choice;
    int con = 0;
    char trash;
    
    do 
    {
        printf("\nChoose your Item to battle(R/P/S): ");
        scanf("%c", &choice);
        scanf("%c", &trash);
        //scanf("%c", &trash);
        choice = toupper(choice);
        if(choice != 'R' && choice != 'P' && choice != 'S' )
        {
            printf("Invalid choice of item. Please choose a valid item.\n");

        }
        else
        {
            break;
        }
    }while(con == 0);
    return choice; 

}

char computerMove()
{
    srand(time(0));
    char item[] = {'R','P','S'};
    char i; 

    i = rand() % 3; // 0 - 2
    char computerItem = item[i];
    printf("Computer's choice of item is: %c\n", computerItem);
    return computerItem; 
}

void compareItem(char choice, char computerItem, int *totalWins)
{
    int new = *totalWins;
    if(choice == 'R')
    {
        switch (computerItem)
        {
        case 'R':
            printf("It's a draw!");
            break;
        case 'S':
            printf("You won this round!");
            *totalWins = new + 1;
            break; 
        case 'P':
            printf("The Computer won this round!");
            break;
        }
    }
    else if(choice == 'S')
    {
        switch (computerItem)
        {
        case 'S':
            printf("It's a draw!");
            break;
        case 'P':
            printf("You won this round!");
            *totalWins = new + 1;
            break; 
        case 'R':
            printf("The Computer won this round!");
            break;
        }
    }
    else if(choice == 'P')
    {
         switch (computerItem)
        {
        case 'P':
            printf("It's a draw!");
            break;
        case 'R':
            printf("You won this round!");
            *totalWins = new + 1;
            break; 
        case 'S':
            printf("The Computer won this round!");
            break;
        }
    }
    


}