class Solution(object):
    def reverse(self, head, tail):
        prev = tail
        while head != tail:
            temp = head.next
            head.next = prev
            prev = head
            head = temp
        
        return prev
    
    def reverseKGroup(self, head, k):
        node = head
        
        for i in range(k):
            if node == None:
                return head
            node = node.next
        
        new_head = self.reverse(head, node)
        head.next = self.reverseKGroup(node, k)
        
        return new_head