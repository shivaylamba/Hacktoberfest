/*
 * C++ Program to Implement Singly Linked List
 */
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
struct node
{
    int info;
    struct node *next;
}*head;
 
class linked_list
{
    public:
        node* create_node(int);
        void insert_begin();
        void insert_pos();
        void insert_last();
        void delete_begin(); 
        void delete_pos();
        void delete_last();
        void display();
        linked_list() 
        {
            head = NULL;
        }
};
 
/*
 * Main :contains menu 
 */
void main()
{
    int choice, nodes, element, position, i;
    linked_list list;
    head = NULL;
    while (1)
    {
	clrscr();
	cout<<endl<<"Choose the option to be Performed"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4.Delete a Particular Node"<<endl;
        cout<<"5.Delete Node from the beginning"<<endl;
        cout<<"6.Delete Node from the End"<<endl;
        cout<<"7.Display Linked List"<<endl;
        cout<<"8.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            list.insert_begin();
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            list.insert_last();
            cout<<endl;
            break;
        case 3:
            cout<<"Inserting Node at a given position:"<<endl;
            list.insert_pos();
            cout<<endl;
            break;
        case 4:
            cout<<"Delete a particular node: "<<endl;
            list.delete_pos();
            break;
        case 5:
            cout<<"Delete node from Beginning:"<<endl;  
            list.delete_begin();
            cout<<endl;
            break;
        case 6:
            cout<<"Delete node from the End: "<<endl;
            list.delete_last();
            cout<<endl;
            break;
        case 7:
            cout<<"Display elements of link list"<<endl;
            list.display();
            cout<<endl;
            break;
        case 8:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
 
/*
 * Creating Node
 */
node *linked_list::create_node(int value)
{
    struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;     
        return temp;
    }
}
 
/*
 * Inserting element in beginning
 */
void linked_list::insert_begin()
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *p;
    temp = create_node(value);
    if (head == NULL)
    {
        head = temp;
        head->next = NULL;          
    } 
    else
    {
	p = head;
	head = temp;
	head->next = p;
    }
    cout<<"Element Inserted at beginning"<<endl;
    getch();
}

/*
 * Inserting Node at last
 */
void linked_list::insert_last()
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *s;
    temp = create_node(value);
    s = head;
    while (s->next != NULL)
    {
	s = s->next;
    }
    temp->next = NULL;
    s->next = temp;
    cout<<"Element Inserted at last"<<endl;
    getch();
}

/*
 * Insertion of node at a given position
 */
void linked_list::insert_pos()
{
    int value, pos, counter = 0;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    cout<<"Enter the postion at which node to be inserted: ";
    cin>>pos;
    int i;
    s = head;
    while (s != NULL)
    {
	s = s->next;
	counter++;
    }
    if (pos == 1)
    {
	if (head == NULL)
	{
	    head = temp;
	    head->next = NULL;
	    cout<<"Element Inserted at given position"<<endl;
	}
	else
	{
	    ptr = head;
	    head = temp;
	    head->next = ptr;
	    cout<<"Element Inserted at given position"<<endl;
	}
    }
    else if (pos > 1  && pos <= counter)
    {
	s = head;
	for (i = 1; i < pos; i++)
	{
	    ptr = s;
	    s = s->next;
	}
	ptr->next = temp;
	temp->next = s;
	cout<<"Element Inserted at given position"<<endl;
    }
    else
    {
	cout<<"Positon out of range"<<endl;
    }
    getch();
}
/*
 * Delete element at a given position
 */
void linked_list::delete_pos()
{
    int pos, i, counter = 0;
    if (head == NULL)
    {
	cout<<"List is empty"<<endl;
	getch();
	return;
    }
    cout<<"Enter the position of value to be deleted: ";
    cin>>pos;
    struct node *s, *ptr;
    s = head;
    if (pos == 1)
    {
	head = s->next;
	cout<<"Element Deleted"<<endl;
    }
    else
    {
	while (s != NULL)
	{
	    s = s->next;
	    counter++;
	}
	if (pos > 0 && pos <= counter)
	{
	    s = head;
	    for (i = 1;i < pos;i++)
	    {
		ptr = s;
		s = s->next;
	    }
	    ptr->next = s->next;
	    cout<<"Element Deleted"<<endl;
	}
	else
	{
	    cout<<"Position out of range"<<endl;
	}
	free(s);
    }
    getch();
}
void linked_list::delete_begin()
{
    int value;
    if (head == NULL)
    {
	cout<<"List is empty"<<endl;
	getch();
	return;
    }
    else{
	struct node *s;
	s = head;
	head = head->next;
	free(s);
	cout<<"Element Deleted from Beginning"<<endl;
    }
    getch();
}


void linked_list::delete_last()
{
    if (head == NULL)
    {
	cout<<"List is empty"<<endl;
	getch();
	return;
    }
    else{
	struct node *temp, *s;
	s = head;
	while ((s->next)->next != NULL)
	{
	    s = s->next;
	}
	temp = s->next;
	s->next = NULL;
	free(temp);
	cout<<"Element Deleted from last"<<endl;
    }
    getch();
}

/*
 * Display Elements of a link list
 */
void linked_list::display()
{
    struct node *temp;
    if (head == NULL)
    {
	cout<<"The List is Empty"<<endl;
	getch();
	return;
    }
    temp = head;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
	cout<<temp->info<<"->";
	temp = temp->next;
    }
    cout<<"NULL"<<endl;
    getch();
}