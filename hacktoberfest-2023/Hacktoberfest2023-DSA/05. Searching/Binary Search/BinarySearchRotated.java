//PROBLEM STATEMENT:- ROTATED BINARY SEARCH
//        You are given a rotated sorted array nums that has been rotated at an unknown pivot point.
//        Your task is to find and return the index of the target element target in the array.
//        If the target is not found in the array, return -1.
//        A rotated sorted array is an array that was originally sorted in ascending order but has been rotated to some extent
//
//        Test Cases:-
//        1.Input: nums = [5, 6, 7, 8, 2, 3, 4], target = 8
//        Output: 3
//        Explanation: The target element 8 is found at index 3 in the rotated sorted array.
//
//        2.Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
//        Output: 4
//        Explanation: The target element 0 is found at index 4 in the rotated sorted array.
//
//        3.Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 3
//        Output: -1
//        Explanation: The target element 3 is not present in the rotated sorted array, so the function returns -1.

import static java.util.Arrays.binarySearch;

public class BinarySearchRotated {
    public static void main(String[] args) {
        int[] arr={5,6,7,8,2,3,4};
        int target= 8;
        System.out.println(Search1(arr, target));
    }
    //code for searching in the arrays
    static  int Search1(int[] nums,int target){
        int pivot=FindPivot(nums);
        //if pivot is not found then the array  is not rotated
        if(pivot==-1){
            return binarySearch(nums,target,0,pivot-1);
        }

        //if pivot is found and we get 2 arrays ascending
        if(nums[pivot]==target){
            return pivot;
        }
        if(target>=nums[0]){
            return binarySearch(nums,target,0,pivot-1);
        }

        // code for normal binary search
        return binarySearch(nums,target,0,nums.length-1);
    }
    //code for binary search
    static int binarySearch(int[] arr,int target,int start,int end){
        while(start<=end){
            int mid= start+(end - start)/2;
            if(target<arr[mid]){
                end=mid-1;
            } else if (target>arr[mid]) {
                start=mid+1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
    //code to find pivot
    static  int FindPivot(int[] arr){
        int start=0;
        int end=arr.length-1;
        while(start<=end){
            int mid= start+(end-start)/2;
            if(mid<end && arr[mid]>arr[mid+1]){
                return mid;
            }
            if(mid>start && arr[mid]<arr[mid-1]){
                return mid-1;
            }
            if (arr[mid]<=arr[start]){
                end=mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return -1;
    }
}

//Approach:-
//
//        1. Define the Search1 function which takes the input array nums and target element target.
//        2. Find the pivot point using the FindPivot function. If no pivot is found, perform a regular binary search on the whole array.
//        3. If a pivot is found, perform binary search in one of two subarrays:
//        4. If target is equal to nums[pivot], return pivot.
//        5. If target is greater than or equal to nums[0], perform binary search in the left subarray from 0 to pivot-1.
//        Otherwise, perform binary search in the right subarray from pivot+1 to nums.length-1.
//        6. Implement the binarySearch function for regular binary search.
//        7. Implement the FindPivot function to find the pivot point in the rotated sorted array.
