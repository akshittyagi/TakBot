#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>
using namespace std;
//Debugger functions 
void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

void print(vector<string> elems)
{
	for(int i=0;i<elems.size();i++)
		cerr << elems[i]<<" ";

	cerr<<endl;
}
//End of Debugger Functions

class Gamer{

	int dimension;
	int totSquares;
	vector<string> board[dimension];
	int currTurnNo;
	int maxNoOfMovablePieces;
	int maxUp;
	int maxDown;
	char maxRight;
	int noOfMoves;
	vector<Player> listOfPlayers;

public:
	
	class Player{
		int flatStones;
		int capStones;
	public:
		Player(int flats,int caps)
		{
			this.flatStones = flats;
			this.capStones = caps;
		}
	};

	Gamer(int n)
	{
		this.dimension = n;
		this.totSquares = n*n;
		this.currTurnNo = 0;
		this.maxNoOfMovablePieces = this.dimension;
		this.maxUp = this.dimension;
		this.maxDown = 1
		this.maxRight = char(int('a'+n-1));
		this.noOfMoves = 0;
		//Default as 5*5
		listOfPlayers.push_back(Player(21,1));
		listOfPlayers.push_back(Player(21,1)); 
	}

	void makeMove(vector<string> move);
	int squareToNum(vector<string>,int start,int end);	
};
int Game::squareToNum(vector<string> sqStr,int start,int end)
{
	if(end-start!=1)
		return -1;
	if(!isalpha(sqStr[start]) or !(islower(sqStr[start])) or !(isdigit(sqStr[start+1])))
		return -1;
	int row = int(sqStr[start])-96;
	int col = int(sqStr[start+1]);
	if(row<1 or row>this.dimension or col<1 or col>this.dimension)
		return -1;

	return this.dimension*(col-1)+(row-1);
}
void Game::makeMove(vector<string> move)
{
	/* Update Shit
		-> Update the board the of this.Game object
		-> Update the GameState
	*/
	int currentPiece;
	if(this.currTurnNo==0)	
		this.noOfMoves+=1;
	if(this.noOfMoves!=1)
		currentPiece = this.currTurnNo;
	else
		currentPiece = 1 - this.currTurnNo;

	if(isaplha(move[0]))
	{
		int square = this.squareToNum(move,1,move.size());
		if(move[0]=='F' or move[0]=='S')
		{
			this.board[square].push_back(move[0]+" "+currentPiece);
			this.listOfPlayers[currentPiece].flatStones -= 1;
		}
		else if(move[0]=='C')
		{
			this.board[square].push_back(move[0]+" "+currentPiece);
			this.listOfPlayers[currentPiece].capStones -= 1;
		}
	}
	else if(isdigit(move[0]))
	{
		int count = int(move[0]);
		int square = this.squareToNum(move,1,3);
		string direction = move[3];
		int change;
		if(direction=="+")
			change = this.dimension;	
		else if(direction=="-")
			change = -1*this.dimension;
		else if(direction==">")
			change = 1;
		else if(direction=="<")
			change = -1;
		int prevSquare = square;
		for(int i=4;i<move.size();i++)
		{//Ignore the syntax from this point
			int nextCount = int(move[i]);
			int nextSquare = prevSquare + change;
			if( (this.board[nextSquare].size()>0) and (this.board[nextSquare][-1][1] == 'S'))
				this.board[nextSquare][-1] = this.board[nextSquare][-1][0] + "F";	
			if(nextCount-count==0)
				this.board[nextSquare] += this.board[square][-count:];
			else
				this.baord[nextSquare] += this.board[square][-count:-count+nextCount];
			prevSquare = nextSquare;
			count -= nextCount
		}
		count = int(move[0])
		this.board[square] = this.board[square][:-count]
	}
	this.turn = 1 - this.turn
}

class GameState{

};

class Player{
	int sizeOfBoard;
	int timeLeft;
	int playerNo;
	Game game;
	
    public:
		Player()
		{
			//TODO:Initialize the params 
			string data;
			cin >> data;
			vector<string> elems;
			split(data,' ',elems);
			print(elems);
			this.playerNo = int(elems[0])-1;
			this.sizeOfBoard = int(elems[1]);
			this.timeLeft = int(elems[2]);
			this.game = Game(this.sizeOfBoard);
			this.Play();
		}
		void Play();
};
void Player::Play()
{
	if(this.playerNo==1)
	{
		//Player 2
		string moveData;
		cin >> moveData;
		vector<string> move;
		split(moveData,' ',move);
		this.game.makeMove(move);
	}
	while(true)
	{
		//making our move
		vector<string> moveChosen = this.game.getBestMove(this.player);
		this.game.makeMove(moveChosen);
		moveChosen[0] = moveChosen[0] + '\n'
		cout << moveChosen[0];
		string movePicked;
		cin >> movePicked;
		vector<string> move;
		split(movePicked,' ',move);
		this.game.makeMove(move); 
	}	

}		

int main()
{
	//Default constructor called(unparam)
	Player aiPlayer;
}