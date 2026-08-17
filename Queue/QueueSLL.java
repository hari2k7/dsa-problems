import java.util.Scanner;

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
    }

    void delete_beg() {
        if (head == null) {
            throw new Error("Queue Underflow");
        }

        head = head.next;
    }

    void display() {
        Node temp = head;

        while (temp != null) {
            System.out.print(temp.data + "->");
            temp = temp.next;
        }

        System.out.println("Null");
    }
}

class Queue {

    SinglyLinkedList sll = new SinglyLinkedList();

    int p = 0;

    void enqueue(int n) {
        sll.insert_end(n);
        p++;
    }

    void dequeue() {
        try {
            int deletednum = sll.head.data;

            sll.delete_beg();
            p--;

            System.out.println(deletednum);
        } catch (Exception e) {
            System.out.println("Queue Underflow");
        }
    }

    void front() {
        if (sll.head == null) {
            System.out.println("Queue Underflow");
            return;
        }

        System.out.println(sll.head.data);
    }

    void rear() {
        if (sll.head == null) {
            System.out.println("Queue Underflow");
            return;
        }

        Node temp = sll.head;

        while (temp.next != null) {
            temp = temp.next;
        }

        System.out.println(temp.data);
    }

    void display() {
        sll.display();
    }

    boolean isEmpty() {
        if (p == 0)
            return true;

        return false;
    }

    int size() {
        return p;
    }
}

public class QueueSLL {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Queue q = new Queue();

        while (true) {

            System.out.println("\n1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Front");
            System.out.println("4. Rear");
            System.out.println("5. isEmpty");
            System.out.println("6. Size");
            System.out.println("7. Display");
            System.out.println("8. Exit");

            System.out.print("Enter your choice: ");
            int ch = sc.nextInt();

            switch (ch) {

                case 1:
                    System.out.println("Enter a number to enqueue: ");
                    int n = sc.nextInt();

                    q.enqueue(n);
                    break;

                case 2:
                    q.dequeue();
                    break;

                case 3:
                    q.front();
                    break;

                case 4:
                    q.rear();
                    break;

                case 5:
                    System.out.println(q.isEmpty());
                    break;

                case 6:
                    System.out.println(q.size());
                    break;

                case 7:
                    q.display();
                    break;

                case 8:
                    System.out.println("Exiting...");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}