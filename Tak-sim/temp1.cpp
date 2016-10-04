
struct Node
{
	Node** children;
	int no_of_children;
	int value;

	void deleteNode();
};


void Node::deleteNode()
{
	for (int i = 0; i != this->no_of_children; ++i)
		this->children[i]->deleteNode();
	delete [] this->children;
	delete this;
}

class Tree{

public:
	Node* tree;
	int bestMove;

	Tree(Board board, int playerNo)
	{
		// cout << "Yay\n";
		tree = makeTree(board,4,playerNo);
		bestMove = -1;
	}
	Node* makeTree(Board board, int depth, int playerNo);
	void deleteTree();
	int minimax(Node* root, int depth, bool maxNode, int alpha, int beta);
};

Node* Tree::makeTree(Board board, int depth, int playerNo)
{
	// cout << "Depth : " << depth << "\n";
	Node* node = new Node();
	node -> value = board.evaluate();
	// cout << "Children : " << node -> no_of_children << "\n";
	if (depth >= 0){
		vector<string> validMoves = board.getValidMoves(playerNo);
		node -> no_of_children = validMoves.size();
		if (depth > 1)
			cerr << depth<< "(" << node->no_of_children << ")" << " ";
		if (node->no_of_children > 0){
			// cout << "Yay3    "<< depth << "\n";
			node -> children = new Node* [node->no_of_children];
			for (int i = 0; i < node->no_of_children; i++){
				Board boardTemp(board) ;
				boardTemp.makeMove(playerNo,validMoves[i]);
				node -> children[i] = this->makeTree(boardTemp, depth - 1,1-playerNo);
			}
		}	
	}
	else
	{
		node -> children = NULL;
	}
	return node;
}

void Tree::deleteTree()
{
	for (int i = 0; i != this->tree->no_of_children; ++i)
		this->tree->children[i]->deleteNode();
	delete [] this->tree->children;
}

int Tree::minimax(Node* root, int depth, bool maxNode, int alpha, int beta)
{
	///Assume depth of 4
	if (depth == 4)
		return (root -> value);

	if (maxNode)
	{
		int best = INT_MIN;
		for (int i=0; i < (root -> no_of_children); i++)
		{
			// cerr<<"I am here1 i: " << i << " " << (root -> no_of_children) << " " << children.size() << " \n";
			int value = minimax(root->children[i], depth+1, false, alpha, beta);
			this->bestMove = i;
			best = 	max(best, value);
			alpha = std::max(alpha, best);

			if (beta <= alpha)
				break;
		}
		return best;
	}
	else
	{
		int best = INT_MAX;

		for (int i=0; i< (root->no_of_children); i++)
		{
			int value = minimax(root -> children[i], depth+1, true, alpha, beta);
			this->bestMove = i;
			best = std::min(best, value);
			beta = std::min(beta, best);

			if (beta <= alpha)
				break;
		}
		return best;
	}
}
