#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
//double elapsed1, elapsed2;
// elapsed1 is for player 1 and elapsed2 is for player 2
// initialized the board as double pointer 2d int array
int **board[6][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
    };
/*
effects: This function drops a token of the specified player (tokens made as integers (1 or 2)) into the specified column taking turns
with the 2 players. 
requires: 
the column not to be full, but I didn't write it in the play function since I checked if the column is full in the main function,
and then display the play function if the column is not full. 
*/   
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
/* requires: valid column number (between 0 and 6) note: this issue is held in the main (checking valid column number then seeing if
   the column is full or not) 
   effects: this function upon entering a valid column number will check if this column is filled with tokens fully
*/
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
/* requires: the board (2d array) we want to draw
   effects: this function will draw the board. I didn't put update board function since in the main after calling the play function,
   the 2d int array will change and store the values after the playing, and thus i will call the draw function which will draw the
   updated board.
*/        
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
/*  requires: row and col are within bounds of the array, so I fixed this in the conditions for the loops like: for(int i=1;i<7;i++).
    Here, i should be less than 7 for the function to work correctly for row size: 6 and column size: 7. A coder or a professional client
    can change the implementation inside if he/she wants sizes other than the mentioned above, but he/she should be careful for the
    bounds of the board.
    effects: returns true if 4 tokens of the same kind are connected together (either horizontally, vertically or diagonally) which will 
    be a winning event.  
 */
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
// welcome function which welcomes players and states basic rules for connect 4 game
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
/* requires: all empty spaces to be filled without having a winning event.
   effects: specifies if there is a tie between the players or not.
*/
int tie_Code_Of_Duty(int count){
if(count==42) return 1;
else return 0;
}
/* requires: nothing
   effects: chooses a player randomly to start first in the game.
*/
int flipCoin_Code_Of_Duty()
{
    srand(time(NULL));
    if (rand() % 2 == 0)
        return 1;
    else
        return 0;
}
/* requires: an integer to be passed
   effects: checks if the column number that is entered by the user is a valid column number or not 
   (negative numbers and 0 can't be correct in addition to numbers greater than 7).
*/
int wrongColumn_Code_Of_Duty(int n){
    if(n>7 || n<1) return 1;
    else return 0;
}
/* requires: double pointer 2d int arrays
   effects: this function copies the values and the elements of one double pointer 2d int array to another one.
*/
void copy_Code_Of_Duty (int** board[6][7], int** copied[6][7]){
   for(int i=0;i<6;i++){
       for(int j=0;j<7;j++){
           copied[i][j]=board[i][j];}
   }
}
/* requires: valid column and row numbers to be entered
   effects: checks if a given position is empty or filled with a certain token
*/
        int checkEmpty_Code_Of_Duty(int** board[6][7], int col, int row) {
     if(board[row][col]==0) {return 1;}
     else return 0;}
/* requires: we have to check if a given position is empty so that we can insert a value (a token) at this position.
   effects: sets the given value of the token at the place defined by the row and column numbers. This position should be empty
   to set the value. 
*/     
void setValue_Code_Of_Duty(int** board[6][7], int col, int row, int c){
     if(checkEmpty_Code_Of_Duty(board, col, row)){
     board[row][col] = c;}}
int drop_Code_Of_Duty (int** board[6][7], int col, int c) {
    if (isFullColumn_Code_Of_Duty(board, col)) return 0;
    for(int row = 5; row >= 0; row--) {
        setValue_Code_Of_Duty(board, col, row, c);
        break;}
    return 1; }
/*  requires: row and col are within bounds of the array, so I fixed this in the conditions for the loops like: for(int i=1;i<7;i++).
    Here, i should be less than 7 for the function to work correctly for row size: 6 and column size: 7. A coder or a professional client
    can change the implementation inside if he/she wants sizes other than the mentioned above, but he/she should be careful for the
    bounds of the board.
    effects: after finding 4 tokens of the same kind connected together (either horizontally, vertically, or diagonally), this function
    will identify the kind of the these 4 tokens and will determine which token has won the game.
*/    
char getWinner_Code_Of_Duty(int **board[6][7]) {
    // horizontalCheck
    int c=0;
    for (int i = 1; i<7 ; i++ ){
        for (int j = 0; j<=3; j++){
            if (board[i][j] == 1 && board[i][j+1] == 1 && board[i][j+2] == 1 && board[i][j+3] == 1){
                c = 1;
            }
        }
    }
    // verticalCheck
    for (int i = 1; i<=3 ; i++ ){
        for (int j = 0; j<=6; j++){
            if (board[i][j] == 1 && board[i+1][j] == 1 && board[i+2][j] == 1 && board[i+3][j] == 1){
                c=1;
            }
        }
    }
     // ascendingDiagonalCheck
    for (int i=3;i>=1; i--){
        for (int j=0; j<4; j++){
            if (board[i][j] == 1 && board[i+1][j+1] == 1 && board[i+2][j+2] == 1 && board[i+3][j+3] == 1)
                c=1;
        }
    }
    // descendingDiagonalCheck
    for (int i=6; i>=1; i--){
        for (int j=0; j<4; j++){
            if (board[i][j] == 1 && board[i-1][j+1] == 1 && board[i-2][j+2] == 1 && board[i-3][j+3] == 1)
                c=1;
        }
    }
    // horizontalCheck
    for (int i = 1; i<7 ; i++ ){
        for (int j = 0; j<=3; j++){
            if (board[i][j] == 2 && board[i][j+1] == 2 && board[i][j+2] == 2 && board[i][j+3] == 2){
                c=2;
            }
        }
    }
    // verticalCheck
    for (int i = 1; i<=3 ; i++ ){
        for (int j = 0; j<=6; j++){
            if (board[i][j] == 2 && board[i+1][j] == 2 && board[i+2][j] == 2 && board[i+3][j] == 2){
                c=2;
            }
        }
    }
     // ascendingDiagonalCheck
    for (int i=3;i>=1; i--){
        for (int j=0; j<4; j++){
            if (board[i][j] == 2 && board[i+1][j+1] == 2 && board[i+2][j+2] == 2 && board[i+3][j+3] == 2)
                c=2;
        }
    }
    // descendingDiagonalCheck
    for (int i=6; i>=1; i--){
        for (int j=0; j<4; j++){
            if (board[i][j] == 2 && board[i-1][j+1] == 2 && board[i-2][j+2] == 2 && board[i-3][j+3] == 2)
                c=2;
        }
    }
    return c;
    }
/* requires: a winner that is important to find for the bot move algorithm.
   effects: this function will play random games and at the end of each game, it will identity if there is a winner or not to
   to the game and it will return the value of the winner token or zero if there is a tie. (note: here ignoring the time-winning case
   for simplicity).
*/
char randomGame_Code_Of_Duty(int** board[6][7]){
    for(int i=0; i<10;i++){
    int col1=rand()%6;
    int col2=rand()%6;
    drop_Code_Of_Duty(board, col1, 1);
    drop_Code_Of_Duty(board, col2, 2);
    }
    char winner=getWinner_Code_Of_Duty(board);
    if(winner==1||winner==2)
    return winner;
    else return 0;
}
/*This function takes the `board` array and the `player` number as input, and returns the number of discs on the board that belong to
 the specified player. It does this by iterating over all the elements of the board and counting the number of elements that match the
 player number.*/
int countDiscs_Code_Of_Duty(int** board, int player) {
    const int ROWS = 6;
    const int COLS = 7;
    int count = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == player) {
                count++;
            }
        }
    }
    return count;
}
/* 
requires: the helper functions that I implemented and used for the bot move all include an argument as int ** board[6][7], but for the
competition and the project the argument should be as int ** board, so the first thing required to do is accessing the int ** board
elements and then allocate them in an int** board[6][7] in order to be able to call the helper functions I designed. 
effects: this function will return a column number representing a bot move. This function is based on Monte Carlo algorithm
and probabilities. 
Explanation of algorithm of the function:
Suggest a move among the (at max) 7 possible. For each move we play random games and store the ratio between won and lost games.
Finally the move with the best ratio is returned. If there is no valid moves, -1 is returned. This is one of the simplest implementation 
of a connect four AI we can write, yet it is strong enough to play with humans showing to be a capable opponent. The implementation uses
the Monte Carlo methods class of algorithms: for every potential move the bot can do, it does it and then plays random games, 
sampling the number of games won and lost. Then the decision on what move to make is made based on the move that appears to have the
best won/lost ratio. The code is very simple but there is space for optimizations. I will be working on the optimizations later to make 
my function more accurate.
testing for bot move and helper functions: At first, I will check if the row at the bottom is empty. If it is, then my bot is the first player to play in the game. 
Therefore, for testing for this, the the elements in the bottom row in the 2d array that I passed to the function will all be zeroes
and I will check if my bot will be the first player to play or not. If the bottom row is not empty and contains a token in one of the 
columns, then my bot is the second player to play. To test this, I put a token (either the value 1 or the value 2) at any column in the 
bottom row and see the effect. The copy function will help me to get a temporary 2d array which is used to perform the random games 
separartely from the main 2d array and have the calculations. For testing it, I passed with for loops on every element of the new copied
array and checked if it is equal to the original one (note: here the size of the rows and the size of the columns are fixed, so the
testing for these sizes only is enough for my purpose). The drop function will help me to drop and set a value at a specific row/column 
position. To test this, I tried to set a value of an empty position twice (first one with value 1 and the second with the value 2), I then
tried to set a value on a non-empty position and see what happens. getWinner function has the same testing as checkWin function (the
testing of checkWin is in another document). randomGame function will generate different scenarios of playing a game. To test it, I 
tested it by a large number of games and see if there were random results like my bot winning, losing, or if we have a tie. If the
results were all the same, then there is something wrong. If the results contained only 2 result-possibilities (like winnig
and losing or winning and tie or losing and tie), then there is something wrong. For testing the bot move in all, I played with the bot
several times and started putting values that will aim to help me connect 4 tokens to win, and I observed how will my bot will respond
to my moves (will it let me win or will it block it?). Also, I tried to put for the bot 3 tokens (either horizontally, vertically, or
diagonally) to see if the bot will put the winning token or not.
*/
int make_move_Hard_Code_Of_Duty(int** board, int player) {
    const int ROWS = 6;
    const int COLS = 7;
    int copied[ROWS][COLS];
    int availableMoves = 0;
    int bestMove = -1;
    double bestRatio = 0.0;
    int gamesPerMove = 10000;

    // Count the number of available moves
    for (int col = 0; col < COLS; col++) {
        if (!isFullColumn_Code_Of_Duty(board, col)) {
            availableMoves++;
        }
    }

    // If there are no available moves, return -1
    if (availableMoves == 0) {
        return -1;
    }

    // Find the best move
    for (int move = 0; move < COLS; move++) {
        if (isFullColumn_Code_Of_Duty(board, move)) {
            continue;
        }
        memcpy(copied, board, sizeof(copied));
        drop_Code_Of_Duty(copied, move, player);
        if (getWinner_Code_Of_Duty(copied) == player) {
            return move;
        }
        int nextPlayer = (player == 1) ? 2 : 1;
        int won = 0, lost = 0;
        for (int i = 0; i < gamesPerMove; i++) {
            int winner = randomGame_Code_Of_Duty(copied, nextPlayer);
            if (winner == player) {
                won++;
            } else if (winner != player && winner != 0) {
                lost++;
            }
        }
        double ratio = (double)won / (lost + 1);
        if (ratio > bestRatio || bestMove == -1) {
            bestMove = move;
            bestRatio = ratio;
        }
    }
    return bestMove;
}
/*
I will adjust the number of wins and losses to make the bot easier to beat. To do this, I simply changed the way the `won`
and `lost` variables are incremented in the loop that simulates random games. For example, to make the bot easier, I
increased the number of losses by incrementing `lost` whenever the other player wins, and decreased the number of wins by incrementing
`won` only when the bot wins by a certain margin. 
*/ 
int make_move_Easy_Code_Of_Duty(int** board, int player) {
    const int ROWS = 6;
    const int COLS = 7;
    int copied[ROWS][COLS];
    int availableMoves = 0;
    int bestMove = -1;
    double bestRatio = 0.0;
    int gamesPerMove = 10000;

    // Count the number of available moves
    for (int col = 0; col < COLS; col++) {
        if (!isFullColumn_Code_Of_Duty(board, col)) {
            availableMoves++;
        }
    }

    // If there are no available moves, return -1
    if (availableMoves == 0) {
        return -1;
    }

    // Find the best move
    for (int move = 0; move < COLS; move++) {
        if (isFullColumn_Code_Of_Duty(board, move)) {
            continue;
        }
        memcpy(copied, board, sizeof(copied));
        drop_Code_Of_Duty(copied, move, player);
        if (getWinner_Code_Of_Duty(copied) == player) {
            return move;
        }
        int nextPlayer = (player == 1) ? 2 : 1;
        int won = 0, lost = 0;
for (int i = 0; i < gamesPerMove; i++) {
    int winner = randomGame_Code_Of_Duty(copied, nextPlayer);
    if (winner == player) {
        // Increment won only if the bot wins by at least 2 discs
        int diff = countDiscs_Code_Of_Duty(copied, player) - countDiscs_Code_Of_Duty(copied, (player == 1) ? 2 : 1);
        if (diff >= 2) {
            won++;
        }
    } else if (winner == 0) {
        // Increment lost if the game is a tie
        lost++;
    } else {
        // Increment lost if the other player wins
        lost++;
    }
}
        double ratio = (double)won / (lost + 1);
        if (ratio > bestRatio || bestMove == -1) {
            bestMove = move;
            bestRatio = ratio;
        }
    }
    return bestMove;
}
