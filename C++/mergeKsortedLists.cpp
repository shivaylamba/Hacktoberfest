// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// ------------------------------------------------------------------------------------------------------------------------
/**
//  Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* sol(ListNode* root,ListNode* head) {
        if(root==NULL && head==NULL)
            return NULL;
        
        if(root==NULL)
            return head;
        
        if(head==NULL)
            return root;
        
        ListNode* i = root;ListNode* j=head;
        ListNode* curr=NULL;ListNode* last=NULL;
        
        while(i!=NULL && j!=NULL) {
            if(i->val<j->val)
            {
                if(last==NULL) {
                    curr = i;
                    last = curr;
                }
                
                else {
                    last->next = i;
                    last = last->next;
                }
                
                i = i->next;
            }
            
            else {
                //
                 if(last==NULL) {
                    curr = j;
                    last = curr;
                }
                
                else {
                    last->next = j;
                    last = last->next;
                }
                
                j = j->next;
            }
        }
        
        while(i!=NULL) {
            //
                            if(last==NULL) {
                    curr = i;
                    last = curr;
                }
                
                else {
                    last->next = i;
                    last = last->next;
                }
                
                i = i->next;
        }
        
        while(j!=NULL) {
            //
            if(last==NULL) {
                    curr = j;
                    last = curr;
                }
                
                else {
                    last->next = j;
                    last = last->next;
                }
                
                j = j->next;
        }
        
        return curr;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& list) {
        int n = list.size();
        
        if(n==0)
            return NULL;
        
        if(n==1)
            return list[0];
        
        ListNode* g = sol(list[0],list[1]);
        
        for(int i=2;i<n;i++)
            g = sol(g,list[i]);
        
        return g;
    }
};