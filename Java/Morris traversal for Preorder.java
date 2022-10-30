// Java program to implement Morris preorder traversal

// A binary tree node
class Node {
	
	int data;
	Node left, right;
	
	Node(int item) {
		data = item;
		left = right = null;
	}
}

class BinaryTree {
	
	Node root;
	
	void morrisTraversalPreorder()
	{
		morrisTraversalPreorder(root);
	}

	// Preorder traversal without recursion and without stack
	void morrisTraversalPreorder(Node node) {
		while (node != null) {

			// If left child is null, print the current node data. Move to
			// right child.
			if (node.left == null) {
				System.out.print(node.data + " ");
				node = node.right;
			} else {

				// Find inorder predecessor
				Node current = node.left;
				while (current.right != null && current.right != node) {
					current = current.right;
				}

				// If the right child of inorder predecessor
				// already points to this node
				if (current.right == node) {
					current.right = null;
					node = node.right;
				}

				// If right child doesn't point to this node, then print
				// this node and make right child point to this node
				else {
					System.out.print(node.data + " ");
					current.right = node;
					node = node.left;
				}
			}
		}
	}
	
	void preorder()
	{
		preorder(root);
	}

	// Function for Standard preorder traversal
	void preorder(Node node) {
		if (node != null) {
			System.out.print(node.data + " ");
			preorder(node.left);
			preorder(node.right);
		}
	}
	
	// Driver programs to test above functions
	public static void main(String args[]) {
		BinaryTree tree = new BinaryTree();
		tree.root = new Node(1);
		tree.root.left = new Node(2);
		tree.root.right = new Node(3);
		tree.root.left.left = new Node(4);
		tree.root.left.right = new Node(5);
		tree.root.right.left = new Node(6);
		tree.root.right.right = new Node(7);
		tree.root.left.left.left = new Node(8);
		tree.root.left.left.right = new Node(9);
		tree.root.left.right.left = new Node(10);
		tree.root.left.right.right = new Node(11);
		tree.morrisTraversalPreorder();
		System.out.println("");
		tree.preorder();
		
	}
}

// this code has been contributed by Mayank Jaiswal
