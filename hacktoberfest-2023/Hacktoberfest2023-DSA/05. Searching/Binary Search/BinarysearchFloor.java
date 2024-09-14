//PROBLEM STATEMENT:-
//        You are given a sorted array of integers arr, and a target integer target.
//        Your task is to find and return the index of the largest element in the array that is less than
//        or equal to the target value (the "floor" of the target) using a modified binary search algorithm.
//
//        Test Cases:-
//        1.Input: arr = [2, 3, 5, 9, 12, 14, 16, 18], target = 13
//        Output: 3
//        Explanation: The largest element in the array that is less than or equal to 13 is 12, which is at index 3.
//
//        2.Input: arr = [2, 3, 5, 9, 12, 14, 16, 18], target = 5
//        Output: 2
//        Explanation: The largest element in the array that is less than or equal to 5 is 5 itself, which is at index 2.
//
//        3.Input: arr = [2, 3, 5, 9, 12, 14, 16, 18], target = 1
//        Output: -1
//        Explanation: There is no element in the array less than or equal to 1. The function returns -1.

public class BinarysearchFloor {
    public static void main(String[] args) {
        int[] arr={2,3,5,9,12,14,16,18};
        int target=13;
        System.out.println(Floor(arr,target));
    }
    static int Floor(int[] arr, int target){
        int start=0;
        int end= arr.length-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            if (target<arr[mid]){
                end=mid-1;
            } else if (target>arr[mid]) {
                start=mid+1;
            }
            else {
                return mid;
            }
        }
        return end;
    }
}

//        Approach:-
//        1. Initialize start to 0 and end to arr.length - 1.
//        2. While start is less than or equal to end:
//        3. Calculate mid as (start + end) / 2.
//        4. If target is less than arr[mid], update end to mid - 1.
//           If target is greater than arr[mid], update start to mid + 1.
//           If target is equal to arr[mid], return mid.
//        5. Return end as the index of the largest element less than or equal to the target.