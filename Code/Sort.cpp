#include "library.h"

// 1. Selection Sort
int selection(int a[], int n) {
    int comp = 0;
    for (int i = 0; ++comp && i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; ++comp && j < n; j++) {
            if (++comp && a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) swap(a[i], a[min_idx]);
    }
    return comp;
}

// 2. Insertion Sort
int insertion(int a[], int n) {
    int comp = 0;
    for (int i = 1; ++comp && i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (++comp && j >= 0 && ++comp && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    return comp;
}

// 3. Binary Insertion Sort
int bin_insertion(int a[], int n) {
    int comp = 0;
    for (int i = 1; ++comp && i < n; i++) {
        int key = a[i];
        int left = 0, right = i - 1;
        while (++comp && left <= right) {
            int mid = left + (right - left) / 2;
            if (++comp && a[mid] > key) right = mid - 1;
            else left = mid + 1;
        }
        for (int j = i - 1; ++comp && j >= left; j--) {
            a[j + 1] = a[j];
        }
        a[left] = key;
    }
    return comp;
}

// 4. Bubble Sort
int bubble(int a[], int n) {
    int comp = 0;
    bool swapped;
    for (int i = 0; ++comp && i < n - 1; i++) {
        swapped = false;
        for (int j = 0; ++comp && j < n - i - 1; j++) {
            if (++comp && a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (++comp && !swapped) break;
    }
    return comp;
}

// 5. Shaker Sort
int shaker(int a[], int n) {
    int comp = 0;
    bool swapped = true;
    int start = 0, end = n - 1;
    while (++comp && swapped) {
        swapped = false;
        for (int i = start; ++comp && i < end; ++i) {
            if (++comp && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (++comp && !swapped) break;
        swapped = false;
        --end;
        for (int i = end - 1; ++comp && i >= start; --i) {
            if (++comp && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
    return comp;
}

// 6. Shell Sort
int shell(int a[], int n) {
    int comp = 0;
    for (int gap = n / 2; ++comp && gap > 0; gap /= 2) {
        for (int i = gap; ++comp && i < n; i += 1) {
            int temp = a[i];
            int j;
            for (j = i; ++comp && j >= gap && ++comp && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
    return comp;
}

// 7. Heap Sort
void heapify(int a[], int n, int i, int& comp) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (++comp && l < n && ++comp && a[l] > a[largest]) largest = l;
    if (++comp && r < n && ++comp && a[r] > a[largest]) largest = r;
    if (++comp && largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest, comp);
    }
}
int heap(int a[], int n) {
    int comp = 0;
    for (int i = n / 2 - 1; ++comp && i >= 0; i--) heapify(a, n, i, comp);
    for (int i = n - 1; ++comp && i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, comp);
    }
    return comp;
}

// 8. Merge Sort
void merge_helper(int a[], int l, int m, int r, int& comp) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; ++comp && i < n1; i++) L[i] = a[l + i];
    for (int j = 0; ++comp && j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (++comp && i < n1 && ++comp && j < n2) {
        if (++comp && L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (++comp && i < n1) {
        a[k] = L[i];
        i++; k++;
    }
    while (++comp && j < n2) {
        a[k] = R[j];
        j++; k++;
    }
    delete[] L; delete[] R;
}
void merge_sort(int a[], int l, int r, int& comp) {
    if (++comp && l >= r) return;
    int m = l + (r - l) / 2;
    merge_sort(a, l, m, comp);
    merge_sort(a, m + 1, r, comp);
    merge_helper(a, l, m, r, comp);
}
int Merge(int a[], int n) {
    int comp = 0;
    merge_sort(a, 0, n - 1, comp);
    return comp;
}

// 9. Quick Sort
int partition(int a[], int low, int high, int& comp) {
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; ++comp && j <= high - 1; j++) {
        if (++comp && a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}
void quick_sort(int a[], int low, int high, int& comp) {
    if (++comp && low < high) {
        int pi = partition(a, low, high, comp);
        quick_sort(a, low, pi - 1, comp);
        quick_sort(a, pi + 1, high, comp);
    }
}
int quick(int a[], int n) {
    int comp = 0;
    quick_sort(a, 0, n - 1, comp);
    return comp;
}

// 10. Counting Sort
int counting(int a[], int n) {
    int comp = 0;
    if (++comp && n <= 1) return comp;
    int max_val = a[0];
    for (int i = 1; ++comp && i < n; i++) {
        if (++comp && a[i] > max_val) max_val = a[i];
    }
    int* count = new int[max_val + 1]{0};
    int* output = new int[n];
    for (int i = 0; ++comp && i < n; i++) count[a[i]]++;
    for (int i = 1; ++comp && i <= max_val; i++) count[i] += count[i - 1];
    for (int i = n - 1; ++comp && i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for (int i = 0; ++comp && i < n; i++) a[i] = output[i];
    delete[] count; delete[] output;
    return comp;
}

// 11. Radix Sort
int getMax(int a[], int n, int& comp) {
    int mx = a[0];
    for (int i = 1; ++comp && i < n; i++)
        if (++comp && a[i] > mx) mx = a[i];
    return mx;
}
void countSortForRadix(int a[], int n, int exp, int& comp) {
    int* output = new int[n];
    int i, count[10] = { 0 };
    for (i = 0; ++comp && i < n; i++) count[(a[i] / exp) % 10]++;
    for (i = 1; ++comp && i < 10; i++) count[i] += count[i - 1];
    for (i = n - 1; ++comp && i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (i = 0; ++comp && i < n; i++) a[i] = output[i];
    delete[] output;
}
int radix(int a[], int n) {
    int comp = 0;
    int m = getMax(a, n, comp);
    for (int exp = 1; ++comp && m / exp > 0; exp *= 10) {
        countSortForRadix(a, n, exp, comp);
    }
    return comp;
}

// 12. Flash Sort
int flash(int a[], int n) {
    int comp = 0;
    if (++comp && n <= 1) return comp;
    int minVal = a[0], maxIdx = 0;
    for (int i = 1; ++comp && i < n; ++i) {
        if (++comp && a[i] < minVal) minVal = a[i];
        if (++comp && a[i] > a[maxIdx]) maxIdx = i;
    }
    if (++comp && a[maxIdx] == minVal) return comp;
    int m = int(0.45 * n);
    int* l = new int[m]{0};
    double c1 = (double)(m - 1) / (a[maxIdx] - minVal);
    for (int i = 0; ++comp && i < n; ++i) {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    for (int i = 1; ++comp && i < m; ++i) l[i] += l[i - 1];
    swap(a[maxIdx], a[0]);
    int nmove = 0, j = 0, k = m - 1, flash;
    while (++comp && nmove < n - 1) {
        while (++comp && j > l[k] - 1) {
            ++j;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (++comp && k < 0) break;
        while (++comp && j != l[k]) {
            k = int(c1 * (flash - minVal));
            int hold = a[l[k] - 1];
            a[l[k] - 1] = flash;
            flash = hold;
            --l[k];
            ++nmove;
        }
    }
    delete[] l;
    for (int i = 1; ++comp && i < n; ++i) {
        int key = a[i], p = i - 1;
        while (++comp && p >= 0 && ++comp && a[p] > key) {
            a[p + 1] = a[p];
            p--;
        }
        a[p + 1] = key;
    }
    return comp;
}