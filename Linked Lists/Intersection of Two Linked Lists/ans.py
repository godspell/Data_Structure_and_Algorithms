class Solution(object):
    def find_intersection(self, head):
        fast, slow = head, head
        flag = False
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                flag = True
                break
                
        fast = head
        if flag:
            while fast != slow:
                fast = fast.next
                slow = slow.next
            return slow
        return None
    
    def getIntersectionNode(self, headA, headB):
        tail = headA
        while tail.next:
            tail = tail.next
        tail.next = headB
        ans = self.find_intersection(headA)
        tail.next = None
        return ans