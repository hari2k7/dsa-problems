class Employee{
    String emp_id;
    String name;
    int salary;

    Employee(String emp_id,
    String name,
    int salary){
        this.emp_id = emp_id;
        this.name = name;
        this.salary = salary;
    }

    void display(){
        System.out.println(emp_id+" "+name+" "+salary);
    }
}

class TreeNode {
    Employee data;
    TreeNode left;
    TreeNode right;

    TreeNode(Employee data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Node{
    Employee data;
    Node next;

    Node(Employee data){
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList{
    Node head;

    void insert_end(Employee data){
        Node new_node = new Node(data);

        if(head == null){
            head = new_node;
            return;
        }

        Node temp = head;
        while(temp.next != null){
            temp = temp.next;
        }

        temp.next = new_node;
    }

    void delete_beg(){
        if(head==null){
            return;
        }

        head = head.next;
    }

    void sortAscending(){
        Node i = head;
        while(i!=null){
            Node j = i.next;
            while(j!=null){
                if(i.data.salary > j.data.salary){
                    Employee temp = i.data;
                    i.data = j.data;
                    j.data = temp;
                }
            }
        }
    }
    void sortDescending(){
        Node i = head;
        while(i!=null){
            Node j = i.next;
            while(j!=null){
                if(i.data.salary < j.data.salary){
                    Employee temp = i.data;
                    i.data = j.data;
                    j.data = temp;
                }
            }
        }
    }
}

class Queue{
    SinglyLinkedList sll = new SinglyLinkedList();

    void enqueue(Employee data){
        sll.insert_end(data);
    }

    Employee dequeue(){

        if (sll.head == null) {
            return null;
        }

        Employee data = sll.head.data;

        sll.delete_beg();

        return data;
    }

    boolean isEmpty(){
        return sll.head == null;
    }
}

class BinaryTree{
    TreeNode root;
    int p = 0;

    void createRoot(Employee data){
        if(root != null){
            System.out.println("Root already exists");
            return;
        }

        root = new TreeNode(data);
    }

    TreeNode searchNode(TreeNode temp, String emp_id){
        if(root == null){
            return null;
        }

        if(temp.data.emp_id == emp_id){
            return temp;
        }

        TreeNode result = searchNode(temp.left, emp_id);

        if(result != null){
            return result;
        }

        return searchNode(temp.right, emp_id);

    }

    void addLeft(String parentId, Employee data){
        TreeNode parentNode = searchNode(root, parentId);

        if(parentNode == null){
            System.out.println("parent node not found");
            return;
        }

        if(parentNode.left != null){
            System.out.println("Left suboardinate already exists");
            return;
        }

        parentNode.left = new TreeNode(data);
        p++;

        System.out.println("Employee added as left suboardinate");

    }

    void addRight(String parentId, Employee data){
        TreeNode parentNode = searchNode(root, parentId);

        if(parentNode == null){
            System.out.println("Parent node not found");
            return;
        }

        if(parentNode.right != null){
            System.out.println("Right suboardinate already exists");
            return;
        }

        parentNode.right = new TreeNode(data);
        p++;
        System.out.println("Right suboardinate added");
    }

    Employee search(String emp_id){
        TreeNode result = searchNode(root, emp_id);

        if(result==null){
            return null;
        }

        return result.data;
    }

    

    
}

public class FullBinaryTree {
    
}
