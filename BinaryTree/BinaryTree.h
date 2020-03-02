#pragma once
template<class T>
class SearchTree;
template<class T>
class BinaryTree {
private:
	BinaryTree<T>* left;
	BinaryTree<T>* right;
public:
	T value;
	BinaryTree(const T& val, BinaryTree<T>* l, BinaryTree<T>* r) : value(val), left(l), right(r) {}
	BinaryTree<T>* Left(void)const;
	BinaryTree<T>* Right(void)const;
	BinaryTree<T>* Create(T, BinaryTree<T>*, BinaryTree<T>);
	void Order(BinaryTree<T>*, void visit(T&));
	friend class SearchTree<T*>;
};
template <class T>
class SearchTree {
protected:
	BinaryTree<T>* root;
	BinaryTree<T>* node;
	int count;
	BinaryTree<T>* SearchNode(const T&, BinaryTree<T>*&) const;
public:
	SearchTree(void);
	SearchTree(const SearchTree<T>& tree);
	~SearchTree(void);
	int Search(T&);
	void FreeTree(BinaryTree<T>*);
	void Insert(const T&);
	void Delete(const T&);
	void leafList(BinaryTree<T>*);

};
