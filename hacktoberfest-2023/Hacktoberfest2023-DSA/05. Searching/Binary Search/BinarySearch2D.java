//PROBLEM STATEMENT :-
//You are given a 2D matrix where each row and column is sorted in ascending order.
// Your task is to implement a function to search for a target integer target in the matrix.
// If the target is found, return its row and column indices; otherwise, return [-1, -1] to
// indicate that the target is not present in the matrix.

//Input:
//        matrix = [
//        [10, 20, 30, 40],
//        [15, 25, 35, 45],
//        [28, 29, 37, 49],
//        [33, 34, 38, 50]
//        ]
//        target = 30
//
//        Output:
//        [0, 2]
//
//        Explanation: The target element 30 is found at matrix[0][2].
//
//        Input:
//        matrix = [
//        [1, 3, 5, 7],
//        [10, 11, 16, 20],
//        [23, 30, 34, 60]
//        ]
//        target = 13
//
//        Output:
//        [-1, -1]
//
//        Explanation: The target element 13 is not present in the matrix.
//

import java.util.Arrays;

public class BinarySearch2D {
    public static void main(String[] args) {
        int[][] arr={
                {10,20,30,40},
                {15,25,35,45},
                {28,29,37,49},
                {33,34,38,50}
        };
        int target=30;
        System.out.println(Arrays.toString(search(arr,target)));
    }
    static int[]  search(int[][] matrix, int target){
        int row=0;
        int col=matrix.length-1;
        while(row<matrix.length && col>=0){
            if(matrix[row][col]==target){
                return new int[]{row,col};
            }
            if (matrix[row][col]<target) {
                row++;
            }
            else {
                col--;
            }
        }
        return new int[]{-1,-1};
    }

}
//Approach:-

//Initialization:-
// Start in the top-right corner of the matrix (or any corner that suits your preference).
// Initialize row to 0 and col to the last column index (matrix[0].length - 1).

//    Search Algorithm:-
//Enter a while loop that continues as long as row is within the bounds of the matrix (0 <= row < matrix.length) and col is within the bounds of the matrix (0 <= col < matrix[0].length).
//Inside the loop:
//Compare the element at matrix[row][col] with the target value:
//If they are equal, return [row, col] as the indices where the target is found.
//If matrix[row][col] is less than the target, increment row to move down one row (since the current row is sorted in ascending order).
//If matrix[row][col] is greater than the target, decrement col to move left one column (since the current column is sorted in ascending order).

//    Exit Loop:-
//If the loop exits without finding the target, return [-1, -1] to indicate that the target is not present in the matrix.

//Complexity Analysis
//It has a time complexity of O(m + n), where m is the number of rows and n is the number of columns in the matrix, as it explores either rows or columns in each step of the search.