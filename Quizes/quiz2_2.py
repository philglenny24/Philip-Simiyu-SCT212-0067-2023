class ListNode:
     def __init__(self,val=0,next=None):
        self.val = val
        self.next = next
     def detectCycle(head):
        slow=fast=head
         #Detecting the cycle
        while fast and fast.next:
             slow=slow.next
             fast=fast.next.next
             if slow==fast:
                 #find origin/start of the cycle
                 slow=head
                 while head!=fast:
                     slow=slow.next
                     fast=fast.next
                 return slow
        return None
