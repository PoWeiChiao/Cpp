#include <iostream>
#include <vector>

using namespace std;

class Sort {
private:
void Swap(vector<int>& vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
};

int Partition(vector<int>& vec, int front, int end) {
    int pivot = vec[end];
    int i = front - 1;
    for (int j = front; j < end; ++j) {
        if (vec[j] < pivot) {
            i++;
            Swap(vec, i, j);
        }
    }
    i++;
    Swap(vec, i, end);
    return i;
};

void Merge(vector<int>& vec, int front, int mid, int end) {
    vector<int> left(vec.begin() + front, vec.begin() + mid + 1);
    vector<int> right(vec.begin() + mid + 1, vec.begin() + end + 1);

    left.push_back(INT_MAX);
    right.push_back(INT_MAX);

    int leftIdx = 0;
    int rightIdx = 0;
    for (int i = front; i <= end; ++i) {
        if (left[leftIdx] <= right[rightIdx]) {
            vec[i] = left[leftIdx];
            leftIdx++;
        } else {
            vec[i] = right[rightIdx];
            rightIdx++;
        }
    }
};

public:
    Sort() {};

    ~Sort() {};

    void InsertionSort(vector<int>& vec) {
        if (vec.empty()) return;
        if (vec.size() == 1) return;
        for (int i = 1; i < vec.size(); ++i) {
            int idx = i - 1;
            int temp = vec[i];
            while (idx >= 0 && vec[idx] > temp) {
                vec[idx + 1] = vec[idx];
                idx--;
            }
            vec[idx + 1] = temp;
        }
    };

    void QuickSort(vector<int>& vec, int front, int end) {
        if (front < end) {
            int pivot = Partition(vec, front, end);
            QuickSort(vec, front, pivot - 1);
            QuickSort(vec, pivot + 1, end);
        }
    };

    void MergeSort(vector<int>& vec, int front, int end) {
        if (front < end) {
            int mid = (front + end) / 2;
            MergeSort(vec, front, mid);
            MergeSort(vec, mid + 1, end);
            Merge(vec, front, mid, end);
        }
    };
};

int main() {
    vector<int> vec = { -1, 2, -3, 5, 7, 1, 2, 0 };
    Sort s;
    s.MergeSort(vec, 0, vec.size() - 1);
    for (auto &v : vec) cout << v << endl;
    return 0;
}