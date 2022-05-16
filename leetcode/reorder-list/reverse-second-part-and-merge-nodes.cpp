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
    
    ListNode* findListMiddle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* getReverseList(ListNode *head) {
        ListNode *tail = head;
        ListNode *last = NULL;
        while(tail != NULL) {
            ListNode *next = tail->next;
            tail->next = last;
            last = tail;
            tail = next;
        }
        return last;
    }
    
    void mergeLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while(list1 != NULL || list2 != NULL) {
            if (list1 != NULL) {
                head->next = list1;
                list1 = list1->next;
                head = head->next;   
            }
            if (list2 != NULL) {
                head->next = list2;
                list2 = list2->next;
                head = head->next;    
            }
        }
    }
    
    /**
     * @details Creates and returns a reordered list in the form of  [i_0, i_n-1, i_1, i_n-2, ..., ceil(i_n/2)]
     *          This solution split the list two, merging first part and reversed second.
     *
     *          Tradeoffs:
     *          - No additional space needed 👍
     *          - Additional pointer/linked list mechanics needed, which turns solution more complex 👎
     * 
     *          Space complexity: O(1)
     *          Time complexity: O(N)
     * 
     * @param head the head of the list to be reordered as described
     */
    void reorderList(ListNode* head) {    
        ListNode* middle = this->findListMiddle(head);
        ListNode* reverseHead = this->getReverseList(middle->next);
        
        middle->next = NULL;
        
        this->mergeLists(head, reverseHead);
    }
};
