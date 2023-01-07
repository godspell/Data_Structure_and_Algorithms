def solve(root1, root2):
    if root1 is None:
        return root2
    if root2 is None:
        return root1
    
    if root1.data <= root2.data:
        root1.bottom = solve(root1.bottom, root2)
        return root1
    else:
        root2.bottom = solve(root1, root2.bottom)
        return root2
        
def flatten(root):
    #Your code here
    if root == None or root.next == None:
        return root
    
    head, nexthead = root, root.next
    while nexthead != None:
        temp = nexthead.next
        head.next = None
        nexthead.next = None
        head = solve(head, nexthead)
        nexthead = temp
    
    return head