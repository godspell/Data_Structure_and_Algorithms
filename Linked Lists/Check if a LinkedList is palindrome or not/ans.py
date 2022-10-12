class Solution(object):
    def isPalindrome(self, head):
        fast, slow = head, head
        prev = None
        while fast and fast.next:
            temp = slow
            fast = fast.next.next
            slow = slow.next
            temp.next = prev
            prev = temp
        
        if fast: fast = slow.next
        else: fast = slow
        
        slow = prev
        
        while fast and slow:
            if fast.val != slow.val: return False
            fast = fast.next
            slow = slow.next
        
        return True