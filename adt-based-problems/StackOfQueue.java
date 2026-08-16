import java.util.Scanner;

class Node<T> {
    T data;
    Node<T> next;

    Node(T data) {
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList<T> {
    Node<T> head;

    void insert_beginning(T data) {
        Node<T> new_node = new Node<T>(data);
        new_node.next = head;
        head = new_node;
    }

    void insert_end(T data) {
        if (head == null) {
            insert_beginning(data);
            return;
        }

        Node<T> new_Node = new Node<T>(data);

        Node<T> temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = new_Node;
        new_Node.next = null;
    }

    void delete_beg() {
        if (head == null || head.next == null) {
            head = null;
            return;
        }

        head = head.next;
    }

    void delete_end() {
        if (head == null || head.next == null) {
            head = null;
            return;
        }

        Node<T> temp = head;
        while (temp.next.next != null) {
            temp = temp.next;
        }

        temp.next = null;
    }

    void display() {
        if (head == null) {
            return;
        }

        Node<T> temp = head;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }
}

class Queue {
    SinglyLinkedList<Character> sllq = new SinglyLinkedList<>();

    int p = 0;

    void enqueue(char data) {
        sllq.insert_end(data);
        p++;
    }

    char dequeue() {
        if (sllq.head == null) {
            System.out.println("Queue underflow");
            return '\0';
        }
        char de = sllq.head.data;
        sllq.delete_beg();
        p--;
        return de;
    }

    char front() {
        if (sllq.head == null) {
            System.out.println("Queue Underflow");
            return '\0';
        }

        return sllq.head.data;
    }

    void display() {
        sllq.display();
    }

    boolean isEmpty() {
        if (sllq.head == null)
            return true;

        return false;
    }

    int size() {
        return p;
    }
}

class Stack {
    SinglyLinkedList<Queue> slls = new SinglyLinkedList<>();

    int p = 0;

    void push(Queue data) {
        slls.insert_beginning(data);
        p++;
    }

    Queue pop() {
        if (slls.head == null) {
            System.out.println("Stack Underflow");
            return null;
        }
        Queue de = slls.head.data;
        slls.delete_beg();
        p--;
        return de;
    }

    Queue top() {
        if (slls.head == null) {
            System.out.println("Stack Underflow");
            return null;
        }
        return slls.head.data;
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
        if (slls.head == null) {
            System.out.println("Stack Empty");
        }

        Node<Queue> temp = slls.head;

        while (temp != null) {
            temp.data.display();
            temp = temp.next;
        }
    }
}

public class StackOfQueue {
    Scanner sc = new Scanner(System.in);

    Stack s = new Stack();

    Queue currentGroup = null;

    void AddGroup() {
        Queue q = new Queue();

        System.out.print("How many requests do you want to add?: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.print("Enter request " + (i + 1) + ": ");
            char c = sc.next().charAt(0);
            q.enqueue(c);
        }

        s.push(q);
    }

    void RemoveGroup() {
        if (s.isEmpty()) {
            System.out.println("Stack Underflow");
            return;
        }
        currentGroup = s.pop();
    }

    void AddRequest(char c) {
        if (currentGroup == null) {
            System.out.println("No group to add");
            return;
        }

        currentGroup.enqueue(c);
        System.out.println("Group removed and selected for processing.");
    }

    void ProcessRequest() {
        if (currentGroup == null) {
            System.out.println("No group to process");
            return;
        }
        char request = currentGroup.dequeue();

        if (request != '\0') {
            System.out.println(request);
        }
    }

    void display() {
        s.display();
    }

    public static void main(String[] args) {

        StackOfQueue obj = new StackOfQueue();

        int choice;

        do {
            System.out.println("\n===== Stack of Queues =====");
            System.out.println("1. Add Group");
            System.out.println("2. Remove Group");
            System.out.println("3. Add Request");
            System.out.println("4. Process Request");
            System.out.println("5. Display");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");

            choice = obj.sc.nextInt();

            switch (choice) {

                case 1:
                    obj.AddGroup();
                    break;

                case 2:
                    obj.RemoveGroup();
                    break;

                case 3:
                    System.out.print("Enter request: ");
                    char c = obj.sc.next().charAt(0);
                    obj.AddRequest(c);
                    break;

                case 4:
                    obj.ProcessRequest();
                    break;

                case 5:
                    obj.display();
                    break;

                case 6:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice");
            }

        } while (choice != 6);
    }
}
