#include <bits/stdc++.h>
using namespace std;


class MinHeap {
private:
    vector<int> heap; // Vector lưu trữ các phần tử của heap
    int maxSize;      // Số phần tử tối đa mà heap có thể chứa
    int size;         // Số phần tử hiện tại trong heap

    // Lấy chỉ mục của cha của phần tử tại vị trí i
    int getParentID(int i) {
        return (i - 1) / 2;
    }

    // Lấy chỉ mục của con trái của phần tử tại vị trí i
    int getLeftChildID(int i) {
        return 2 * i + 1;
    }

    // Lấy chỉ mục của con phải của phần tử tại vị trí i
    int getRightChildID(int i) {
        return 2 * i + 2;
    }

    // Hoán đổi giá trị của hai phần tử
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // Điều chỉnh heap sau khi thêm phần tử (heapify up)
    void heapifyUp(int i) {
        while (i > 0 && heap[getParentID(i)] > heap[i]) {
            swap(heap[getParentID(i)], heap[i]);
            i = getParentID(i); // Di chuyển lên trên cây
        }
    }

    // Điều chỉnh heap sau khi xóa phần tử (heapify down)
    void heapifyDown(int i) {
        int left = getLeftChildID(i);
        int right = getRightChildID(i);
        int smallest = i;

        // Kiểm tra nếu con trái nhỏ hơn phần tử hiện tại
        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        // Kiểm tra nếu con phải nhỏ hơn phần tử hiện tại
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        // Nếu phần tử nhỏ nhất không phải là phần tử ban đầu, hoán đổi và đệ quy
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Tạo Heap
    MinHeap(int capacity) {
        maxSize = capacity;
        size = 0;
    }

    // Chèn một phần tử vào heap
    void insert(int val) {
        if (size >= maxSize) {
            cout << "Heap is full!" << endl;
            return;
        }
        heap.push_back(val);
        size++;
        heapifyUp(size - 1); // Điều chỉnh lại heap
    }

    // Xóa một phần tử khỏi heap
    void remove(int val) {
        auto it = find(heap.begin(), heap.end(), val); // Tìm vị trí của phần tử cần xóa
        if (it != heap.end()) {
            int index = distance(heap.begin(), it);
            heap[index] = heap.back(); // Đưa phần tử cuối lên vị trí cần xóa
            heap.pop_back();           // Xóa phần tử cuối cùng
            size--;
            heapifyDown(index); // Điều chỉnh lại heap
        }
    }


    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap heap(20); // Tạo một heap có tối đa 20 phần tử
    vector<int> values = {2, 1, 10, 6, 3, 8, 7, 13, 20};

    // Chèn các phần tử ban đầu vào heap
    for (int val : values) heap.insert(val);

    cout << "Min Heap ban dau: ";
    heap.printHeap();

    // Thêm các phần tử mới vào heap
    vector<int> new_values = {14, 0, 35};
    for (int val : new_values) heap.insert(val);
    cout << "Min Heap sau khi chen 14, 0, 35: ";
    heap.printHeap();

    // Xóa một số phần tử khỏi heap
    vector<int> delete_values = {6, 13, 35};
    for (int val : delete_values) heap.remove(val);
    cout << "Min Heap sau khi xoa 6, 13, 35: ";
    heap.printHeap();

    return 0;
}

