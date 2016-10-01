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
		tree = makeTree(board,0,playerNo);
		bestMove = -1;
	}
	Node* makeTree(Board board, int depth, int playerNo);
	void deleteTree();
	int minimax(Node* root, int depth, bool maxNode, int alpha, int beta);
};
