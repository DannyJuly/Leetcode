/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        ListNode*pre = NULL;
        ListNode*slow = head;
        ListNode*fast = head;
        ListNode*s = NULL;
        while(fast != NULL && fast->next != NULL)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = s;
            s = pre;
        }
        ListNode*temp = slow;
        if(fast != NULL) temp = temp->next; 
        slow = pre;
        while(temp!=NULL)
            if(temp->val!=slow->val) return false;
            else {temp = temp->next;slow = slow->next;}
        return true;
        
    }
};

