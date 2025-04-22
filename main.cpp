#include <iostream>
#include <windows.h>
using namespace std;

// Структура вузла бінарного дерева
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Клас бінарного дерева
class BinaryTree {
private:
    Node* root;

    // Функція додавання елементів у дерево\\Допоміжна рекурсивна функція вставки
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->value)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    // Префіксний обхід та підрахунок суми
    int preOrderSum(Node* node) {
        if (!node) return 0;
        cout << "Відвідано вузол з значенням: " << node->value << endl;
        return node->value + preOrderSum(node->left) + preOrderSum(node->right);
    }

    // Вивід дерева у префіксному порядку
    void display(Node* node) {
        if (!node) return;
        cout << node->value << " ";
        display(node->left);
        display(node->right);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    int calculateSum() {
        cout << "Починаємо префіксний обхід для обчислення суми:\n";
        return preOrderSum(root);
    }

    void display() {
        cout << "Префіксний обхід дерева: ";
        display(root);
        cout << endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    BinaryTree tree;

    // Наповнення дерева значеннями
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    tree.display(); // Виведення стану дерева

    int sum = tree.calculateSum(); // Підрахунок суми
    cout << "Сума всіх значень у дереві: " << sum << endl;

    return 0;
}



