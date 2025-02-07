// https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list

/*
Given a Circular Linked List node, which is sorted in non-descending order, write a function to insert a value 
insertVal into the list such that it remains a sorted circular list. The given node can be a reference to any single 
node in the list and may not necessarily be the smallest value in the circular list.
If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, 
the circular list should remain sorted.
If the list is empty (i.e., the given node is null), you should create a new single circular list and return the reference 
to that single node. Otherwise, you should return the originally given node.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        /*  The number of nodes in the list is in the range [0, 5 * 104].
            -106 <= Node.val, insertVal <= 106
        */
        if(head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        };

        Node* cur = head;
        Node* next = head->next;
        while(insertVal <= cur->val) {
            if (cur->next != cur && cur->next != head) {
                cur = cur->next;
                next = cur->next;
            } else 
                break;
        }
        //insert;
        cur->next = new Node(insertVal, next);

        return head;

        
    }
};