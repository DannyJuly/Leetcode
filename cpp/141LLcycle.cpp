/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
///28ms hashmap(set)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> nodes;
        while(head!=NULL){
            if(nodes.count(head)!=0)
                return true;
            else
                nodes.insert(head);
            head = head->next;
        }
        return false;
    }
};

//double pointer (slow and fast)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            if(fast == slow)
                return true;
            else{
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        return false;
    }
    
};

