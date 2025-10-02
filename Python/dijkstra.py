"""
Dijkstra's Algorithm
Author: Piyush Sharma
Hacktoberfest 2025 Contribution
"""

from typing import Dict, List, Tuple
import heapq

def dijkstra(graph: Dict[int, List[Tuple[int, int]]], start: int) -> Dict[int, int]:
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    pq = [(0, start)]
    
    while pq:
        current_distance, current_node = heapq.heappop(pq)
        if current_distance > distances[current_node]:
            continue
        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    return distances

if __name__ == "__main__":
    graph_example = {
        0: [(1, 4), (2, 1)],
        1: [(3, 1)],
        2: [(1, 2), (3, 5)],
        3: []
    }
    shortest_paths = dijkstra(graph_example, 0)
    print("Shortest paths from node 0:", shortest_paths)
