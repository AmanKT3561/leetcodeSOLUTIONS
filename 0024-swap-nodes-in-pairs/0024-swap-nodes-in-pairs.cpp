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
    ListNode *swap_recur(ListNode *head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *remaining=head->next->next;
        ListNode *nextNode=head->next;
        nextNode->next=head;
        head->next=swap_recur(remaining);
        return nextNode;
    }
    ListNode* swapPairs(ListNode* head) {
        return swap_recur(head);
    }
};