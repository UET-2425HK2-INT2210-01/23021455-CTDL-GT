#include <iostream>
using namespace std;

const int MAX_NODES = 100; // Giới hạn số lượng nút trong cây

struct TreeNode {
    int value; // Giá trị của nút
    TreeNode* firstChild; // Con đầu tiên
    TreeNode* nextSibling; // Anh chị em kế tiếp

    TreeNode(int val) { // Constructor
        value = val;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};

class Tree {
private:
    TreeNode* root; // Gốc của cây
    TreeNode* nodeArray[MAX_NODES]; // Mảng lưu các con trỏ đến các nút
    bool hasParent[MAX_NODES]; // Đánh dấu xem một nút có cha hay không

public:
    Tree() {
        root = nullptr;
        for (int i = 0; i < MAX_NODES; i++) {
            hasParent[i] = false; // Ban đầu, tất cả các nút không có cha
            nodeArray[i] = nullptr; // Khởi tạo danh sách nút là nullptr
        }
    }

    void addNode(int parentVal, int childVal) {
        if (parentVal == childVal) { // Kiểm tra điều kiện không hợp lệ
            cout << "Lỗi: Cha và con không thể trùng nhau!\n";
            return;
        }
        if (!nodeArray[parentVal]) { // Nếu nút cha chưa tồn tại, tạo mới
            nodeArray[parentVal] = new TreeNode(parentVal);
        }
        if (!nodeArray[childVal]) { // Nếu nút con chưa tồn tại, tạo mới
            nodeArray[childVal] = new TreeNode(childVal);
        }
        TreeNode* parent = nodeArray[parentVal];
        TreeNode* child = nodeArray[childVal];

        if (!parent->firstChild) { // Nếu cha chưa có con, gán con đầu tiên
            parent->firstChild = child;
        } else { // Nếu cha đã có con, tìm đến anh chị em cuối cùng rồi thêm vào
            TreeNode* temp = parent->firstChild;
            while (temp->nextSibling) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = child;
        }
        hasParent[childVal] = true; // Đánh dấu nút con này có cha
    }

    void findRoot(int numNodes) { // Tìm gốc của cây
        for (int i = 1; i <= numNodes; i++) {
            if (!hasParent[i] && nodeArray[i]) { // Nếu nút không có cha
                root = nodeArray[i];
                return;
            }
        }
        root = nullptr; // Nếu không tìm thấy gốc
    }

    int getTreeHeight(TreeNode* node) { // Tính chiều cao của cây
        if (!node) return -1; // Cây rỗng
        int maxHeight = -1;
        TreeNode* temp = node->firstChild;
        while (temp) {
            maxHeight = max(maxHeight, getTreeHeight(temp)); // Tính chiều cao lớn nhất của các nhánh con
            temp = temp->nextSibling;
        }
        return maxHeight + 1; // Chiều cao của nút hiện tại
    }

    void preorderTraversal(TreeNode* node) { // Duyệt cây theo thứ tự trước
        if (!node) return;
        cout << node->value << " ";
        TreeNode* temp = node->firstChild;
        while (temp) {
            preorderTraversal(temp);
            temp = temp->nextSibling;
        }
    }

    void postorderTraversal(TreeNode* node) { // Duyệt cây theo thứ tự sau
        if (!node) return;
        TreeNode* temp = node->firstChild;
        while (temp) {
            postorderTraversal(temp);
            temp = temp->nextSibling;
        }
        cout << node->value << " ";
    }

    bool isBinaryTree(TreeNode* node) { // Kiểm tra cây nhị phân
        if (!node) return true;
        int childCount = 0;
        TreeNode* temp = node->firstChild;
        while (temp) {
            childCount++;
            temp = temp->nextSibling;
        }
        if (childCount > 2) return false; // Nếu một nút có nhiều hơn 2 con thì không phải cây nhị phân
        temp = node->firstChild;
        while (temp) {
            if (!isBinaryTree(temp)) return false;
            temp = temp->nextSibling;
        }
        return true;
    }

    void inorderTraversal(TreeNode* node) { // Duyệt cây theo thứ tự trung
        if (!node) return;
        if (!isBinaryTree(node)) {
            cout << "NOT BINARY TREE" << endl;
            return;
        }
        TreeNode* left = node->firstChild;
        TreeNode* right = (left) ? left->nextSibling : nullptr;
        inorderTraversal(left);
        cout << node->value << " ";
        inorderTraversal(right);
    }

    void traverseTree(int numNodes) { // Điều khiển quá trình duyệt cây
        findRoot(numNodes);
        if (!root) {
            cout << "Không tìm thấy gốc!\n";
            return;
        }
        cout << getTreeHeight(root) << endl;
        preorderTraversal(root); cout << endl;
        postorderTraversal(root); cout << endl;
        inorderTraversal(root); cout << endl;
    }
};

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    Tree tree;
    for (int i = 0; i < numEdges; i++) {
        int parent, child;
        cin >> parent >> child;
        tree.addNode(parent, child);
    }
    tree.traverseTree(numNodes);
    return 0;
}
