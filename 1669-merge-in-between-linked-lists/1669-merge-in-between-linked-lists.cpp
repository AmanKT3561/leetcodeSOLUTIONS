class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* temp = list1;

        for (int i = 0; i < a - 1; i++)
            temp = temp->next;

        ListNode* x = temp;

        for (int i = 0; i <= b - a + 1; i++)
            x = x->next;

        temp->next = list2;

        ListNode* tail = list2;
        while (tail->next)
            tail = tail->next;

        tail->next = x;

        return list1;
    }
};