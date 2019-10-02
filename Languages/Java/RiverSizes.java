import java.util.*;

class Program {
	public static Stack<ArrayList<Integer>> getUnvisitedNeighbours( int i ,int j ,int[][] matrix , int [][] visited){
		Stack<ArrayList<Integer>> unvisitedNeighbours = new Stack<>();
		
		if(i>0 && visited[i-1][j]!=1){
			ArrayList<Integer> node =  new ArrayList<>();
			node.add(i-1);
			node.add(j);
			unvisitedNeighbours.push(node);
			
		}
		
		if(i<matrix.length-1 && visited[i+1][j]!=1){
			ArrayList<Integer> node =  new ArrayList<>();
			node.add(i+1);
			node.add(j);
			unvisitedNeighbours.add(node);
			
		}
		
		if(j>0 && visited[i][j-1]!=1){
			ArrayList<Integer> node =  new ArrayList<>();
			node.add(i);
			node.add(j-1);
			unvisitedNeighbours.push(node);
			
		}
		
		if(j<matrix[i].length-1 && visited[i][j+1]!=1){
			ArrayList<Integer> node =  new ArrayList<>();
			node.add(i);
			node.add(j+1);
			unvisitedNeighbours.push(node);
			
		}
		return unvisitedNeighbours;
	}
	
	public static void traverseNode( int i ,int j ,int[][] matrix , int [][] visited , ArrayList<Integer> sizes){
		
		int currentRiverSize = 0;
		
		Stack<ArrayList<Integer>> nodesToExplore = new Stack<>();
		Stack<ArrayList<Integer>> unvisitedNeighbours = new Stack<>();
		
		ArrayList<Integer> node =  new ArrayList<>();
		ArrayList<Integer> currentNode =  new ArrayList<>();
		node.add(i);
		node.add(j);
		nodesToExplore.push(node);
		
		while(nodesToExplore.size()!=0){
				currentNode = nodesToExplore.pop();
				i = currentNode.get(0);
				j = currentNode.get(1);
			
			if(visited[i][j]==1){
					continue;
				}
			visited[i][j]=1;
			
			if(matrix[i][j]==0){
				continue;
			}
			currentRiverSize++;
			unvisitedNeighbours = getUnvisitedNeighbours(i ,j , matrix , visited);
			for(ArrayList<Integer> neighbour : unvisitedNeighbours){
				nodesToExplore.push(neighbour);
			}
			
			
		}
		if (currentRiverSize>0){
			sizes.add(currentRiverSize);
		}
	}
  public static ArrayList<Integer> riverSizes(int[][] matrix) {
    // Write your code here.
		
		ArrayList<Integer> sizes = new ArrayList<>();
		int[][] visited = new int[matrix.length][matrix[0].length];
		
		for(int i=0 ; i<matrix.length ; i++){
			for(int j=0 ; j<matrix[i].length ; j++){
				
				if(visited[i][j]==1){
					continue;
				}
				
				traverseNode( i , j ,matrix , visited , sizes);
				
			}
		}
		return sizes;
	//test
  }
}
