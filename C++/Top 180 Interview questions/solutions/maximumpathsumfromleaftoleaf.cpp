
int solve(TreeNode* root, int &res)
{
	if(root==NULL)
		return 0;
	int lt = solve(root->left,res);
	int rt = solve(root->right,res);
	int temp = max(lt + rt) + root->val;
	if(!root->left && !root->right)
		temp = max(temp,root->val);
	res = max(res,lt+rt+root->val);
	return temp;
}
int main(TreeNode* root)
{
	int res = INT_MIN;
	solve(root,res);
	return res;
}