import java.util.Scanner;

class Node<T> {
    T data;
    Node<T> next;

    Node(T data) {
        this.data = data;
        this.next = null;
    }
}

class dNode<T> {
    T data;
    dNode<T> prev;
    dNode<T> next;

    dNode(T data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

class SinglyLinkedList<T> {
    Node<T> head;

    void insert_beginning(T data) {
        Node<T> new_node = new Node<>(data);
        new_node.next = head;
        head = new_node;
    }

    void insert_end(T data) {

        Node<T> new_node = new Node<>(data);

        if (head == null) {
            head = new_node;
            return;
        }

        Node<T> temp = head;

        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = new_node;
    }

    T delete_beg() {

        if (head == null) {
            return null;
        }

        T data = head.data;
        head = head.next;

        return data;
    }

    T delete_end() {
        if (head == null) {
            return null;
        }

        if (head.next == null) {
            T data = head.data;
            head = null;
            return data;
        }

        Node<T> temp = head;

        while (temp.next.next != null) {
            temp = temp.next;
        }

        T data = temp.next.data;
        temp.next = null;

        return data;
    }

    boolean isEmpty() {

        return head == null;
    }

    int size() {
        int count = 0;
        Node<T> temp = head;

        while (temp != null) {
            count++;
            temp = temp.next;
        }

        return count;
    }

    void display() {
        Node<T> temp = head;

        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }

        System.out.println();
    }
}

class DoublyLinkedList<T> {
    dNode<T> head;

    void insert_beginning(T data) {
        dNode<T> new_node = new dNode<>(data);
        new_node.next = head;
        new_node.prev = null;
        if (head != null) {
            head.prev = new_node;
        }
        head = new_node;
    }

    void insert_end(T data) {
        if (head == null) {
            insert_beginning(data);
            return;
        }

        dNode<T> new_node = new dNode<>(data);

        dNode<T> temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = new_node;
        new_node.prev = temp;
    }

    T delete_beginning() {
        if (head == null) {
            return null;
        }

        T data = head.data;

        if (head.next == null) {
            head = null;
            return data;
        }

        head = head.next;
        head.prev = null;

        return data;

    }

    T delete_end() {

        if (head == null) {
            return null;
        }

        if (head.next == null) {
            T data = head.data;
            head = null;
            return data;
        }

        dNode<T> temp = head;

        while (temp.next.next != null) {
            temp = temp.next;
        }

        T data = temp.next.data;

        temp.next = null;

        return data;
    }

    boolean isEmpty() {

        return head == null;
    }

    int size() {
        int count = 0;
        dNode<T> temp = head;

        while (temp != null) {
            count++;
            temp = temp.next;
        }

        return count;
    }

    void display() {
        dNode<T> temp = head;

        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }

        System.out.println();
    }

    T peek_front() {

        if (head == null) {
            return null;
        }

        return head.data;
    }

}

class Passenger {
    String passengerID;
    String name;
    int boardingGroup;

    Passenger(String passengerID, String name, int boardingGroup) {
        this.passengerID = passengerID;
        this.name = name;
        this.boardingGroup = boardingGroup;
    }

    void display() {
        System.out.println(passengerID + " " + name + " " + boardingGroup);
    }
}

class Queue {
    SinglyLinkedList<Passenger> sll = new SinglyLinkedList<>();

    void enqueue(Passenger passenger) {
        sll.insert_end(passenger);
    }

    Passenger dequeue() {
        Passenger delPassenger = sll.delete_beg();
        if (delPassenger == null) {
            System.out.println("Queue underflow");
            return null;
        }

        return delPassenger;
    }

    Passenger front() {
        if (sll.head == null) {
            System.out.println("Queue Underflow");
            return null;
        }

        return sll.head.data;
    }

    boolean isEmpty() {
        return sll.head == null;
    }

    int size() {
        return sll.size();
    }

}

class Gate {
    String gateNo;

    Gate(String gateNo) {
        this.gateNo = gateNo;
    }

    Queue q = new Queue();

    void addPassenger(Passenger passenger) {
        q.enqueue(passenger);
    }

    Passenger processPassenger() {
        Passenger delPassenger = q.dequeue();
        return delPassenger;
    }

    boolean isEmpty() {
        return q.isEmpty();
    }

    int size() {
        return q.size();
    }
}

class Deque {
    DoublyLinkedList<Gate> dll = new DoublyLinkedList<>();

    void enqueueFront(Gate gate) {
        dll.insert_beginning(gate);
    }

    void enqueueRear(Gate gate) {
        dll.insert_end(gate);
    }

    Gate dequeueFront() {
        Gate delGate = dll.delete_beginning();
        return delGate;
    }

    Gate dequeueRear() {
        Gate delGate = dll.delete_end();
        return delGate;
    }

    boolean isEmpty() {
        return dll.isEmpty();
    }

    int size() {
        return dll.size();
    }

    Gate front() {
        return dll.peek_front();
    }
}

class GateManager {
    Deque dq = new Deque();
    Gate currGate = null;

    SinglyLinkedList<Passenger> processedPassenger = new SinglyLinkedList<>();

    void addGateFront(Gate g) {
        dq.enqueueFront(g);
    }

    void addGateEnd(Gate g) {
        dq.enqueueRear(g);
    }

    void closeGateFront() {

        Gate gate = dq.dequeueFront();

        if (gate == null) {
            System.out.println("No gates available");
            return;
        }

        System.out.println("Closed Gate: " + gate.gateNo);
    }

    void closeGateBack() {

        Gate gate = dq.dequeueRear();

        if (gate == null) {
            System.out.println("No gates available");
            return;
        }

        System.out.println("Closed Gate: " + gate.gateNo);
    }

    void selectGateFront() {

        currGate = dq.front();

        if (currGate == null) {
            System.out.println("No gates available");
            return;
        }

        System.out.println(
                "Selected Gate: " + currGate.gateNo);
    }

    void addPassengerToCurrGate(Passenger p) {
        if (currGate == null) {
            System.out.println("No gate selected");
            return;
        }
        currGate.addPassenger(p);
    }

    void processPassenger() {
        Passenger delPassenger = currGate.processPassenger();
        if (delPassenger == null) {
            System.out.println("All passenger processed");
            return;
        }
        processedPassenger.insert_end(delPassenger);
    }

    Passenger viewNextPassenger() {

        if (currGate == null) {
            System.out.println("No gate selected");
            return null;
        }

        Passenger p = currGate.q.front();

        if (p == null) {
            return null;
        }

        p.display();

        return p;

    }

    void displayGates() {

        if (dq.isEmpty()) {
            System.out.println("No gates available");
            return;
        }

        dNode<Gate> temp = dq.dll.head;

        while (temp != null) {
            System.out.print(temp.data.gateNo + " ");
            temp = temp.next;
        }

        System.out.println();

    }

    void displayProcessedPassengers() {
        processedPassenger.display();
    }

    void sortByBoarding() {
        Node<Passenger> i = processedPassenger.head;
        while (i != null) {
            Node<Passenger> j = i.next;

            while (j != null) {
                if (i.data.boardingGroup > j.data.boardingGroup) {
                    Passenger temp = i.data;
                    i.data = j.data;
                    j.data = temp;
                }

                j = j.next;
            }

            i = i.next;
        }

    }

    boolean isEmpty() {
        return dq.isEmpty();
    }

    int size() {
        return dq.size();
    }

}

public class AirportGateManagement {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        GateManager gm = new GateManager();

        while (true) {

            System.out.println("\n===== AIRPORT GATE MANAGEMENT =====");

            System.out.println("1. Add Gate Front");
            System.out.println("2. Add Gate Rear");
            System.out.println("3. Close Gate Front");
            System.out.println("4. Close Gate Back");
            System.out.println("5. Select Gate Front");
            System.out.println("6. Add Passenger");
            System.out.println("7. Process Passenger");
            System.out.println("8. View Next Passenger");
            System.out.println("9. Display Gates");
            System.out.println("10. Display Processed Passengers");
            System.out.println("11. Sort by Boarding Group");
            System.out.println("12. isEmpty");
            System.out.println("13. Size");
            System.out.println("14. Exit");

            System.out.print("Enter your choice: ");

            int ch = sc.nextInt();

            switch (ch) {

                case 1:

                    System.out.print("Enter Gate Number: ");

                    String gateFront = sc.next();

                    Gate gf = new Gate(gateFront);

                    gm.addGateFront(gf);

                    break;

                case 2:

                    System.out.print("Enter Gate Number: ");

                    String gateRear = sc.next();

                    Gate gr = new Gate(gateRear);

                    gm.addGateEnd(gr);

                    break;

                case 3:

                    gm.closeGateFront();

                    break;

                case 4:

                    gm.closeGateBack();

                    break;

                case 5:

                    if (gm.dq.isEmpty()) {

                        System.out.println("No gates available");

                    } else {

                        gm.currGate = gm.dq.dll.head.data;

                        System.out.println(
                                "Current Gate: " +
                                        gm.currGate.gateNo);
                    }

                    break;

                case 6:

                    if (gm.currGate == null) {

                        System.out.println(
                                "No gate selected");

                        break;
                    }

                    System.out.print("Enter Passenger ID: ");

                    String passengerID = sc.next();

                    System.out.print("Enter Name: ");

                    String name = sc.next();

                    System.out.print("Enter Boarding Group: ");

                    int boardingGroup = sc.nextInt();

                    Passenger passenger = new Passenger(
                            passengerID,
                            name,
                            boardingGroup);

                    gm.addPassengerToCurrGate(
                            passenger);

                    break;

                case 7:

                    gm.processPassenger();

                    break;

                case 8:

                    gm.viewNextPassenger();

                    break;

                case 9:

                    gm.displayGates();

                    break;

                case 10:

                    gm.displayProcessedPassengers();

                    break;

                case 11:

                    gm.sortByBoarding();

                    gm.displayProcessedPassengers();

                    break;

                case 12:

                    System.out.println(
                            gm.isEmpty());

                    break;

                case 13:

                    System.out.println(
                            gm.size());

                    break;

                case 14:

                    System.out.println("Exiting...");

                    sc.close();

                    return;

                default:

                    System.out.println(
                            "Invalid choice");
            }
        }
    }
}
