public class secondLargestNum {

    static int secondLargest(int[] arr) {
        int largest = arr[0];
        int second_largest = Integer.MIN_VALUE;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > largest) {
                second_largest = largest;
                largest = arr[i];
            } else if (arr[i] > second_largest && arr[i] != largest) {
                second_largest = arr[i];
            }
        }

        return second_largest;
    }

    public static void main(String[] args) {
        int[] arr = {9, 3, 8, 6, 8, 6, 5};
        System.out.println(secondLargest(arr));
    }
}