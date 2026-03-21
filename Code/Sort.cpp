#include "library.h"

// --- Helper Functions ---
void heapify(int a[], int n, int i, int& comp) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ((comp++, left < n) && (comp++, a[left] > a[largest])) {
        largest = left;
    }
    if ((comp++, right < n) && (comp++, a[right] > a[largest])) {
        largest = right;
    }
    if (comp++, largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest, comp);
    }
}

void merge_array(int a[], int left, int mid, int right, int& comp) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; comp++, i < n1; i++) L[i] = a[left + i];
    for (int j = 0; comp++, j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while ((comp++, i < n1) && (comp++, j < n2)) {
        if (comp++, L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (comp++, i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (comp++, j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void merge_sort_rec(int a[], int left, int right, int& comp) {
    if (comp++, left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_rec(a, left, mid, comp);
        merge_sort_rec(a, mid + 1, right, comp);
        merge_array(a, left, mid, right, comp);
    }
}

int partition(int a[], int low, int high, int& comp) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; comp++, j <= high - 1; j++) {
        if (comp++, a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quick_rec(int a[], int low, int high, int& comp) {
    if (comp++, low < high) {
        int pi = partition(a, low, high, comp);
        quick_rec(a, low, pi - 1, comp);
        quick_rec(a, pi + 1, high, comp);
    }
}

int get_max(int a[], int n, int& comp) {
    int max_val = a[0];
    for (int i = 1; comp++, i < n; i++) {
        if (comp++, a[i] > max_val) {
            max_val = a[i];
        }
    }
    return max_val;
}

void count_sort_radix(int a[], int n, int exp, int& comp) {
    int* output = new int[n];
    int count[10] = {0};
    
    for (int i = 0; comp++, i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }
    
    for (int i = 1; comp++, i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; comp++, i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    
    for (int i = 0; comp++, i < n; i++) {
        a[i] = output[i];
    }
    delete[] output;
}

// --- Main Sorting Functions ---

int selection(int a[], int n, int mode) {
    cout << "Algorithm: Selection Sort" << (mode ? " | " : "\n");
    int comp = 0;
    for (int i = 0; comp++, i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; comp++, j < n; j++) {
            if (comp++, a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (comp++, min_idx != i) {
            swap(a[i], a[min_idx]);
        }
    }
    return comp;
}

int insertion(int a[], int n, int mode) {
    cout << "Algorithm: Insertion Sort" << (mode ? " | " : "\n");
    int comp = 0;
    for (int i = 1; comp++, i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while ((comp++, j >= 0) && (comp++, a[j] > key)) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    return comp;
}

int bin_insertion(int a[], int n, int mode) {
    cout << "Algorithm: Binary Insertion Sort" << (mode ? " | " : "\n");
    int comp = 0;
    for (int i = 1; comp++, i < n; i++) {
        int key = a[i];
        int left = 0, right = i - 1;
        while (comp++, left <= right) {
            int mid = left + (right - left) / 2;
            if (comp++, a[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        for (int j = i - 1; comp++, j >= left; j--) {
            a[j + 1] = a[j];
        }
        a[left] = key;
    }
    return comp;
}

int bubble(int a[], int n, int mode) {
    cout << "Algorithm: Bubble Sort" << (mode ? " | " : "\n");
    int comp = 0;
    for (int i = 0; comp++, i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; comp++, j < n - i - 1; j++) {
            if (comp++, a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (comp++, !swapped) break;
    }
    return comp;
}

int shaker(int a[], int n, int mode) {
    cout << "Algorithm: Shaker Sort" << (mode ? " | " : "\n");
    int comp = 0;
    int left = 0;
    int right = n - 1;
    int k = 0;
    while (comp++, left < right) {
        bool swapped = false;
        for (int i = left; comp++, i < right; i++) {
            if (comp++, a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
                k = i;
            }
        }
        if (comp++, !swapped) break;
        right = k;
        swapped = false;
        for (int i = right; comp++, i > left; i--) {
            if (comp++, a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                swapped = true;
                k = i;
            }
        }
        if (comp++, !swapped) break;
        left = k;
    }
    return comp;
}

int shell(int a[], int n, int mode) {
    cout << "Algorithm: Shell Sort" << (mode ? " | " : "\n");
    int comp = 0;
    for (int gap = n / 2; comp++, gap > 0; gap /= 2) {
        for (int i = gap; comp++, i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; (comp++, j >= gap) && (comp++, a[j - gap] > temp); j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
    return comp;
}

int heap(int a[], int n, int mode) {
    cout << "Algorithm: Heap Sort" << (mode ? " | " : "\n");
    int comp = 0;
    for (int i = n / 2 - 1; comp++, i >= 0; i--) {
        heapify(a, n, i, comp);
    }
    for (int i = n - 1; comp++, i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, comp);
    }
    return comp;
}

int merge(int a[], int n, int mode) {
    cout << "Algorithm: Merge Sort" << (mode ? " | " : "\n");
    int comp = 0;
    merge_sort_rec(a, 0, n - 1, comp);
    return comp;
}

int quick(int a[], int n, int mode) {
    cout << "Algorithm: Quick Sort" << (mode ? " | " : "\n");
    int comp = 0;
    quick_rec(a, 0, n - 1, comp);
    return comp;
}

int counting(int a[], int n, int mode) {
    cout << "Algorithm: Counting Sort" << (mode ? " | " : "\n");
    int comp = 0;
    if (comp++, n <= 1) return comp;
    
    int max_val = a[0];
    for (int i = 1; comp++, i < n; i++) {
        if (comp++, a[i] > max_val) {
            max_val = a[i];
        }
    }
    
    int* count = new int[max_val + 1]();
    int* output = new int[n];
    
    for (int i = 0; comp++, i < n; i++) {
        count[a[i]]++;
    }
    
    for (int i = 1; comp++, i <= max_val; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; comp++, i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    
    for (int i = 0; comp++, i < n; i++) {
        a[i] = output[i];
    }
    
    delete[] count;
    delete[] output;
    return comp;
}

int radix(int a[], int n, int mode) {
    cout << "Algorithm: Radix Sort" << (mode ? " | " : "\n");
    int comp = 0;
    if (comp++, n <= 0) return comp;
    int max_val = get_max(a, n, comp);
    for (int exp = 1; comp++, max_val / exp > 0; exp *= 10) {
        count_sort_radix(a, n, exp, comp);
    }
    return comp;
}

int flash(int a[], int n, int mode) {
    cout << "Algorithm: Flash Sort" << (mode ? " | " : "\n");
    int comp = 0;
    if (comp++, n <= 1) return comp;
    
    int m = (int)(0.45 * n);
    if (comp++, m < 1) m = 1;
    
    int* L = new int[m]();
    int min_val = a[0], max_idx = 0;
    
    for (int i = 1; comp++, i < n; i++) {
        if (comp++, a[i] < min_val) {
            min_val = a[i];
        }
        if (comp++, a[i] > a[max_idx]) {
            max_idx = i;
        }
    }
    
    if (comp++, min_val == a[max_idx]) {
        delete[] L;
        return comp;
    }
    
    double c1 = (double)(m - 1) / (a[max_idx] - min_val);
    
    for (int i = 0; comp++, i < n; i++) {
        int k = (int)(c1 * (a[i] - min_val));
        L[k]++;
    }
    
    for (int k = 1; comp++, k < m; k++) {
        L[k] += L[k - 1];
    }
    
    swap(a[max_idx], a[0]);
    
    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int flash_val;
    
    while (comp++, nmove < n - 1) {
        while (comp++, j > L[k] - 1) {
            j++;
            k = (int)(c1 * (a[j] - min_val));
        }
        
        flash_val = a[j];
        if (comp++, k < 0) break;
        
        while (comp++, j != L[k]) {
            k = (int)(c1 * (flash_val - min_val));
            int hold = a[L[k] - 1];
            a[L[k] - 1] = flash_val;
            flash_val = hold;
            L[k]--;
            nmove++;
        }
    }
    
    for (int i = 1; comp++, i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while ((comp++, j >= 0) && (comp++, a[j] > key)) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    
    delete[] L;
    return comp;
}