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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Step 2: Move fast n+1 steps
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Step 3: Move both pointers
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Step 4: Delete node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        delete nodeToDelete;
        
        return dummy->next;   
    }
};