#[derive(Debug)]
struct BST {
    value: i32,
    left: Option<Box<BST>>,
    right: Option<Box<BST>>,
}

impl BST {
    fn new(value: i32) -> Self {
        BST {
            value,
            left: None,
            right: None,
        }
    }

    fn insert(&mut self, value: i32) {
        if value < self.value {
            match self.left {
                Some(ref mut left) => left.insert(value),
                None => self.left = Some(Box::new(BST::new(value))),
            }
        } else if value > self.value {
            match self.right {
                Some(ref mut right) => right.insert(value),
                None => self.right = Some(Box::new(BST::new(value))),
            }
        }
    }

    fn search(&self, value: i32) -> bool {
        if self.value == value {
            true
        } else if value < self.value {
            match &self.left {
                Some(left) => left.search(value),
                None => false,
            }
        } else {
            match &self.right {
                Some(right) => right.search(value),
                None => false,
            }
        }
    }
}

fn main() {
    let mut root = BST::new(8);
    root.insert(3);
    root.insert(10);
    root.insert(1);
    root.insert(6);

    println!("BST structure: {:?}", root);
    println!("Search 6 -> {}", root.search(6));
    println!("Search 15 -> {}", root.search(15));
}
