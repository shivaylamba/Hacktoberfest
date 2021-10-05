struct Info
{
	int sz; // size of subtree
	int max; // min value in subtree
	int min; // max value in subtree
	int ans; // size of largest in the subtrees
	// of current node
	bool isBST;
};

Info largestBSTBT(Node * root)
{
	if(rooy==NULL)
		return {0,INT_MIN, INT_MAX, 0, true};
	if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};
    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);

    Info ret;
    ret.sz = (1 + l.sz + r.sz);
    if(l.isBST && r.isBST && l.max < root->data &&
    	r.min > root.val)
    {
    	// this will be the result that we will be returning
    	// so isliye we are storing the result here
    	res.min = min(l.min, min(r.min, root->data));
    	res.max = max(r.max,max(l.max,root->data));
    	ret.ans = res.sz;
    	ret.isbst = true;
    }

    // else
    ret.ans = max(l.ans,r.ans);
    // ans means it is valid and
    // it is stored in the ans
    res.isBST = false;

    return ret;
}

