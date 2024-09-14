//PROBLEM STATEMENT:-
//        You are given a sorted array of integers arr, and a target integer target.
//        Your task is to find and return the index of the smallest element in the array
//        that is greater than or equal to the target value (the "ceiling" of the target)
//        using a modified binary search algorithm.
//
//        Test Cases:-
//
//        1.Input: arr = [2, 3, 15, 9, 15, 16, 18], target = 15
//        Output: 2
//        Explanation: The smallest element in the array that is greater than or equal to 15 is 15 itself, which is at index 2.
//
//        2.Input: arr = [2, 3, 15, 9, 15, 16, 18], target = 12
//        Output: 2
//        Explanation: The smallest element in the array that is greater than or equal to 12 is 15, which is at index 2.
//
//        3.Input: arr = [2, 3, 15, 9, 15, 16, 18], target = 20
//        Output: 7
//        Explanation: There is no element in the array greater than or equal to 20. The function returns the length of the array (out of bounds index), which is 7.


public class BinarysearchCeiling {
    public static void main(String[] args) {
        int[] arr= {2,3,1,9,14,16,18};
        int target=15;
        System.out.println(Celling(arr,target));
    }
    static int Celling(int[] arr,int target){
        int start= 0;
        int end = arr.length - 1;

        //making a loop to check every element
        while (start<= end){
            int mid= start +(end-start)/2;

            if (target>arr[mid]){
                start=mid+1;
            } else if (target<arr[mid]) {
                end=mid-1;
            }
            else {
                return mid;
            }
        }
        return start;
    }
}

//Approach:-
//1.Initialize start to 0 and end to arr.length - 1.
//2.While start is less than or equal to end, do the following:-
//a . Calculate the middle index mid.
//b. If target is greater than arr[mid], set start to mid + 1.
//c. If target is less than arr[mid], set end to mid - 1.
//d. If target is equal to arr[mid], return mid.
// Return start as the index of the smallest element greater than or equal to the target.
