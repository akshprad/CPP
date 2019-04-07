//AKSHADA PRADHAN
//SY BTECH CSE PANEL-5
//ROLL NUMBER: 203105
//ASSIGNMENT 2
//BST CREATION AND TRAVERSAL
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

class treenode{
	char data[10];
	treenode *left,*right;
	friend class tree;
};

class tree{
	treenode *root;
	public:
		tree(){
			root=new treenode();
			root=NULL;
		}

		void create_nr();
		void create_r(treenode *);
		void create_r();
		void display_preo_btree(treenode *root); //pre display
		void display_poso_btree(treenode *root); //post display
		void display_ino_btree(treenode *root);  //in display
		void predisp();
		void predisp_r();
	    void posdisp();
	    void indisp();
};
class Stack{
	treenode *data[20];
	int top;
public:
	Stack(){
		top=-1;
	}
	int isfull(){
		if(top==19){
			return 1;
		}
		else{
			return 0;
		}
	}
	int isempty(){
		if(top==-1){
			return 1;
		}
		else{
			return 0;
		}
	}
	void push(treenode *n){
		if(top!=19){
			top++;
			data[top];
		}
	}
	treenode * pop(){
		treenode * temp;
		if(top!=-1){
			temp=data[top];
			top--;
			return temp;
		}
		else{
			return NULL;
		}
	}
};

void tree::create_nr(){
	treenode *curr,*temp;
	int flag=0;
	char ch,d;
	do{
	if(root==NULL){
		root=new treenode();
		cout<<"\nEnter data\n";
		cin>>root->data;
		root->left=root->right=NULL;
	}
	else{
		temp=root;
		curr=new treenode();
		cout<<"\nEnter data\n";
		cin>>curr->data;
		curr->left=curr->right=NULL;
		while(flag==0){
			cout<<"\nWhere do you want to attach current after"<<temp->data<<"L or R?\n";
			cin>>ch;
			if(ch=='l'){
				if(temp->left==NULL){
					temp->left=curr;
					flag=1;
				}
				else{
				       temp=temp->left;
				}
			}

			else{
				if(temp->right==NULL){
					temp->right=curr;
					flag=1;
				}
				else{
					temp=temp->right;
					cout<<"Temp="<<temp->data;
				}
			}
		}
		flag=0;
	}
	cout<<"\nDo you want to add more elements?Y or N\n";
	cin>>d;
	}while(d=='y'||d=='Y');
}

void tree::display_preo_btree(treenode *root)      //preorder
{
 if(root!=NULL)
 {
  cout<<" "<<root->data<<" ";
  display_preo_btree(root->left);
  display_preo_btree(root->right);
 }
}

void tree::predisp()
{
 display_preo_btree(root);
 cout<<endl;
}

void tree::display_poso_btree(treenode *root)  //post order
{
 if(root!=NULL)
 {
  display_poso_btree(root->left);
  display_poso_btree(root->right);
  cout<<" "<<root->data<<" ";
 }
}

void tree::posdisp()
{
 display_poso_btree(root);
 cout<<endl;
}

void tree::display_ino_btree(treenode *root) //in order
{
 if(root!=NULL)
 {
  display_ino_btree(root->left);
  cout<<" "<<root->data<<" ";
  display_ino_btree(root->right);
 }
}

void tree::indisp()
{
 display_ino_btree(root);
 cout<<endl;
}

void tree::create_r(){
	cout<<"Enter data for root node\n";
	root=new treenode;
	cin>>root->data;
	create_r(root);
}
void tree::create_r(treenode *root){
	char ch;
	 cout<<"Do you want to add node on left of "<<root->data;
	 cin>>ch;
	 if(ch=='y'){
		 treenode *temp;
		 temp=new treenode;
		 temp->left=temp->right=NULL;
		 cout<<"Enter data for left node";
		 cin>>temp->data;
		 root->left=temp;
		 	 create_r(temp);
	 }
	 cout<<"Do you want to add node to right!(l or r)<<root->data";
	 cin>>ch;
	 if(ch=='y'){
		 treenode *temp;
		 temp=new treenode;
		 temp->right=temp->left=NULL;
		 cout<<"Enter data for right node";
		 cin>>temp->data;
		 root->right=temp;
		 create_r(temp);
	 }
}
void tree::predisp_r(){
	treenode *temp;
	temp=new treenode;
	Stack S;
	temp=root;
	while(1){

		while(temp!=NULL){
			cout<<temp->data;
			S.push(temp);
		    temp=temp->left;
		}
		if(S.isempty()==1){
			break;
		}
		temp=S.pop();
		temp=temp->right;
	}
}
void tree::posdisp_r(){
	treenode *temp;
	Stack S1;
	temp=new treenode;
	temp=root;
	while(1){
		while(temp!=NULL){
			S1.push(temp);
			temp=temp->left;
		}
		if(S1.data[top]->right==NULL){
			temp=S1.pop();
			cout<<temp->data<<" ";
		}
		while(S1.data[top]->right==temp && S1.isempty()=0){
			temp=S1.pop();
			cout<<temp->data<<" ";
		}
		if(S1.isempty()==1){
			break;
			temp=S1.data[top]->right;
		}
	}
}
int main(){
	tree T;
	 int ch=0         ;
	 while(ch!=4)
	 {
	  cout<<"\n============================================================\n";
	  cout<<"\nEnter choice to perform operations on Binary Tree: ";
	  cout<<"\n1.Create Binary Tree using Non-Recursive Method";
	  cout<<"\n2.Create Binary Tree using Recursive Method";
	  cout<<"\n3.Displaying Binary tree in all orders with rec (pre/post/in)";
	  cout<<"\n4.Displaying Binary tree in all orders with Non Rec(pre/post/in)";
	  cout<<"\n5.Exit";
	  cout<<"\nChoice:";
	  cin>>ch;
	  switch(ch)
	  {
	   case 1:T.create_nr();
		  break;
	   case 2:T.create_r();
		  break;
	   case 3:cout<<"\n\nPreordered Binary tree is  : ";
	   	  T.predisp();
	   	  cout<<"\nPostordered Binary tree is : ";
	   	  T.posdisp();
	   	  cout<<"\nInordered Binary tree is   : ";
	   	  T.indisp();
	   	  cout<<"\n\n============================================================\n";
	  	  break;
	   case 4:cout<<"\n Preordered Binary Tree is :";
	   	   	   T.predisp_r();
		   break;
	   case 5:
		   break;
	   default:cout<<"\nPls Enter the correct choice";
	   	   break;
	  }
	 }
	 return 0;
}

