class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

def add_lists(l1,l2):
    dummy=Node(0)
    tail=dummy
    carry=0
    while l1 or l2 or carry:
        s=(l1.data if l1 else 0)+(l2.data if l2 else 0)+carry
        carry=s//10
        tail.next=Node(s%10)
        tail=tail.next
        l1=l1.next if l1 else None
        l2=l2.next if l2 else None
    return dummy.next

def print_list(head):
    while head:
        print(head.data,end=" ")
        head=head.next
    print()

l1=Node(2); l1.next=Node(4); l1.next.next=Node(3)
l2=Node(5); l2.next=Node(6); l2.next.next=Node(4)
res=add_lists(l1,l2)
print_list(res)
