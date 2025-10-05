use std::cmp::{max, Ordering};

#[derive(Debug)]
struct AVL {
    value: i32,
    height: i32,
    left: Option<Box<AVL>>,
    right: Option<Box<AVL>>,
}

impl AVL {
    fn new(value: i32) -> Self {
        AVL {
            value,
            height: 1,
            left: None,
            right: None,
        }
    }

    fn height(node: &Option<Box<AVL>>) -> i32 {
        match node {
            Some(n) => n.height,
            None => 0,
        }
    }

    fn balance_factor(&self) -> i32 {
        Self::height(&self.left) - Self::height(&self.right)
    }

    fn update_height(&mut self) {
        self.height = 1 + max(Self::height(&self.left), Self::height(&self.right));
    }

    fn rotate_right(mut y: Box<AVL>) -> Box<AVL> {
        let mut x = y.left.take().unwrap();
        y.left = x.right.take();
        y.update_height();
        x.right = Some(y);
        x.update_height();
        x
    }

    fn rotate_left(mut x: Box<AVL>) -> Box<AVL> {
        let mut y = x.right.take().unwrap();
        x.right = y.left.take();
        x.update_height();
        y.left = Some(x);
        y.update_height();
        y
    }

    fn insert(node: Option<Box<AVL>>, value: i32) -> Option<Box<AVL>> {
        let mut n = match node {
            Some(mut n) => {
                match value.cmp(&n.value) {
                    Ordering::Less => n.left = AVL::insert(n.left.take(), value),
                    Ordering::Greater => n.right = AVL::insert(n.right.take(), value),
                    Ordering::Equal => return Some(n),
                }
                n
            }
            None => return Some(Box::new(AVL::new(value))),
        };

        n.update_height();
        let balance = n.balance_factor();

        if balance > 1 && value < n.left.as_ref().unwrap().value {
            return Some(AVL::rotate_right(Box::new(n)));
        }

        if balance < -1 && value > n.right.as_ref().unwrap().value {
            return Some(AVL::rotate_left(Box::new(n)));
        }

        if balance > 1 && value > n.left.as_ref().unwrap().value {
            n.left = Some(AVL::rotate_left(n.left.take().unwrap()));
            return Some(AVL::rotate_right(Box::new(n)));
        }

        if balance < -1 && value < n.right.as_ref().unwrap().value {
            n.right = Some(AVL::rotate_right(n.right.take().unwrap()));
            return Some(AVL::rotate_left(Box::new(n)));
        }

        Some(Box::new(n))
    }
}

fn main() {
    let mut root: Option<Box<AVL>> = None;
    for value in [10, 20, 30, 40, 50, 25] {
        root = AVL::insert(root, value);
    }
    println!("Balanced AVL Tree: {:#?}", root);
}
