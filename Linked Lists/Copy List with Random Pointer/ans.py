class Solution(object):
    def copyRandomList(self, head):
        curr = head
        while curr:
            nextnode = curr.next
            newnode = Node(curr.val)
            curr.next = newnode
            newnode.next = nextnode
            curr = nextnode
        
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            else:
                curr.next.random = None
            curr = curr.next.next
        
        curr = head
        dummy = Node(-1)
        prev = dummy
        while curr:
            prev.next = curr.next
            curr.next = curr.next.next
            prev = prev.next
            curr = curr.next
        
        return dummy.next
        