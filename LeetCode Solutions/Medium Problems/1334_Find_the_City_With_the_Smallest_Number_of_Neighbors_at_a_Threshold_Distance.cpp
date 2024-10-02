/*
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
Example 1:
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:
Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
Constraints:
2 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti, distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct.
*/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            distance[i][i] = 0;  // distance to itself is 0
        }

        // The distance between nodes which are connected temporary distance between them
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1], dist = edge[2];
            distance[node1][node2] = dist;
            distance[node2][node1] = dist;
        }

        for (int midle = 0; midle < n; ++midle) {
            for (int source = 0; source < n; ++source) {
                for (int destination = 0; destination < n; ++destination) {
                    if (distance[source][midle] < INT_MAX && distance[midle][destination] < INT_MAX) {
                        distance[source][destination] = min(
                            distance[source][destination], distance[source][midle] + distance[midle][destination]
                        );  // the minimum distance is either current value or new value with path that goes through midle
                    }
                }
            }
        }

        int minimum_number = n;
        int res = -1;

        for (int source = 0; source < n; ++source) {
            int source_count = 0;
            for (int destination = 0; destination < n; ++destination) {
                if (distance[source][destination] <= distanceThreshold) {
                    ++source_count;
                }
            }

            if (source_count <= minimum_number) {  // as in dijkstra when number equal we choose greater node
                minimum_number = source_count;
                res = source;
            }
        }

        return res;
    }
};