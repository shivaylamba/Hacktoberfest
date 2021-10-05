void findCeil(Node* root, int input)
{
	if(root==NULL)
		return -1;
	// there is no node that could be found
	if(root->val == input)
		return root->val;
	// which is the ceil itself
	if(root->val > input)
		return findCeil(root->left,input);
	int floor  = findCeil(root->right, input);
	retrun (floor<=input)? floor : root->key;
	// the node will be found in left subtree
	// or the root itself
}