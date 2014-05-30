Gobblet Game (C++)
===================

About Gobblet
----------------
Gobblet is a 2-player board game released in 2001. A strategy game with similarities to Checkers and Connect 4, Gobblet requires both memory and problem solving skills.  

https://www.youtube.com/watch?v=XE6YYMn_334

Game Rules
----------------

The game board consist of 16 squares in a 4x4 pattern.  Players choose either the light or dark colored pieces. There are twelve pieces for each player in four different sizes (3 pieces of each size).  The pieces are called Gobblets because of their nesting design. The larger pieces fit over top of, or gobble up, the smaller pieces.  

The players begin by arranging their Gobblets in three stacks of four Gobblets each. The player must play the Gobblets in the order they appear - larger piece to smaller piece.  

The first player places a Gobblet from their external stack anywhere on the board. The second player also places a Gobblet from their external stack anywhere on the board.  The players then take turns and do one of the following:
* place a new Gobblet on the board
* move an existing Gobblet on the board to an empty square on the board
* cover any Gobblet (theirs or their opponent’s) on the board with a larger sized Gobblet from their external stack
* cover any Gobblet (theirs or their opponent’s) on the board with a larger sized Gobblet from one of their Gobblet’s already on the board

Winning the game
----------------
The first player to align 4 Gobblets in a row either horizontally, vertically or diagonally, wins. 

About the program
==================
This program allows a user to play against a machine. It is not designed for entertainment but rather for showing how a Min Max algorithm (http://en.wikipedia.org/wiki/Minimax) can be used. 

This implementation only looks one step ahead.  The machine looks at possible moves the machine can make, and then analyzes what moves the human will make based on the machine’s move.  The machine will then determine which of the human moves leaves the human opponent in the worse position, and makes the machine move accordingly.  

The heuristics used
----------------
The algorithm calculates how many Gobblets are in a row or diagonal for a given player and assigns points:
1000 points if there are 4 in a row (the player already winning), 5 points if there are 3 Gobblets and 2 points for 2 Gobblets. This system is used to determine a numerical value for a given Gobblet arrangement on a board for a given player.

Imperfect program
----------------
This game is not perfect and you can game the system. For example, the machine does not check for the possibility of moving a Gobblet from the board to cover an opponent's Gobblet - it only considers using Gobblets from a stack to cover an opponent's Gobblets.  Also, it only checks a situation one move ahead.

However, even with these restrictions the algorithm seems to show an ‘intelligent’ behaviour.

Game interface
----------------
The interface is very simple and uses text only UX. A player makes moves for the computer based on information of how the computer wants to move. Everything is controlled by the command line.



