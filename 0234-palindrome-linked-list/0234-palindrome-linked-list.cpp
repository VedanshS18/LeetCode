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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr != NULL){
            ListNode* Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        ListNode* left = head;
        ListNode* right = prev;

        while(right != NULL){
            if(right->val != left->val){
                return false;
            }
            right = right->next;
            left = left->next;
        }
        return true;
    }
};