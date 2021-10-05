class Solution {
public:
    int numTrees(int n) {
       //F(i, n) = G(i-1) * G(n-i)	1 <= i <= n 
    // f denotes the number of BST with root i and range 1 to n
        // g denotes number of bst with that many nodes
        vector<int> G(n + 1);
        G[0] = 1;
        G[1] = 1;
        for(int i = 2 ; i < n + 1 ; i++)
        {
        // G[2] = G[0] * G[1] + G[1] * G[1]
            for(int j = 1 ; j <= i ; j++)
            {
                G[i]+=G[j-1] * G[i-j];
            }
        }
        return G[n];
    }
};