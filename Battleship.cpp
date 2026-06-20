#include <iostream>
#include<string>
#include <windows.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

int iternery=0;

int choice1;
char board1[10][10], board2[10][10];
void showGameMenu();
void setShips(char board[10][10]);
void initializeBoard(char board[10][10]);
void setColor(int textColor, int bgColor);
void vsPlayer(char board1[10][10], char board2[10][10]);
int shipcount(char board[10][10]);
void playerAttack(char opponentBoard[10][10], int &playerScore);
void saveResults(string name1, string name2, int score1, int score2);
void showLeaderboard(const string playerNames[], const int scores[], int totalPlayers);
void printBoard(char board[10][10], bool hideShips);
bool gameover(char board[10][10]);
void displayResult(int player1Score, int player2Score);

void setRandomShips(char board[10][10]);

void vsComputer(char playerBoard[10][10], char computerBoard[10][10]);

void computerAttack(char playerBoard[10][10], int &computerScore);

void clearBoard(char board[10][10]);

void updateScore(int &score);

void computerBoatDying();

void playerBoatDying();

void HAutoAssigner(char board[10][10], int lengthofship, char characterofship);

bool HitorMiss = 0;

int computerScore = 0;
int playerScore = 0;

char playerBoard[10][10] = {{'\0'}};
char computerBoard[10][10] = {{'\0'}};

int ComputerShipsLeft[5] = {1, 1, 1, 1, 1};
int ComputerLife = 5;

int PlayerShipsLeft[5] = {1, 1, 1, 1, 1};
int PlayerLife = 5;

bool Enddecided = 0;

int currentplayercolor = 0;

string Player1Name = "";

const int BLACK = 0;
const int BLUE = 1;
const int GREEN = 2;
const int CYAN = 3;
const int RED = 4;
const int MAGENTA = 5;
const int YELLOW = 6;
const int WHITE = 7;
int player1color;
int player2color;

void playerAttackPVC(char opponentBoard[10][10], int &playerScore);

void clearScreen() {

		system("cls");

}

void showGameMenu(){

	for(int j=1;j<=50;j++)
	cout<<"=";

	cout<<endl;

	cout << "\n           WELCOME TO BATTLESHIP GAME\n\n";

	for(int j=1;j<=50;j++)
	cout<<"=";

	cout<<endl;

	cout<<"\n\n";
	cout<<"              MAIN MENU\n\n";
	for(int i=1;i<=50;i++)
	cout<<"=";

	cout<<endl;

	cout<<"1. Start New Game\n2. Instructions\n3. View Leaderboard\n4. Exit\n";

	for(int i=1;i<=50;i++)
	cout<<"=";

	cout<<endl;

	cout<<"\n\n\nEnter your choice(1-4): ";
	cin>>choice1;

	system("pause");
	clearScreen();

	switch(choice1){

	case 1: {

	for(int i=1;i<=30;i++)
	cout<<"=";

	cout<<endl;
	cout<<"      START NEW GAME\n";

	for (int i = 1; i <= 30; i++)
		cout << "=";

		cout << endl;

	cout<<"Choose game mode:\n1. Player vs Computer\n2. Player vs Player\nEnter choice (1 or 2): ";

	int modechoice;
	cin>>modechoice;

	cin.clear();
	cin.ignore(10000,'\n');

	while (modechoice != 1 && modechoice != 2) {
    cout << "Enter correct choice (1 or 2): ";
    cin >> modechoice;
	}

	if(modechoice==1)
	vsComputer(playerBoard,computerBoard);
	if(modechoice==2)
	vsPlayer(board1,board2);

	break;
		}

	case 2:{

	for(int i=1;i<=30;i++)
	cout<<"=";

	cout<<endl<<endl;

	cout<<"          Instructions\n\n";

	for(int i=1;i<=30;i++)
	cout<<"=";

	cout<<endl<<endl;
	for(int i=1;i<=83;i++)
	cout<<"=";

	cout<<endl;

	cout<<"\n1. Place your ships on the board.\n2. You and the computer take turns firing the shots. 'O' means MISS,'X' means HIT.\n4. Sink all enemy ships to win!\n5. Your score is based on accuracy and speed.\n\n";
	for(int i=1;i<=83;i++)
	cout<<"=";

	cout<<endl;

	system("pause");
	clearScreen();

	break;
		}
	case 3:	{

	cout<<"        === LEADERBOARD ==="<<endl;

  	string names[100];
    int scores[100];
    int totalPlayers = 0;

    showLeaderboard(names, scores, totalPlayers);

    system("pause");
	clearScreen();

	break;
		}

	case 4: cout<<"GOODBYE! PLAY AGAIN SOON :)" ;
			break;

	default: cout<<"Invalid case entered! Kindly select a number between 1 and 4";
	}

	}

void setShips(char board[10][10]){
	int r,c,pchoice;
	char vhchoice;
	string ships[5]={"AircraftCarrier","Battleship","Destroyer","Submarine","PatrolBoat"};
	char shipletter[5]={'A','B','D','S','P'};
	int shipsize[5]={5,4,3,3,2};

	cout<<"Choose placement option\n1. Manual\n2. Random \nChoice: ";
	cin>>pchoice;

	while(pchoice!=1 && pchoice!=2){
		cout<<"Incorrect choice! Enter again: ";
		cin>>pchoice;
	}

	if(pchoice==1){

		for(int i=0;i<5;i++){
			system("pause");
			clearScreen();
			if(i==2)
				cout<<"You have two ships of size "<<shipsize[i]<<" to place\n";
			else
				cout<<"You have one ship of size "<<shipsize[i]<<" to place\n";

			printBoard(board, false);

			cout<<"Enter starting row (0-9): ";
			cin>>r;
			cout<<"Enter starting column (0-9): ";
			cin>>c;

			bool validplace = false;

			while(!validplace){

				validplace = true;

				if(r<0 || r>=10 || c<0 || (c+shipsize[i])>10){
					validplace = false;
															}

				if(validplace){
					for(int j=0; j<shipsize[i]; j++){
						if(board[r][c+j]=='A'|| board[r][c+j]=='B'||board[r][c+j]=='D'||board[r][c+j]=='S'||board[r][c+j]=='P' ){
							validplace = false;
							break;
																																}
													}
								}

				if(!validplace){
					cout<<"Incorrect position! Enter again: ";
					cout<<"Enter starting row (0-9): ";
					cin>>r;
					cout<<"Enter starting column (0-9): ";
					cin>>c;
					}
						}

			for(int j=c; j<c+shipsize[i]; j++){
				board[r][j]=shipletter[i];
												}

			system("pause");
			clearScreen();

			cout<<"== Updated Board ==\n";
			printBoard(board, false);

			cout<<"Would you like to place your ship vertically? (y/n)\n";
			cin>>vhchoice;

			while(vhchoice!='y'&& vhchoice!='n'){
				cout<<"Wrong choice! Enter again: ";
				cin>>vhchoice;
			}

			if(vhchoice=='y'){

				for(int j=c; j<c+shipsize[i]; j++){
					board[r][j]='~';
													}

				while(!validplace){
					validplace = true;

					if(r<0 || (r+shipsize[i])>10 || c<0 || c>=10){
						validplace = false;
					}

					if(validplace){
						for(int j=0; j<shipsize[i]; j++){
							if(board[r+j][c]=='A'||board[r+j][c]=='B' || board[r+j][c]=='D' || board[r+j][c]=='S' || board[r+j][c]=='P'){
								validplace = false;
								break;
														}
																																		}
									}

					if(!validplace){
						cout<<"Incorrect position! Enter again: ";
						cout<<"Enter starting row (0-9): ";
						cin>>r;
						cout<<"Enter starting column (0-9): ";
						cin>>c;
									}
								}

				for(int j=r; j<r+shipsize[i]; j++){
					board[j][c]=shipletter[i];
				}
						}

			if(vhchoice=='y'){
				system("pause");
				clearScreen();
				cout<<"== Updated Board ==\n";
				printBoard(board, false);
							}
		}
	}
	else{
		system("pause");
		clearScreen();

		for(int i=0; i<5; i++){
			bool validplace = false;
			while(!validplace){
				validplace = true;
				r = rand() % 10;
				c = rand() % 10;
				vhchoice = rand() % 2 + 1;

				if(vhchoice==1){
					if((c+shipsize[i])>10){
						validplace = false;
					}

					if(validplace){
						for(int j=0; j<shipsize[i]; j++){
							if(board[r][c+j]=='A'|| board[r][c+j]=='B'||board[r][c+j]=='D'||board[r][c+j]=='S'||board[r][c+j]=='P'){
								validplace = false;
								break;
							}
						}
					}
				}
				else{
					if((r+shipsize[i])>10){
						validplace = false;
					}

					if(validplace){
						for(int j=0; j<shipsize[i]; j++){
							if(board[r+j][c]=='A'||board[r+j][c]=='B'||board[r+j][c]=='D'||board[r+j][c]=='S'||board[r+j][c]=='P'){
								validplace = false;
								break;
							}
						}
					}
				}
			}

			if(vhchoice==1){
				for(int j=c; j<c+shipsize[i]; j++){
					board[r][j]=shipletter[i];
				}
			}
			else{
				for(int j=r; j<r+shipsize[i]; j++){
					board[j][c]=shipletter[i];
				}
			}
		}

		cout<<"== Ships placed randomly ==\n";

		printBoard(board, false);
	}
}

void initializeBoard(char board[10][10]){

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            board[i][j] = '~';
}

void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

string name1,name2="Computer";

void vsPlayer(char board1[10][10], char board2[10][10]){

	system("pause");
	clearScreen();

	initializeBoard(board1);
 	initializeBoard(board2);

	int score1=0,score2=0;

	cout<<"=================================================================\n\n"<<"           WELCOME TO PLAYER VS PLAYER MODE\n\n"<<"=================================================================\n";

	cout<<"Enter Player 1 name : ";
	cin>>name1;

	cout<<"Enter Player 1 color :\nGREEN = 2\nCYAN = 3\nRED = 4\nYELLOW = 6\nEnter choice: ";
	cin>>player1color;

	while(player1color!=2 && player1color!=3 && player1color!=4 && player1color!=6){
		cout<<"Incorrect Color Choice! Enter again: ";
		cin>>player1color;
	}

	system("pause");
	clearScreen();

	cout<<"\nEnter Player 2 name : ";
	cin>>name2;

	cout<<"Enter Player 2 color :\nGREEN = 2\nCYAN = 3\nRED = 4\nYELLOW = 6\nEnter choice: ";
	cin>>player2color;

	while(player2color!=2 && player2color!=3 && player2color!=4 && player2color!=6){
		cout<<"Incorrect Color Choice! Enter again: ";
		cin>>player2color;
	}

	while(player1color==player2color){
		cout<<name2<<" Enter color again\n";
		cin>>player2color;
	}

	system("pause");
	clearScreen();

	cout<<name1<<" Place your Ships\n";

	currentplayercolor=player1color;

	setShips(board1);

	system("pause");
	clearScreen();

	cout<<name2<<" Place your Ships\n";

	currentplayercolor=player2color;
	setShips(board2);

	system("pause");
	clearScreen();

	cout<<"=== SHIPS PLACED ===\n";

	while(!gameover(board1) && !gameover(board2)){

		system("pause");
		clearScreen();

		cout<<name1<<" ATTACK!!!\n";

		currentplayercolor=player1color;
		printBoard(board2,true);

		for(int i=1;i<=shipcount(board1)+1;i++){

			playerAttack(board2,score1);
			if(gameover(board2))
				break;

		}

		printBoard(board2,true);

		if(gameover(board2))
			break;

		system("pause");
		clearScreen();

		cout<<name2<<" ATTACK!!!\n";

		currentplayercolor=player2color;
		printBoard(board1,true);

		for(int i=1;i<=shipcount(board2)+1;i++){

			playerAttack(board1,score2);
			if(gameover(board1))
				break;
		}

		printBoard(board1,true);

		if(gameover(board1))
		break;
	}

	displayResult(score1,score2);

}

int shipcount(char board[10][10]){
	int count=0;
	bool A=false,B=false,D=false,S=false,P=false;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(board[i][j]=='A')
			A=true;
			if(board[i][j]=='B')
			B=true;
			if(board[i][j]=='D')
			D=true;
			if(board[i][j]=='S')
			S=true;
			if(board[i][j]=='P')
			P=true;
		}

	}
	if(A)
	count++;

	if(B)
	count++;

	if(D)
	count++;

	if(S)
	count++;

	if(P)
	count++;

	return count;
}

void playerAttack(char opponentBoard[10][10], int &playerScore){
	int r, c;
	cout << "Enter the coordinates of your attack:\nRow: ";
	cin >> r;
	cout << "Column: ";
	cin >> c;

	while (r < 0 || r > 9 || c < 0 || c > 9 ||
		   opponentBoard[r][c] == 'a' || opponentBoard[r][c] == 'b' || opponentBoard[r][c] == 'd' || opponentBoard[r][c] == 's' || opponentBoard[r][c] == 'p' || opponentBoard[r][c] == 'O')
		   {

		if (r < 0 || r > 9 || c < 0 || c > 9)
		{
			cout << "Incorrect Coordinates! Enter again\nRow: ";
			cin >> r;
			cout << "Column: ";
			cin >> c;
		}
		else if (opponentBoard[r][c] == 'a' || opponentBoard[r][c] == 'b' || opponentBoard[r][c] == 'd' || opponentBoard[r][c] == 's' || opponentBoard[r][c] == 'p')
		{
			cout << "ALREADY HIT! ENTER NEW COORDINATES\nRow: ";
			cin >> r;
			cout << "Column: ";
			cin >> c;
		}
		else if (opponentBoard[r][c] == 'O')
		{
			cout << "ALREADY MISSED! ENTER NEW COORDINATES\nRow: ";
			cin >> r;
			cout << "Column: ";
			cin >> c;
		}
	}

	if(opponentBoard[r][c] == 'A'||opponentBoard[r][c] == 'B'||opponentBoard[r][c] == 'D'||opponentBoard[r][c] == 'S'||opponentBoard[r][c] == 'P' ){
		cout << "  DIRECT HIT\n";
		opponentBoard[r][c] += 'a' - 'A';
		playerScore = playerScore + 10;
	}
	else if(opponentBoard[r][c] == '~'){
		cout << "  MISS\n";
		opponentBoard[r][c] = 'O';
		playerScore = playerScore - 1;
	}
}

void printsides(char board[10][10], int n, bool hideShips)
{

	cout << n << " ";

	for (int i = 0; i < 10; i++)
	{

		char cell = board[n][i];

		if (cell == 'S' || cell == 'A' || cell == 'B' || cell == 'D' || cell == 'P')
		{
			if (hideShips)
			{

				cout << " .";
			}
			else
			{

				cout << " " << cell;
			}
		}
		else if (cell == 'O')
		{

			cout << " O";
		}
		else if (cell == 'X')
		{

			cout << " X";
		}
		else
		{

			cout << " .";
		}
	}
}

void printBoard(char board[10][10], bool hideShips)
{

	int n[5] = {4, 4, 4, 4, 4};

	bool foundA = false;
	bool foundB = false;
	bool foundD = false;
	bool foundS = false;
	bool foundP = false;
	for (int j = 0; j < 10 && (!foundA); j++)
		for (int k = 0; k < 10 && (!foundA); k++)
		{
			if (board[j][k] == 'A')
			{
				foundA = true;
				break;
			}

			if ((j == 9) && k == 9)
				n[0] = 13;
		}

	for (int j = 0; j < 10 && (!foundB); j++)
		for (int k = 0; k < 10 && (!foundB); k++)
		{
			if (board[j][k] == 'B')
			{
				foundB = true;
				break;
			}

			if ((j == 9) && k == 9)
				n[1] = 13;
		}

	for (int j = 0; j < 10 && (!foundD); j++)
		for (int k = 0; k < 10 && (!foundD); k++)
		{
			if (board[j][k] == 'D')
			{
				foundD = true;
				break;
			}

			if ((j == 9) && k == 9)
				n[2] = 13;
		}

	for (int j = 0; j < 10 && (!foundS); j++)
		for (int k = 0; k < 10 && (!foundS); k++)
		{
			if (board[j][k] == 'S')
			{
				foundS = true;
				break;
			}

			if ((j == 9) && k == 9)
				n[3] = 13;
		}

	for (int j = 0; j < 10 && (!foundP); j++)
		for (int k = 0; k < 10 && (!foundP); k++)
		{
			if (board[j][k] == 'P')
			{
				foundP = true;
				break;
			}

			if ((j == 9) && k == 9)
				n[4] = 13;
		}

	cout << " Player A's Board";

	cout << "                   0    1    2    3    4    5    6    7    8    9  ";

	cout << "             Player B's Board";

	cout << endl;

	cout << "";

	cout << "                           +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+";

	cout << "";

	cout << endl;

	cout << "   0 1 2 3 4 5 6 7 8 9";

	cout << "  0 ¦";

	for (int i = 0; i < 10; i++)
	{
		char cell = board[0][i];
		if (cell == 'O')
		{
			setColor(0, 8);
			cout << "  O  ";

		}

		else if ((cell == 'A' || cell == 'B' || cell == 'D' || cell == 'S' || cell == 'P'))
		{
			if ((hideShips))
			{
				setColor(7, 1);
				cout << "  ~  ";

			}

			else
			{
				setColor(7, currentplayercolor);
				cout << "  " << cell << "  ";

			}
		}

		else if (cell == 'a')
		{

			setColor(15, n[0]);
			cout << "  X  " ;

		}

		else if (cell == 'b')
		{
			setColor(15, n[1]);
			cout << "  X  " ;
		}

		else if (cell == 'd')
		{
			setColor(15, n[2]);
			cout << "  X  " ;
		}

		else if (cell == 's')
		{
			setColor(15, n[3]);
			cout << "  X  " ;
		}

		else if (cell == 'p')
		{
			setColor(15, n[4]);
			cout << "  X  " ;
		}

		else
		{
			setColor(7, 1);
			cout << "  ~  " ;
		}
		setColor(7, 0);
		cout << "¦";
	}

	cout << "      0 1 2 3 4 5 6 7 8 9";

	cout << endl;

	printsides(board1, 0, iternery%2);

	cout << "     +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦    ";

	printsides(board2, 0, (iternery+1)%2);

	cout << endl;

	printsides(board1, 1, iternery % 2);

	cout << "  1 ¦";
	for (int i = 0; i < 10; i++)
	{
		char cell = board[1][i];
		if (cell == 'O')
		{
			setColor(0, 8);
			cout << "  O  ";
		}

		else if ((cell == 'A' || cell == 'B' || cell == 'D' || cell == 'S' || cell == 'P'))
		{
			if ((hideShips))
			{
				setColor(7, 1);
				cout << "  ~  ";
			}

			else
			{
				setColor(7, currentplayercolor);
				cout << "  " << cell << "  ";
			}
		}

		else if (cell == 'a')
		{

			setColor(15, n[0]);
			cout << "  X  ";
		}

		else if (cell == 'b')
		{
			setColor(15, n[1]);
			cout << "  X  ";
		}

		else if (cell == 'd')
		{
			setColor(15, n[2]);
			cout << "  X  ";
		}

		else if (cell == 's')
		{
			setColor(15, n[3]);
			cout << "  X  ";
		}

		else if (cell == 'p')
		{
			setColor(15, n[4]);
			cout << "  X  ";
		}

		else
		{
			setColor(7, 1);
			cout << "  ~  ";
		}
		setColor(7, 0);
		cout << "¦";
	}

	cout << "     ";
	printsides(board2, 1, (iternery + 1) % 2);

	cout << endl;

	printsides(board1, 2, iternery % 2);

	cout << "     +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦    ";

	printsides(board2, 2, (iternery + 1) % 2);
	cout << endl;

	printsides(board1, 3, iternery % 2);

	cout << "  2 ¦";
	for (int i = 0; i < 10; i++)
	{
		char cell = board[2][i];
		if (cell == 'O')
		{
			setColor(0, 8);
			cout << "  O  ";
		}

		else if ((cell == 'A' || cell == 'B' || cell == 'D' || cell == 'S' || cell == 'P'))
		{
			if ((hideShips))
			{
				setColor(7, 1);
				cout << "  ~  ";
			}

			else
			{
				setColor(7, currentplayercolor);
				cout << "  " << cell << "  ";
			}
		}

		else if (cell == 'a')
		{

			setColor(15, n[0]);
			cout << "  X  ";
		}

		else if (cell == 'b')
		{
			setColor(15, n[1]);
			cout << "  X  ";
		}

		else if (cell == 'd')
		{
			setColor(15, n[2]);
			cout << "  X  ";
		}

		else if (cell == 's')
		{
			setColor(15, n[3]);
			cout << "  X  ";
		}

		else if (cell == 'p')
		{
			setColor(15, n[4]);
			cout << "  X  ";
		}

		else
		{
			setColor(7, 1);
			cout << "  ~  ";
		}
		setColor(7, 0);
		cout << "¦";
	}
	cout << "     ";
	printsides(board2, 3, (iternery + 1) % 2);

	cout << endl;

	printsides(board1, 4, iternery % 2);

	cout << "     +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦    ";

	printsides(board2, 4, (iternery + 1) % 2);

	cout << endl;

	printsides(board1, 5, iternery % 2);

	cout << "  3 ¦";
	for (int i = 0; i < 10; i++)
	{
		char cell = board[3][i];
		if (cell == 'O')
		{
			setColor(0, 8);
			cout << "  O  ";
		}

		else if ((cell == 'A' || cell == 'B' || cell == 'D' || cell == 'S' || cell == 'P'))
		{
			if ((hideShips))
			{
				setColor(7, 1);
				cout << "  ~  ";
			}

			else
			{
				setColor(7, currentplayercolor);
				cout << "  " << cell << "  ";
			}
		}

		else if (cell == 'a')
		{

			setColor(15, n[0]);
			cout << "  X  ";
		}

		else if (cell == 'b')
		{
			setColor(15, n[1]);
			cout << "  X  ";
		}

		else if (cell == 'd')
		{
			setColor(15, n[2]);
			cout << "  X  ";
		}

		else if (cell == 's')
		{
			setColor(15, n[3]);
			cout << "  X  ";
		}

		else if (cell == 'p')
		{
			setColor(15, n[4]);
			cout << "  X  ";
		}

		else
		{
			setColor(7, 1);
			cout << "  ~  ";
		}
		setColor(7, 0);
		cout << "¦";
	}

	cout << "     ";
	printsides(board2, 5, (iternery + 1) % 2);

	cout << endl;

	printsides(board1, 6, iternery % 2);

	cout << "     +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦    ";

	printsides(board2, 6, (iternery + 1) % 2);

	cout << endl;

	printsides(board1, 7, iternery % 2);

	cout << "  4 ¦";

	for (int i = 0; i < 10; i++)
	{
		char cell = board[4][i];
		if (cell == 'O')
		{
			setColor(0, 8);
			cout << "  O  ";
		}

		else if ((cell == 'A' || cell == 'B' || cell == 'D' || cell == 'S' || cell == 'P'))
		{
			if ((hideShips))
			{
				setColor(7, 1);
				cout << "  ~  ";
			}

			else
			{
				setColor(7, currentplayercolor);
				cout << "  " << cell << "  ";
			}
		}

		else if (cell == 'a')
		{

			setColor(15, n[0]);
			cout << "  X  ";
		}

		else if (cell == 'b')
		{
			setColor(15, n[1]);
			cout << "  X  ";
		}

		else if (cell == 'd')
		{
			setColor(15, n[2]);
			cout << "  X  ";
		}

		else if (cell == 's')
		{
			setColor(15, n[3]);
			cout << "  X  ";
		}

		else if (cell == 'p')
		{
			setColor(15, n[4]);
			cout << "  X  ";
		}

		else
		{
			setColor(7, 1);
			cout << "  ~  ";
		}
		setColor(7, 0);
		cout << "¦";
	}
	cout << "     ";
	printsides(board2, 7, (iternery + 1) % 2);

	cout << endl;

	printsides(board1, 8, iternery % 2);
	cout << "     +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦    ";
	printsides(board2, 8, (iternery + 1) % 2);

	cout << endl;

	printsides(board1, 9, iternery % 2);

	cout << "  5 ¦";

	for (int i = 0; i < 10; i++)
	{
		char cell = board[5][i];
		if (cell == 'O')
		{
			setColor(0, 8);
			cout << "  O  ";
		}

		else if ((cell == 'A' || cell == 'B' || cell == 'D' || cell == 'S' || cell == 'P'))
		{
			if ((hideShips))
			{
				setColor(7, 1);
				cout << "  ~  ";
			}

			else
			{
				setColor(7, currentplayercolor);
				cout << "  " << cell << "  ";
			}
		}

		else if (cell == 'a')
		{

			setColor(15, n[0]);
			cout << "  X  ";
		}

		else if (cell == 'b')
		{
			setColor(15, n[1]);
			cout << "  X  ";
		}

		else if (cell == 'd')
		{
			setColor(15, n[2]);
			cout << "  X  ";
		}

		else if (cell == 's')
		{
			setColor(15, n[3]);
			cout << "  X  ";
		}

		else if (cell == 'p')
		{
			setColor(15, n[4]);
			cout << "  X  ";
		}

		else
		{
			setColor(7, 1);
			cout << "  ~  ";
		}
		setColor(7, 0);
		cout << "¦";
	}
	cout << "     ";
	printsides(board2, 9, (iternery + 1) % 2);

	cout << endl;
	cout << "                           +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦";

	cout << endl;

	cout << "                        6 ¦";

	for (int i = 0; i < 10; i++)
	{
		char cell = board[6][i];
		if (cell == 'O')
		{
			setColor(0, 8);
			cout << "  O  ";
		}

		else if ((cell == 'A' || cell == 'B' || cell == 'D' || cell == 'S' || cell == 'P'))
		{
			if ((hideShips))
			{
				setColor(7, 1);
				cout << "  ~  ";
			}

			else
			{
				setColor(7, currentplayercolor);
				cout << "  " << cell << "  ";
			}
		}

		else if (cell == 'a')
		{

			setColor(15, n[0]);
			cout << "  X  ";
		}

		else if (cell == 'b')
		{
			setColor(15, n[1]);
			cout << "  X  ";
		}

		else if (cell == 'd')
		{
			setColor(15, n[2]);
			cout << "  X  ";
		}

		else if (cell == 's')
		{
			setColor(15, n[3]);
			cout << "  X  ";
		}

		else if (cell == 'p')
		{
			setColor(15, n[4]);
			cout << "  X  ";
		}

		else
		{
			setColor(7, 1);
			cout << "  ~  ";
		}
		setColor(7, 0);
		cout << "¦";
	}
	cout << endl;
	cout << "                           +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

	cout << "                        7 ¦";

	for (int i = 0; i < 10; i++)
	{
		char cell = board[7][i];
		if (cell == 'O')
		{
			setColor(0, 8);
			cout << "  O  ";
		}

		else if ((cell == 'A' || cell == 'B' || cell == 'D' || cell == 'S' || cell == 'P'))
		{
			if ((hideShips))
			{
				setColor(7, 1);
				cout << "  ~  ";
			}

			else
			{
				setColor(7, currentplayercolor);
				cout << "  " << cell << "  ";
			}
		}

		else if (cell == 'a')
		{

			setColor(15, n[0]);
			cout << "  X  ";
		}

		else if (cell == 'b')
		{
			setColor(15, n[1]);
			cout << "  X  ";
		}

		else if (cell == 'd')
		{
			setColor(15, n[2]);
			cout << "  X  ";
		}

		else if (cell == 's')
		{
			setColor(15, n[3]);
			cout << "  X  ";
		}

		else if (cell == 'p')
		{
			setColor(15, n[4]);
			cout << "  X  ";
		}

		else
		{
			setColor(7, 1);
			cout << "  ~  ";
		}
		setColor(7, 0);
		cout << "¦";
	}
	cout << endl;
	cout << "                           +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

	cout << "                        8 ¦";

	for (int i = 0; i < 10; i++)
	{
		char cell = board[8][i];
		if (cell == 'O')
		{
			setColor(0, 8);
			cout << "  O  ";
		}

		else if ((cell == 'A' || cell == 'B' || cell == 'D' || cell == 'S' || cell == 'P'))
		{
			if ((hideShips))
			{
				setColor(7, 1);
				cout << "  ~  ";
			}

			else
			{
				setColor(7, currentplayercolor);
				cout << "  " << cell << "  ";
			}
		}

		else if (cell == 'a')
		{

			setColor(15, n[0]);
			cout << "  X  ";
		}

		else if (cell == 'b')
		{
			setColor(15, n[1]);
			cout << "  X  ";
		}

		else if (cell == 'd')
		{
			setColor(15, n[2]);
			cout << "  X  ";
		}

		else if (cell == 's')
		{
			setColor(15, n[3]);
			cout << "  X  ";
		}

		else if (cell == 'p')
		{
			setColor(15, n[4]);
			cout << "  X  ";
		}

		else
		{
			setColor(7, 1);
			cout << "  ~  ";
		}
		setColor(7, 0);
		cout << "¦";
	}
	cout << endl;

	cout << "                           +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

	cout << "                        9 ¦";

	for (int i = 0; i < 10; i++)
	{
		char cell = board[9][i];
		if (cell == 'O')
		{
			setColor(0, 8);
			cout << "  O  ";
		}

		else if ((cell == 'A' || cell == 'B' || cell == 'D' || cell == 'S' || cell == 'P'))
		{
			if ((hideShips))
			{
				setColor(7, 1);
				cout << "  ~  ";
			}

			else
			{
				setColor(7, currentplayercolor);
				cout << "  " << cell << "  ";
			}
		}

		else if (cell == 'a')
		{

			setColor(15, n[0]);
			cout << "  X  ";
		}

		else if (cell == 'b')
		{
			setColor(15, n[1]);
			cout << "  X  ";
		}

		else if (cell == 'd')
		{
			setColor(15, n[2]);
			cout << "  X  ";
		}

		else if (cell == 's')
		{
			setColor(15, n[3]);
			cout << "  X  ";
		}

		else if (cell == 'p')
		{
			setColor(15, n[4]);
			cout << "  X  ";
		}

		else
		{
			setColor(7, 1);
			cout << "  ~  ";
		}
		setColor(7, 0);
		cout << "¦";
	}
	cout << endl;

	cout << "                           +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;

	iternery++;
}
bool gameover(char board[10][10]){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(board[i][j]=='S'||board[i][j]=='A'|| board[i][j]=='B'|| board[i][j]=='D'|| board[i][j]=='P')
				return false;
		}
	}
	return true;
}
void displayResult(int player1Score, int player2Score){

	system("pause");
	clearScreen();

	cout<<"==============================\n"<<"          GAME OVER \n"<<"==============================\n\n";

	cout<<"Player 1 Score : "<<player1Score<<endl<<"Player 2 Score : "<<player2Score<<endl<<endl;

	if(player1Score> player2Score)
		cout<<"PLAYER 1 WINSSS!!!!!\n";
	else if(player2Score>player1Score)
		cout<<"PLAYER 2 WINSSS!!!!!\n";
	else
		cout<<"DRAW! BETTER LUCK NEXT TIME :(\n";

	saveResults(name1,name2,player1Score,player2Score);

	system("pause");
	clearScreen();

}
void saveResults(string name1, string name2, int score1, int score2) {
    ofstream file("Leaderboard.txt", ios::app);
    if(file.is_open()) {
        file << name1 << " " << score1 << endl;
        file << name2 << " " << score2 << endl;
        file.close();
    }
}

void showLeaderboard(const string playerNames[], const int scores[], int totalPlayers){
	ifstream file("Leaderboard.txt");
    int t = 0;
    string Names[100];
    int Scores[100];

    if(file.is_open()){
        while(!file.eof()){
            file >> Names[t] >> Scores[t];
            if(file.fail())
			break;
            t++;
        }
        file.close();
    }

    for(int i = 0; i < t - 1; i++){
        for(int j = 0; j < t - 1 - i; j++){
            if(Scores[j] < Scores[j + 1]){
                int temp1 = Scores[j];
                Scores[j] = Scores[j + 1];
                Scores[j + 1] = temp1;

                string temp2 = Names[j];
                Names[j] = Names[j + 1];
                Names[j + 1] = temp2;
            }
        }
    }

	if(t==0){
		cout<<"No Scores Available yet....\n";
	}
	else{
		if (t>10){

	for(int i=0;i<10;i++){
		cout<<i+1<<". "<<Names[i]<<" "<<Scores[i]<<endl;
						}
				}
	else{
		for(int i=0;i<t;i++){
		cout<<i+1<<". "<<Names[i]<<" "<<Scores[i]<<endl;
							}

		}
		}

	}

int main()
{
	srand(time(0));

	while(true){

	showGameMenu();
	if(choice1==4)
	break;

}
    return 0;
}

void playerAttackPVC(char opponentBoard[10][10], int &playerScore)
{
	int r, c;
	cout << "Enter the coordinates of your attack:\nRow: ";
	cin >> r;
	cout << "Column: ";
	cin >> c;

	while (r < 0 || r > 9 || c < 0 || c > 9 ||
		   opponentBoard[r][c] == 'a' || opponentBoard[r][c] == 'b' || opponentBoard[r][c] == 'd' || opponentBoard[r][c] == 's' || opponentBoard[r][c] == 'p' || opponentBoard[r][c] == 'O')
	{

		if (r < 0 || r > 9 || c < 0 || c > 9)
		{
			cout << "Incorrect Coordinates! Enter again\nRow: ";
			cin >> r;
			cout << "Column: ";
			cin >> c;
		}
		else if (opponentBoard[r][c] == 'a' || opponentBoard[r][c] == 'b' || opponentBoard[r][c] == 'd' || opponentBoard[r][c] == 's' || opponentBoard[r][c] == 'p')
		{
			cout << "ALREADY HIT! ENTER NEW COORDINATES\nRow: ";
			cin >> r;
			cout << "Column: ";
			cin >> c;
		}
		else if (opponentBoard[r][c] == 'O')
		{
			cout << "ALREADY MISSED! ENTER NEW COORDINATES\nRow: ";
			cin >> r;
			cout << "Column: ";
			cin >> c;
		}
	}

	if (opponentBoard[r][c] == 'A' || opponentBoard[r][c] == 'B' || opponentBoard[r][c] == 'D' || opponentBoard[r][c] == 'S' || opponentBoard[r][c] == 'P')
	{
		cout << "  DIRECT HIT\n";
		opponentBoard[r][c] += ('a' - 'A');
		playerScore = playerScore + 10;
	}
	else if (opponentBoard[r][c] == '~')
	{
		cout << "  MISS\n";
		opponentBoard[r][c] = 'O';
		playerScore = playerScore - 1;
	}

	computerBoatDying();
}

void updateScore(int &score)
{
	cout << "Score Updated";
	if (HitorMiss)
	{
		score += 10;
	}
	else
	{
		score -= 1;
	}
}

void computerAttack(char playerBoard[10][10], int &computerScore)
{
	srand(time(0));

	while (1)
	{
		int r = rand() % 10;
		int c = rand() % 10;

		if (playerBoard[r][c] == '~')
		{
			playerBoard[r][c] = 'O';
			HitorMiss = false;
			updateScore(computerScore);
			break;
		}

		if (playerBoard[r][c] == 'A' || playerBoard[r][c] == 'B' || playerBoard[r][c] == 'D' || playerBoard[r][c] == 'S' || playerBoard[r][c] == 'P')
		{

			playerBoard[r][c] += ('a' - 'A');
			HitorMiss = true;
			updateScore(computerScore);
			break;
		}

		if (playerBoard[r][c] == 'a' || playerBoard[r][c] == 'b' || playerBoard[r][c] == 'd' || playerBoard[r][c] == 's' || playerBoard[r][c] == 'p')
		{

			continue;
		}

	}

	playerBoatDying();
}

void HAutoAssigner(char board[10][10], int lengthofship, char characterofship)
{

	int r = 0;
	int c = 0;
	bool vertical = 0;

	bool CheckIfAvaialable = 1;

	do
	{
		CheckIfAvaialable = true;
		r = rand() % 10;
		c = rand() % 10;
		vertical = rand() % 2;

		for (int i = 0; i < lengthofship; i++)
		{
			if (vertical == 0)
			{
				if ((((c + i) < 10)) && (board[r][c + i] != '~'))
				{
					CheckIfAvaialable = false;
				}
			}

			else if (vertical != 0)
			{
				if ((((r + i) < 10)) && (board[r + i][c] != '~'))
				{
					CheckIfAvaialable = false;
				}
			}
		}

	} while (!CheckIfAvaialable);

	for (int i = 0; i < lengthofship; i++)
	{
		if (vertical == 0)
		{
			board[r][c + i] = characterofship;
		}

		else if (vertical != 0)
		{
			board[r + i][c] = characterofship;
		}
	}
}

void setRandomShips(char board[10][10])
{
	srand(time(0));

	int lengthofship = 0;
	char characterofship = 0;

	lengthofship = 5;
	characterofship = 'A';
	HAutoAssigner(board, lengthofship, characterofship);

	lengthofship = 4;
	characterofship = 'B';
	HAutoAssigner(board, lengthofship, characterofship);

	lengthofship = 3;
	characterofship = 'D';
	HAutoAssigner(board, lengthofship, characterofship);

	lengthofship = 3;
	characterofship = 'S';
	HAutoAssigner(board, lengthofship, characterofship);

	lengthofship = 2;
	characterofship = 'P';
	HAutoAssigner(board, lengthofship, characterofship);
}

void computerBoatDying()
{

	int count[5] = {0};

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (computerBoard[i][j] == 'A')
				count[0]++;

			if (computerBoard[i][j] == 'B')
				count[1]++;

			if (computerBoard[i][j] == 'D')
				count[2]++;

			if (computerBoard[i][j] == 'S')
				count[3]++;

			if (computerBoard[i][j] == 'P')
				count[4]++;
		}
	}

	if (count[0] == 0)
		ComputerShipsLeft[0] = false;

	if (count[1] == 0)
		ComputerShipsLeft[1] = false;

	if (count[2] == 0)
		ComputerShipsLeft[2] = false;

	if (count[3] == 0)
		ComputerShipsLeft[3] = false;

	if (count[4] == 0)
		ComputerShipsLeft[4] = false;

	ComputerLife = 0;
	for (int i = 0; i < 5; i++)
	{
		ComputerLife += ComputerShipsLeft[i];
	}
}

void playerBoatDying()
{

	int count[5] = {0};

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (playerBoard[i][j] == 'A')
				count[0]++;

			if (playerBoard[i][j] == 'B')
				count[1]++;

			if (playerBoard[i][j] == 'D')
				count[2]++;

			if (playerBoard[i][j] == 'S')
				count[3]++;

			if (playerBoard[i][j] == 'P')
				count[4]++;
		}
	}

	if (count[0] == 0)
		PlayerShipsLeft[0] = false;

	if (count[1] == 0)
		PlayerShipsLeft[1] = false;

	if (count[2] == 0)
		PlayerShipsLeft[2] = false;

	if (count[3] == 0)
		PlayerShipsLeft[3] = false;

	if (count[4] == 0)
		PlayerShipsLeft[4] = false;

	PlayerLife = 0;
	for (int i = 0; i < 5; i++)
	{
		PlayerLife += PlayerShipsLeft[i];
	}
}

void Adapter(bool hideships)
{
	if (hideships)
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
			{
				board1[i][j] = playerBoard[i][j];
				board2[i][j] = computerBoard[i][j];
			}
	}
	else
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
			{
				board2[i][j] = playerBoard[i][j];
				board1[i][j] = computerBoard[i][j];
			}
	}
}

void vsComputer(char playerBoard[10][10], char computerBoard[10][10])
{

	initializeBoard(playerBoard);
	initializeBoard(computerBoard);

	cout << "Enter Player Name:";
	getline(cin, Player1Name);

	cout << "Enter color of your choice, \n\n0-Black,2-Green,3-Aquan/Cyan,6-Yellow,9-Light Blue,10-Light Green,14-Light Yellow :";

	while (true)
	{
		cout << "Your choice: ";

		if (!(cin >> currentplayercolor))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Please enter a number.\n";
			continue;
		}

		if (currentplayercolor != 0 && currentplayercolor != 2 && currentplayercolor != 3 &&
			currentplayercolor != 6 && currentplayercolor != 9 && currentplayercolor != 10 &&
			currentplayercolor != 14)
		{
			cout << "Color not in list. Try again.\n";
			continue;
		}

		break;
	}

	cout << endl;

	cout<<"\nExtra Feature, Players board shifts between player A and B between turns....(On purpose)\n";
	cout << "\nAlso scores update only one turn afterwards to calm the rage roaders down, play slowly\n";

	setShips(playerBoard);

	getchar();

	setRandomShips(computerBoard);

	while (!Enddecided)
	{

		getchar();

		if ((PlayerLife + 1) >= 1)
		{

			cout << "Players Attack\n";
			cout << "Player Score :" << playerScore << endl;
			cout << "Player No of Turns Left After this :" << PlayerLife - 0 << endl;

			playerAttackPVC(computerBoard, playerScore);
			Adapter(1);
			printBoard(computerBoard, 1);
		}

		if ((ComputerLife + 1) >= 1)
		{
			system("pause");
			clearScreen();

			cout << "Computer Attack\n";
			cout << "Computer Score :" << computerScore << endl;
			cout << "Computer No of Turns Left After this :" << ComputerLife - 0 << endl;
			computerAttack(playerBoard, computerScore);
			Adapter(0);
			printBoard(playerBoard, 0);
		}

		if ((PlayerLife + 1) >= 2)
		{

			system("pause");
			clearScreen();

			cout << "Players Attack\n";
			cout << "Player Score :" << playerScore << endl;
			cout << "Player No of Turns Left After this :" << PlayerLife - 1;
			playerAttackPVC(computerBoard, playerScore);
			Adapter(1);
			printBoard(computerBoard, 1);
		}

		if ((ComputerLife + 1) >= 2)
		{
			system("pause");
			clearScreen();

			cout << "Computer Attack\n";
			cout << "Computer Score :" << computerScore << endl;
			cout << "Computer No of Turns Left After this :" << ComputerLife - 1 << endl;
			computerAttack(playerBoard, computerScore);
			Adapter(0);
			printBoard(playerBoard, 0);
		}

		if ((PlayerLife + 1) >= 3)
		{

			system("pause");
			clearScreen();

			cout << "Players Attack\n";
			cout << "Player Score :" << playerScore << endl;
			cout << "Player No of Turns Left After this :" << PlayerLife - 2;
			playerAttackPVC(computerBoard, playerScore);
			Adapter(1);
			printBoard(computerBoard, 1);
		}

		if ((ComputerLife + 1) >= 3)
		{
			system("pause");
			clearScreen();

			cout << "Computer Attack\n";
			cout << "Computer Score :" << computerScore << endl;
			cout << "Computer No of Turns Left After this :" << ComputerLife - 2 << endl;
			computerAttack(playerBoard, computerScore);
			Adapter(0);
			printBoard(playerBoard, 0);
		}

		if ((PlayerLife + 1) >= 4)
		{

			system("pause");
			clearScreen();

			cout << "Players Attack\n";
			cout << "Player Score :" << playerScore << endl;
			cout << "Player No of Turns Left After this :" << PlayerLife - 3;
			playerAttackPVC(computerBoard, playerScore);
			Adapter(1);
			printBoard(computerBoard, 1);
		}

		if ((ComputerLife + 1) >= 4)
		{
			system("pause");
			clearScreen();

			cout << "Computer Attack\n";
			cout << "Computer Score :" << computerScore << endl;
			cout << "Computer No of Turns Left After this :" << ComputerLife - 3 << endl;
			computerAttack(playerBoard, computerScore);
			Adapter(0);
			printBoard(playerBoard, 0);
		}

		if ((PlayerLife + 1) >= 5)
		{

			system("pause");
			clearScreen();

			cout << "Players Attack\n";
			cout << "Player Score :" << playerScore << endl;
			cout << "Player No of Turns Left After this :" << PlayerLife - 4;
			playerAttackPVC(computerBoard, playerScore);
			Adapter(1);
			printBoard(computerBoard, 1);
		}

		if ((ComputerLife + 1) >= 5)
		{
			system("pause");
			clearScreen();

			cout << "Computer Attack\n";
			cout << "Computer Score :" << computerScore << endl;
			cout << "Computer No of Turns Left After this :" << ComputerLife - 4 << endl;
			computerAttack(playerBoard, computerScore);
			Adapter(0);
			printBoard(playerBoard, 0);
		}

		if ((PlayerLife + 1) == 6)
		{

			system("pause");
			clearScreen();

			cout << "Players Attack\n";
			cout << "Player Score :" << playerScore << endl;
			cout << "Player No of Turns Left After this :" << PlayerLife - 5;
			playerAttackPVC(computerBoard, playerScore);
			Adapter(1);
			printBoard(computerBoard, 1);
		}

		if ((ComputerLife + 1) == 6)
		{

			system("pause");
			clearScreen();

			cout << "Computer Attack\n";
			cout << "Computer Score :" << computerScore << endl;
			cout << "Computer No of Turns Left After this :" << ComputerLife - 5 << endl;
			computerAttack(playerBoard, computerScore);
			Adapter(0);
			printBoard(playerBoard, 0);
		}

		if ((PlayerLife == 0) && (ComputerLife == 0))
		{
			cout << "Its a Draw\n\n";
			Enddecided = true;

			break;
		}

		if (PlayerLife == 0)
		{
			cout << "You Lost\n\n";
			Enddecided = true;
			break;
		}

		if (ComputerLife == 0)
		{
			cout << "You Win!\n\n";
			Enddecided = true;
			break;
		}
	}

	 saveResults(Player1Name,"Computer",playerScore,computerScore);
}
