class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto p = head;
        int length = 0;
        while (p) {
            ++length;
            p = p->next;
        }
        
        for (int size = 1; size < length; size <<= 1) {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;
            
            while (cur) {
                auto left = cur;
                auto right = cut(left, size); // left->@->@ right->@->@->@...
                cur = cut(right, size); // left->@->@ right->@->@  cur->@->...
                
                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }
    
    ListNode* cut(ListNode* head, int n) {
        auto p = head;
        while (--n && p) {
            p = p->next;
        }
        
        if (!p) return nullptr;
        
        auto next = p->next;
        p->next = nullptr;
        return next;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;       
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};

class Solution {
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        auto slow = head;
        auto fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        auto left = sortList(head);
        auto right = sortList(tmp);
        ListNode dummyHead(0);
        ListNode* dummy = &dummyHead;
        ListNode* res = dummy;
        while(left != nullptr && right!=nullptr){
            if(left->val < right->val){
                dummy->next = left;
                left = left->next;
            }else{
                dummy->next = right;
                right = right->next;
            }
            dummy = dummy->next;
        }
        dummy->next = left != nullptr ? left : right;
        return res->next;
    }
}

//
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode dummyHead(0);
        ListNode * p = &dummyHead;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1;
                p = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;     
        return dummyHead.next;
        
    }  
    
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        auto slow = head;
        auto fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        auto left = sortList(head);
        auto right = sortList(tmp);
        ListNode* res =merge(left,right);
        return res;
    }
};