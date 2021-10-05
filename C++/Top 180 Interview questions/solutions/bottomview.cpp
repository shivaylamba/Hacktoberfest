 void bottom_view(Node *node, map<int, pair<char,int>>& m, int dist, int level)
{
    if (node == NULL)
       return;
    if (m.count(dist) == 0 || m[dist].second < level)
        m[dist] = make_pair(node->data, level);

    bottom_view(node->left, m, dist-1, level + 1);
    bottom_view(node->right, m, dist+1, level + 1);
}
    void bottomview(Node * root) {
        map<int, pair<char,int>> m;
        top_view(root, m, 0, 0);
        for (auto i : m)
        cout << i.second.first << " ";
    }