#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createnode (int data)
{
  struct node *n;
  n = (struct node *) malloc (sizeof (struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;

}

int isbst (struct node *root)
{
  static struct node *prev = NULL;
  if (root != NULL)
    {
      if (!isbst (root->left))
	{
	  return 0;
	}
      if (prev != NULL && root->data <= prev->data)
	{
	  return 0;
	}
      prev = root;
      return isbst (root->right);
    }
  else
    {
      return 1;
    }
}


int main ()
{
  struct node *p = createnode (5);
  struct node *p1 = createnode (2);
  struct node *p2 = createnode (6);
  struct node *p3 = createnode (9);
  struct node *p4 = createnode (4);
  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;

  if (isbst (p))
    {
      cout << "It is a BST" << endl;
    }
  else
    {
      cout << "Not a BST" << endl;
    }
}
