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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* next = head;
        ListNode* pre = nullptr;
        
        while(next){
            next = next->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        return pre;
    }
};

//java,  p always points to the end of elements
public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}


