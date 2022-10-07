class Solution(object):
    def reverseList(self, head):
        if head is None:
            return
        prev = None
        curr = head
        
        while curr != None:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        return prev
   