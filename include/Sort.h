#ifndef SORT_INCLUDE_SORT_H
#define SORT_INCLUDE_SORT_H

// сортировка вставками, Шейкерная сортировка, пирамидальная сортировка

#include <vector>
#include "../include/Stats.h"

// сортировка вставками
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


// Шейкерная сортировка
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



// пирамидальная сортировка

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом index
template<typename T>
void heapify(std::vector<T>& arr, int size, int index, Stats& stats) {
    int largest = index;

    // Инициализируем наибольший элемент как корень
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Если левый дочерний элемент больше корня
    stats.comparison_count += 1;
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
        stats.copy_count += 1;
    }

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    stats.comparison_count += 1;
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
        stats.copy_count += 1;
    }

    // Если самый большой элемент не корень
    stats.comparison_count += 1;
    if (largest != index) {
        std::swap(arr[index], arr[largest]);
        stats.copy_count += 1;

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, size, largest, stats);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
template<typename T>
void heap_sort(std::vector<T>& arr, Stats& stats) {
    int size = arr.size();

    // Построение кучи (перегруппируем массив)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i, stats);
    }

    // Один за другим извлекаем элементы из кучи
    for (int i = size - 1; i > 0; i--) {

        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);
        stats.copy_count += 2;

        // вызываем процедуру heapify на уменьшенной куче
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