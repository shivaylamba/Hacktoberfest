#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

};


BinaryTreeNode<int>* takeInputLevelWise() {
    int data;
//  cout << "Enter root : ";
    cin >> data;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);

    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {
        BinaryTreeNode<int> *current = pendingNodes.front();
        pendingNodes.pop();

        int leftData, rightData;
    //  cout << "Enter left child of : " << current -> data << " : ";
        cin >> leftData;

        if(leftData != -1) {
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(leftData);
            current -> left = left;
            pendingNodes.push(left);
        }

    //  cout << "Enter right child of  " << current -> data << " : ";
        cin >> rightData;

        if(rightData != -1) {
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(rightData);
            current -> right = right;
            pendingNodes.push(right);
        }
    }
    return root;

}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBinaryTreeVerticalOrder(root);
    return 0;
}


	
	void verticalTraversal(BinaryTreeNode<int>* root,int order,map<int,vector<int>> &mp){
        
        if(root == NULL)return;
        
        mp[order].push_back(root->data);
        verticalTraversal(root->left,order-1,mp);
        verticalTraversal(root->right,order+1,mp);
        
    }

	void printBinaryTreeVerticalOrder(BinaryTreeNode<int>* root) {	 
		
	// Following is the structure of the Binary Tree node class
	/*
		class BinaryTreeNode {
	    		public :
    				T data;
    			BinaryTreeNode<T> *left;
    			BinaryTreeNode<T> *right;

			BinaryTreeNode(T data) {
	        		this -> data = data;
        			left = NULL;
        			right = NULL;
    			}
		};
	*/
	
		
	map<int,vector<int>> mp;
        int order = 0;
        verticalTraversal(root,order,mp);
	
     	for(auto it = mp.begin();it!=mp.end();it++){
            
            for(auto x:mp[it->first]){
                cout<<x<<" ";
            }
            cout<<endl;
        }
     	
}



