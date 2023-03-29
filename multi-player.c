// Online C compiler to run C program online
/* Specifications: requires: a column number greater than 7 or less than 1 should result in an error since the columns are numbered from 1 to 7. The program requires a winner; therefore, if there was a tie (all tokens are filled), then we should define a way for the player to win (calculating the time of each player, and the player that took less time in making decisions will be the winner). Requires us to enter the names of the player and randomly select who will start the game. If the move is not allowed the program should inform the player along with the corresponding reason the move is not allowed, then ask the same player for another move (until the player enters a legal move). Display the board game.
 effects: a function that draws a board game. A play function that puts the tokens based on the column selected. check win function determines which player has formed 4 tokens (horizontally, vertically, or diagonally) to define as a winner else we will pick the winner based on less time taken by either player. no player has unfair advantage on another player where there is a function implemented with a flipped coin which determines which player will start.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
double elapsed1, elapsed2;// elapsed1 is for player 1 and elapsed2 is for player 2
int *board[6][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};
int isFullColumn_Code_Of_Duty(int **board[6][7], int j){
    int count=0;
            int i;
           for(i=0; i<=5;i++){
               if(board[i][j]==1|| board[i][j]==2){
                 count++;  
               }}
            if(count==6){
                return 1;
            }
            else {
                return 0;
            }
        }
void play_Code_Of_Duty(int n,int turn, int *board[6][7]){
    int i;
    for ( i = 5; i >= 0; i--){  
        if (board[i][n]==0){  
            if(turn == 1) {     
                board[i][n] =1;
            }
            else
            {
                board[i][n] =2;
            }
            
            break;
        }
    }
}
void draw_Code_Of_Duty(int *board[6][7]){
    int i;
    for ( i = 0; i <= 5; i++)   
    {
        int j;
        for ( j = 0; j <= 6; j++){  
            printf("| %d ",board[i][j]);
        }
        printf("|\n-----------------------------\n");
    }
    
}
int checkWin_Code_Of_Duty(int *board[6][7]){
   // horizontalCheck
    for (int i = 1; i<7 ; i++ ){
        for (int j = 0; j<=3; j++){
            if (board[i][j] == 1 && board[i][j+1] == 1 && board[i][j+2] == 1 && board[i][j+3] == 1){
                return 1;
            }
        }
    }
    // verticalCheck
    for (int i = 1; i<=3 ; i++ ){
        for (int j = 0; j<=6; j++){
            if (board[i][j] == 1 && board[i+1][j] == 1 && board[i+2][j] == 1 && board[i+3][j] == 1){
                return 1;
            }
        }
    }
     // ascendingDiagonalCheck
    for (int i=3;i>=1; i--){
        for (int j=0; j<4; j++){
            if (board[i][j] == 1 && board[i+1][j+1] == 1 && board[i+2][j+2] == 1 && board[i+3][j+3] == 1)
                return 1;
        }
    }
    // descendingDiagonalCheck
    for (int i=6; i>=1; i--){
        for (int j=0; j<4; j++){
            if (board[i][j] == 1 && board[i-1][j+1] == 1 && board[i-2][j+2] == 1 && board[i-3][j+3] == 1)
                return 1;
        }
    }
    // horizontalCheck
    for (int i = 1; i<7 ; i++ ){
        for (int j = 0; j<=3; j++){
            if (board[i][j] == 2 && board[i][j+1] == 2 && board[i][j+2] == 2 && board[i][j+3] == 2){
                return 1;
            }
        }
    }
    // verticalCheck
    for (int i = 1; i<=3 ; i++ ){
        for (int j = 0; j<=6; j++){
            if (board[i][j] == 2 && board[i+1][j] == 2 && board[i+2][j] == 2 && board[i+3][j] == 2){
                return 1;
            }
        }
    }
     // ascendingDiagonalCheck
    for (int i=3;i>=1; i--){
        for (int j=0; j<4; j++){
            if (board[i][j] == 2 && board[i+1][j+1] == 2 && board[i+2][j+2] == 2 && board[i+3][j+3] == 2)
                return 1;
        }
    }
    // descendingDiagonalCheck
    for (int i=6; i>=1; i--){
        for (int j=0; j<4; j++){
            if (board[i][j] == 2 && board[i-1][j+1] == 2 && board[i-2][j+2] == 2 && board[i-3][j+3] == 2)
                return 1;
        }
    }
    return 0;
}
void welcome_Code_Of_Duty(){
    printf("Welcome to CONNECT 4!\n\n");
    printf("        Rules and how to play:\n");
    printf("1. The game board has seven columns and six rows.\n");
    printf("2. There are 21 red and 21 yellow tokens.\n");
    printf("3. One player plays with red tokens, the other with yellow tokens.\n");
    printf("4. The tokens are inserted at the top of a column, and they will fall down and land on the ground (if the column was empty) or on top of a previously inserted token.\n");
    printf("5. Red starts.\n");
    printf("6. Red and yellow take turns.\n");
    printf("7. One can only insert tokens in one of the seven columns.\n");
    printf("8. One cannot insert a token into a column that is full.\n");
    printf("9. A line consists of several tokens, either in vertical, horizontal, or diagonal form, which contain only tokens of the same color.\n");
    printf("10. A player wins if they manage to form a line of four tokens of their color.\n");
    printf("11. The game ends if one of the players wins.\n");
    printf("12. There will be no ties. In case of a tie on the board, the player that took less over-all time wins.\n");
}
int tie_Code_Of_Duty(int count){
if(count==42) return 1;
else return 0;
}
int flipCoin_Code_Of_Duty()
{
    srand(time(NULL));
    if (rand() % 2 == 0)
        return 1;
    else
        return 0;
}
int wrongColumn_Code_Of_Duty(int n){
    if(n>7 || n<1) return 1;
    else return 0;
}
int main(){
  //  clock_t start_tf, end_tf;
//    double total_t;
time_t Start1, Start1while, End1, End1while;
time_t Start2, Start2while, End2, End2while;
    int count=0;
    double elapsed1, elapsed2;
    char player1Name[50],player2Name[50];
    int numBlock;
    welcome_Code_Of_Duty();     
    printf("Player 1 name:\n>");
    scanf("%s",player1Name);
    printf("Player 2 name:\n>");
    scanf("%s",player2Name);
    printf("Welcome %s and %s to Connect 4\n",player1Name,player2Name);
    draw_Code_Of_Duty(board);
    int turn;
    int n;
    if (flipCoin_Code_Of_Duty()==1){printf("%s will play first\n", player1Name);
    turn = 1;
        printf("Please insert number 1-7\n> ");
        printf("> ");
        time(&Start1);
       // start_t = clock();
        scanf("%d",&n);
        while(wrongColumn_Code_Of_Duty(n)==1){
        printf("Wrong column number, please try again\n");
        scanf("%d", &n);
    } 
       // end_t = clock();
        if (n>=1 && n<=7){ 
    n=n-1;
     play_Code_Of_Duty(n,turn,board);
     time(&End1);
     count++;
        draw_Code_Of_Duty(board);
    }
        turn = 2;
        
        printf("Now, %s will play\n", player2Name);
    }
    else {printf("%s will play first\n", player2Name); turn = 2;
     printf("Please insert number 1-7\n> ");
        printf("> ");
        time(&Start2);
        scanf("%d",&n);
    while(wrongColumn_Code_Of_Duty(n)==1){
        printf("Wrong column number, please try again\n");
        scanf("%d", &n);
    }    
        if (n>=1 && n<=7){ 
    n=n-1;
     play_Code_Of_Duty(n,turn,board);
     time(&End2);
     count++;
        draw_Code_Of_Duty(board);}
        turn = 1;
        printf("Now, %s will play\n", player1Name);
    }
    while (1)    
    {
            printf("Please insert number 1-7\n> ");
            if(turn==2) {time(&Start2while);}
            else{time(&Start1while);}
            scanf("%d",&n);
             while(isFullColumn_Code_Of_Duty(board, n-1)==1){
            printf("This column is full. Please try again\n");
            scanf("%d", &n);}
        n = n-1;                
        play_Code_Of_Duty(n,turn,board);
        if(turn==2){time(&End2while);}
        else {time(&End1while);}
        count++;
        draw_Code_Of_Duty(board);            
        bool check = checkWin_Code_Of_Duty(board);   
        if (check == 1){     
            if (turn == 1){
                printf("%s is Winner",player1Name);           break;                       
            }
            else
            {
                printf("%s is Winner",player2Name);           break;     
            }
        }
        else if(tie_Code_Of_Duty(count)==1){
            printf("tie\n");
            elapsed1=difftime(End1, Start1);
            elapsed1=elapsed1+difftime(End1while, Start1while);
            elapsed2=difftime(End2, Start2);
            elapsed2=elapsed2+difftime(End2while, Start2while);
            if(elapsed1<elapsed2){printf("%s is Winner by speed", player1Name);
                break;
            }
            else if (elapsed1>elapsed2){printf("%s is Winner by speed", player2Name); break;}
        }
        if(turn == 2){  
            turn = 1;
        }
        else
        {
            turn = 2;
        }
    }
    return 0;
}
