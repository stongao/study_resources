// Source: Interviewbit
// Date: 2/11/2017
// Time: 9 min
// Errors: 1. Didn't increment pointer inside while

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode *temp = A, *temp2;
    unordered_map<RandomListNode*,RandomListNode*> hmap;
    
    while(temp != NULL) {
        RandomListNode *newNode = new RandomListNode(temp->label);
        hmap.insert(make_pair(temp,newNode));
        temp = temp->next;
    }
    
    temp = A;
    while(temp != NULL) {
        temp2 = hmap.at(temp);
        if(temp->next != NULL) {
            temp2->next = hmap.at(temp->next);
        }
        if(temp->random != NULL) {
            temp2->random = hmap.at(temp->random);
        }
        temp = temp->next;
    }
    
    return hmap.at(A);
    

}
