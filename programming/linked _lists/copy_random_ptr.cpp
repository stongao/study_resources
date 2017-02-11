// Source : Interviewbit https://www.interviewbit.com/problems/copy-list/
// Date :  2/11/2017
// Time: 13 min
// Errors: 1. Attention to structure/class initialization
//          2. Attention to NULL check
//          3. Write full conditions in NULL check. eg if(temp != NULL ) instead of just if(temp)


/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode *temp = A, *temp2, *head2;
    if(A == NULL) {
        return NULL;
    }
    
    while(temp != NULL) {
        RandomListNode *newNode = new RandomListNode(temp->label);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
    
    temp = A;
    while(temp != NULL) {
        if(temp->random != NULL) {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }
    
    head2 = A->next;
    temp2 = head2;
    temp = A;
    while(temp != NULL) {
        temp->next = temp->next->next;
        if(temp2->next != NULL) {
            temp2->next = temp2->next->next;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }
    
    return head2;

}
