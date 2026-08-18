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

class Container {
    String containerID;
    String companyID;
    int weight;
    String cargoType;

    Container(String containerID, String companyID, int weight, String cargoType) {
        this.containerID = containerID;
        this.companyID = companyID;
        this.weight = weight;
        this.cargoType = cargoType;
    }

    void display() {
        System.out.println(containerID + " " + " " + companyID + weight + " " + cargoType);
    }
}

class Stack {
    SinglyLinkedList<Container> sll = new SinglyLinkedList<>();

    int p = 0;

    void push(Container container) {
        sll.insert_beginning(container);
        p++;
    }

    Container pop() {
        if (sll.head == null) {
            System.out.println("Stack Underflow");
            return null;
        }
        Container delContainer = sll.delete_beg();
        p--;

        return delContainer;
    }

    Container top() {
        if (sll.head == null) {
            System.out.println("Stack Underflow");
            return null;
        }

        return sll.head.data;
    }

    boolean isEmpty() {
        return sll.head == null;
    }

    int size() {
        return p;
    }
}

class Company {
    String companyId;

    Company(String companyId) {
        this.companyId = companyId;
    }

    Stack sk = new Stack();

    void addContainr(Container container) {
        sk.push(container);
    }

    Container processContainer() {
        return sk.pop();
    }

    boolean isEmpty() {
        return sk.isEmpty();
    }

    int size() {
        return sk.size();
    }

}

class Queue {
    SinglyLinkedList<Company> sll = new SinglyLinkedList<>();

    int p = 0;

    void enqueue(Company company) {
        sll.insert_end(company);
        p++;
    }

    Company dequeue() {
        if (sll.head == null) {
            System.out.println("Queue Underflow");
            return null;
        }

        Company delCompany = sll.delete_beg();
        p--;
        return delCompany;
    }

    Company front() {
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
        return p;
    }

}

class ProcessingSystem {
    Queue Cqueue = new Queue();
    SinglyLinkedList<Container> processedContainer = new SinglyLinkedList<>();

    Company currentCompany = null;

    void addcompany(String Cid) {
        Company comp = new Company(Cid);

        Cqueue.enqueue(comp);

        System.out.println(Cid + " " + "Added");
    }

    Company findCompany(String companyId) {
        Node<Company> temp = Cqueue.sll.head;

        while (temp != null) {
            if (temp.data.companyId.equals(companyId)) {
                return temp.data;
            }
            temp = temp.next;
        }

        return null;
    }

    void addContainr(String cid, Container container) {
        Company company = findCompany(cid);

        if (company == null) {
            System.out.println("Comapny Not Found");
            return;
        }

        company.addContainr(container);
        System.out.println("Container " + container.containerID + " added");
    }

    void selectNextCompany() {
        if (currentCompany != null && !currentCompany.isEmpty()) {
            System.out.println("Processing containers pending");
            return;
        }

        currentCompany = Cqueue.dequeue();

        if (currentCompany == null) {
            System.out.println("No Companies pending");
            return;
        }

        System.err.println("Selected Company " + currentCompany.companyId);
    }

    void processContainer() {
        if (currentCompany == null) {
            System.out.println("No company selected");
            return;
        }

        if (currentCompany.isEmpty()) {
            System.out.println("Current company is empty");
            return;
        }

        Container delContainer = currentCompany.processContainer();
        processedContainer.insert_end(delContainer);
        System.out.println("Processed " + delContainer.containerID);

        if (currentCompany.isEmpty()) {
            System.out.println("Company " + currentCompany.companyId + " completed");
            currentCompany = null;
            return;
        }

    }

    void displayPendingCompanies() {

        if (Cqueue.isEmpty()) {
            System.out.println("No Companies pending");
            return;
        }

        System.out.print("Pending Companies: ");

        Node<Company> temp = Cqueue.sll.head;

        while (temp != null) {

            System.out.print(temp.data.companyId + " ");

            temp = temp.next;
        }

        System.out.println();
    }

    void displayProcessedContainers() {
        if (processedContainer.isEmpty()) {
            System.out.println("No containers processed");
            return;
        }

        System.out.println("Proceesed Containers: ");
        processedContainer.display();
    }

    void sortAscending() {
        Node<Container> i = processedContainer.head;

        while (i != null) {
            Node<Container> j = i.next;

            while (j != null) {
                if (i.data.weight > j.data.weight) {
                    Container temp = i.data;
                    i.data = j.data;
                    j.data = temp;
                }

                j = j.next;
            }

            i = i.next;
        }

        System.out.println("Sorted in ascending order.");
    }

    void sortDescending() {
        Node<Container> i = processedContainer.head;

        while (i != null) {
            Node<Container> j = i.next;

            while (j != null) {
                if (i.data.weight < j.data.weight) {
                    Container temp = i.data;
                    i.data = j.data;
                    j.data = temp;
                }

                j = j.next;
            }

            i = i.next;
        }

        System.out.println("Sorted in descending order.");
    }

    boolean isEmpty() {
        return Cqueue.isEmpty() && currentCompany == null;
    }

    int size() {
        return Cqueue.size();
    }

}

public class RailwayCargoProcessingSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ProcessingSystem ps = new ProcessingSystem();

        int ch;

        do {

            System.out.println("\n===== EXAMINATION PROCESSING SYSTEM =====");
            System.out.println("1. Add Department");
            System.out.println("2. Add Script to Department");
            System.out.println("3. Select Next Department");
            System.out.println("4. Process Script");
            System.out.println("5. Display Pending Departments");
            System.out.println("6. Display Evaluated Scripts");
            System.out.println("7. Sort by Marks Ascending");
            System.out.println("8. Sort by Marks Descending");
            System.out.println("9. isEmpty");
            System.out.println("10. Size");
            System.out.println("11. Exit");
            System.out.print("Enter your choice: ");

            ch = sc.nextInt();

            switch (ch) {

                case 1:
                    System.out.print("Enter Company ID: ");
                    String companyId = sc.next();
                    ps.addcompany(companyId);
                    break;

                case 2:
                    System.out.print("Enter Company ID: ");
                    String cid = sc.next();

                    System.out.print("Enter Container ID: ");
                    String containerID = sc.next();

                    System.out.print("Enter Weight: ");
                    int weight = sc.nextInt();

                    System.out.print("Enter Cargo Type: ");
                    String cargoType = sc.next();

                    Container container = new Container(containerID, cid, weight, cargoType);

                    ps.addContainr(cid, container);
                    break;

                case 3:
                    ps.selectNextCompany();
                    break;

                case 4:
                    ps.processContainer();
                    break;

                case 5:
                    ps.displayPendingCompanies();
                    break;

                case 6:
                    ps.displayProcessedContainers();
                    break;

                case 7:
                    ps.sortAscending();
                    ps.displayProcessedContainers();
                    break;

                case 8:
                    ps.sortDescending();
                    ps.displayProcessedContainers();
                    break;

                case 9:
                    if (ps.isEmpty()) {
                        System.out.println("System is Empty");
                    } else {
                        System.out.println("System is Not Empty");
                    }
                    break;

                case 10:
                    System.out.println("Number of Pending Companies: " + ps.size());
                    break;

                case 11:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid Choice!");
            }

        } while (ch != 11);
    }
}