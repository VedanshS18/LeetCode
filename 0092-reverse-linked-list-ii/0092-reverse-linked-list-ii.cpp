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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* beforeleft = NULL;
        ListNode* Left = head;
        ListNode* Right = head;
        int count = 1;

        while(count < left){
            beforeleft = Left;
            Left = Left->next;
            count++;
        }
        count = 1;
        while(count < right){
            Right = Right->next;
            count++;
        }

        ListNode* afterRight = Right->next;

        ListNode* prev = NULL;
        ListNode* curr = Left;

        while(curr != afterRight){
            ListNode* Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        
        if(beforeleft != NULL){
            beforeleft->next = Right;
        }else{
            head = Right;
        }

        Left->next = curr;

        return head;
    }
};