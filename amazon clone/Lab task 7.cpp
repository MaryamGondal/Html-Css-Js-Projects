#include<iostream>
using namespace std;
class Node{
	public:
	int val;
	Node* left;
	Node* right;
	Node(int data){
		val=data;
		left=NULL;
		right=NULL;
	}
};

     Node* insertBST(Node* root,int val){
		if(root==NULL){
			return new Node(val);
		}
		if(val<root->val){
			root->left=insertBST(root->left,val);
		}
		else
		root->right=insertBST(root->right,val);
			return root;
	}
	void inorder(Node* root){
		if(root==NULL){
			return;
		}
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
		
		
	}
	//function for sum of left nodes
    int sumBST(Node* root){
    	if(root==NULL){
    		return 0;
		}
    	int sum=0;
    	if(root->left!=NULL){
    	sum+=root->left->val;
		sum+=sumBST(root->left);
		sum+=sumBST(root->right);
    		
		}
		return sum;
	}
	//function to print smallest element
	int smallestElement(Node* root){
		if(root==NULL){
			return NULL;
		}
		while(root->left!=NULL){
		root= root->left;
		}
    return root->val;
	}
    //function to print kth largest element
	Node* kthlargest(Node* root,int& k)
{
	if(root==NULL)
	return NULL;
	
	Node* right=kthlargest(root->right,k);
	if(right!=NULL)
	return right;
	k--;
	
	if(k==1)
	return root;
	
	return kthlargest(root->left,k);
}
	//function to check if the two nodes are equal or not
	bool isIdentical(Node* root1,Node* root2){
		if(root1==NULL|| root2==NULL){
			return(root1==root2);
		}
		return(root1->val==root2->val)&&isIdentical(root1->left,root2->left)&&isIdentical(root1->left,root2->left);
	}
int main(){
	//BinarySearchTree b1;
	Node* root=NULL;
	root=insertBST(root,5);
	insertBST(root,3);
	insertBST(root,7);
	insertBST(root,2);
	insertBST(root,1);
	insertBST(root,6);
	Node* root2=NULL;
	root2=insertBST(root2,5);
	insertBST(root2,3);
	insertBST(root2,7);
	insertBST(root2,2);
	insertBST(root2,1);
	insertBST(root2,6);
	 inorder(root2);
	cout<<"\nSum of left roots: "<<sumBST(root)<<endl;
	cout<<"Smallest Element: "<<smallestElement(root)<<endl;
	cout<<"Largest Element: "<<kthlargest(root,1)<<endl;
	cout<<"Identical(1) or non-Identical(0): "<<isIdentical(root,root2);
	
}
