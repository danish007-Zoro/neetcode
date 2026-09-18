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
    int getlen(ListNode* head){
        int length = 0;
        ListNode* temp = head;

        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next == NULL) return head;

        int length = getlen(head);
        if(length<k) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        int position = 0;

        while(position<k){
            position++;
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        if(curr!=NULL){
            ListNode* recursionhead = reverseKGroup(curr, k);
            head->next = recursionhead;
        }
        return prev;
    }
};
