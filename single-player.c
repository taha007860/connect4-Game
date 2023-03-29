/*In this single player mode, the user plays against the bot. The user goes first and then the bot makes a move. The game continues until
 one of the players wins or the game ends in a tie. 

At the start of the game, the user is prompted to enter their name. The game board is then displayed and the user is prompted to enter a
number from 1 to 7 to specify which column they want to drop their piece into. The user's move is then made on the board and the board is
displayed again. 

The bot then makes a move by generating a random column number to drop its piece into. The bot's move is made on the board and the board
is displayed again.

This process continues until one of the players wins or the game ends in a tie. A player wins if they get four of their pieces in a row
(horizontally, vertically, or diagonally) before the other player does. If the board is completely filled and no player has won, the game
ends in a tie.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "Code_Of_Duty.h"
int *board[6][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};
int main(){
    int isHuman=0;
    int count=0;
    char playerName[50];
    welcome_Code_Of_Duty();     
    printf("Player name:\n>");
    scanf("%s",playerName);
    printf("Welcome %s to Connect 4\n",playerName);
    draw_Code_Of_Duty(board);
    int turn;
    int n;
    if (flipCoin_Code_Of_Duty()==1){
        printf("%s will play first\n", playerName);
        turn = 1;
        isHuman=1;
    }
    else {
        printf("bot will play first\n"); 
        turn = 2;
        isHuman=0;
        n=make_move_Hard_Code_Of_Duty(board);   
        if (n>=0 && n<=6){ 
            play_Code_Of_Duty(n,turn,board);
            time(&End2);
            count++;
            draw_Code_Of_Duty(board);
        }
        turn = 1;
        isHuman=1;
        printf("Now, %s will play\n", playerName);
    }
    while (1)    
    {
        if(turn==1&&isHuman==1){
            printf("Please insert number 1-7\n> ");
            scanf("%d",&n);
            while(wrongColumn_Code_Of_Duty(n)==1){
                printf("Wrong column number, please try again\n");
                scanf("%d", &n);
            } 
            n = n-1;
        }
        else{
            printf("bot will play\n");
            n=make_move_Code_Hard_Of_Duty(board);
        } 

        if(isFullColumn_Code_Of_Duty(board, n)==1){
            printf("This column is full. Please try again\n");
            continue;
        }
                
        play_Code_Of_Duty(n,turn,board);
        
        count++;
        draw_Code_Of_Duty(board);            
        bool check = checkWin_Code_Of_Duty(board);   
        if (check == 1){     
            if (turn == 1){
                printf("%s is Winner",playerName);           
            }
            else{
                printf("bot is Winner");     
            }
            break;
        }
        else if(tie_Code_Of_Duty(count)==1){
            printf("tie\n");
            break;
        }
        if(turn == 2){  
            turn = 1;
            isHuman=1;
            printf("Now, %s will play\n", playerName);
        }
        else{
            turn = 2;
            isHuman=0;
            printf("bot will play\n");
        }
    }
    return 0;
}
