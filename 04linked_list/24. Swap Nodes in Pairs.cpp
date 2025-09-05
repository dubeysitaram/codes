// 24. Swap Nodes in Pairs.cpp
/*
Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
*/


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
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr)return head;
		ListNode* temp = head;
		while (temp && temp->next) {
			int x = temp->next->val;
			int y = temp->val;
			temp->next->val = y;
			temp->val = x;
			temp = temp->next->next;
		}
		return head;
	}
};