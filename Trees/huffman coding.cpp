#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	node* right,*left;
	char ch;
	int frq;
	
	
};

node *newNode(char ch,int frq)
{
	node* temp=new node();
	
	temp->ch=ch;
	temp->frq=frq;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

class compare{
	public:
	bool operator()(node *a,node *b)
	{
		return a->frq>b->frq;
	}
};

void encode(node *root,string str,unordered_map<char,string> &huffmanCode)
{
	if (root == NULL)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

int main()
{
	int n;
	cout<<"Enter Number of character: "<<endl;
	cin>>n;
	
	vector<node> arr;
	priority_queue<node*, vector<node*>, compare> pq;
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"Enter character and its frequency: "<<endl;
		int f;
		char c;
		cin>>c>>f;
		node *temp=newNode(c,f);
		//arr.push_back(temp);
		pq.push(temp);
	}
	
	

	while(pq.size()!=1)
	{
		cout<<"loop"<<endl;
		node *temp1=pq.top();
		pq.pop();
		
		node *temp2=pq.top();
		pq.pop();
		
		
		cout<<"min: "<<temp1->frq<<" second min: "<<temp2->frq<<endl;
		node *temp=newNode('$',temp1->frq+temp2->frq);
		temp->left=temp1;
		temp->right=temp2;
		cout<<"Pushed :"<<temp->ch<<" frq: "<<temp->frq<<" left: "<<temp->left->ch<<" right: "<<temp->right->ch<<endl;
		pq.push(temp);
	}
	
	node *root=pq.top();
	pq.pop();
//	cout<<"root: "<<root.left->ch<<" root right: "<<root.right->ch<<endl;

	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);
	
	cout << "Huffman Codes are :\n" << '\n';
	for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}
	
	
	return 0;
}
