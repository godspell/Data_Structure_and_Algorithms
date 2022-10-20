class Solution(object):
    def rotateRight(self, head, k):
        if not head: return 
        curr, l = head, 1
        while curr.next:
            l += 1
            curr = curr.next
        
        curr.next = head
        k = k % l;
        
        curr = head
        for _ in range(l - k - 1):
            curr = curr.next
            
        front = curr.next
        curr.next = None
        return front
        
        