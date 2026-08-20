import java.util.Scanner;

class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {

    Node head;

    void insert_beginning(int data) {

        Node new_node = new Node(data);

        if (head == null) {
            head = new_node;
            return;
        }

        new_node.next = head;
        head.prev = new_node;
        head = new_node;
    }

    void insert_end(int data) {

        Node new_node = new Node(data);

        if (head == null) {
            head = new_node;
            return;
        }

        Node temp = head;

        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = new_node;
        new_node.prev = temp;
    }

    int delete_beginning() {

        if (head == null) {
            throw new Error("Deque Underflow");
        }

        int data = head.data;

        if (head.next == null) {
            head = null;
        } else {
            head = head.next;
            head.prev = null;
        }

        return data;
    }

    int delete_end() {

        if (head == null) {
            throw new Error("Deque Underflow");
        }

        Node temp = head;

        while (temp.next != null) {
            temp = temp.next;
        }

        int data = temp.data;

        if (temp.prev == null) {
            head = null;
        } else {
            temp.prev.next = null;
        }

        return data;
    }

    void display() {

        Node temp = head;

        while (temp != null) {
            System.out.print(temp.data + "<->");
            temp = temp.next;
        }

        System.out.println("Null");
    }
}

class Deque {

    DoublyLinkedList dll = new DoublyLinkedList();

    int p = 0;

    void insert_front(int n) {

        dll.insert_beginning(n);
        p++;
    }

    void insert_rear(int n) {

        dll.insert_end(n);
        p++;
    }

    void delete_front() {

        try {

            int deletednum = dll.delete_beginning();

            p--;

            System.out.println(deletednum);

        } catch (Exception e) {

            System.out.println("Deque Underflow");
        }
    }

    void delete_rear() {

        try {

            int deletednum = dll.delete_end();

            p--;

            System.out.println(deletednum);

        } catch (Exception e) {

            System.out.println("Deque Underflow");
        }
    }

    void front() {

        if (dll.head == null) {

            System.out.println("Deque Underflow");
            return;
        }

        System.out.println(dll.head.data);
    }

    void rear() {

        if (dll.head == null) {

            System.out.println("Deque Underflow");
            return;
        }

        Node temp = dll.head;

        while (temp.next != null) {
            temp = temp.next;
        }

        System.out.println(temp.data);
    }

    boolean isEmpty() {

        if (p == 0)
            return true;

        return false;
    }

    int size() {

        return p;
    }

    void display() {

        dll.display();
    }
}

public class DequeDLL {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Deque d = new Deque();

        while (true) {

            System.out.println("\n1. Insert Front");
            System.out.println("2. Insert Rear");
            System.out.println("3. Delete Front");
            System.out.println("4. Delete Rear");
            System.out.println("5. Front");
            System.out.println("6. Rear");
            System.out.println("7. isEmpty");
            System.out.println("8. Size");
            System.out.println("9. Display");
            System.out.println("10. Exit");

            System.out.print("Enter your choice: ");

            int ch = sc.nextInt();

            switch (ch) {

                case 1:

                    System.out.print("Enter a number to insert at front: ");

                    int n = sc.nextInt();

                    d.insert_front(n);

                    break;

                case 2:

                    System.out.print("Enter a number to insert at rear: ");

                    int n1 = sc.nextInt();

                    d.insert_rear(n1);

                    break;

                case 3:

                    d.delete_front();

                    break;

                case 4:

                    d.delete_rear();

                    break;

                case 5:

                    d.front();

                    break;

                case 6:

                    d.rear();

                    break;

                case 7:

                    System.out.println(d.isEmpty());

                    break;

                case 8:

                    System.out.println(d.size());

                    break;

                case 9:

                    d.display();

                    break;

                case 10:

                    System.out.println("Exiting...");

                    sc.close();

                    return;

                default:

                    System.out.println("Invalid choice");
            }
        }
    }
}