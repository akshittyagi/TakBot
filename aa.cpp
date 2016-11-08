#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
	Node *children;
	int value;
	int noOfChildren;
	Node()
	{
		value = -1;
		noOfChildren = 0;
	}
	Node(int val,int n)
	{
		value = val;
		noOfChildren = n;
		children = new Node[noOfChildren];
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

int main()
{
	vector<Node> vec;
	vec.push_back(Node(10,3));
	vec.push_back(Node(11,1));
	vec.push_back(Node(9,1));
	vec.push_back(Node(7,1)); 
	sort(vec.begin(), vec.end(), NodeComparator());
	for(int i=0;i<vec.size();i++)
		cout<<vec[i].value<<" ";
	cout<<endl;

	Node test(10,3);
	test.children[0].value=1;
	test.children[1].value=3;
	test.children[2].value=2;
	test.msort();
	cout<<test.children[0].value<<" "<<test.children[1].value<<" "<<test.children[2].value<<endl;
}

