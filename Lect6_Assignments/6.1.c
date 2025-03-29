#include <iostream>
using namespace std;


struct Node {
    int data; // Giá trị của node
    Node* left; // Con trỏ trỏ đến node con bên trái
    Node* right; // Con trỏ trỏ đến node con bên phải

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


class BST {
public:
    Node* root; // Con trỏ gốc của cây BST

    BST() : root(nullptr) {}

    // Hàm chèn một giá trị vào cây BST
    Node* insert(Node* node, int val) {
        if (!node) return new Node(val); // Nếu vị trí cần chèn trống, tạo node mới
        if (val < node->data) // Nếu giá trị nhỏ hơn node hiện tại, chèn vào bên trái
            node->left = insert(node->left, val);
        else // Nếu giá trị lớn hơn hoặc bằng, chèn vào bên phải
            node->right = insert(node->right, val);
        return node;
    }

    // Hàm tìm node có giá trị nhỏ nhất trong cây con
    Node* findMin(Node* node) {
        while (node && node->left) node = node->left; // Duyệt về bên trái đến node nhỏ nhất
        return node; // Trả về node có giá trị nhỏ nhất
    }

    // Hàm xóa một giá trị khỏi cây BST
    Node* remove(Node* node, int val) {
        if (!node) return node; // Nếu node rỗng, trả về luôn

        if (val < node->data) // Nếu giá trị cần xóa nhỏ hơn node hiện tại, tìm ở cây con bên trái
            node->left = remove(node->left, val);
        else if (val > node->data) // Nếu giá trị cần xóa lớn hơn, tìm ở cây con bên phải
            node->right = remove(node->right, val);
        else {
            // Trường hợp node có một hoặc không có con
            if (!node->left) {
                Node* tmp = node->right; // Lưu con phải (có thể là nullptr)
                delete node; // Xóa node hiện tại
                return tmp; // Trả về con phải để thay thế
            } else if (!node->right) {
                Node* tmp = node->left; // Lưu con trái
                delete node; // Xóa node hiện tại
                return tmp; // Trả về con trái để thay thế
            }
            // Trường hợp node có hai con
            Node* tmp = findMin(node->right); // Tìm node nhỏ nhất bên phải
            node->data = tmp->data; // Gán giá trị nhỏ nhất vào node hiện tại
            node->right = remove(node->right, tmp->data); // Xóa node nhỏ nhất bên phải
        }
        return node; // Trả về node sau khi cập nhật
    }

    // Hàm duyệt cây theo thứ tự trước (Preorder Traversal)
    void preorder(Node* node) {
        if (!node) return; // Nếu node rỗng, kết thúc
        cout << node->data << " "; // In giá trị node hiện tại
        preorder(node->left); // Duyệt cây con trái
        preorder(node->right); // Duyệt cây con phải
    }
};

int main() {
    BST tree; // Khởi tạo cây BST
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20}; // Mảng giá trị ban đầu

    // Chèn từng giá trị vào BST
    for (int val : values) tree.root = tree.insert(tree.root, val);

    cout << "BST ban dau: ";
    tree.preorder(tree.root); // In cây theo thứ tự trước
    cout << endl;

    int new_values[] = {14, 0, 35}; // Mảng giá trị cần chèn thêm
    for (int val : new_values) tree.root = tree.insert(tree.root, val);

    cout << "BST sau khi chen 14, 0, 35: ";
    tree.preorder(tree.root);
    cout << endl;

    int delete_values[] = {6, 13, 35}; // Mảng giá trị cần xóa
    for (int val : delete_values) tree.root = tree.remove(tree.root, val);

    cout << "BST sau khi xoa 6, 13, 35: ";
    tree.preorder(tree.root);
    cout << endl;

    return 0;
}
