#include <iostream>
#include <string>
#include <sstream>
#include <vector>	
#include <ctype.h>
#include <algorithm>
#include <string>
#define MAX 10000
#define MIN -10000

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
class Board{
	int dimension;
	vector<string> *board;

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

	vector<Player> listOfPlayers;

	Board(int n){
		this.dimension = n;
		//Default as 5*5
		this.board = new int[this.dimension];
		listOfPlayers.push_back(Player(21,1));
		listOfPlayers.push_back(Player(21,1)); 
	}

	void makeMove(vector<string> move);
	int squareToNum(vector<string>,int start,int end);
	vector<string> getValidMoves(int playerNo, int flats, int caps);
};
int Board::squareToNum(vector<string> sqStr,int start,int end)
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
void Board::makeMove(int playerNo, vector<string> move)
{
	/* Update Shit
		-> Update the board the of this.Game object
		-> Update the GameState
	*/
	if(isaplha(move[0]))
	{
		int square = this.squareToNum(move,1,move.size());
		if(move[0]=="F" or move[0]=="S")
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
}
class Game{

	int dimension;
	int totSquares;
	int currTurnNo;
	int maxNoOfMovablePieces;
	int maxUp;
	int maxDown;
	char maxRight;
	int noOfMoves;
	Board board;

public:
	Game(int n)
	{
		this.dimension = n;
		this.totSquares = n*n; 
		this.currTurnNo = 0;
		this.maxNoOfMovablePieces = this.dimension;
		this.maxUp = this.dimension;
		this.maxDown = 1
		this.maxRight = char(int('a'+n-1));
		this.noOfMoves = 0;
		this.board(this.dimension);
	}

	string getBestMove(int playerNo, int flats, int caps);
	string makeMove(int playerNo, string move)
};

string Game::getBestMove(int playerNo, int flats, int caps){
	Tree* minmaxTree(this.board);
	int highestValue = minmaxTree.minimax(minmaxTree.tree, 0, true, MIN, MAX);
	int bestMoveIndex = minmaxTree.bestMove;
	string bestMove = this.board.getValidMoves(bestMoveIndex);
	minmaxTree.deleteTree();
	delete minmaxTree;
	return bestMove;
}

void Game::makeMove(string move)
{
	int currentPiece;
	if(this.currTurnNo==0)
		this.noOfMoves+=1;
	if(this.noOfMoves!=1)
		currentPiece = this.currTurnNo;
	else
		currentPiece = 1 - this.currTurnNo;

	this.board.makeMove(currentPiece, move);
	this.turn = 1 - this.turn;
}


class AIPlayer{
	int sizeOfBoard;
	int timeLeft;
	int playerNo;
	Game game;
	
    public:
		AIPlayer()
		{
			//TODO:Initialize the params 
			// string data;
			// cin >> data;
			// vector<string> elems;
			// split(data,' ',elems);
			// print(elems);
			// this.playerNo = int(elems[0])-1;
			// this.sizeOfBoard = int(elems[1]);
			// this.timeLeft = int(elems[2]);
			// this.game = Game(this.sizeOfBoard);
			// this.Play();
		}
		void Play();
};

void AIPlayer::Play()
{
	if(this.playerNo==1)
	{
		//Player 2
		string moveData;
		cin >> moveData;
		this.game.makeMove(moveData);
	}
	while(true)
	{
		//making our move
		string moveChosen = this.game.getBestMove(this.player);
		this.game.makeMove(moveChosen);
		moveChosen = moveChosen + '\n'
		cout << moveChosen;
		string movePicked;
		cin >> movePicked;
		this.game.makeMove(movePicked); 
	}	

}


struct Node
	{
		Node* children;
		int no_of_children;
		int value;
	};

class Tree{

public:	
	Node* tree;
	int bestMove;

	Tree(Board board){
		tree = makeTree(board,0);
		bestMove = -1;
	}
	Node* makeTree(Board board,int depth);
	void deleteTree();
	int minimax(Node* tree,int depth,bool maxNode,int alpha,int beta);
};

Node* Tree::makeTree(Board board, int depth)
	{
		Node* node = new Node();
		node.no_of_children = board.getValidMoves().size();
		node.value = board.evaluate();
		if (depth > 0 && node.no_of_children > 0)
		{
			node.children = new Node* [node.no_of_children];
			for (int i = 0; i != node.no_of_children; ++i)
				node.children[i] = makeTree(board.makeMove(board.getVaidMoves()[i]), depth - 1);
		}
		else
		{
			node.children = NULL;
		}
		return node;
	}
void Tree::deleteTree()
	{
		for (int i = 0; i != this.tree.no_of_children; ++i)
			(tree.children[i]).deleteTree();
		delete [] tree.children;
	}
int Tree::minimax(Node* tree, int depth, bool maxNode, int alpha, int beta)
	{
		///Assume depth of 3
		if (depth == 3)
			return tree.value;

		if (maxNode)
		{
			int best = MIN;
			for (int i=0; i<tree.no_of_children; i++)
			{
				int value = minimax(tree.children[i], depth+1, false, alpha, beta);
				bestMove = i;
				best = std::max(best, value);
				alpha = std::max(alpha, best);

				if (beta <= alpha)
					break;
			}
			return best;
		}
		else
		{
			int best = MAX;

			for (int i=0; i<tree.no_of_children; i++)
			{
				int value = minimax(tree.children[i], depth+1, true, alpha, beta);
				bestMove = i;
				best = std::min(best, value);
				beta = std::min(beta, best);

				if (beta <= alpha)
					break;
			}
			return best;
		}
	}	



int main()
{
	//Default constructor called(unparam)
	AIPlayer aiPlayer;
}