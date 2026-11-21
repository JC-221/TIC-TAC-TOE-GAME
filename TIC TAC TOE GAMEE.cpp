#include <iostream>
#include <cstdlib>
using namespace std;

class Tgame{

    private:
        char board[3][3];

    public:
    	//first function to initialize a board
        void initializeBoard(){
            char numbers[3][3] = {
                {'1', '2', '3'},
                {'4', '5', '6'},
                {'7', '8', '9'}
            };
            
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    board[i][j] = numbers[i][j];
                }
            }
        }
        //second function to display board on screen
        void displayBoard(){
            cout << endl;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cout << "  " << board[i][j];
                    if(j < 2){
                        cout << " |";
                    }
                }
                cout << endl;
                if(i < 2){
                    cout << "  ---+---+---" << endl;
                }
            }
        }
        //third function for helping to play
        void playerMove(int player){
            int option;
            while(true){
                cout << "\nPlayer " << player
                     << " choose your position: ";
                cin >> option;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input! Enter a number.\n";
                    continue;
                }
                if(option < 1 || option > 9){
                    cout << "Invalid position! Choose between 1 and 9.\n";
                    continue;
                }
                bool valid = true;
                switch(option){
                    case 1:
                        if(board[0][0] == '1')
                            board[0][0] = (player == 1) ? 'X' : 'O';//this checks if is player one playing and replace value by X else it replace it by O 
                        else valid = false;//this makes the position not being choosed for another time because it has already occupied
                        break;
                    case 2:
                        if(board[0][1] == '2')
                            board[0][1] = (player == 1) ? 'X' : 'O';
                        else valid = false;
                        break;
                    case 3:
                        if(board[0][2] == '3')
                            board[0][2] = (player == 1) ? 'X' : 'O';
                        else valid = false;
                        break;
                    case 4:
                        if(board[1][0] == '4')
                            board[1][0] = (player == 1) ? 'X' : 'O';
                        else valid = false;
                        break;
                    case 5:
                        if(board[1][1] == '5')
                            board[1][1] = (player == 1) ? 'X' : 'O';
                        else valid = false;
                        break;
                    case 6:
                        if(board[1][2] == '6')
                            board[1][2] = (player == 1) ? 'X' : 'O';
                        else valid = false;
                        break;
                    case 7:
                        if(board[2][0] == '7')
                            board[2][0] = (player == 1) ? 'X' : 'O';
                        else valid = false;
                        break;
                    case 8:
                        if(board[2][1] == '8')
                            board[2][1] = (player == 1) ? 'X' : 'O';
                        else valid = false;
                        break;
                    case 9:
                        if(board[2][2] == '9')
                            board[2][2] = (player == 1) ? 'X' : 'O';
                        else valid = false;
                        break;
                }
                //this condition give turn to the next player to continue playing
                if(valid){
                    break;
                }
                else{
                    cout << "Position already occupied! Try again.\n";//message displayed when you choose the number which has been already occupied
                }
            }
        }
        bool checkWinner(){
            if(
                (board[0][0]=='X' && board[0][1]=='X' && board[0][2]=='X') ||
                (board[1][0]=='X' && board[1][1]=='X' && board[1][2]=='X') ||
                (board[2][0]=='X' && board[2][1]=='X' && board[2][2]=='X') ||
                (board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X') ||
                (board[0][1]=='X' && board[1][1]=='X' && board[2][1]=='X') ||
                (board[0][2]=='X' && board[1][2]=='X' && board[2][2]=='X') ||
                (board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X') ||
                (board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')
            ){
                cout << "\nPlayer 1 wins!\n";
                return true;
            }
            if(
                (board[0][0]=='O' && board[0][1]=='O' && board[0][2]=='O') ||
                (board[1][0]=='O' && board[1][1]=='O' && board[1][2]=='O') ||
                (board[2][0]=='O' && board[2][1]=='O' && board[2][2]=='O') ||
                (board[0][0]=='O' && board[1][0]=='O' && board[2][0]=='O') ||
                (board[0][1]=='O' && board[1][1]=='O' && board[2][1]=='O') ||
                (board[0][2]=='O' && board[1][2]=='O' && board[2][2]=='O') ||
                (board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O') ||
                (board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')
            ){
                cout << "\nPlayer 2 wins!\n";
                return true;
            }
            return false;
        }
        //fourth function for playing the game
        
        void playGame(){
            char again;
            
            do{
                int player = 1;
                bool winner = false;

                initializeBoard();

                system("cls");

                cout << "\n============================\n";
                cout << "       TIC-TAC-TOE GAME";
                cout << "\n============================\n";

                for(int turn = 1; turn <= 9; turn++){
                    displayBoard();

                    playerMove(player);

                    system("cls");

                    cout << "\n============================\n";
                    cout << "       TIC-TAC-TOE GAME";
                    cout << "\n============================\n";

                    if(checkWinner()){
                        displayBoard();
                        winner = true;
                        break;
                    }

                    if(player == 1){
                        player = 2;
                    }
                    else{
                        player = 1;
                    }
                }

                if(!winner){
                    displayBoard();
                    cout << "\nThe game is a draw!\n";
                }
                
                cout << "\nDo you want to play again? (Y/N): ";
                cin >> again;
            }
			while(again == 'Y' || again == 'y');
            cout << "\nThank you for playing!\n";
        }
    };

int main(){
    Tgame game;
    game.playGame();    
    return 0;
}