#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node* insert_at_end(struct node* head, int data ){
  struct node* new = (struct node*)malloc(sizeof(struct node));
   struct node* last = head;
   new->data=data;
  new->next=NULL;
  if(head==NULL){
    head=new;
    return head;
  }
  while(last->next!=NULL){
    last=last->next;
  }
  last->next=new;
  return head;
  }

  struct node* merge_list(struct node* merge, struct node* head, int count, int k){
	int i,j;
	i = 0;
	j = 0;
	struct node* temp = NULL;
	while(i<count&&j<k){
		if(merge->data<=head->data){
			temp = insert_at_end(temp,merge->data);
			i++;
			merge = merge->next;
		}
		else{
			temp = insert_at_end(temp,head->data);
			head = head->next;
			j++;
		}
	}
	while(i<count){
		temp = insert_at_end(temp, merge->data);
		merge = merge->next;
		i++;
	}
	while(j<k){
		temp = insert_at_end(temp, head->data);
		head = head->next;
		j++;
	}

	return temp;
}



  void plist(struct node* head){
     struct node* temp= head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
  }

  int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int n;
		scanf(" %d",&n);
		int i,j;
        struct node* merge = NULL;
		int count = 0;
		for(i=0;i<n;i++){
			int k;
			struct node* head = NULL;
			scanf(" %d",&k);
			int data;
			for(j=0;j<k;j++){
				scanf(" %d",&data);
				head = insert_at_end(head,data);
			}
			merge = merge_list(merge, head, count, k);
			count+=k;
		}
		plist(merge);
	}
	return 0;
}

