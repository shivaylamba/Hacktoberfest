               //geeksforgeeks
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int i;
	int h;
	struct node *left;
	struct node *right;
}node;

node *search(node *root,int a)
{
	node *temp=root;
	while(1)
	{
		if(temp=='\0')
		return '\0';
		if(temp->i==a)
		return temp;
		if(a<temp->i)
		temp=temp->left;
		else
		{
			temp=temp->right;
		}
	}
}

node *parent(node *root,int a)
{
	node *t=root;
	node *p=root;
	if(t->i==a)
	return '\0';
	while(t->i!=a)
	{
		if(a<t->i)
		{
			p=t;
			t=t->left;
		}
		else
		{
			p=t;
			t=t->right;
		}
	}
	return p;
}

int max(int lh,int rh)
{
	int ht=(lh>rh?lh:rh);
	return ht;
}

int height(node *root)
{
	if(root=='\0')
	return 0;
	return root->h;
}

int balance(node *root)
{
	if(root=='\0')
		return 0;
	return (height(root->left)-height(root->right));
}

node *right_rotation(node *root)
{
	node *x,*y,*z;
	x=root;
	y=root->left;
	z=y->right;
	
	y->right=x;
	x->left=z;
	x->h=1+max(height(x->left),height(x->right));
	y->h=1+max(height(y->left),height(y->right));
	return y;
}

node *left_rotation(node *root)
{
	node *x,*y,*z;
	x=root;
	y=root->right;
	z=y->left;
	
	y->left=x;
	x->right=z;
	x->h=1+max(height(x->left),height(x->right));
	y->h=1+max(height(y->left),height(y->right));
	return y;
}

node *insert(node *root, int a)
{
	if(root=='\0')
	{
		node *new=(node *)malloc(sizeof(node));
		new->i=a;
		new->h=1;
		new->left='\0';
		new->right='\0';
		return new;
	}
	if(a<root->i)
		root->left=insert(root->left,a);
	else
	{
		if(a>root->i)
			root->right=insert(root->right,a);
		else
		    return root;
	}
	root->h=1+max(height(root->left),height(root->right));
	int bf;
	bf= balance(root);
	
	if(bf>1 && a<root->left->i)
	{
		return right_rotation(root);
	}
	if(bf>1 && a>root->left->i)
    {
    	root->left=left_rotation(root->left);
    	return right_rotation(root);
	}
	if(bf<-1 && a>root->right->i)
	{
		return left_rotation(root);
	}
	if(bf<-1 && a<root->right->i)
	{
		root->right=right_rotation(root->right);
		return left_rotation(root);
	}
	return root;
}

node *min(node *root)
{
	node *temp=root;
	while(temp->left!='\0')
	{
		temp=temp->left;
	}
	return temp;
}

node* delete(node* root, int a) 
{ 
    if (root == NULL) 
        return root; 
    if ( a < root->i) 
        root->left = delete(root->left, a); 
    else if( a > root->i ) 
        root->right = delete(root->right, a); 
    else
    { 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            node *temp = root->left?root->left:root->right;  
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else 
            {
            	root->i=temp->i;
            	root->left='\0';
            	root->right='\0';
			}
            free(temp); 
        } 
        else
        {
            node* temp = min(root->right);
            root->i= temp->i;
            root->right = delete(root->right, temp->i); 
        } 
    } 
    if (root == NULL) 
      return root; 
    root->h = 1 + max(height(root->left),height(root->right)); 
    int bf = balance(root); 
    
    if (bf > 1 && balance(root->left) >= 0) 
        return right_rotation(root); 
        
    if (bf > 1 && balance(root->left) < 0) 
    { 
        root->left =  left_rotation(root->left); 
        return right_rotation(root); 
    } 
  
    if (bf < -1 && balance(root->right) <= 0) 
        return left_rotation(root); 
  
    if (bf < -1 && balance(root->right) > 0) 
    { 
        root->right = right_rotation(root->right); 
        return left_rotation(root); 
    } 
  
    return root; 
} 

int depth(node *root,int a, node *t)
{
	int c=1;
	while(t!=root)
	{
		t=parent(root,t->i);
		c++;
	}
	return c;
}

void inorder(node *root)
{
	if(root=='\0')
	return;
	inorder(root->left);
	printf("%d  ",root->i);
    inorder(root->right);
}

void preorder(node *root)
{
	if(root=='\0')
	return;
	printf("%d  ",root->i);
	preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
	if(root=='\0')
	return;
	postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->i);
}

void levelprint(node *root,int a)
{
	if(root=='\0')
	return;
	if(a==1)
	printf("%d  ",root->i);
	else
	{
		levelprint(root->left,a-1);
		levelprint(root->right,a-1);
	}
}

void levelorder(node *root)
{
	int i,h;
	h=height(root);
	for(i=1;i<=h;i++)
	{
		levelprint(root,i);
	}
}

node *successor(node *root,int a,node *s)
{
	node *temp=s->right;
	if(temp!='\0')
	{
		while(temp->left!='\0')
		temp=temp->left;
	    return temp;
	}
	else
	{
		while(1)
		{
			s=parent(root,s->i);
			if(s->i>a)
			{
				return s;
			}
			if(root==s)
			return '\0';
		}
	}
}

node *predecessor(node *root,int a,node *s)
{
	node *temp=s->left;
	if(temp!='\0')
	{
		while(temp->right!='\0')
		temp=temp->right;
	    return temp;
	}
	else
	{
		while(1)
		{
			s=parent(root,s->i);
			if(s->i<a)
			{
				return s;
			}
			if(root==s)
			return '\0';
		}
	}
}

node *lca(node *root,node *t,node *s)
{
	while(1)
    {
    	if(root->i > t->i && root->i > s->i)
    	root=root->left;
    	else
    	if(root->i  < t->i && root->i < s->i)
    	root=root->right;
    	else
    	break;
	}
	return root;
}


int main()
{
	node *root='\0',*t,*p,*q;
	int a,j,n,m,b,h;
	printf("1.insert an element in AVL tree\n");
	printf("2.Delete an element from the AVL tree\n");
	printf("3.Search an element from the given AVL tree\n");
	printf("4.inorder\n");
	printf("5.preorder\n");
	printf("6.postorder\n");
	printf("7.levelorder\n");
	printf("8.height of the AVL tree\n");
	printf("9.height of a given node of the AVL tree\n");
	printf("10.depth of a given node of the AVL tree\n");
	printf("11.predecessor of a given node of the AVL tree\n");
	printf("12.the successor of a given node of the AVL tree\n");
	printf("13.the least common ancestor of two given nodes of the AVL tree\n");
	printf("14.exit\n");
	while(1)
	{
		printf("enter the key for above operation = ");
		scanf("%d",&n);
		if(n==14)
		break;
		switch(n)
		{
			case 1:
				printf("enter the element = ");
				scanf("%d",&a);
				root=insert(root,a);
				printf("element is inserted\n");
				break;
			case 2:
				if(root=='\0')
				{
					printf("AVL tree is null");
					break;
				}
				printf("enter the element which you want to delete = ");
				scanf("%d",&a);
				t= search(root,a);
				if(t=='\0'){
				printf("%d is not found in BST\n",a);
				break;}
				printf("%d is deleted",t->i);
				root=delete(root,a);
				break;
			case 3:
				printf("enter the element which you want to search = ");
			    scanf("%d",&a);
				t=search(root,a);
				if(t=='\0')
				printf("%d is not found\n",a);
				else
				printf("%d is found",t->i);
				break;		
			case 4:
				if(root=='\0')
				printf("tree is null");
				else
				inorder(root);
				break;
			case 5:
				if(root=='\0')
				printf("tree is null");
				else
				preorder(root);
				break;
			case 6:
				if(root=='\0')
				printf("tree is null");
				else
				postorder(root);
				break;
			case 7:
				if(root=='\0')
				printf("tree is null");
				else
				levelorder(root);
				break;
			case 8:
				h=height(root);
				if(h==0)
				printf("tree is null");
				else
				printf("the height of tree is %d",h);
				break;
			case 9:
				printf("enter the element = ");
				scanf("%d",&a);
				t=search(root,a);
				if(t=='\0')
				printf("%d is not found",a);
				else
				printf("the height of element is %d",height(t));
				break;
			case 10:
				printf("enter the element = ");
				scanf("%d",&a);
				t=search(root,a);
				if(t=='\0')
				printf("%d is not found",a);
				else
				{
					printf("the depth of element is %d",depth(root,a,t));
				}
				break;
			case 11:
				printf("enter the element which you want to find predecessor = ");
			    scanf("%d",&a);
			    t=search(root,a);
			    if(t=='\0')
			    printf("%d is not found",a);
			    else{
			    p=predecessor(root,a,t);
			    if(p=='\0')
			    printf("predecessor of %d does not exist",a);
			    else
			    printf("predecessor of %d is %d",a,p->i);
			    }
		    	break;
			case 12:
				printf("enter the element which you want to find successor = ");
			    scanf("%d",&a);
			    t=search(root,a);
			    if(t=='\0')
			    printf("%d is not found",a);
			    else{
			    p=successor(root,a,t);
			    if(p=='\0')
			    printf("successor of %d does not exist",a);
			    else
			    printf("successor of %d is %d",a,p->i);
			    }
		    	break;
		    case 13:
		    	printf("enter the elements\n");
		    	scanf("%d %d",&a,&b);
		    	t=search(root,a);
		    	p=search(root,b);
		    	if(t=='\0'||p=='\0')
		    	printf("lca can't be find");
		    	else
		    	{
		    		q=lca(root,t,p);
		    		printf("%d is lca",q->i);
				}
				break;
	    }
	    printf("\n\n");
	}
	return 0;
}
