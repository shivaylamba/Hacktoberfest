#[derive(Debug)]
struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32) -> Self {
        Node {
            value,
            left: None,
            right: None,
        }
    }

    fn insert_left(&mut self, value: i32) {
        self.left = Some(Box::new(Node::new(value)));
    }

    fn insert_right(&mut self, value: i32) {
        self.right = Some(Box::new(Node::new(value)));
    }

    fn preorder(&self) {
        print!("{} ", self.value);
        if let Some(left) = &self.left {
            left.preorder();
        }
        if let Some(right) = &self.right {
            right.preorder();
        }
    }
}

fn main() {
    let mut root = Node::new(1);
    root.insert_left(2);
    root.insert_right(3);
    root.left.as_mut().unwrap().insert_left(4);

    println!("Preorder traversal:");
    root.preorder();
}
