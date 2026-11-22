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
        int l = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            l++;
            curr = curr->next;
        }
        if (n == l) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
      
        int t = l - n + 1;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        int count = 1; 
        
        while (count < t) {
            count++;
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;
        
        return head;
    }
};
