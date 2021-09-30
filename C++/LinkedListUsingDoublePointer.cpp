#include<iostream>
#include<stdio.h>
#include<malloc.h>

typedef struct node {
    struct node* prev;
    struct node* next;
    int data;
}snode;

void insrt(snode** hd, snode** tl, int n) {
    snode* p = NULL;
    p = (snode*)malloc(sizeof(snode));
    if (p != NULL) {
        p->data = n;
        p->next = NULL;
        if (*hd == NULL) {
            *hd = *tl = p;
        }
        else {
            (*tl)->next = p;
            *tl = p;
        }
        printf("Element Inserted!\n");
    }
    else
        printf("Memory Not Allocated!\n");
}

void del(snode** hd, snode** tl, int k) {
    int loc = 1;
    snode* temp = *hd, * prev;
    if (temp != NULL && temp->data == k) {
        *hd = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != k) {
        prev = temp;
        temp = temp->next;
        loc++;
    }
    if (temp == NULL)
        return;
    printf("%d is found at postion %d", k, loc);
    prev->next = temp->next;
    free(temp);
    printf("Node Deleted!\n");
}

void disp(snode* hd, snode* tl) {
    printf("Linked List Status: ");
    while (hd != tl) {
        printf("%d ", hd->data);
        hd = hd->next;
    }
    printf("%d\n", hd->data);
}

int main() {
    snode* head = NULL, * tail = NULL;
    int ch, n;
    do {
        printf("\n\tMENU\n1. Insert\n2. Delete a Node with Key\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter Value to insert: ");
            scanf("%d", &n);
            insrt(&head, &tail, n);
        }
        else if (ch == 2) {
            if (head == NULL) {
                printf("Linked List Underflow\n");
                continue;
            }
            printf("Enter Key: ");
            scanf("%d", &n);
            del(&head, &tail, n);
        }
        else if (ch == 3) {
            if (head == NULL) {
                printf("Linked List Underflow\n");
                continue;
            }
            disp(head, tail);
        }
        else if (ch == 4)
            break;
        else
            printf("Invalid Choice!");
    } while (ch != 4);
}