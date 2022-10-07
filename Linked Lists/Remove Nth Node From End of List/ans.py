class Solution(object):
    def removeNthFromEnd(self, head, n):
        fast = head
        slow = head
        for i in range(0, n):
            fast = fast.next
        
        if fast is None:
            return head.next
        
        while fast.next != None:
            fast = fast.next
            slow = slow.next
            
        todelete = slow.next
        slow.next = slow.next.next
        
        return head