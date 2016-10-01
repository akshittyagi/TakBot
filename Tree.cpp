#include "Tree.h"
Node* Tree::makeTree(Board board, int depth, int playerNo)
{
	Node* node = new Node();
	vector<string> validMoves = board.getValidMoves(playerNo);
	node -> no_of_children = validMoves.size();
	node -> value = board.evaluate();
	if (depth > 0 && node->no_of_children > 0)
	{
		node -> children = new Node* [node->no_of_children];
		for (int i = 0; i != node->no_of_children; ++i){
			//Board boardTemp;
			board.makeMove(playerNo,validMoves[i]);
			node -> children[i] = this->makeTree(board, depth - 1,1-playerNo);
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
	///Assume depth of 3
	if (depth == 3)
		return (root -> value);

	if (maxNode)
	{
		int best = INT_MIN;
		for (int i=0; i < (root -> no_of_children); i++)
		{
			int value = minimax(tree->children[i], depth+1, false, alpha, beta);
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
