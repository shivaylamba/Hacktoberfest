<?php
// Simple Stack Implementation
class Stack {
    private $stack;
    private $limit;
    
    public function __construct($limit = 10) {
        $this->stack = array();
        $this->limit = $limit;
    }
    
    public function push($item) {
        if (count($this->stack) < $this->limit) {
            array_push($this->stack, $item);
        } else {
            throw new Exception("Stack is full!");
        }
    }
    
    public function pop() {
        if ($this->isEmpty()) {
            throw new Exception("Stack is empty!");
        }
        return array_pop($this->stack);
    }
    
    public function peek() {
        return end($this->stack);
    }
    
    public function isEmpty() {
        return empty($this->stack);
    }
}

// Usage example
$stack = new Stack();
$stack->push(1);
$stack->push(2);
$stack->push(3);
echo "Top element: " . $stack->peek(); // Output: 3
?>