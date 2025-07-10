/*
In a linked list of size n, where n is even, 
the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. 
These are the only nodes with twins for n = 4.The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

Constraints:

The number of nodes in the list is an even integer in the range [2, 105].
1 <= Node.val <= 105
*/


/*
Approach: 
1. Use the fast and slow pointer technique to find the midpoint of the linked list.
2. While finding the midpoint, simultaneously reverse the first half of the linked list.
3. After the loop, `temp` points to the second half and `prev` points to the reversed first half.
4. Traverse both halves simultaneously and compute the sum of corresponding nodes.
5. Track the maximum of these twin sums and return it as the result.
*/

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        
        // Reverse the first half while finding the middle of the list
        while (fast) {
            fast = fast->next->next;
            ListNode* address = temp->next;
            temp->next = prev;
            prev = temp;
            temp = address;
        }

        int ans = 0;
        // Calculate max twin sum
        while (temp) {
            ans = max(ans, temp->val + prev->val);
            temp = temp->next;
            prev = prev->next;
        }

        return ans;
    }
};

 