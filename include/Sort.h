#ifndef SORT_INCLUDE_SORT_H
#define SORT_INCLUDE_SORT_H

// ���������� ���������, ��������� ����������, ������������� ����������

#include <vector>
#include "../include/Stats.h"

// ���������� ���������
template<typename T>
Stats insertion_sort(std::vector<T>& arr) {
    Stats stats;
    if (arr.size() < 2)
        return stats;
    for (int i = 1; i < arr.size(); ++i) {
        int j = i;
        stats.comparison_count++;
        while (j != 0 && arr[j] < arr[j - 1]) {
            std::swap(arr[j - 1], arr[j]);
            stats.copy_count += 2;
            --j;
        }
    }
    return stats;
}


// ��������� ����������
template<typename T>
Stats cocktail_sort(std::vector<T>& arr) {
    Stats stats;
    if (arr.size() < 2) return stats;
    int left = 0, right = arr.size() - 1;
    int last_swap = 0;
    while (left < right) {
        for (int i = left; i < right; ++i) {
            stats.comparison_count++;
            if (arr[i + 1] < arr[i]) {
                std::swap(arr[i + 1], arr[i]);
                stats.copy_count += 2;
                last_swap = i;
            }
        }
        right = last_swap;
        for (int j = right; j > left; --j) {
            stats.comparison_count++;
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                stats.copy_count += 2;
                last_swap = j;
            }
        }
        left = last_swap;
    }
    return stats;
}



// ������������� ����������

// ��������� ��� �������������� � �������� ���� ��������� � �������� ����� index
template<typename T>
void heapify(std::vector<T>& arr, int size, int index, Stats& stats) {
    int largest = index;

    // �������������� ���������� ������� ��� ������
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // ���� ����� �������� ������� ������ �����
    stats.comparison_count += 1;
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
        stats.copy_count += 1;
    }

    // ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
    stats.comparison_count += 1;
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
        stats.copy_count += 1;
    }

    // ���� ����� ������� ������� �� ������
    stats.comparison_count += 1;
    if (largest != index) {
        std::swap(arr[index], arr[largest]);
        stats.copy_count += 1;

        // ���������� ����������� � �������� ���� ���������� ���������
        heapify(arr, size, largest, stats);
    }
}

// �������� �������, ����������� ������������� ����������
template<typename T>
void heap_sort(std::vector<T>& arr, Stats& stats) {
    int size = arr.size();

    // ���������� ���� (�������������� ������)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i, stats);
    }

    // ���� �� ������ ��������� �������� �� ����
    for (int i = size - 1; i > 0; i--) {

        // ���������� ������� ������ � �����
        std::swap(arr[0], arr[i]);
        stats.copy_count += 2;

        // �������� ��������� heapify �� ����������� ����
        heapify(arr, i, 0, stats);
    }
}

template<typename T>
Stats heap_sort_wrapper(std::vector<T>& arr) {
    Stats stats;
    heap_sort(arr, stats);
    return stats;
}


#endif