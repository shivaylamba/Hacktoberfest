vector<int> PreInpost(Node* root)
{
	if(root==NULL)
		return {};
	vector<int> pre,in,post;
	stack<pair<Node,int>> st;
	st.push(root,1);
	while(!st.empty())
	{
		auto it = st.top();
		st.pop();
		if(it.second==1)
		{
			pre.push_back(it->first->val);
			it.second++;
			st.push(it);

			if(it->first->left)
				st.push(it->first->left,1);
		}
		if(it.second==2)
		{
			in.push_back(it->first->val);
			it.second++;
			st.push(it);

			if(it->first->left)
				st.push(it->first->left,1);
		}
		else{
			post.push_back(it->first->val);
		}

	}
}