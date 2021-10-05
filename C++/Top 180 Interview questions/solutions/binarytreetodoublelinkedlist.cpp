void binarysearchfunc(Node* root, Node* head)
{
	if(root==NULL)
		return 0 ;
	static Node* prev = NULL ;
	// so that the same node is accessible in all the
	// recursive calls and its value does not change
	// as we will be updating the prev in all the \
	// recursive calls

	binarysearchfunc(root->left, head);
	if(prev == NULL)
		head = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	binarysearchfunc(root->right,head);
	// recursively call for left and the right subtre
}