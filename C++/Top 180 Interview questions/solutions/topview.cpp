 void top_view(Node *node, map<int, pair<char,int>>& m, int dist, int level)
{
    if (node == NULL)
       return;
    if (m.count(dist) == 0 || m[dist].second > level)
        m[dist] = make_pair(node->data, level);
    // this will just replace the existing data

    top_view(node->left, m, dist-1, level + 1);
    top_view(node->right, m, dist+1, level + 1);
}
    void topView(Node * root) {
        map<int, pair<char,int>> m;
        top_view(root, m, 0, 0);
        for (auto i : m)
        cout << i.second.first << " ";
    }