//PROBLEM STATEMENT :-
//        You have been given a sorted array of integers and target,
//        you have to find the index of the target element.
//
//        Test Cases:-
//
//        1.Input Array: [1, 2, 3, 4, 5, 6, 7, 8, 9]
//        Target Element: 5
//        Expected Output: Index 4 (since 5 is at index 4 in the array)
//
//        2.Input Array: [1, 2, 3, 4, 6, 7, 8, 9]
//        Target Element: 5
//        Expected Output: -1 (since 5 is not in the array)
//
//        3.Input Array: [1]
//        Target Element: 1
//        Expected Output: Index 0

public class BinarySearch {
    public static void main(String[] args) {
        int[] arr={-18,-12,-4,0,2,3,4,15,16,18,22,45,89}; // array must be shorted
        int target= 22;
        int ans=BinarySearching(arr,target);
        System.out.println(ans);
    }

    private static int BinarySearching(int[] arr, int target) {
        int start=0;
        int end=arr.length-1;
        while(start<=end){
            //finding the middle element using " mid = start+(end-start)/2 "
            int mid= start+(end-start)/2;
            if(target<arr[mid]){
                end=mid-1;
            } else if (target>arr[mid]) {
                start=mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
}

//Approach:-
//1.Initialize start and end pointers: Set start to 0 (the beginning of the array) and end to the length of the array minus one (the end of the array).

// Binary Search Loop.
// Enter a while loop that continues while start is less than or equal to end, indicating a valid search interval.

//Calculate Middle Index:
//Inside the loop, calculate the middle index mid as start + (end - start) / 2.

//Compare with Target:
//Compare the target value with the element at the middle index, arr[mid]:
//If target is less than arr[mid], update end to mid - 1. This narrows the search interval to the left half.
//If target is greater than arr[mid], update start to mid + 1. This narrows the search interval to the right half.
//If target is equal to arr[mid], return mid as the index where the target element is found.

//Exit Loop:
//If the loop finishes without finding the target, return -1 to indicate that the target is not in the array.