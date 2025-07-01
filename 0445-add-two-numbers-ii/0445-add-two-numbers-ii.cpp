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
ListNode* reverse(ListNode* head){
    ListNode* temp = head;
    ListNode* prev = nullptr;

    while(temp){
        ListNode* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp =  next;

    }
    return prev;
}


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum = 0;
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            sum = sum + carry;
            curr->next = new ListNode(sum % 10);
            carry = sum/10;
            curr = curr->next;  

        }
        return reverse(dummy->next);
    }
};