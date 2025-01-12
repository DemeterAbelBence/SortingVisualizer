#pragma once 

#include <memory>
#include <vector>
#include <algorithm>

#include "window/WindowHandler.hpp"

namespace srt {
	template<typename T>
	void swap(T* arr, int i, int j);

	template<typename T>
	void quickSort(T* arr, int i, int j, int pivot);

	template<typename T>
	void quickSortVector(std::vector<T>& vec);
};

template<class T>
void srt::swap(T* arr, int i, int j) {
	T tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

template<typename T>
void srt::quickSort(T* arr, int i, int j, int pivot) {
	if (j == pivot || pivot < 0) {
		return;
	}

	while (j < pivot) {
		if (arr[j] <= arr[pivot]) {
			swap(arr, ++i, j);
		}
		j++;
	}

	swap(arr, i + 1, pivot);
	quickSort(arr, i, i + 1, pivot);
	quickSort(arr, -1, 0, i);
};

template<typename T>
void srt::quickSortVector(std::vector<T>& vec) {
	int pivot = vec.size() - 1;
	quickSort(&vec[0], -1, 0, pivot);
}