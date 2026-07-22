import java.util.Scanner;

class Solution {
    public String largestOddNumber(String num) {
        for (int i = num.length() - 1; i >= 0; i--) {
            if ((num.charAt(i) - '0') % 2 != 0) {
                return num.substring(0, i + 1);
            }
        }

        return "";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        String num = sc.nextLine();

        Solution obj = new Solution();
        String result = obj.largestOddNumber(num);

        System.out.println("Largest odd number: " + result);

        sc.close();
    }
}