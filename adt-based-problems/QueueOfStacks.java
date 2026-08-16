import java.util.Scanner;

class Node<T> {
    T data;
    Node<T> next;

    Node(T data){
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList<T>{
    Node<T> head;

    void insert_beginning(T data){
        Node<T> new_node = new Node<T>(data);
        new_node.next = head;
        head = new_node;     
    }

    void insert_end(T data){
        if(head==null){
            insert_beginning(data);
            return;
        }

        Node<T> new_Node = new Node<T>(data);

        Node<T> temp = head;
        while(temp.next != null){
            temp=temp.next;
        }

        temp.next = new_Node;
        new_Node.next = null;
    }

    void delete_beg(){
        if(head==null || head.next == null){
            head = null;
            return;
        }

        head = head.next;
    }

    void delete_end(){
        if(head==null || head.next == null){
            head = null;
            return;
        }

        Node<T> temp = head;
        while(temp.next.next != null){
            temp = temp.next;
        }

        temp.next = null;
    }

    void display(){
        if(head==null){
            return;
        }

        Node<T> temp = head;
        while(temp!=null){
            System.out.println(temp.data);
            temp=temp.next;
        }
    }
}

class Queue{
    SinglyLinkedList<Stack> sllq = new SinglyLinkedList<>();

    int p = 0;

    void enqueue(Stack data){
        sllq.insert_end(data);
        p++;
    }

    Stack dequeue(){
        if(sllq.head == null){
            System.out.println("Queue underflow");
            return null;
        }
        Stack de = sllq.head.data;
        sllq.delete_beg();
        p--;
        return de;
    }

    Stack front() {
        if (sllq.head == null) {
            System.out.println("Queue Underflow");
            return null;
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

class Stack{
    SinglyLinkedList<Character> slls = new SinglyLinkedList<>();

    int p = 0;

    void push(char data){
        slls.insert_beginning(data);
        p++;
    }

    char pop(){
        if(slls.head == null){
            System.out.println("Stack Underflow");
            return '\0';
        }
        char de = slls.head.data;
        slls.delete_beg();
        p--;
        return de;
    }

    char top(){
        if(slls.head == null){
            System.out.println("Stack Underflow");
            return '\0';
        }
        return slls.head.data;
    }

    boolean isEmpty(){
        if(p == 0) return true;
        return false;
    }

    int size(){
        return p;
    }

    void display(){
        if(slls.head == null){
            System.out.println("Stack Empty");
        }
        slls.display();
    }
}

public class QueueOfStacks {
    Scanner sc = new Scanner(System.in);

    Queue q = new Queue();
    Stack currentBatch = null;

    void addBatch(){
            Stack s = new Stack();
            System.out.println("how many elements do you want to add?: ");
            int n = sc.nextInt();
            sc.nextLine();

            for(int i=0; i<n; i++){
                System.out.println("Enter element "+(i+1)+" :");
                char c = sc.next().charAt(0);
                s.push(c);
            }

            q.enqueue(s);
    }

    void processBatch(){
        if(q.isEmpty()){
            System.out.println("Queue Underflow");
            return;
        }
        currentBatch = q.dequeue();

    }

    void processTask(){
        if(currentBatch == null){
            System.out.println("No batch is currently being processed");
            return;
        }
        char task = currentBatch.pop();
        
        if(task != '\0') System.out.println(task);
    }
    
    public static void main(String[] args) {

        QueueOfStacks obj = new QueueOfStacks();
        
        int choice;
        
        do {
            System.out.println("\n===== Queue of Stacks =====");
            System.out.println("1. Add Batch");
            System.out.println("2. Process Batch");
            System.out.println("3. Process Task");
            System.out.println("4. Display");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
        
            choice = obj.sc.nextInt();
        
            switch (choice) {
            
                case 1:
                    obj.addBatch();
                    break;
            
                case 2:
                    obj.processBatch();
                    break;
            
                case 3:
                    obj.processTask();
                    break;
            
                case 4:
                    obj.q.display();
                    break;
            
                case 5:
                    System.out.println("Exiting...");
                    break;
            
                default:
                    System.out.println("Invalid choice");
            }
        
        } while (choice != 5);
    }
}
