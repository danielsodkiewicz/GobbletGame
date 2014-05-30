//
//  Created by Daniel Sodkiewicz on 4/11/14.
//  Copyright (c) 2014 Daniel Sodkiewicz. All rights reserved.
// https://www.youtube.com/watch?v=XE6YYMn_334
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <fstream>
#include <cmath>


using namespace std;

// functions
int score(int array[], int);
void cparray(int array1[], int array2[]);
int usestack(int, int );
int getstack(int, int );
void showboard();
bool legalmove(int,int,int);
void move(int, int, int);
bool makemove(int, int, int, int, int, int);
int winner();

// 3 stacks with goblets for each player
stack <int> player_1a;
stack <int> player_1b;
stack <int> player_1c;

stack <int> player_2a;
stack <int> player_2b;
stack <int> player_2c;



int isthereawinner = 0;

// game board - empty
int board[4][4] = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
};



// from b1 to b2
void cparray(int b1[4][4], int b2[4][4]) {
    
    for (int i(0); i < 4; i++)
        for(int ii(0); ii < 4; ii++)
        {
            b2[ii][i]= b1[ii][i];
         
        }
    
}


// board stacks
// board_xy

stack <int> board_00;
stack <int> board_01;
stack <int> board_02;
stack <int> board_03;

stack <int> board_10;
stack <int> board_11;
stack <int> board_12;
stack <int> board_13;

stack <int> board_20;
stack <int> board_21;
stack <int> board_22;
stack <int> board_23;

stack <int> board_30;
stack <int> board_31;
stack <int> board_32;
stack <int> board_33;



void showboard() {
    
    for(int i =0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (board [j][i] >= 0) cout << " ";
            cout << board [j][i];
        }
        cout<<endl;
    }
    
    int p1a = 0;
    int p1b = 0;
    int p1c = 0;
    int p2a = 0;
    int p2b = 0;
    int p2c = 0;
    
    if(!player_1a.empty()) p1a = player_1a.top();
    if(!player_1b.empty()) p1b = player_1b.top();
    if(!player_1c.empty()) p1c = player_1c.top();
    
    if(!player_2a.empty()) p2a = player_2a.top();
    if(!player_2b.empty()) p2b = player_2b.top();
    if(!player_2c.empty()) p2c = player_2c.top();
    
    cout << endl << "Player 1: " << p1a << p1b << p1c <<endl;
    cout << "Player 2: " << " " << p2a << " " << p2b<<" " << p2c << endl << endl << "---------"<<endl<<endl;

}


// winner?  0: no, 1: player 1, 2: player 2
int winner() {
   
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int p4 = 0; // how many of your goblets in a row
    
    for (int i=0 ; i<4; i++)
    {
        p1 = 0;
        p2 = 0;
   
        
        
        
        for (int j=0 ; j<4; j++)
        {
            // player 1 negative
          
                if (board[i][j]<0) p1++;
                
                if (board[j][i]<0) p2++;
                
                if (board[i][i]<0 && j==0) p3++; // diagonal 1
                
                if (board[3-i][i]<0 && j==0) p4++; // diagonal 2
  
            
        }
        
        if (p1==4) return 1;
        if (p2==4) return 1;
        if (p3==4) return 1;
        if (p4==4) return 1;
    }
        
    p3 = 0;
    p4 = 0;
    
    for (int i=0 ; i<4; i++)
        {
            p1 = 0;
            p2 = 0;
           

            for (int j=0 ; j<4; j++)
         {
             //  player 2 positive
             if (board[i][j]>0) p1++;
        
             if (board[j][i]>0) p2++;
        
             if (board[i][i]>0 && j==0) p3++; // diagonal 1
        
             if (board[3-i][i]>0 && j==0) p4++; // diagonal 2
        
         }
            if (p1==4) return 2;
            if (p2==4) return 2;
            if (p3==4) return 2;
            if (p4==4) return 2;
        }
 

    return 0;
}



// calculate quality of move
int score(int boardw[4][4], int player) {
    int score = 0 ;
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int p4 = 0; // how many of your goblet in a row
  
    for (int i=0 ; i<4; i++)
    {
        p1 = 0;
        p2 = 0;
        p3 = 0;
        p4 = 0;
        
        for (int j=0 ; j<4; j++)
        {
            if(player==1)  //negative
            {
                if (boardw[i][j]<0) p1++;
                if (boardw[i][j]>0) p1--;
         
                if (boardw[j][i]<0) p2++;
                if (boardw[j][i]>0) p2--;
         
                if (boardw[j][j]<0 && i==0) p3++; // diagonal 1
                if (boardw[j][j]>0 && i==0) p3--; // diagonal 1
                
                if (boardw[3-j][j]<0 && i==0) p4++; // diagonal 2
                if (boardw[3-j][j]>0 && i==0) p4--; // diagonal 2
                
            } else {
                if (boardw[i][j]>0) p1++;
                if (boardw[i][j]<0) p1--;
               
                  if (boardw[j][i]>0) p2++;
                  if (boardw[j][i]<0) p2--;
                
                  if (boardw[j][j]>0 && i==0) p3++; // diagonal 1
                  if (boardw[j][j]<0 && i==0) p3--; // diagonal 1
                
                  if (boardw[3-j][j]>0 && i==0) p4++; // diagonal 2
                  if (boardw[3-j][j]<0 && i==0) p4--; // diagonal 2
            }
            
        }
        
        if (p1==4) score+=1000;
        if (p1==3) score+=50;
        if (p1==2) score+=2;
        
        if (p2==4) score+=1000;
        if (p2==3) score+=50;
        if (p2==2) score+=2;
        
        if (p3==4) score+=1000;
        if (p3==3) score+=50;
        if (p3==2) score+=2;
        
        if (p4==4) score+=1000;
        if (p4==3) score+=50;
        if (p4==2) score+=2;
        
        
        
        
    }
    return score;
}

// a - your goblet
// x, y - coordinates
bool legalmove(int a, int x, int y)
{
    
    if (abs(board[x][y])<abs(a)) return true;
    else return false;
    
}

// for player 2
void nextbestmove() {
    
    int boardcopy[4][4];
    int boardcopy2[4][4];
    int scorenr=0;
    int scorenrmin=999999;
    
    int scorenr_player1=0;
    int moveX=0;
    int moveY=0;
    
    int movetype = -1; // 1 take from stacks, 0 take from board
    int fromX=0;
    int fromY=0;
    int fromStack = 0;
    
    int movetypefinal = 0;
    int fromXfinal=0;
    int fromYfinal=0;
    int fromStackfinal = 0;
    
    cparray(board,boardcopy);
    
    // move player 2
    
    for (int movenr = 0; movenr<1; movenr++) {
        for (int x(0); x < 4; ++x) {
            for(int y(0); y < 4; ++y) {
                
                // 1 if (board[x][y]==0)
                
                //2
                if (abs(board[x][y])<4)
                {
                    
                    
                 
                    // 2 consiodering putting pieces over each other from stacks
                    if ( board[x][y]!=0 ){
                        movetype = 0;
                        if(abs(board[x][y])<getstack(2,1))  {
                            boardcopy[x][y] = getstack(2,1);
                            fromStack = 1;
                        }
                        else if(abs(board[x][y])<getstack(2,2)) {
                            boardcopy[x][y] = getstack(2,2);
                            fromStack = 2;
                        }
                        else if(abs(board[x][y])<getstack(2,3)) {
                            boardcopy[x][y] = getstack(2,3);
                            fromStack = 3;
                        }
                        
                        fromX=0; // not used yet
                        fromY=0; // not used yet
                        
                    }
                    else {
                     movetype = 1;
                     boardcopy[x][y]=1;
                    }
                    
                    
                    
                    // simple version
                    // 1 boardcopy[x][y]=1;
                    
               
           
                    scorenr_player1=0;
                    
                    
                    cparray(boardcopy,boardcopy2);
                    
                    // check next best move for player 1
                    for (int xx(0); xx < 4; ++xx) {
                        for(int yy(0); yy < 4; ++yy) {
                            
                            // if (boardcopy2[xx][yy]==0)
                            if (abs(boardcopy2[xx][yy])<4)
                            {
                                
                                // 2 consiodering putting pieces over each other from stacks
                                if ( boardcopy2[x][y]!=0 ){
                            
                                    if(abs(boardcopy2[x][y])<getstack(1,1)) boardcopy2[x][y] = getstack(1,1);
                                    else if(abs(boardcopy2[x][y])<getstack(1,2)) boardcopy2[x][y] = getstack(1,2);
                                    else if(abs(boardcopy2[x][y])<getstack(1,3)) boardcopy2[x][y] = getstack(1,3);
                                }
                                else {
                                    
                                    boardcopy2[x][y]=1;
                                }

                                
                                
                                // 1
                                // boardcopy2[xx][yy]=-1;
                                
                                
                                
                                                          /*
                                for(int i =0; i<4; i++)
                                {
                                    for (int j=0; j<4; j++)
                                    {
                                        if (boardcopy[j][i] >= 0) cout << " ";
                                        cout << boardcopy[j][i];
                                    }
                                    cout<<endl;
                                }
                             */
                              
                                
                                
                                if ( scorenr_player1 < score(boardcopy2,1))
                                {
                                    scorenr_player1 = score(boardcopy2,1);
                                   
                             //       cout<< "--" << endl;
                             //       cout << "Player 2: "  <<score(boardcopy,2) << " x: " << x << " y:"<< y << endl;
                             //       cout << "Player 1: " << score(boardcopy2,1) << " x: " << xx << " y:"<< yy << endl;
                                    

                                    
                                }
                                cparray(boardcopy,boardcopy2);
                            }
                        }
                    }
                    
                    // WHAT IS scorenr here ??????????????????????????????????????
               //     cout<< "* Scorenrmin: " << scorenrmin<< " scorenr_player1:" << scorenr_player1 << endl;
                    
             //       if ( scorenr< score(boardcopy,2) && scorenrmin >= scorenr_player1 )
              //      if ( (scorenrmin > scorenr_player1) || (scorenrmin<50 && scorenr< score(boardcopy,2) ))
                     if ( (scorenrmin > scorenr_player1))
                    {
                        
                        scorenrmin = scorenr_player1;
                        scorenr = score(boardcopy,2);
                        moveX = x;
                        moveY = y;
                        
                        
                        
                        if (movetype == 0) {
                            
                            movetypefinal = 0;
                            
                            fromXfinal = fromX; // not used yet
                            fromYfinal = fromY; // not used yet
                            fromStackfinal = fromStack;
                            
                        } else movetypefinal = 1;
                        
                       
                        
                        
                        
                        
                        
                        
                     //   cout<< "** CHANGE Scorenrmin: " << scorenrmin<< " scorenr_player1:" << scorenr_player1 << endl;
                        
                    //    cout << x << y << " score: " << scorenr << endl;
                    //   cout << x << y << " MAX: " << scorenr << " | MIN:" << scorenrmin << endl;
                        
                    } else if (scorenr< score(boardcopy,2) && scorenr_player1 < 50 )
                    {
                        
                        scorenrmin = scorenr_player1;
                        scorenr = score(boardcopy,2);
                        moveX = x;
                        moveY = y;
                        
                        if (movetype == 0) {
                            
                            movetypefinal = 0;
                            
                            fromXfinal = fromX; // not used yet
                            fromYfinal = fromY; // not used yet
                            fromStackfinal = fromStack;
                            
                        } else movetypefinal = 1;
                        
                        
                    }
                    
                    
                    
                    cparray(board,boardcopy);
                }
            }
        }
    }
    
   
    if (movetypefinal == 1) {
        
       cout << "Best move for player 2. x:" << moveX << ", y:" << moveY << " score: " << scorenr << ". With scorenr_player1:" << scorenr_player1 << endl ;
        
    } else {
        
        cout << "Best move for player 2. Take from stack " << fromStack << " and cover gabble located at x:" << moveX << ", y:" << moveY << " score: " << scorenr << ". With scorenr_player1:" << scorenr_player1 << endl ;
    }
 
  
    

    
    
}


// g==0  move up, g==1 move down number
void move(int g, int x, int y)
{
    if (g!=0)
    {
        if (x==0 && y==0) { board_00.push(g);  board[0][0] = g; }
        if (x==0 && y==1) { board_01.push(g);  board[0][1] = g; }
        if (x==0 && y==2) { board_02.push(g);  board[0][2] = g; }
        if (x==0 && y==3) { board_03.push(g);  board[0][3] = g; }
    
        if (x==1 && y==0) { board_10.push(g);  board[1][0] = g; }
        if (x==1 && y==1) { board_11.push(g);  board[1][1] = g; }
        if (x==1 && y==2) { board_12.push(g);  board[1][2] = g; }
        if (x==1 && y==3) { board_13.push(g);  board[1][3] = g; }
    
        if (x==2 && y==0) { board_20.push(g);  board[2][0] = g; }
        if (x==2 && y==1) { board_21.push(g);  board[2][1] = g; }
        if (x==2 && y==2) { board_22.push(g);  board[2][2] = g; }
        if (x==2 && y==3) { board_23.push(g);  board[2][3] = g; }
    
        if (x==3 && y==0) { board_30.push(g);  board[3][0] = g; }
        if (x==3 && y==1) { board_31.push(g);  board[3][1] = g; }
        if (x==3 && y==2) { board_32.push(g);  board[3][2] = g; }
        if (x==3 && y==3) { board_33.push(g);  board[3][3] = g; }
    }
    else
    {
        if (x==0 && y==0) { board_00.pop(); if (!board_00.empty()) { board[0][0] = board_00.top(); } else board[0][0] = 0; }
        if (x==0 && y==1) { board_01.pop(); if (!board_01.empty()) { board[0][1] = board_01.top(); } else board[0][1] = 0; }
        if (x==0 && y==2) { board_02.pop(); if (!board_02.empty()) { board[0][2] = board_02.top(); } else board[0][2] = 0; }
        if (x==0 && y==3) { board_03.pop(); if (!board_03.empty()) { board[0][3] = board_03.top(); } else board[0][3] = 0; }
        
        if (x==1 && y==0) { board_10.pop(); if (!board_10.empty()) { board[1][0] = board_10.top(); } else board[1][0] = 0; }
        if (x==1 && y==1) { board_11.pop(); if (!board_11.empty()) { board[1][1] = board_11.top(); } else board[1][1] = 0; }
        if (x==1 && y==2) { board_12.pop(); if (!board_12.empty()) { board[1][2] = board_12.top(); } else board[1][2] = 0; }
        if (x==1 && y==3) { board_13.pop(); if (!board_13.empty()) { board[1][3] = board_13.top(); } else board[1][3] = 0; }
        
        if (x==2 && y==0) { board_20.pop(); if (!board_20.empty()) { board[2][0] = board_20.top(); } else board[2][0] = 0; }
        if (x==2 && y==1) { board_21.pop(); if (!board_21.empty()) { board[2][1] = board_21.top(); } else board[2][1] = 0; }
        if (x==2 && y==2) { board_22.pop(); if (!board_22.empty()) { board[2][2] = board_22.top(); } else board[2][2] = 0; }
        if (x==2 && y==3) { board_23.pop(); if (!board_23.empty()) { board[2][3] = board_23.top(); } else board[2][3] = 0; }
        
        if (x==3 && y==0) { board_30.pop(); if (!board_30.empty()) { board[3][0] = board_30.top(); } else board[3][0] = 0; }
        if (x==3 && y==1) { board_31.pop(); if (!board_31.empty()) { board[3][1] = board_31.top(); } else board[3][1] = 0; }
        if (x==3 && y==2) { board_32.pop(); if (!board_32.empty()) { board[3][2] = board_32.top(); } else board[3][2] = 0; }
        if (x==3 && y==3) { board_33.pop(); if (!board_33.empty()) { board[3][3] = board_33.top(); } else board[3][3] = 0; }
    }
    
    
  
}

// player | TO: x ,y  FROM: stack = 0(board), 1, 2, 3  | ,   x0 and y0 when stack = 0

// makemove(1,0,0,2): player 1, takes gable from stack 2 and moves to  0 0
// makemove(2,3,3,0,1,1): player 2, takes gable from board 1 1 and moves to 3 3
bool makemove(int player, int x, int y, int stack, int x0 = 0, int y0 = 0)
{
    int g; // gablet to move
    
    
    //legal?
    if (stack==0)
    {
        g = board[x0][y0];
        if (player==1 && g>0) return false;
        if (player==2 && g<0) return false;
        if(!legalmove(g,x,y)) return false;
    }
    else
    {
        g = getstack(player,stack);
        if(!legalmove(g,x,y)) return false;
    }
    
    
    // take from board
    if (stack==0)
    {
        g = board[x0][y0];
        move(0,x0,y0);  // up
        
        // !!!!!!! HERE WE MUST CHECK IF AFTER MOVING IT UP SOMEBODY IS WINNING?
        isthereawinner = winner();
            
        move(g,x,y);    // down
    } else {
        g = usestack(player,stack);
        move(g,x,y);    // down
    }
    
    return true;
    
}


int getstack(int player,int stacknr)
{
    
    int x ;
    
    if (player == 1 ){
        
        if(stacknr==1)
        {
            if (!player_1a.empty()) { x = player_1a.top();   return x; }
            else return 0;
        }
        
        if(stacknr==2)
        {
            if (!player_1b.empty()) { x = player_1b.top();   return x; }
            else return 0;
        }
        
        if(stacknr==3)
        {
            if (!player_1c.empty()) { x = player_1c.top();  return x; }
            else return 0;
        }
        
    } else if (player == 2) {
        
        if(stacknr==1)
        {
            if (!player_2a.empty()) { x = player_2a.top();   return x; }
            else return 0;
        }
        
        if(stacknr==2)
        {
            if (!player_2b.empty()) { x = player_2b.top();   return x; }
            else return 0;
        }
        
        if(stacknr==3)
        {
            if (!player_2c.empty()) { x = player_2c.top();   return x; }
            else return 0;
        }
        
    }
    return 0;
    
}

// take goblets from stacks, returns 0 when empty
int usestack(int player, int stacknr)
{
    int x ;
    
    if (player == 1 ){
        
        if(stacknr==1)
        {
            if (!player_1a.empty()) { x = player_1a.top();  player_1a.pop(); return x; }
            else return 0;
        }
        
        if(stacknr==2)
        {
            if (!player_1b.empty()) { x = player_1b.top();  player_1b.pop(); return x; }
            else return 0;
        }
        
        if(stacknr==3)
        {
            if (!player_1c.empty()) { x = player_1c.top();  player_1c.pop(); return x; }
            else return 0;
        }
        
    } else if (player == 2) {
        
        if(stacknr==1)
        {
            if (!player_2a.empty()) { x = player_2a.top();  player_2a.pop(); return x; }
            else return 0;
        }
        
        if(stacknr==2)
        {
            if (!player_2b.empty()) { x = player_2b.top();  player_2b.pop(); return x; }
            else return 0;
        }
        
        if(stacknr==3)
        {
            if (!player_2c.empty()) { x = player_2c.top();  player_2c.pop(); return x; }
            else return 0;
        }
    
    }
    return 0;
}







int main(int argc, const char * argv[])
{
    
    // test scrore
    /*
    board[1][1] = -1;
    board[0][1] = -2;
    board[2][1] = -2;
    
    board[2][2] = -2;

    cout<< "score: "<<  score(board, 0);
    
    */
    
    // test legalmove
   /*
     board[1][1] = -1;
     board[0][1] = -2;
     board[2][1] = -2;
     
    
     
     cout<< "legalmove 1: "<<  legalmove(2,1,1)<<endl;
     cout<< "legalmove 2: "<<  legalmove(2,2,1);
    
    */

    
    

    
    // initiala stacks with goblets
    
    player_1a.push(-1);
    player_1a.push(-2);
    player_1a.push(-3);
    player_1a.push(-4);
    
    player_1b.push(-1);
    player_1b.push(-2);
    player_1b.push(-3);
    player_1b.push(-4);
    
    player_1c.push(-1);
    player_1c.push(-2);
    player_1c.push(-3);
    player_1c.push(-4);
    
    player_2a.push(1);
    player_2a.push(2);
    player_2a.push(3);
    player_2a.push(4);
    
    player_2b.push(1);
    player_2b.push(2);
    player_2b.push(3);
    player_2b.push(4);
    
    player_2c.push(1);
    player_2c.push(2);
    player_2c.push(3);
    player_2c.push(4);
    
    
 //   showboard();

    int c_player = 1;
    int c_stack;
    int c_x;
    int c_y;
    int c_x0;
    int c_y0;
    int round = 0;
    
    showboard();
    
    while (!winner() && !isthereawinner) {
        
        cout << "Player " << c_player <<endl;
        if (c_player==2 && round > 1) nextbestmove();
        cout << "Select stack [1],[2],[3] or move gable from board [0]" <<endl;
        cin >> c_stack;
        
        if (c_stack==0)
        {
            cout << "Select location on gable you want to move (0 1 2 3)" <<endl;
            cout << "x:" <<endl;
            cin >> c_x0;
            cout << "y:" <<endl;
            cin >> c_y0;
            
            cout << "Select where you want to move (0 1 2 3)" <<endl;
            cout << "x:" <<endl;
            cin >> c_x;
            cout << "y:" <<endl;
            cin >> c_y;
            
            makemove(c_player,c_x,c_y,0,c_x0,c_y0);
        } else {
            cout << "Select where you want to move (0 1 2 3)" <<endl;
            cout << "x:" <<endl;
            cin >> c_x;
            cout << "y:" <<endl;
            cin >> c_y;
            
            makemove(c_player,c_x,c_y,c_stack);
        }
        showboard();
   //    cout << "Player 1 score: " << score(board,1) << endl;
   //     cout << "Player 2 score: " << score(board,2) << endl;
        if (c_player==1) c_player=2;
        else c_player=1;
        
        round++;
    }
    
   
    if (isthereawinner == 1) cout << "Player 1 winning!" <<endl;
    else if (isthereawinner == 2) cout << "Player 2 winning!" <<endl;
    else if (winner() == 1) cout << "Player 1 winning!" <<endl;
    else if (winner() == 2) cout << "Player 2 winning!" <<endl;
    

    
    return 0;
}

