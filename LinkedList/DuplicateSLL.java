class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList {
    Node head;

    void insertEnd(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        Node temp = head;

        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = newNode;
    }

    void removeDuplicates() {
        Node temp = head;

        while (temp != null) {
            Node current = temp;

            while (current.next != null) {
                if (temp.data == current.next.data) {
                    current.next = current.next.next;
                } else {
                    current = current.next;
                }
            }

            temp = temp.next;
        }
    }

    void display() {
        Node temp = head;

        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }

        System.out.println("NULL");
    }
}

public class DuplicateSLL {
    public static void main(String[] args) {
        SinglyLinkedList sll = new SinglyLinkedList();

        sll.insertEnd(10);
        sll.insertEnd(10);
        sll.insertEnd(20);
        sll.insertEnd(20);
        sll.insertEnd(30);
        sll.insertEnd(10);

        System.out.println("Before Removing Duplicates:");
        sll.display();

        sll.removeDuplicates();

        System.out.println("After Removing Duplicates:");
        sll.display();
    }
}