/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* mergeTwoList(ListNode* List1, ListNode* List2) {
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    while(List1 != NULL && List2 != NULL){
        if(List1->val < List2->val){
            temp->next = List1;
            temp = List1;
            List1 = List1->next;
        }
        else{
            temp->next = List2;
            temp = List2;
            List2 = List2->next;
        }
    }
    if(List1) temp->next = List1;
    else temp->next = List2;

    return dummyNode->next;
}
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);
        return mergeTwoList(left, right);
    }
};