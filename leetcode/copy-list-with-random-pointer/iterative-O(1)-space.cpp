/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    /**
     * @details Creates and returns a deep copy of a linked list with additional random pointers.
     *          This solution interweaves original and copy list in order to solve without additional
     *          space, while keeping O(N) time complexity.
     *
     *          Tradeoffs:
     *          - No additional space needed 👍
     *          - Mechanics are more difficult to understand 👎
     *          - Mutates input list while executing, which can be a problem for concurrent runs 👎
     * 
     *          Space complexity: O(1)
     *          Time complexity: O(N)
     * 
     * @param head the head of the list to clone
     * @return Node* the deep-copy list
     */
    Node* copyRandomList(Node* head) {
        Node* tail = head;
        // interweaves newly copied nodes with original list
        while(tail != NULL) {
            Node *copy = new Node(tail->val);
            copy->next = tail->next;
            tail->next = copy;
            tail = tail->next->next;
        }
        
        // fill random pointers  
        tail = head;
        while(tail != NULL) {
            tail->next->random = tail->random != NULL ? tail->random->next : NULL;
            tail = tail->next->next;
        }
        
        Node* copyHead = new Node(0);
        Node* copyTail = copyHead;
        
        // build copied list and restore the original list pointers
        tail = head;
        while(tail != NULL) {
            copyTail->next = tail->next;
            tail->next = tail->next->next;
            copyTail = copyTail->next;
            tail = tail->next;
        }
        
        return copyHead->next;
    }
};