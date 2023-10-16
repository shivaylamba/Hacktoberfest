// Given a reference (pointer to pointer) to the head 
// of a list and an int, inserts a new node 
// on the front of the list.
void push(Node** head_ref, int new_data)
{
	// 1. allocate node
	Node* new_node = new Node();

	// 2. put in the data
	new_node->data = new_data;

	// 3. Make next of new node as head
	// and previous as NULL
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	// 4. change prev of head node to new node
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	// 5. move the head to point to the new node
	(*head_ref) = new_node;
}

// This code is contributed by shivanisinghss2110
// Given a node as prev_node, insert a new node 
// after the given node
void insertAfter(Node* prev_node, int new_data)
{
	// Check if the given prev_node is NULL
	if (prev_node == NULL) {
		cout << "the given previous node cannot be NULL";
		return;
	}

	// 1. allocate new node
	Node* new_node = new Node();

	// 2. put in the data
	new_node->data = new_data;

	// 3. Make next of new node as next of prev_node
	new_node->next = prev_node->next;

	// 4. Make the next of prev_node as new_node
	prev_node->next = new_node;

	// 5. Make prev_node as previous of new_node
	new_node->prev = prev_node;

	// 6. Change previous of new_node's next node
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

// This code is contributed by shivanisinghss2110.
// Given a node as prev_node, insert a new node 
// after the given node
void insertBefore(Node* next_node, int new_data)
{
	// Check if the given next_node is NULL
	if (next_node == NULL) {
		printf("the given next node cannot be NULL");
		return;
	}

	// 1. Allocate new node
	Node* new_node = new Node();

	// 2. Put in the data
	new_node->data = new_data;

	// 3. Make previous of new node as previous of next_node
	new_node->prev = next_node->prev;

	// 4. Make the previous of next_node as new_node
	next_node->prev = new_node;

	// 5. Make next_node as next of new_node
	new_node->next = next_node;

	// 6. Change next of new_node's previous node
	if (new_node->prev != NULL)
		new_node->prev->next = new_node;
	else
		head = new_node;
}
// Given a reference (pointer to pointer) to the head
// of a DLL and an int, appends a new node at the end
void append(Node** head_ref, int new_data)
{
	// 1. allocate node
	Node* new_node = new Node();

	Node* last = *head_ref; /* used in step 5*/

	// 2. put in the data
	new_node->data = new_data;

	// 3. This new node is going to be the last node, so
	// make next of it as NULL
	new_node->next = NULL;

	// 4. If the Linked List is empty, then make the new
	// node as head
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	// 5. Else traverse till the last node
	while (last->next != NULL)
		last = last->next;

	// 6. Change the next of last node
	last->next = new_node;

	// 7. Make last node as previous of new node
	new_node->prev = last;

	return;
}

// This code is contributed by shivanisinghss2110
