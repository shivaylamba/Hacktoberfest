#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
Node *root = NULL;
Node *temp = NULL;
void Insert()
{
  Node *obj = new Node;
  Node *objptr = new Node;
  cout<< "\nEnter Number: ";
  cin>> obj->data;
  obj->left = NULL;
  obj->right = NULL;
  if(root == NULL)
  {
       root = obj;
       cout<< "Number has been inserted in TREE!\n";
   }
  else
  {
   objptr = root;
   while(objptr!=NULL)
   {
   if(obj->data == objptr->data)
   {
     cout<< "Number already in TREE!\n";
      break;
   }
  else if(obj->data < objptr->data)
 {
 if(objptr->left)
{ objptr = objptr->left; }
 else
  {
    objptr->left = obj;
    cout<< "Number has been inserted in TREE!\n";
    break;
  } }
 else if(obj->data > objptr->data)
{
 if(objptr->right)
{ objptr = objptr->right; }
else
{
  objptr->right = obj;
  cout<< "Number has been inserted in TREE!\n";
  break;
 }
} } } }
bool Search(Node *ptr)
{
  Node *a = root;
  if(a == NULL)
 { cout<< "TREE is EMPTY!\n"; }
  while(a)
 {
   if(a->data == ptr->data)
  { return true; }
  else if(a->data < ptr->data)
 {
  if(a->left)
  { a = a->left; } }
  else
 { a = a->right; } } }
void Max()
{
  Node *max = root;
  if(max == NULL)
 { cout<< "TREE is EMPTY!\n"; }
else
{
 while(max)
{
  if(max->right)
{ max = max->right; }
else
{
    cout<< max->data<< " is Maximum Number in TREE!\n";
    break;
 } } } }
void Min()
{
  Node *min = root;
  if(min == NULL)
   { cout<< "TREE is EMPTY!\n"; }
  else
   {
    while(min)
    {
    if(min->left)
   { min = min->left; }
  else
   {
      cout<< min->data<< " is Minimum Number in TREE!\n";
      break;
  } } } }
void Delete(Node *ptr)
{
   bool found = Search(ptr);
   if (root == NULL)
   { cout<< "TREE is EMPTY!\n"; }
   if(found == false)
   { cout<< ptr->data<< " NOT FOUND in TREE!\n"; }
   else if(found==true)
   {
      if(ptr->right == NULL)
      {
         temp = ptr;
         ptr = ptr->left;
        cout<< temp->data<< " Has Been Deleted!\n";
       delete temp;
     }
    else if(ptr->left == NULL)
   {
       temp = ptr;
      ptr = ptr->right;
      cout<< temp->data<< " Has Been Deleted!\n";
      delete temp;
    }
   else if(ptr->left==NULL && ptr->right==NULL)
   {
      cout<< ptr->data<< " Has Been Deleted!\n";
       delete ptr;
    }
  else
   {
     Node *temp2 = new Node;
     temp = ptr->right;
    while(temp->left)
    { temp = temp->left; }
    temp->left = ptr->left;
    temp2 = ptr;
   ptr = ptr->right;
   cout<< temp2->data<< " Has Been Deleted!\n";
   delete temp2;
 } } }
int main()
{
    int ch;
    cout<< "************** BINARY SEARCH TREE****************\n";
    cout<< "*\t1. Insert an element into TREE          *\n";
    cout<< "*\t2. Search an element in TREE            *\n";
    cout<< "*\t3. Max element in TREE                  *\n";
    cout<< "*\t4. Min element in TREE                  *\n";
    cout<< "*\t5. Delete an element from TREE          *\n";
    cout<< "*\t6. Exit System                          *\n";
    cout<< "*************************************************\n";
    cout<< endl;
    while(ch!=6)
     {
      cout<< "Enter Choice: ";
      cin>> ch;
     if(ch==1)
     { Insert(); }
    else if(ch==2)
    {
      Node *obj = new Node;
      cout<< "Enter Number you want to Search: ";
      cin>> obj->data;
      bool found = Search(obj);
      if(found==true)
     { cout<< obj->data<< " FOUND in TREE!\n"; }
      else
      { cout<< obj->data<< " NOT FOUND in TREE!\n"; } }
      else if(ch==3)
      { Max(); }
      else if(ch==4)
      { Min(); }
     else if(ch==5)
    {
    Node *obj = new Node;
     cout<< "Enter Number you want to Search: ";
     cin>> obj->data;
     Delete(obj);
   } }
  if(ch==6)
 { cout<< "Exiting System....\n"; }
  system("pause");
  return 0;
}
