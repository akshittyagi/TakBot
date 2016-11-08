#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
	Node *children;
	int value;
	int noOfChildren;
	string move;
	bool flatten;
	Node()
	{
		value = -1;
		noOfChildren = 0;
		move = "";
		flatten = false;
	}
	
	Node(int val,int n, int mov, bool b)
	{
		value = val;
		noOfChildren = n;
		children = new Node[noOfChildren];
		move = mov;
		flatten = b;
	}

	Node(int val)
	{
		value = val;
	}

	void listInit(int n)
	{
		noOfChildren = n;
		children = new Node[noOfChildren];
	}

	friend bool operator < (const Node& a, const Node& b){
        return a.value<b.value;
    }
    
    void msort(){
        sort(children, children+noOfChildren);
    }

};

struct NodeComparator
{
	inline bool operator() (const Node& node1, const Node& node2)
	{
		return node1.value<node2.value ;
	}
};

vector<int> Board::minimax(Board board1, int depth, bool maxNode, int alpha, int beta, int playerNo, int d)
{	vector<int> v;
	int bestMoveI = 0;
	if (depth == d){
		int best = 0;
		if (depth%2==1)
			best = board1.evaluate(1-playerNo);
		else
			best = board1.evaluate(playerNo);
		v.push_back(0);
		v.push_back(best);
		return (v);
	}
	vector<string> validMoves = board1.getValidMoves(playerNo);
	if (maxNode)
	{
		int best = INT_MIN;
		bool b = true;
		for (int i=0; i < validMoves.size(); i++)
		{
			Board boardTemp(board1) ;
			boardTemp.makeMove(playerNo,validMoves[i]);
			int value = minimax(boardTemp, depth+1, false, alpha, beta, 1-playerNo,d)[1];
			if (value >= 1000){
				bestMoveI = i;
				best = value;
			}
			if (best < value){
				bestMoveI = i;
				best = value;
			}
			
			alpha = std::max(alpha, best);

			if (beta <= alpha){
				break;
			}
		}
		v.push_back(bestMoveI);
		v.push_back(best);
		return v;
	}
	else
	{
		int best = INT_MAX;
		// //cerr << "Here-1" << validMoves.size();
		for (int i=0; i< validMoves.size(); i++)
		{
			Board boardTemp(board1) ;
			boardTemp.makeMove(playerNo,validMoves[i]);
			int value = minimax(boardTemp, depth+1, true, alpha, beta,1-playerNo,d)[1];
			// if (value == -1000){
			// 	this->roadBool = true;
			// }
			// if (!this->roadBool){
			if (value <= -1000){
				bestMoveI = i;
				best = value;
			}
			if (best > value){
				bestMoveI = i;
				best = value;
			}
			// }	
			beta = std::min(beta, best);

			if (beta <= alpha){
				// if (depth <=2 )
				// 	cerr << "Depth" << depth << " ";
				break;
			}
		}
		v.push_back(bestMoveI);
		v.push_back(best);
		return v;
	}
	//validMoves.clear();
}
int Board::minimax_ids(Board board1, int depth, bool maxNode, int alpha, int beta, int playerNo, int i){
	
	int max = INT_MIN;
	vector<int> n = this->minimax(board1, depth, maxNode, alpha, beta, playerNo, 1);
	if (n[1]>=1000)
		return n[0];
	n = this->minimax(board1, depth, maxNode, alpha, beta, playerNo, i);
	return n[0];
	////cerr << "Score : " << max << endl;
	// return besMove_;
}
int main()
{
	Node test(10,3);
	test.children[0].value=1;
	test.children[1].value=3;
	test.children[2].value=2;
	test.msort();
	cout<<test.children[0].value<<" "<<test.children[1].value<<" "<<test.children[2].value<<endl;
}
