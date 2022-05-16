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
    /**
     * @details Creates and returns a reordered list in the form of  [i_0, i_n-1, i_1, i_n-2, ..., ceil(i_n/2)]
     *          This solution split the list two, merging first part and reversed second.
     *
     *          Tradeoffs:
     *          - Simple, straight solution 👍 
     *          - Additional space needed to store previous node references 👎
     *          - A more standard way of doing that would be adding previous pointers 👎
     * 
     *          Space complexity: O(N)
     *          Time complexity: O(N)
     * 
     * @param head the head of the list to be reordered as described
     */
    void reorderList(ListNode* head) {        
        ListNode* tail = head;
        map<ListNode*,ListNode*> previousNode; 
        
        while(tail->next != NULL) {
            previousNode[tail->next] = tail;
            tail = tail->next;
        }
        
        ListNode* last = tail;
        tail = head;

        while(tail->next != NULL && tail->next != last) {
            last->next = tail->next;
            tail->next = last;
            tail = last->next;
            
            last = previousNode[last];
            last->next = NULL;
        }
    }
};
