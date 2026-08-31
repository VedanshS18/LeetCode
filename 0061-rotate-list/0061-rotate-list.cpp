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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* tail = head;
        ListNode* shift = head;

        int count = 1;
        while(shift->next != NULL){
            shift = shift->next;
            count++;
        }

        k = k % count;

        if(k == 0){
            return head;
        }

        int shifting = count - k;
        count = 1;

        while(count < shifting){
            tail = tail->next;
            count++;
        }

        shift->next = head;
        head = tail->next;
        tail->next = NULL;

        return head;
        
    }
};