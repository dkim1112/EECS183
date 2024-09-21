/**
 * rps.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277c
 *
 * Dongeun Kim
 * dongeunk
 *
 * EECS 183: Project 2
 * Fall 2024
 *
 * This program lets users play the rock paper scissor game. Through multiple functions such as checking whether if the user input is a valid move or not,
 * or even just determining who wins the round, and who wins the game, it lets users to play the game with ease. It is a two player game, and each gets
 * a turn to input their moves. The person who wins more out of the 3 round is the winner of the game. There are draws as well.
 */

#include <iostream>
#include <string>

const int MAX_ROUNDS = 3;

using namespace std;

//************************************************************************
// The following four functions have already been implemented for you.
// You should use them when writing the other functions, but do not edit
// their implementations.
//************************************************************************

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints a pretty header to introduce the user to the game.
 */
void printInitialHeader();

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints the menu.
 * Prompts:  "1) Play rock, paper, scissors"
 *           "2) Play rock, paper, scissors, lizard, spock"
 *           "3) Quit"
 *           "Choice --> "
 */
void printMenu();

/**
 * Requires: errorNumber be either 1 or 2
 * Modifies: cout
 * Effects:  If errorNumber is 1, prints an error message indicating
 *           an illegal name was entered.
 *           If errorNumber is 2, prints an error message indicating
 *           an illegal move was entered.
 */
void printErrorMessage(int errorNumber);

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints out the final greeting for the program.
 */
void printCloser();

//************************************************************************
// You must implement all of the following functions. Add your 
// implementations below rps() as indicated.
//************************************************************************

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Utilizes the other functions in this file to play 
 *           the game Rock Paper Scissors.
 *
 *           Starter algorithm pseudocode: 
 *           1. Print the header
 *           2. Get player 1 name
 *           3. Get player 2 name
 *           4. Repeat the following until the user quits the program:
 *              * Get the menu choice
 *              * Play the game and announce the winner, 
 *                or quit the program (according to user's menu choice)
 *           5. Print the closing message 
 */
void rps();

/**
 * Requires: playerNumber is either 1 or 2
 * Modifies: cout, cin
 * Effects:  Prompts the user to enter their name. Names entered may
 *           have spaces within them.
 *               Example: "Kermit the frog"
 *
 *           If an empty name is given, this is invalid input, so print
 *           error message 1, and return a default name.
 *           For player 1, the default name is: Rocky
 *           For player 2, the default name is: Creed
 *           Otherwise, return name entered by user.
 *              
 * Prompt:   Player [playerNumber], enter your name:
 */
string getName(int playerNumber);

/**
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  Prints the menu, and reads the input from the user.
 *           Checks to make sure the input is within range for the menu.
 *           If it is not, prints "Invalid menu choice". Continues to print 
 *           the menu and read in input until a valid choice is entered,
 *           then returns the user's choice of menu options. You can assume
 *           a user will enter an integer, and nothing else, as their choice.
 *
 * Prompt:   Invalid menu choice
 */
int getMenuChoice();

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Returns true if and only if move represents a valid move character
 *           one of 'R', 'r', 'P', 'p', 'S', 's'. Returns false otherwise.
 */
bool isMoveGood(char move);

/**
 * Requires: playerName is the name of the player being prompted for their
 *           move.
 * Modifies: cout, cin
 * Effects:  Prompts the player for their move and returns it.
 *           This function should accept the first non-whitespace character as
 *           the move. If an illegal character is entered for their move, print
 *           error message 2 and return rock as a default. 
 *           You can assume a user will enter a single character, 
 *           and nothing else, as their move.
 *
 * Prompt:   [playerName], enter your move:
 */
char getMove(string playerName);

/**
 * Requires: move is the move of the player being checked for a win.
 *           opponentMove is the move of the opponent.
 *           both move and opponentMove are valid moves.
 * Modifies: nothing
 * Effects:  Returns true if and only if the player who made move won>
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "",
 *           prints a message indicating the round is a draw. 
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   This round is a draw!
 *           ------------- OR -------------
 *           [winner_name] wins the round!
 */
void announceRoundWinner(string winnerName);

/**
 * Requires: p1Name and p2Name are the names of the respective players
 * Modifies: nothing
 * Effects:  Simulates a complete round of rock-paper-scissors, which
 *           consists of three steps:
 *             1. Get player1 move
 *             2. Get player2 move
 *             3. Return 0 if the round was a draw; 1 if player 1 won;
 *                2 if player 2 won.
 */
int doRound(string p1Name, string p2Name);

/**
 * Requires: winnerName is the name of the player who won the game.
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "", 
 *           prints that the game was a draw.
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   No winner!
 *           ------------- OR -------------
 *           Congratulations [winnerName]!
 *           You won EECS 183 Rock-Paper-Scissors!
 */
void announceWinner(string winnerName);

/**
 * Requires: p1Name and p2Name are the names of the respective players,
 *           gameType can be 1 for regular rock-paper-scissors
 *           or 2 for rock-paper-scissors-lizard-spock
 * Modifies: cout
 *
 * Base Project:
 * Effects:  If gameType is 2, prints "Under Construction" to indicate that the
 *           s'more has not been implemented. Returns empty string.
 *           Otherwise, plays exactly three rounds of rock-paper-scissors while
 *           keeping track of the number of round wins for each player.
 *           When a round results in a draw, neither player is the winner,
 *           so neither player is awarded a point.
 *           After each round is played, the round winner (or draw) is
 *           announced. 
 *           Returns the name of the game winner, or "" in event of a draw.
 * Prompt:   Under Construction
 *
 * S'more Version:
 * Effects:  Has same functionality as base project, but also handles a
 *           gameType of 2. When game_type is 2, plays exactly three rounds of
 *           rock-paper-scissors-lizard-spock. Keeps track of round wins for
 *           each player and announces round winners in the same fashion as 
 *           described above.
 */
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// Implement the functions below this line.
//************************************************************************

// This is the chunck of code that runs the rps game.
// Entire outline of the rps game.
void rps() {
    printInitialHeader();
    
    // Get player names
    string player1 = getName(1);
    string player2 = getName(2);

    // initially set the menu choice to 0.
    int menuChoice = 0;

    // Get the menu choice initially
    menuChoice = getMenuChoice();

    // Continue playing until the user chooses to quit
    while (menuChoice != 3) {
        
        // play the game.
        string winner = doGame(player1, player2, menuChoice);
        
        // announces winner.
        announceWinner(winner);

        // Get the menu choice again for the next round
        menuChoice = getMenuChoice();
    }

    // Print the closing message
    printCloser();
}

string getName(int playerNumber) {
    string playerNameOne;
    string playerNameTwo;

    if (playerNumber == 1) {
        cout << "Player 1, enter your name: " << endl;
        // To allow spaces between names.
        std::getline(std::cin, playerNameOne);

        if (playerNameOne == "") {
            printErrorMessage(1);
            playerNameOne = "Rocky";
            return playerNameOne;
        }
        else {
            return playerNameOne;
        }
    }
    
    // if playerNumber == 2 (the only other possible option)
    else {
        cout << "Player 2, enter your name: " << endl;
        // To allow spaces between names.
        std::getline(std::cin, playerNameTwo);

        if (playerNameTwo == "") {
            printErrorMessage(1);
            playerNameTwo = "Creed";
            return playerNameTwo;
        }
        else {
            return playerNameTwo;
        }
    }
}


int getMenuChoice() {
    int userMenu;
    
    printMenu();
    cin >> userMenu;
    cout << endl;
    
    while (userMenu < 1 || userMenu > 3) {
        cout << "Invalid menu choice" << endl;
        printMenu();
        cin >> userMenu;
    }
    return userMenu;
}

bool isMoveGood(char move) {
    if ((move == 'r') || (move == 'p') || (move == 's')
        || (move == 'R') || (move == 'P') || (move == 'S')) {
        return true;
    }
    else {
        return false;
    }
}

char getMove(string playerName) {
    char move;
    cout << playerName << ", enter your move: ";
    cin >> move;
    
    if (isMoveGood(move)) {
        return move;
    }
    else {
        // setting to default move
        move = 'r';
        printErrorMessage(2);
    }
    return move;
}

bool isRoundWinner(char move, char opponentMove) {
    // assume true = winner is "move"
    // assume false = winner is "opponentMove"
    if (((move == 'r' || move == 'R') && (opponentMove == 's' || opponentMove == 'S'))
        || ((move == 'p' || move == 'P') && (opponentMove == 'r' || opponentMove == 'R'))
        || ((move == 's' || move == 'S') && (opponentMove == 'p' || opponentMove == 'P'))) {
        return true;
    }
    else {
        return false;
    }
}

void announceRoundWinner(string winnerName) {
    if (winnerName == "") {
        cout << "This round is a draw!" << endl;
    }
    else {
        cout << winnerName << " wins the round!" << endl;
    }
}

int doRound(string p1Name, string p2Name) {
    char p1Move = getMove(p1Name);
    char p2Move = getMove(p2Name);
    
    // To handle the exception cases where it doesn't detect a draw
    // Due to the reason of characters mismatching on upper/lower case.
    bool same;
    if ((p1Move == 'r' && p2Move == 'R') || (p1Move == 'R' && p2Move == 'r')
        || (p1Move == 's' && p2Move == 'S') || (p1Move == 'S' && p2Move == 's')
        || (p1Move == 'p' && p2Move == 'P') || (p1Move == 'P' && p2Move == 'p')) {
        same = true;
    }
    else {
        same = false;
    }
    
    // player 1 & player 2 ties
    if ((p1Move == p2Move) || same) {
        return 0;
    }
    // player 1 wins
    else if (isRoundWinner(p1Move, p2Move)){
        return 1;
    }
    // player 2 wins
    else {
        return 2;
    }
}

void announceWinner(string winnerName) {
    if (winnerName == "") {
        cout << "No winner!" << endl;
    }
    else {
        cout << "Congratulations " << winnerName << "!" << endl;
        cout << "You won EECS 183 Rock-Paper-Scissors!" << endl;
    }
}

string doGame(string p1Name, string p2Name, int gameType) {
    if (gameType == 1) {
        int p1WinCnt = 0;
        int p2WinCnt = 0;

        for (int i=0; i<MAX_ROUNDS; ++i) {
            string winnerName = "";
            int roundResult = doRound(p1Name, p2Name);
           
            if (roundResult == 1) {
                p1WinCnt++;
                winnerName = p1Name;
            }
            else if (roundResult == 2) {
                p2WinCnt++;
                winnerName = p2Name;
            }
            else {
                winnerName = "";
            }
            announceRoundWinner(winnerName);
        }
        
        // Now returning the winner of the game as a whole, after 3 complete rounds.
        if (p1WinCnt > p2WinCnt) {
            return p1Name;
        }
        else if (p1WinCnt < p2WinCnt) {
            return p2Name;
        }
        else {
            return "";
        }
    }
    
    else if (gameType == 2) {
        cout << "Under Construction" << endl;
        return "";
    }
    else {
        return "";
    }
}

//***********************************************************************
// DO NOT modify the four functions below.
//***********************************************************************
void printInitialHeader() {
    cout << "----------------------------------------" << endl;
    cout << "               EECS 183                 " << endl;
    cout << "          Rock-Paper-Scissors           " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}

void printMenu() {
    cout << endl << endl;
    cout << "Menu Options" << endl
        << "------------" << endl;
    cout << "1) Play rock, paper, scissors" << endl;
    cout << "2) Play rock, paper, scissors, lizard, spock" << endl;
    cout << "3) Quit" << endl << endl;
    
    cout << "Choice --> ";
    
    return;
}

void printErrorMessage(int errorNumber) {
    if (errorNumber == 1) {
        cout << endl << "ERROR: Illegal name given, using default" 
            << endl << endl;
    } else if (errorNumber == 2) {
        cout << endl << "ERROR: Illegal move given, using default" << endl;
    } else {
        cout << "This should never print!";
    }
    
    return;
}

void printCloser() {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "           Thanks for playing           " << endl;
    cout << "          Rock-Paper-Scissors!          " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}
