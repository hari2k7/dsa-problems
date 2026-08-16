import java.util.Scanner;

class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
}

class CircularLinkedList{
    Node head;

    void insertAtEnd(int data){
        Node new_node = new Node(data);

        if(head==null){
            head = new_node;
            new_node.next = head;
            return;
        }

        Node temp = head;
        while(temp.next != head){
            temp=temp.next;
        }

        new_node.next = head;
        temp.next = new_node;
    }

    void deleteBeg(){

        if(head==null || head.next==head){
            head = null;
            return;
        }
        
        Node temp = head;
        while(temp.next != head){
            temp = temp.next;
        }

        temp.next = head.next;
        head = head.next;
    }

    void display(){
        if(head==null){
            return;
        }
        Node temp = head;
        do {
            System.out.print(temp.data + "->");
            temp = temp.next;
        } while (temp != head);

        System.out.println("(head)");
    }
}

class CircularQueue{
    CircularLinkedList cll = new CircularLinkedList();
    int p = 0;

    void enqueue(int data){
        if(p>=5){
            System.out.println("Queue Overflow");
            return;
        }
        cll.insertAtEnd(data);
        p++;
    }

    void dequeue(){
        if(p<=0){
            System.out.println("Queue Underflow");
            return;
        }
        System.out.println(cll.head.data);
        cll.deleteBeg();
        p--;
    }

    void display(){
        cll.display();
    }
}

public class CircularQueueUsingCLL {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        CircularQueue queue = new CircularQueue();

        int choice;

        do {
            System.out.println("\n--- Circular Queue ---");
            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Display");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter data: ");
                    int data = sc.nextInt();
                    queue.enqueue(data);
                    break;

                case 2:
                    queue.dequeue();
                    break;

                case 3:
                    queue.display();
                    break;

                case 4:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice");
            }

        } while (choice != 4);

        sc.close();
    }
}
