#include<stdio.h>

#define LEN 10

int main() {
	// 1_sort
	int bubbleArr[LEN] = { 8,2,3,1,4,5,7,6,10,9 };
	int selectionArr[LEN] = { 8,2,3,1,4,5,7,6,10,9 };
	int countingArr[LEN] = { 8,2,3,1,4,5,7,6,10,9 };
	int mergeArr[LEN] = { 8,2,3,1,4,5,7,6,10,9 };
	int quickArr[LEN] = { 8,2,3,1,4,5,7,6,10,9 };

	printf("Bubble Sort\n");
	BubbleSort(bubbleArr, LEN);
	PrintArray(bubbleArr, LEN);

	printf("Selection Sort\n");
	SelectionSort(selectionArr, LEN);
	PrintArray(selectionArr, LEN);

	printf("Counting Sort\n");
	CountingSort(countingArr, LEN);
	PrintArray(countingArr, LEN);

	printf("Quick Sort\n");
	QuickSort(quickArr, 0, LEN - 1);
	PrintArray(quickArr, LEN);

	printf("Merge Sort\n");
	MergeSort(mergeArr, 0, LEN - 1);
	PrintArray(mergeArr, LEN);

	return 0;
}