#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_set>
#include <vector>
#include <climits>
using namespace std;

// Генерация массива случайных чисел
void generateRandomArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // случайные числа от 0 до 99
    }
}

// 1.1. Поиск максимального элемента в массиве
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 1.2. Суммирование всех элементов массива
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// 1.3. Проверка, содержит ли массив заданное число
bool containsNumber(int arr[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            return true;
        }
    }
    return false;
}

// 2.1. Пузырьковая сортировка
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2.2. Сортировка вставками
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Функция для копирования массива (чтобы использовать его в нескольких алгоритмах)
void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

// 3.1. Поиск второй по величине строки с использованием сортировки (O(n * log n))
string findSecondLargestStringSort(string arr[], int size) {
    sort(arr, arr + size); // Лексикографическая сортировка массива строк
    return arr[size - 2];  // Возвращаем вторую по величине строку
}

// 3.2. Поиск второй по величине строки за один проход (O(n))
string findSecondLargestStringLinear(string arr[], int size) {
    string largest = "";
    string secondLargest = "";

    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

// 4.1. Проверка на палиндром с использованием двух указателей
bool isPalindromeTwoPointers(const string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        // Пропускаем не буквенно-цифровые символы
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        // Сравниваем символы
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// 4.2. Проверка на палиндром с использованием очищенной строки
bool isPalindromeCleanString(const string& s) {
    string filtered;
    for (char c : s) {
        if (isalnum(c)) {
            filtered += tolower(c);
        }
    }
    string reversed = filtered;
    reverse(reversed.begin(), reversed.end());
    return filtered == reversed;
}

// 5.1. Подсчет уникальных элементов с использованием множества (O(n))
int countUniqueElementsUsingSet(int arr[], int size) {
    unordered_set<int> uniqueElements;
    for (int i = 0; i < size; i++) {
        uniqueElements.insert(arr[i]);
    }
    return uniqueElements.size();
}

// 5.2. Подсчет уникальных элементов с использованием сортировки (O(n log n))
int countUniqueElementsUsingSort(int arr[], int size) {
    if (size == 0) return 0;
    sort(arr, arr + size);  // Сортируем массив
    int uniqueCount = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            uniqueCount++;
        }
    }
    return uniqueCount;
}

// 6. Поиск наименьшего отсутствующего положительного числа (O(n))
int findSmallestMissingPositiveNumberOptimized(int arr[], int size) {
    unordered_set<int> numSet;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            numSet.insert(arr[i]);
        }
    }

    int smallestMissing = 1;
    while (numSet.find(smallestMissing) != numSet.end()) {
        smallestMissing++;
    }

    return smallestMissing;
}

// 7. Поиск наименьшего отсутствующего положительного числа с сортировкой (O(n log n))
int findSmallestMissingPositiveNumberSorted(int arr[], int size) {
    sort(arr, arr + size); // Сортируем массив
    int smallestMissing = 1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == smallestMissing) {
            smallestMissing++;
        }
    }
    return smallestMissing;
}

int main() {
    setlocale(LC_ALL, "rus");

    cout << "          ЗАДАНИЕ 1          \n" << endl;

    const int size = 1000;
    int hjvf[size];

    // Генерация массива случайных чисел
    generateRandomArray(hjvf, size);

    // Поиск максимального элемента
    int maxElement = findMax(hjvf, size);
    cout << "Максимальный элемент: " << maxElement << endl;

    // Суммирование всех элементов
    int sumOfElements = sumArray(hjvf, size);
    cout << "Сумма всех элементов: " << sumOfElements << endl;

    // Проверка, содержит ли массив заданное число (например, число 50)
    int numberToFind = 50;
    bool contains = containsNumber(hjvf, size, numberToFind);
    cout << "Содержит число " << numberToFind << "? " << (contains ? "Yes" : "No") << endl;

    cout << '\n';
    cout << "          ЗАДАНИЕ 2          " << endl;

    // Копирование массива для сравнения сортировок
    int arrayForBubbleSort[size], arrayForInsertionSort[size];
    copyArray(hjvf, arrayForBubbleSort, size);
    copyArray(hjvf, arrayForInsertionSort, size);

    // Пузырьковая сортировка с замером времени
    clock_t startBubble = clock();
    bubbleSort(arrayForBubbleSort, size);
    clock_t endBubble = clock();
    double timeBubble = double(endBubble - startBubble) / CLOCKS_PER_SEC;

    cout << "Время пузырьковой сортировки: " << timeBubble << " секунд" << endl;

    // Сортировка вставками с замером времени
    clock_t startInsertion = clock();
    insertionSort(arrayForInsertionSort, size);
    clock_t endInsertion = clock();
    double timeInsertion = double(endInsertion - startInsertion) / CLOCKS_PER_SEC;

    cout << "Время сортировки вставками: " << timeInsertion << " секунд" << endl;

    // Сравнение времени
    cout << "\nСравнение эффективности сортировок:";
    if (timeBubble < timeInsertion) {
        cout << " Пузырьковая сортировка была быстрее." << endl;
    }
    else if (timeInsertion < timeBubble) {
        cout << " Сортировка вставками была быстрее." << endl;
    }
    else {
        cout << " Обе сортировки заняли одинаковое время." << endl;
    }

    cout << "\n          ЗАДАНИЕ 3.Поиск второй по величине строки в массиве          \n" << endl;

    const int strSize = 5;
    string strArray[strSize] = { "apple", "banana", "cherry", "date", "elderberry" };

    // Решение 1: С использованием сортировки
    string secondLargestSort = findSecondLargestStringSort(strArray, strSize);
    cout << "Вторая по величине строка (сортировка): " << secondLargestSort << endl;

    // Решение 2: Однопроходный алгоритм
    string secondLargestLinear = findSecondLargestStringLinear(strArray, strSize);
    cout << "Вторая по величине строка (линейный поиск): " << secondLargestLinear << endl;

    cout << "\n          ЗАДАНИЕ 3.Проверка на палиндром          \n" << endl;

    // Пример строки для проверки на палиндром
    string testString = "A man, a plan, a canal, Panama";

    // Способ 1: Проверка на палиндром с двумя указателями
    bool resultTwoPointers = isPalindromeTwoPointers(testString);
    cout << "Палиндром (два указателя): " << (resultTwoPointers ? "Yes" : "No") << endl;

    // Способ 2: Проверка на палиндром с использованием очищенной строки
    bool resultCleanString = isPalindromeCleanString(testString);
    cout << "Палиндром (очищенная строка): " << (resultCleanString ? "Yes" : "No") << endl;

    cout << "\n          ЗАДАНИЕ 3. Подсчет уникальных элементов в массиве          \n" << endl;

    // Подсчет уникальных элементов с использованием множества
    int uniqueCountSet = countUniqueElementsUsingSet(hjvf, size);
    cout << "Количество уникальных элементов (с множеством): " << uniqueCountSet << endl;

    // Подсчет уникальных элементов с использованием сортировки
    int uniqueCountSort = countUniqueElementsUsingSort(hjvf, size);
    cout << "Количество уникальных элементов (с сортировкой): " << uniqueCountSort << endl;

    cout << "\n          ЗАДАНИЕ 3. Поиск наименьшего отсутствующего положительного числа          \n" << endl;

    // Входные данные для поиска наименьшего отсутствующего положительного числа
    int arr1[] = { 1, 2, 0, -1, 3 };
    int sizeArr1 = sizeof(arr1) / sizeof(arr1[0]);

    // Поиск с использованием множества
    int missingNumberOptimized = findSmallestMissingPositiveNumberOptimized(arr1, sizeArr1);
    cout << "Наименьшее отсутствующее положительное число (оптимизированное): " << missingNumberOptimized << endl;

    // Поиск с использованием сортировки
    int missingNumberSorted = findSmallestMissingPositiveNumberSorted(arr1, sizeArr1);
    cout << "Наименьшее отсутствующее положительное число (с сортировкой): " << missingNumberSorted << endl;

    return 0;
}
