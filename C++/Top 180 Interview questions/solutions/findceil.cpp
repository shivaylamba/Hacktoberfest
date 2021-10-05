void findCeil(Node* root, int input)
{
	if(root==NULL)
		return -1;
	// there is no node that could be found
	if(root->val == input)
		return root->val;
	// which is the ceil itself
	if(root->val < input)
		return findCeil(root->right,input);
	int ceil  = findCeil(root->left, input);
	retrun (ceil>=input)? ceil : root->key;
	// the node will be found in left subtree
	// or the root itself
}