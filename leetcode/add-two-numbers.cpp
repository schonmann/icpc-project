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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *resultListPointer = new ListNode();
        ListNode *lastResultListPointer = NULL;
        ListNode *startResultListPointer = resultListPointer;

        int sumToNextNode = 0;
        while(l1 != NULL || l2 != NULL || sumToNextNode > 0) {
            
            if (lastResultListPointer != NULL) {
                lastResultListPointer->next = new ListNode();
                lastResultListPointer->next->val = sumToNextNode;
                resultListPointer = lastResultListPointer->next;
            }        
            
            int sum = resultListPointer->val; // rest of last operation
            
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
        
            resultListPointer->val = sum % 10;
            sumToNextNode = sum / 10;
            lastResultListPointer = resultListPointer;
        }
        return startResultListPointer;
    }
};