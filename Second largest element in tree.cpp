/*
Second Largest Element In Tree
Given a generic tree, find and return the node with second largest value in given tree.

Note: Return NULL if no node with required value is present.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, 
data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains data of the node with second largest data.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1 :
40
*/

#include<vector>
#include<utility>
#include<climits>

TreeNode<int> * findMax(TreeNode<int> *a, TreeNode<int> *b) {
    if(a -> data > b -> data) {
        return a;
    } else {
        return b;
    }
}

pair<TreeNode<int>*,TreeNode<int>*> helper(TreeNode<int> *root) {
    TreeNode<int> *max_1 = root;
    TreeNode<int> *max_2 = new TreeNode<int>(INT_MIN);
    
    for(int i = 0; i < root -> children.size(); i++) {
        pair<TreeNode<int>*,TreeNode<int>*> temp = helper(root -> children[i]);
        TreeNode<int>* discard;
        
        if(max_1 -> data < temp.first -> data) {
            discard = max_1;
            max_1 = temp.first;
            if(max_2) {
            	max_2 = findMax(findMax(discard,temp.second), max_2);
            } else {
                max_2 = findMax(discard,temp.second);
            }    
        } else if(max_2 -> data < temp.first -> data ) {
            max_2 = temp.first;
        } 
    }
    
    if(max_1 -> data != max_2 -> data) {
    	return {max_1,max_2};
    } else {
        return {max_1,NULL};
    }
    
}

TreeNode<int> * getSecondLargestNode(TreeNode<int> *root) {
    if(root == NULL or root -> children.size() == 0) {
        return NULL;
    }
    
    return helper(root).second;
}
