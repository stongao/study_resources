// Source : Leetcode https://leetcode.com/problems/reverse-nodes-in-k-group/
// Date : Monday, Feb 20
// Time :  ~25 min
// Errors : 1. Did not put check for NULL case
//          2. Did not put check for END case

//set pointer to an after-end node(k+1). If after end node is absent then return.
//take 3 pointers temp- pointer to the node of which next pointer we will change, temp_next point of next partition, temp_prev point of previous partition. Run loop only till temp is not end
//head next should point to the reversed linked list at end, the point of previous partition will be the start of list now
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *end = head;
        
        for(int i = 0; i < k; i++) {
            if(end == NULL) {
                return head;
            }
            else {
                end  = end->next;
            }
        }
        
        ListNode *temp = head->next, *temp_next, *temp_prev = head;
        while(temp != end) {
            temp_next = temp->next;
            temp->next = temp_prev;
            temp_prev = temp;
            temp = temp_next;
        }
        head->next = reverseKGroup(end,k);
        return temp_prev;
    }
};
