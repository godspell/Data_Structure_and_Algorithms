class Solution(object):
    def detectCycle(self, head):
        fast = slow = head
        flag = False
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                flag = True
                break
        
        fast = head
        if flag:
            while fast != slow:
                fast = fast.next
                slow = slow.next
            
            return slow
            
        return None