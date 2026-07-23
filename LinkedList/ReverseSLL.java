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

    void reverse() {
        Node prev = null;
        Node current = head;

        while (current != null) {
            Node next = current.next;

            current.next = prev;
            prev = current;
            current = next;
        }

        head = prev;
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

public class ReverseSLL {
    public static void main(String[] args) {
        SinglyLinkedList sll = new SinglyLinkedList();

        sll.insertEnd(10);
        sll.insertEnd(20);
        sll.insertEnd(30);
        sll.insertEnd(40);

        System.out.println("Before Reverse:");
        sll.display();

        sll.reverse();

        System.out.println("After Reverse:");
        sll.display();
    }
}