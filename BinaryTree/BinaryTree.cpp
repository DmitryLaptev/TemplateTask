// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;
template <class T>
BinaryTree<T>* Create(T val, BinaryTree<T>* l = NULL, BinaryTree<T>* r = NULL) {
	BinaryTree<T>* tree;
	tree = new BinaryTree<T>(val, l, r);
	if (tree == NULL) {
		cout << "Error" << endl;
		return;
	}
	return tree;
}
template <class T>
void Order(BinaryTree<T>* tree, void visit(T& val)) {
	if (tree != NULL) {
		Order(tree->Left(), visit);
		visit(tree->value);
		Order(tree->Right(), visit);
	}
}
template <class T>
BinaryTree<T>* SearchTree<T>::SearchNode(const T& val, BinaryTree<T>*& parent) const {
	BinaryTree<T>* tree = root;
	parent = NULL;
	while (tree != NULL) {
		if (val == tree->value) break;
		else {
			parent = tree;
			if (val < tree->value) tree = tree->left;
			else tree = tree->right;
		}
	}
	return tree;
}
template <class T>
int SearchTree<T>::Search(T& val) {
	BinaryTree<T>* parent;
	node = SearchNode(val, parent);
	if (node != NULL) {
		val = node->value;
		return true;
	}
	else return false;
}
template <class T>
void SearchTree<T>::Insert(const T& val) {
	BinaryTree<T>* tree = root,parent = NULL,*Node;
	while (tree != NULL) {
		parent = tree;
		if (val < tree->value) tree = tree->left;
		else tree = tree->right;
	}
	if (parent == NULL) root = Node;
	else if (val < parent->value) parent->left = Node;
	else parent->right = Node;
	node = Node;
	count++;
}
template <class T>
void FreeTree(BinaryTree<T>* tree) {
	delete tree;
}
template <class T>
void SearchTree<T>::Delete(const T& val) {
	BinaryTree<T>* parent, * child1, * child2;
	if ((child1 = SearchNode(val, parent)) == NULL) return;
	if (child1->right == NULL) child2 = child1->left;
	else if (child1->left == NULL) child2 = child1->right;
	else {
		BinaryTree<T>* parentOfSon = child1;
		child2 = child1->left;
		while (child2->right != NULL) {
			parentOfSon = child2;
			child2 = child2->right;
		}
		if (parentOfSon == child1) child2->right = child1->right;
		else parentOfSon->right = child2->left;
	}
	if (child2 == NULL) root = child2;
	else if (child1->value < parent->value) parent->left = child2;
	else parent->right = child2;
	FreeTree(child1);
	count--;
}
template <class T>
void leafList(SearchTree<T>* tree) {
	if (tree->left == nullptr && tree->right == nullptr) cout << tree->value << endl;
	else {
		if (tree->left) leafList(tree->left);
		if (tree->right) leafList(tree->right);
	}
}
int main()
{

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
