class ListNode:
     def __init__(self,val=0,next=None):
        self.val = val
        self.next = next
     def detectCycle(head):
        slow=fast=head
        while fast and fast.next:
             slow=slow.next
             fast=fast.next.next
             if slow==fast:
                 slow=head
                 while head!=fast:
                     slow=slow.next
                     fast=fast.next
                 return slow
        return None
