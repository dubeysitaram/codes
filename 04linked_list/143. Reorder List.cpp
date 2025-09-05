/*143. Reorder List.cpp
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.



*/


class Solution {
public:
	ListNode* reverse(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* temp = head;
		while (temp) {
			ListNode* address = temp->next;
			temp->next = prev;
			prev = temp;
			temp = address;
		}
		return prev;
	}

	void reorderList(ListNode* head) {
		if (!head || !head->next)
			return; // handle short lists

		// find midpoint
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		// reverse the second half
		ListNode* second = reverse(slow->next);
		slow->next = nullptr; // split the list

		// merging halves
		ListNode* first = head;
		while (first && second) {
			ListNode* t1 = first->next;
			ListNode* t2 = second->next;
			first->next = second;
			second->next = t1;
			first = t1;
			second = t2;
		}
	}
};
