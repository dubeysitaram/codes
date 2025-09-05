// 142. Linked List Cycle II.cpp
/*
Given the head of a linked list,
return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by
continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

*/
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return nullptr;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow)
				break;
		}
		if (fast == nullptr || fast->next == nullptr)return nullptr;
		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
			if (slow == fast)break;
		}
		return slow;
	}
};