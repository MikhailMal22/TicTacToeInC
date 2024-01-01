#include <stdio.h>
#include <stdlib.h>

//Tic-Tac-toe game

char board [3][3]; 
/*  Game board is 2-d array to represent this configuration:
[0][0]|[0][1]|[0][2]
[1][0]|[1][1]|[1][2]
[2][0]|[2][1]|[2][2]
*/
//Player is X, Computer is O
char USER = 'X';
char COM = 'O';

//function prototypes:

void initBoard();           //initialize board with spaces (ASCII = 20)
void drawBoard();           //dispay game board
int checkBoard(int, int);   //check if space on board is free
int toBoard(char *);        //decode decimal input (1-9) to array format([0][0]-[2][2])       
void computerMove2();       //make computer place O on board
int checkIfWin(char);       //check if win condition is satisfied
int checkIfFull();          //check if the board is full
int isGameOver();
void plrMove(char *);

//main 
int main()
{
    //initialize variables
    char num = 0;           //where player will put an X
    char play = 'y';        //game variable
    char currentPlr = USER; //which player has its turn now
    char buffer;            //buffer to hold /n
    initBoard();

    printf("TIC|   |   \n");
    printf("---|---|---\n");
    printf("   |TAC|   \n");
    printf("---|---|---\n");
    printf("   |   |TOE\n");

    printf("Press enter to start the game\n");
    scanf("%c",&buffer);
    
    while(play == 'y')  //game loop
    {
            drawBoard();
            if(currentPlr == USER)
            {
                plrMove(&num);
                currentPlr=COM;
            }
            
            else
            {
                computerMove2();
                currentPlr = USER;
            }

            if(isGameOver() == 1)
            {
                drawBoard();
                printf("Play Again?(y/n)\n");
                scanf("\n%c",&play);
                if(play == 'n')
                {
                    break;
                }
                initBoard();
                currentPlr = USER;
            }
    }
   
    return 0;
}

//fill the board with spaces
void initBoard()
{
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        {
            board[i][j] = ' ';
        }
    }
}
//check if game is over
int isGameOver()
{
    if(checkIfWin(USER) == 1)
    {
        printf("You win!\n");
        return 1;
    }
    else if(checkIfWin(COM) == 1)
    {
        printf("You lose!\n");
        return 1;
    }
    else if(checkIfFull() == 1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
//display board
void drawBoard()
{
    printf(" %c | %c | %c  \n",board[0][0],board[0][1],board[0][2]);
    printf("---|---|---    \n");
    printf(" %c | %c | %c  \n",board[1][0],board[1][1],board[1][2]);
    printf("---|---|---    \n");
    printf(" %c | %c | %c  \n\n",board[2][0],board[2][1],board[2][2]);
}

//decode decimals(1-9) to locations in the array([0][0]-[2][2])
int toBoard(char *n)
{
    switch(*n)
    {
        case '1':
            return checkBoard(0,0);
        case '2':
            return checkBoard(0,1);
        case '3':
            return checkBoard(0,2);
        case '4':
            return checkBoard(1,0);
        case '5':
            return checkBoard(1,1);
        case '6':
            return checkBoard(1,2);
        case '7':
            return checkBoard(2,0);  
        case '8':
            return checkBoard(2,1); 
        case '9':
            return checkBoard(2,2);
        default:
            printf("Invalid input!");
            return 0;
    }
}

//check if the space on board is free
//takes two integers(i and j), each between 0 and 2, and checks if there is an empty space.
//returns 0 if the space is occupied
//places X at [i][j] and returns 1 if the space is free
int checkBoard(int i, int j)
{
    if(board[i][j] == ' ')
    {
        board[i][j] = 'X';
        return 1;
    }
    else 
    {
        return 0;
    }
    
}
int checkIfFull()
{
    for(int i =0; i<=2; i++)
    {
        for(int j=0;j<=2;j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    printf("Draw!\n");
    return 1;
}

//cheks all of the win condition for player x
//returns one if win condition is satisfied,otherwise returns 0
int checkIfWin(char x)
{
    for(int i =0; i<=2; i++)
    {
        for(int j=0;j<=2;j++)
        {
            if(board[i][0]==x && board[i][1]==x && board[i][2]==x)
            {
                return 1;
            }
            else if(board[0][i]==x && board[1][i]==x && board[2][i]==x)
            {
                return 1;
            }
            else if(board[0][0]==x && board[1][1]==x && board[2][2]==x)
            {
                return 1;
            }
            else if(board[0][2]==x && board[1][1]==x && board[2][0]==x)
            {
                return 1;
            }
        }
    }
    return 0;
}

//places "O" on a randomly selected space on the board if it is empty
void computerMove2()
{
    char placed = 0;
    while(placed == 0)
    {
        int i = rand() % 4;
        int j = rand() % 4;
        if(board[i][j] == ' ')
        {
            board[i][j] = COM;
            placed = 1;
            break;
        }
    }
}

void plrMove(char * num)
{
    char temp;
    printf("Where will you place X(1-9)?\n");
    while(1)
    {
        scanf("\n%c",num);
        if(*num < 49 || *num > 57)
        {
            printf("Invalid input!");
        }
        
        else
        {
            temp = *num;
            if(toBoard(&temp) == 0)
            {
                printf("This spot is already taken!");
            }
            else
            {
                break;
            }
        }
    }
}