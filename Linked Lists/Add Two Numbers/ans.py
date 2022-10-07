class Solution(object):
    def addTwoNumbers(self, l1, l2):
        carry = 0
        dummy = curr = ListNode(-1)
        
        while l1 or l2 or carry:
            sum = 0
            if l1 :
                sum += l1.val
                l1 = l1.next
                
            if l2 :
                sum += l2.val
                l2 = l2.next
            
            if carry == 1:
                sum += carry
                carry = 0
            
            curr.next = ListNode(sum%10)
            curr = curr.next
            carry = sum//10
        
        return dummy.next
 