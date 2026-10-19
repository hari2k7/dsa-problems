import java.util.Scanner;

class TreeNode {
    String data;
    TreeNode left;
    TreeNode right;

    TreeNode(String data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree {

    TreeNode root;
    int p = 0;

    void createRoot(String data) {

        if (root != null) {
            System.out.println("Root already exists");
            return;
        }

        root = new TreeNode(data);
        p++;

        System.out.println("Root added");
    }

    TreeNode search(TreeNode temp, String data) {

        if (temp == null) {
            return null;
        }

        if (temp.data.equals(data)) {
            return temp;
        }

        TreeNode result = search(temp.left, data);

        if (result != null) {
            return result;
        }

        return search(temp.right, data);
    }

    void addLeft(String parentData, String data) {

        TreeNode parent = search(root, parentData);

        if (parent == null) {
            System.out.println("Parent not found");
            return;
        }

        if (parent.left != null) {
            System.out.println("Left child already exists");
            return;
        }

        parent.left = new TreeNode(data);
        p++;

        System.out.println("Child added");
    }

    void addRight(String parentData, String data) {

        TreeNode parent = search(root, parentData);

        if (parent == null) {
            System.out.println("Parent not found");
            return;
        }

        if (parent.right != null) {
            System.out.println("Right child already exists");
            return;
        }

        parent.right = new TreeNode(data);
        p++;

        System.out.println("Child added");
    }

    void preorder(TreeNode temp) {

        if (temp == null) {
            return;
        }

        System.out.print(temp.data + " ");

        preorder(temp.left);
        preorder(temp.right);
    }

    void inorder(TreeNode temp) {

        if (temp == null) {
            return;
        }

        inorder(temp.left);

        System.out.print(temp.data + " ");

        inorder(temp.right);
    }

    void postorder(TreeNode temp) {

        if (temp == null) {
            return;
        }

        postorder(temp.left);
        postorder(temp.right);

        System.out.print(temp.data + " ");
    }

    void display() {

        if (root == null) {
            System.out.println("Tree is empty");
            return;
        }

        System.out.print("Preorder: ");
        preorder(root);
        System.out.println();
    }

    boolean isEmpty() {

        return root == null;
    }

    int size() {

        return p;
    }
}

public class HierarchicalTree {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        BinaryTree tree = new BinaryTree();

        while (true) {

            System.out.println("\n1. Create Root");
            System.out.println("2. Add Left Child");
            System.out.println("3. Add Right Child");
            System.out.println("4. Search");
            System.out.println("5. Preorder");
            System.out.println("6. Inorder");
            System.out.println("7. Postorder");
            System.out.println("8. isEmpty");
            System.out.println("9. Size");
            System.out.println("10. Display");
            System.out.println("11. Exit");

            System.out.print("Enter your choice: ");

            int ch = sc.nextInt();

            switch (ch) {

                case 1:

                    System.out.print("Enter root: ");

                    String rootData = sc.next();

                    tree.createRoot(rootData);

                    break;

                case 2:

                    System.out.print("Enter parent: ");

                    String leftParent = sc.next();

                    System.out.print("Enter left child: ");

                    String leftChild = sc.next();

                    tree.addLeft(leftParent, leftChild);

                    break;

                case 3:

                    System.out.print("Enter parent: ");

                    String rightParent = sc.next();

                    System.out.print("Enter right child: ");

                    String rightChild = sc.next();

                    tree.addRight(rightParent, rightChild);

                    break;

                case 4:

                    System.out.print("Enter element to search: ");

                    String searchData = sc.next();

                    if (tree.search(tree.root, searchData) != null) {
                        System.out.println("Element found");
                    } else {
                        System.out.println("Element not found");
                    }

                    break;

                case 5:

                    System.out.print("Preorder: ");

                    tree.preorder(tree.root);

                    System.out.println();

                    break;

                case 6:

                    System.out.print("Inorder: ");

                    tree.inorder(tree.root);

                    System.out.println();

                    break;

                case 7:

                    System.out.print("Postorder: ");

                    tree.postorder(tree.root);

                    System.out.println();

                    break;

                case 8:

                    System.out.println(tree.isEmpty());

                    break;

                case 9:

                    System.out.println(tree.size());

                    break;

                case 10:

                    tree.display();

                    break;

                case 11:

                    System.out.println("Exiting...");

                    sc.close();

                    return;

                default:

                    System.out.println("Invalid choice");
            }
        }
    }
}