#ifndef SORT_H
#define SORT_H

#include<stdio.h>

void QuickSort(int* arr, int left, int right);
int Partioning(int* arr, int left, int right);
void MergeSort(int* arr, int left, int right);
void Merge(int* arr, int left, int right);
void CountingSort(int* arr, int len);
void SelectionSort(int* arr, int len);
void BubbleSort(int* arr, int len);
void PrintArray(int* arr, int len);

void QuickSort(int* arr, int left, int right) {
	if (left <= right) {
		int pivot = Partioning(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int Partioning(int* arr, int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		for (; pivot >= arr[low] && low <= right; low++);
		for (; pivot <= arr[high] && high > left; high--);
		if (low <= high) {
			int temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}

	int temp = arr[left];
	arr[left] = arr[high];
	arr[high] = temp;

	return high;
}

void MergeSort(int* arr, int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, right);
	}

}

void Merge(int* arr, int left, int right) {
	int mid = (left + right) / 2;
	const int len = right - left + 1;
	int * temp = (int*)malloc(len * sizeof(int));

	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right) {
		temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= right) temp[k++] = arr[j++];
	for (i=left, k=0; i <= right; i++, k++) arr[i] = temp[k];
	
}

void CountingSort(int* arr, int len) {
	int max = arr[0];
	for (int i = 1; i < len; i++) {
		if (max < arr[i]) max = arr[i];
	}

	int * countSum = (int*)malloc((max + 1) * sizeof(int));
	for (int i = 0; i <= max; i++) {
		countSum[i] = 0;
	}
	for (int i = 0; i < len; i++) {
		countSum[arr[i]]++;
	}
	for (int i = 1; i <= max; i++) {
		countSum[i] = countSum[i - 1] + countSum[i];
	}

	for (int i = 0; i < countSum[0]; i++) {
		arr[i] = 0;
	}

	for (int i = 1; i <= max; i++) {
		for (int j = countSum[i - 1]; j < countSum[i]; j++) {
			arr[j] = i;
		}
	}
}

void SelectionSort(int * arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		int min = arr[i];
		int k = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < min) {
				min = arr[j];
				k = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
}

void BubbleSort(int * arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void PrintArray(int* arr, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

#endif /* SORT_H */