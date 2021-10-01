# Implementation of Dijkstra Algorithm for Directed Graphs
def find_lowest_cost_node(fcosts):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for fnode in fcosts:
        fcost = fcosts[fnode]
        if fcost < lowest_cost and fnode not in processed:
            lowest_cost = fcost
            lowest_cost_node = fnode
    return lowest_cost_node


graph = {}

N = int(input())
for i in range(N):
    u, v, weight = map(int, input().split())
    if u not in graph:
        graph[u] = {}
        if v not in graph[u]:
            graph[u][v] = weight
    graph[u][v] = weight
    
graph[6] = {}

infinity = float("inf")

costs = {}
for j in graph.keys():
    for i in graph[j].keys():
        if j == 1:
            costs[i] = graph[j][i]
        else:
            if i not in costs:
                costs[i] = infinity

parents = {}
for j in graph.keys():
    for i in graph[j].keys():
        if j == 1:
            parents[i] = j
        else:
            if i not in parents:
                parents[i] = None

processed = []
node = find_lowest_cost_node(costs)
while node is not None:
    cost = costs[node]
    neighbours = graph[node]
    for n in neighbours.keys():
        new_cost = cost + neighbours[n]
        if costs[n] > new_cost:
            costs[n] = new_cost
            parents[n] = node
    processed.append(node)
    node = find_lowest_cost_node(costs)
print(costs[6])

# Test Cases
# 9
# 1 2 5
# 1 3 2
# 2 4 4
# 2 5 2
# 3 2 8
# 3 5 7
# 4 6 3
# 4 5 6
# 5 6 1
