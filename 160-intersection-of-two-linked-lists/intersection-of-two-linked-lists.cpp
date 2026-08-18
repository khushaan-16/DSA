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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* a_point = headA;
        ListNode* b_point = headB;

        while(a_point != b_point){
            if(a_point == NULL){
                a_point = headB;
            }
            else{
                a_point = a_point->next;
            }
            if(b_point == NULL){
                b_point = headA;
            }
            else{
                b_point = b_point->next;
            }
        }
        return a_point;
    }
};