# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Singly Linked List class
class SinglyLinkedList:
    def __init__(self):
        self.head = None

    # Insert at the beginning
    def insert_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # Insert at the end
    def insert_end(self, data):
        new_node = Node(data)

        if(self.head==None):
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node
            return

        tail = self.head
        while(tail.next != None):
            tail=tail.next
            #print(tail.data)

        tail.next = new_node
        new_node.next = None

    # Insert at the middle
    def insert_middle(self, data):
        new_node = Node(data)

        if(self.head==None):
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node
            return

        middle = self.head
        temp = self.head

        length = 0
        while(temp.next != None):
            length+=1
            temp = temp.next
            #print(length)

        for i in range(length//2):
            middle = middle.next

        new_node.next = middle.next
        middle.next = new_node

    # Search
    def search(self):
        n=int(input("Enter element to search: "))
        temp = self.head

        length = 0
        while(temp):
            if(n==temp.data):
                print(length)
                return
            length+=1
            temp = temp.next
        print("Not found")

    # delete at the end
    def delete_end(self):

        if(self.head==None):
            print("list is empty")
            return

        tail = self.head
        while(tail.next.next != None):
            tail=tail.next
        
        if tail.next==None:
            print("Nothing to delete")
            return 
        
        tail.next = None


    # delete at the begining
    def delete_beg(self):
        if(self.head==None):
            print("list is empty")
            return
        self.head = self.head.next



    # Display the list
    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("None")

    


# Driver code
sll = SinglyLinkedList()

'''
sll.insert_end(40)
sll.insert_middle(55)

sll.delete_end()
sll.delete_beg()

sll.display()

sll.search()
'''



while(True):
    print("1.insert at begining")
    print("2.insert_end")
    print("3.insert_middle")
    print("4.insert at begining")
    print("5.delete_end")
    print("6.delete_beg")
    print("7.search")
    print("8.display")
    print("9.Exit")

    ch = int(input("Enter your choice: "))

    if ch == 1:
        num = int(input("Enter a number: "))
        sll.insert_beginning(num)
        sll.display()
        
    elif ch == 2:
        num = int(input("Enter a number: "))
        sll.insert_end(num)
        sll.display()
        
    elif ch == 3:
        num = int(input("Enter a number: "))
        sll.insert_middle(num)
        sll.display()
        
    elif ch == 4:
        num = int(input("Enter a number: "))
        sll.insert_beginning(num)
        sll.display()
        
    elif ch == 5:
        sll.delete_end()
        sll.display()
        
    elif ch == 6:
        sll.delete_beg()
        sll.display()
        
    elif ch == 7:
        sll.search()
        
    elif ch == 8:
        sll.display()
        
    elif ch == 9:
        break
    else:
        print("Try again")



