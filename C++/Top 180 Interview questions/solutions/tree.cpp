int solve(Node* root, int& res)
{
	if(root==NULL)
		return 0;
	int l  = solve(root->left,res);
	int r = solve(root->right,res);
	int temp  = // calculate temp ans (1 + max(l,r));
	int ans = max(temp,relation);
	return temp;
}