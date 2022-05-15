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
     *          Uses a hashmap to store old->new node address mapping, so to avoid duplicated
     *          references.
     * 
     *          Tradeoffs:
     *          - Easier to understand 👍
     *          - No mutation to input needed 👍
     *          - Additional space needed 👎
     * 
     *          Space complexity: O(N)
     *          Time complexity: O(N)
     * 
     * @param head the head of the list to clone
     * @return Node* the deep-copy list
     */
    Node* copyRandomList(Node* head) {
        Node* tail = head;
        Node* copyHead = new Node(0);
        Node* copyTail = copyHead;
        
        unordered_map<Node*,Node*> nodeCopyByNode;
        
        while(tail != NULL) {
            if (nodeCopyByNode.find(tail) == nodeCopyByNode.end()) {
                nodeCopyByNode[tail] = new Node(tail->val);
            }
            copyTail->next = nodeCopyByNode[tail];
            
            if (tail->random != NULL && nodeCopyByNode.find(tail->random) == nodeCopyByNode.end()) {
                nodeCopyByNode[tail->random] =  new Node(tail->random->val);
            }
            copyTail->next->random = nodeCopyByNode[tail->random];
            
            copyTail = copyTail->next;
            tail = tail->next;
        }
        
        return copyHead->next;
    }
};