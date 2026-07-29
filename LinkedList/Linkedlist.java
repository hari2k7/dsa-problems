class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
    }
}

public class Linkedlist {

    static Node head;

    void insertAtLast(int data){
        Node newNode = new Node(data);

        if(head==null){
            head = newNode;
            return;
        }

        Node temp = head;

        while(temp.next != null){
            temp=temp.next;
        }

        temp.next = newNode;

    }

    static void disp(Linkedlist list){
        Node temp = head;
        while(temp!=null){
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public static void main(String[] args){
        Linkedlist list = new Linkedlist();

        list.insertAtLast(10);
        list.insertAtLast(20);
        list.insertAtLast(30);

        disp(list);
    }
}
