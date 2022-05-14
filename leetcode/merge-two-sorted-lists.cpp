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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedListHead = new ListNode(-101);
        ListNode* mergePointer = mergedListHead;
        
        while(list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                mergePointer->next = list1;
                list1 = list1->next;
            } else {
                mergePointer->next = list2;
                list2 = list2->next;
            }
            mergePointer = mergePointer->next;
        }
        
        mergePointer->next = list1 != NULL ? list1 : list2;
        return mergedListHead->next;
    }
};