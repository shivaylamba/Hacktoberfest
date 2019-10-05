import java.util.LinkedList;
import java.util.Queue;

public class SymmetricTree {
	Node root;
	static class Node { 
		 int data; 
		 Node left, right; 

		 public Node(int data) { 
		     this.data = data; 
		     left = right = null; 
		 } 
		 
		} 

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		SymmetricTree t1 = new SymmetricTree();
		t1.root = new Node(1);
		t1.root.left = new Node(3);
		t1.root.right = new Node(3);
		t1.root.left.left = new Node(4);
		t1.root.left.right = new Node(5);
		t1.root.right.left = new Node(5);
		t1.root.right.right = new Node(4);
		
		
//		printLevelOrderOfTree(t1.root);
		
		System.out.println(isMirror(t1.root , t1.root));
	}
	
	static boolean isMirror(Node rootA , Node rootB){
		if(rootA==null && rootB==null){
			return true;
		}
		
		if(rootA!=null && rootB!=null && rootA.data==rootB.data){
			return isMirror(rootA.left,rootB.right) && isMirror(rootA.right,rootB.left);
		}
		
		return false;
	}
	
	static void printLevelOrderOfTree(Node root){
	
	if(root == null)
		return;
	
	Queue<Node> que = new LinkedList<Node>();
	
	que.add(root);
	Node tmp;
	
	while(!que.isEmpty()){
		tmp = que.poll();
		System.out.print(tmp.data+" ");
		if(tmp.left!=null)
			que.add(tmp.left);
		if(tmp.right!=null)
			que.add(tmp.right);
	}
	
}

}
