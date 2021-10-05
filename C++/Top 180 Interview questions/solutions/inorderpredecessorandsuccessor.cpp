void function(TreeNode * root, TreeNode * pre , TreeNode* suc, int val)
{
	if(!root)
		return ;
	// now we will search in the left and right subtree
	if(root->key==val)
	{
		if(root->left)
		{
			TreeNode* tempLeft= root->left;
			while(tempLeft->right)
				tempLeft = tempLeft->right;
			pre = tempLeft;
		}
		if(root->right)
		{
			TreeNode* tempRight = root->right;
			while(tempRight->left)
				tempLeft = tempLeft->left;
			suc = tempRight;
		}
		if(root->key > val)
		{
			suc = root;
			function(root->left, pre, suc , val);
		}
		else
		{
			pre = root;
			function(root->right, pre, suc, val);
		}
		return;
	}
}