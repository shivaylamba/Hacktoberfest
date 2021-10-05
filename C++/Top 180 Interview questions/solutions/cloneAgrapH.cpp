/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, Node* copy, vector<Node*>& visited)
    {
        visited[copy->val] = copy;
        // storing the address in the visited array
        for(auto it : node->neighbors)
        {
            if(visited[it->val]==NULL)
            {
                Node* temp = new Node(it->val);
                (copy->neighbors).push_back(temp);
                dfs(it,temp,visited);
            }
            else
            {
                (copy->neighbors).push_back(visited[it->val]);
            }
            // in visited array we are storing the copy val
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        vector<Node*> visited(101,NULL);
        Node* copy = new Node(node->val,{});
        //passing an empty vector
        dfs(node,copy,visited);
        return copy;
    }
};