pragma solidity ^0.8.0;
contract SupplyChain {
    // The struct for a product
    struct Product {
        uint256 id;
        string name;
        uint256 price;
        uint256 quantity;
        address owner;
    }
    // The struct for an actor
    struct Actor {
        uint256 id;
        string name;
        address walletAddress;
    }
    // The mapping from product IDs to products
    mapping(uint256 => Product) public products;
    // The mapping from actor IDs to actors
    mapping(uint256 => Actor) public actors;
    // The event that is emitted when a product is created
    event ProductCreated(uint256 id, string name, uint256 price, uint256 quantity, address owner);
    // The event that is emitted when a product is transferred
    event ProductTransferred(uint256 id, address from, address to);
    // The function that creates a new product
    function createProduct(string memory name, uint256 price, uint256 quantity) public {
        uint256 id = products.length + 1;
        products[id] = Product(id, name, price, quantity, msg.sender);
        emit ProductCreated(id, name, price, quantity, msg.sender);
    }
    // The function that transfers a product from one actor to another
    function transferProduct(uint256 id, address from, address to) public {
        require(products[id].owner == from, "Only the owner can transfer a product.");
        products[id].owner = to;
        emit ProductTransferred(id, from, to);
    }
    // The function that gets all products in the supply chain
    function getAllProducts() public view returns (Product[] memory) {
        Product[] memory allProducts = new Product[](products.length);
        for (uint256 i = 0; i < products.length; i++) {
            allProducts[i] = products[i + 1];
        }
        return allProducts;
    }
    // The function that gets all actors in the supply chain
    function getAllActors() public view returns (Actor