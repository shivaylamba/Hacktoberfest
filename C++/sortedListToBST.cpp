#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//O(nlogn)
class Solution {
public:
    ListNode* mid_val(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev != NULL)
            prev->next = NULL;
        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        ListNode* mid = mid_val(head);
        TreeNode* root = new TreeNode(mid->val);

        if(head == mid)
            return root;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
