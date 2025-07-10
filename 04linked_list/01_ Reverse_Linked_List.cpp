class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp) {
            ListNode* address = temp->next;
            temp->next = prev;
            prev = temp;
            temp = address;
        }
        return prev;
    }
};