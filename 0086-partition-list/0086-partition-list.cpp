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
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforehead = new ListNode(0);
        ListNode* afterhead = new ListNode(0);

        ListNode* before = beforehead;
        ListNode* after = afterhead;

        while(head != NULL){
            if(head->val < x){
                before->next = head;
                before = before->next;
            }
            else{
                after->next = head;
                after = after->next;
            }

            head = head->next;
        }

        after->next = NULL;
        before->next = afterhead->next;


        

        return beforehead->next;

        
    }
};