#include<stdio.h>
#include<string.h>
#include<openssl/crypto.h>
#include <stdlib.h>
#include <openssl/e_os2.h>
#define SHA256_DIGEST_LENGTH   32
struct block
{
	unsigned char prevHash[SHA256_DIGEST_LENGTH];
	int blockdata;
	struct block *link;
} *head;
void addBlock(int data)
{
	if(head==NULL)
	 {
         head=malloc(sizeof(struct block));
         SHA256("",sizeof(" "), head->prevHash);
         head->blockdata=data;
         return;
	 }
	struct block *currentblock = head;
	while(currentblock->link)
	 {
	     currentblock = currentblock->link;
	 }
	struct block *newBlock = malloc(sizeof(struct block));
	currentblock->link= newBlock;
	newBlock-> blockdata = data;
	SHA256(toString(*currentblock),sizeof(*currentblock),newBlock->prevHash);
}
void verifychain()
{
	if(head==NULL)
	{
		printf("blockchain empty");
		return;
	}
	struct block *curr=head->link,*prev->head;
	int count=1;
	while(curr)
	{
		printf("%d\t[%d]\t",count++,curr->blockdata);
		hashPrinter(SHA256(toString(*prev),sizeof(*prev),NULL),SHA256_DIGEST_LENGTH);
		printf(" . ");
		hashPrinter(curr->prevHash,SHA256_DIGEST_LENGTH);
		if(hashCompare(SHA256(toString(*prev),sizeof(*prev),NULL),curr->prevHash))
			printf("VERIFIED\n" );
		else
			print("verification failed\n");
        prev=curr;
        curr=curr->link;
     }
}
void alterNthBlock(int n ,int newdata)
{
	struct block *curr=head;
    if (curr=NULL)
        {
    	  printf("nth blockdata does not exist" );
    	  return;
    		/* code */
    	}	
    while(count!=n)
{
		 if(curr->link==NULL && count!=n)
		 {
		 	printf("Nth block does not exist\n");
		 	return ;
		 }
		 else if(count==n)
		 	break;
         curr=curr->link;
	     count++;
}
printf("Before: ");
 printBlock(curr);
 curr->blockdata=newdata;
 printf("\nAfter: ");
 printBlock(curr);
 printf("\n");
}
void hackChain()
{
	struct block *curr=head,*prev;
	if(curr==NULL)
	{
		printf("blockchain is empty");
		return;
	}

	while(1)
	{
	    prev=curr;
	    curr=curr->link;
	    if(curr==NULL)
	    	return;
		if(!hashCompare(SHA256(toString(*prev),sizeof(*prev),NULL),curr->prevHash))
	     {
	     	hashPrinter(SHA256(toString(*prev),sizeof(*prev),curr->prevHash),SHA256_DIGEST_LENGTH);
	     printf("\n");
	     }
	
	}
}
unsigned char* tostring(struct block b)
{
	unsigned char *str=malloc(sizeof(unsigned char)*sizeof(b));
    memcpy(str,&b,sizeof(b));
    return str;
}
 void hashPrinter(unsigned char hash[],int length)
 {
 	for(int i=0;i<length;i++)
 		printf("%02x",hash[i]);
 }
int hashCompare(unsigned char *str1,unsigned char *str2)
{
  for(int i=0;i<SHA256_DIGEST_LENGTH;i++)
  {
   	 if(str1[i]!=str2[i])
   	 	return 0;
   	 return 1;
  }
  void printBlock(struct block *b)
  {
  	printf("%p]t",b);
  	hashPrinter(b->prevHash,sizeof(b->prevHash));
  	printf("\t[%d]\t",b->blockdata);
  	printf("%p\n",b->link);
   
  }	
}
 void printAllBlocks()
  {
  	struct block *curr=head;
  	int count=0;
  	while(curr)
  	{
  		printBlock(curr);
  		curr=curr->link;
  	}
  }
  void main()
  {
  	int c,n,r;
  	printf("1)addBlock\n2)add n random blocks \n 3)alterNthBlock\n 4)printAllBlocks \n 5)verifychain \n6) hackChain\n");
  	while(1)
  	{
  		printf("Choice :  ");
  		scanf("%d",&c);
  		switch(c)
  		{
  			case 1:
  			       printf("Enter data: ");
  			       scanf("%d",&n);
  			       addBlock(n);
  			       break;
  			case 2:
  			       printf("How many blocks to enter?: " );
  			       scanf("%d",&n);
  			       for (int i = 0; i < n;i++)
  			       {
  			       	 r=rand()%(n*10);
  			       	 printf("Entering: %d\n",r );
  			       	 addBlock(r);
  			       }
  			       break;
  			case 3:
  			       printf("Which block to alter?: " );
  			       scanf("%d",&n);
  			       printf("Enter value: ");
  			       scanf("%d",&r);
  			       alterNthBlock(n,r);
  			       break;
  			case 4:
  			       printAllBlocks();
  			       break;
  			case 5:
  			       verifychain();
  			       break;
  			case 6:
  			       hackChain();
  			       break;
  			default:
  			       printf("Wrong Choice: \n");
                   break;
  			    }
  		
  	}
  }
 



















































































































































































































































































































































































































































