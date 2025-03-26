# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        newh, tail = head, head
        l = 1
        while tail.next:
            tail = tail.next
            l+=1
        tail.next = head
        k = k % l
        if k:
            for i in range(l-k):
                tail = tail.next
        newh = tail.next
        tail.next = None
        return newh

