#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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
	int board[dimension][dimension];
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
			this.flats = flats;
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
		this.maxRight = char(int('a'+n-1)));
		this.noOfMoves = 0;
		//Default as 5*5
		listOfPlayers.push_back(Player(21,1));
		listOfPlayers.push_back(Player(21,1)); 
	}

	void makeMove(vector<string> move);
};

void Game::makeMove(vector<string> move)
{
	/* Update Shit
		-> Update the board the of this.Game object
		-> Update the GameState
	*/
		
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
		cerr << moveChosen[0];
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