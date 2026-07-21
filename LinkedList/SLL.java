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

    // Insert at the beginning
    void insert_beginning(int data) {
        Node new_node = new Node(data);
        new_node.next = head;
        head = new_node;
    }

    // Insert at the end
    void insert_end(int data) {
        Node new_node = new Node(data);

        if (head == null) {
            insert_beginning(data);
            return;
        }

        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = new_node;
        new_node.next = null;
    }

    // Insert at the middle
    void insert_middle(int data) {
        Node new_node = new Node(data);

        if (head == null) {
            insert_beginning(data);
            return;
        }

        int length = 0;
        Node temp = head;
        while (temp != null) {
            length++;
            temp = temp.next;
        }

        Node middle = head;
        for (int i = 0; i < length / 2; i++) {
            middle = middle.next;
        }

        new_node.next = middle.next;
        middle.next = new_node;
    }

    // delete at the end
    void delete_end() {
        if (head == null) {
            System.out.println("list is empty");
            return;
        }
        if (head.next == null) {
            head = null;
            return;
        }

        Node temp = head;

        while (temp.next.next != null) {
            temp = temp.next;
        }

        temp.next = null;

    }

    // delete at the begining
    void delete_beg() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        head = head.next;
    }

    // delete at middle
    void delete_mid() {
        if (head == null) {
            System.out.println("List is empty");
        }
        if (head.next == null) {
            head = null;
        }

        int length = 0;
        Node middle = head;
        for (int i = 0; i < length / 2 - 1; i++) {
            middle = middle.next;
        }

        middle.next = middle.next.next.next;
        middle.next.next = null;
    }

    // search
    void search(int data) {
        Node temp = head;
        while (temp != null) {
            if (temp.data == data) {
                System.out.println("true");
                return;
            }
            temp = temp.next;
        }
        System.out.println("False");
    }

    // display
    void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
        System.out.println("Null");
    }
}

public class SLL {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        SinglyLinkedList sll = new SinglyLinkedList();

        while (true) {
            System.out.println("\n1. Insert at Beginning");
            System.out.println("2. Insert at End");
            System.out.println("3. Insert at Middle");
            System.out.println("4. Delete at Beginning");
            System.out.println("5. Delete at End");
            System.out.println("6. Delete at middle");
            System.out.println("7. Search");
            System.out.println("8. Display");
            System.out.println("9. Exit");

            System.out.print("Enter your choice: ");
            int ch = sc.nextInt();

            switch (ch) {
                case 1:
                    System.out.print("Enter a number: ");
                    sll.insert_beginning(sc.nextInt());
                    sll.display();
                    break;

                case 2:
                    System.out.print("Enter a number: ");
                    sll.insert_end(sc.nextInt());
                    sll.display();
                    break;

                case 3:
                    System.out.print("Enter a number: ");
                    sll.insert_middle(sc.nextInt());
                    sll.display();
                    break;

                case 4:
                    sll.delete_beg();
                    sll.display();
                    break;

                case 5:
                    sll.delete_end();
                    sll.display();
                    break;

                case 6:
                    sll.delete_mid();
                    sll.display();
                    break;

                case 7:
                    System.out.print("Enter element to search: ");
                    sll.search(sc.nextInt());
                    break;

                case 8:
                    sll.display();
                    break;

                case 9:
                    System.out.println("Exiting...");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}
