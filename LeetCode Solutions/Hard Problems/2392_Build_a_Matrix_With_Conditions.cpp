/*
2392. Build a Matrix With Conditions
You are given a positive integer k. You are also given:
a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.
You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.
The matrix should also satisfy the following conditions:
The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.
Example 1:
Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.
Example 2:
Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.
Constraints:
2 <= k <= 400
1 <= rowConditions.length, colConditions.length <= 104
rowConditions[i].length == colConditions[i].length == 2
1 <= abovei, belowi, lefti, righti <= k
abovei != belowi
lefti != righti
*/
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : rowConditions) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<int> row_sorting = topo_sort(graph, k);
        graph.clear();
        for (const auto& edge : colConditions) {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<int> col_sorting = topo_sort(graph, k);

        if (row_sorting.empty() || col_sorting.empty()) {
            return {};
        }

        unordered_map<int, pair<int, int>> value_position;
        for (int i = 0; i < k; ++i) {
            value_position[row_sorting[i]].first = i;
            value_position[col_sorting[i]].second = i;
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        for (int value = 1; value <= k; ++value) {
            int row = value_position[value].first;
            int column = value_position[value].second;
            res[row][column] = value;
        }

        return res;
    }

private:
    bool dfs(int src, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, unordered_set<int>& cur_path, vector<int>& res) {
        if (cur_path.count(src)) return false;  // cycle detected
        if (visited.count(src)) return true;  // all okay, but we've already visited this node

        visited.insert(src);
        cur_path.insert(src);

        for (int neighbor : graph[src]) {
            if (!dfs(neighbor, graph, visited, cur_path, res))  // if any child returns false
                return false;
        }

        cur_path.erase(src);  // backtrack path
        res.push_back(src);
        return true;
    }

    vector<int> topo_sort(unordered_map<int, vector<int>>& graph, int k) {
        unordered_set<int> visited;
        unordered_set<int> cur_path;
        vector<int> res;

        for (int src = 1; src <= k; ++src) {
            if (!dfs(src, graph, visited, cur_path, res))
                return {};
        }

        reverse(res.begin(), res.end());  // we will have res as reversed so we need to reverse it one more time
        return res;
    }
};