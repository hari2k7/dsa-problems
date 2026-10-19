import java.util.Scanner;

class TreeNode{
    int data;
    TreeNode left;
    TreeNode right;

    TreeNode(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Node{
    TreeNode data;
    Node next;

    Node(TreeNode data){
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList{
    Node head;

    void insert_end(TreeNode data){
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
}

class Queue{
    SinglyLinkedList sll = new SinglyLinkedList();

    void enqueue(TreeNode data){
        sll.insert_end(data);
    }

    TreeNode dequeue(){

        if (sll.head == null) {
            return null;
        }

        TreeNode data = sll.head.data;

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

    void insert(int data) {

        TreeNode new_node = new TreeNode(data);

        if (root == null) {
            root = new_node;
            p++;
            return;
        }

        Queue q = new Queue();
        q.enqueue(root);

        while (!q.isEmpty()) {

            TreeNode temp = q.dequeue();

            if (temp.left == null) {
                temp.left = new_node;
                p++;
                return;
            } else {
                q.enqueue(temp.left);
            }

            if (temp.right == null) {
                temp.right = new_node;
                p++;
                return;
            } else {
                q.enqueue(temp.right);
            }
        }
    }

    void inorder(TreeNode temp) {

        if (temp == null) {
            return;
        }

        inorder(temp.left);

        System.out.print(temp.data + " ");

        inorder(temp.right);
    }

    void preorder(TreeNode temp) {

        if (temp == null) {
            return;
        }

        System.out.print(temp.data + " ");

        preorder(temp.left);

        preorder(temp.right);
    }

    void postorder(TreeNode temp) {

        if (temp == null) {
            return;
        }

        postorder(temp.left);

        postorder(temp.right);

        System.out.print(temp.data + " ");
    }

    boolean search(TreeNode temp, int data) {

        if (temp == null) {
            return false;
        }

        if (temp.data == data) {
            return true;
        }

        return search(temp.left, data) ||
               search(temp.right, data);
    }

    boolean isEmpty() {

        if (root == null) {
            return true;
        }

        return false;
    }

    int size() {
        return p;
    }

    void display() {

        if (root == null) {
            System.out.println("Tree is empty");
            return;
        }

        System.out.print("Inorder: ");

        inorder(root);

        System.out.println();
    }
}

public class ImpBinaryTree {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        BinaryTree tree = new BinaryTree();

        while (true) {

            System.out.println("\n1. Insert");
            System.out.println("2. Search");
            System.out.println("3. Inorder");
            System.out.println("4. Preorder");
            System.out.println("5. Postorder");
            System.out.println("6. isEmpty");
            System.out.println("7. Size");
            System.out.println("8. Display");
            System.out.println("9. Exit");

            System.out.print("Enter your choice: ");

            int ch = sc.nextInt();

            switch (ch) {

                case 1:

                    System.out.print("Enter a number to insert: ");

                    int n = sc.nextInt();

                    tree.insert(n);

                    break;

                case 2:

                    System.out.print("Enter a number to search: ");

                    int s = sc.nextInt();

                    if (tree.search(tree.root, s)) {
                        System.out.println("Element found");
                    } else {
                        System.out.println("Element not found");
                    }

                    break;

                case 3:

                    System.out.print("Inorder: ");

                    tree.inorder(tree.root);

                    System.out.println();

                    break;

                case 4:

                    System.out.print("Preorder: ");

                    tree.preorder(tree.root);

                    System.out.println();

                    break;

                case 5:

                    System.out.print("Postorder: ");

                    tree.postorder(tree.root);

                    System.out.println();

                    break;

                case 6:

                    System.out.println(tree.isEmpty());

                    break;

                case 7:

                    System.out.println(tree.size());

                    break;

                case 8:

                    tree.display();

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
