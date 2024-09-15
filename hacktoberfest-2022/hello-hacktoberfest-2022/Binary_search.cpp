#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key)
{
	if (high >= low) {
		int mid = low + (high - low) / 2;


		// If the element is present at the middle
		// itself
		if (arr[mid] == key)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > key)
			return binarySearch(arr, low, mid - 1, key);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, high, key);
	}
	// We reach here when element is not
	// present in array
	return -1;

}

int main()
{
	int n, key, result = 0;
	cout << "Enter the size of the array " << endl;
	cin >> n;
	int array[n];
	cout << "Enter the elements of the array" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	cout << "Enter the element to be searched" << endl;
	cin >> key;
	result = binarySearch(array, 0, n - 1, key);
	if (result == -1) {
		cout << "Element " << key << " not found in the array" << endl;

	} else {
		cout << "Element " << key << " found at the index " << result << endl;
	}

	return 0;
}