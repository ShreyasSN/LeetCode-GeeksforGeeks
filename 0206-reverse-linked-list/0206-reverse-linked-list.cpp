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
    ListNode* reverseList(ListNode* head, ListNode* nextnode = NULL ,ListNode* prevnode = NULL) {
        return head ? reverseList(head -> next, 
                                 (head -> next =  prevnode, nextnode),
                                 head) :  prevnode;
    }
};