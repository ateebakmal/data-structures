/*Problem difficulty :  Easy problem
Given the head of a linked list and the number k, Your task is to find the kth node from the end. If k is more than the number of nodes, then the output should be -1.

Examples

Input: LinkedList: 1->2->3->4->5->6->7->8->9, k = 2
Output: 8
Explanation: The given linked list is 1->2->3->4->5->6->7->8->9. The 2nd node from end is 8.
*/

#include <unordered_map>

class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        
        Node* current = head;
        int length = 0;
        
        unordered_map<int , int> dict;
        
        while(current != nullptr){
            dict[length] = current->data;
            length++;
            current = current->next;
        }
        
        int index = length - k;
        
        if(index >= length || index < 0){
            return -1;
        }
        
        return dict[index];
        
        
    }
};