using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Week10
{
    public class BinaryTree<T> where T : IComparable<T>
    {
        private BinaryTree<T> root, left, right;
        private T value;
        private List<T> listforPrint = new List<T>();

        public BinaryTree(T value, BinaryTree<T> root)
        {
            this.value = value;
            this.root = root;
        }

        public void Add(T value)
        {
            if (value.CompareTo(this.value) < 0)
            {
                if (left == null) left = new BinaryTree<T>(value, this);
                else left.Add(value);
            }
            else
            {
                if (right == null) right = new BinaryTree<T>(value, this);
                else right.Add(value);
            }
        }

        private BinaryTree<T> Search(BinaryTree<T> tree, T value)
        {
            if (tree == null) return null;
            switch (value.CompareTo(tree.value))
            {
                case 1: return Search(tree.right, value);
                case -1: return Search(tree.left, value);
                case 0: return tree;
                default: return null;
            }
        }

        public BinaryTree<T> Search(T value) => Search(this, value);
        public bool Delete(T value)
        {
            //Проверяем, существует ли данный узел
            BinaryTree<T> tree = Search(value);
            if (tree == null) return false; //Если узла не существует, вернем false
            BinaryTree<T> currentNode;
            //Если удаляем корень
            if (tree == this)
            {
                if (tree.right != null) currentNode = tree.right;
                else currentNode = tree.left;
                while (currentNode.left != null) currentNode = currentNode.left;
                T temp = currentNode.value;
                this.Delete(temp);
                tree.value = temp;
                return true;
            }

            //Удаление листьев
            if (tree.left == null && tree.right == null && tree.root != null)
            {
                if (tree == tree.root.left) tree.root.left = null;
                else tree.root.right = null;
                return true;
            }
            //Удаление узла, имеющего левое поддерево, но не имеющее правого поддерева
            if (tree.left != null && tree.right == null)
            {
                //Меняем родителя
                tree.left.root = tree.root;
                if (tree == tree.root.left) tree.root.left = tree.left;
                else if (tree == tree.root.right)
                {
                    tree.root.right = tree.left;
                }
                return true;
            }

            //Удаление узла, имеющего правое поддерево, но не имеющее левого поддерева
            if (tree.left == null && tree.right != null)
            {
                //Меняем родителя
                tree.right.root = tree.root;
                if (tree == tree.root.left) tree.root.left = tree.right;
                else tree.root.right = tree.right;
                return true;
            }

            //Удаляем узел, имеющий поддеревья с обеих сторон
            if (tree.right != null && tree.left != null)
            {
                currentNode = tree.right;
                while (currentNode.left != null) currentNode = currentNode.left;
                //Если самый левый элемент является первым потомком
                if (currentNode.root == tree)
                {
                    currentNode.left = tree.left;
                    tree.left.root = currentNode;
                    currentNode.root = tree.root;
                    if (tree == tree.root.left) tree.root.left = currentNode;
                    else tree.root.right = currentNode;
                    return true;
                }
                //Если самый левый элемент НЕ является первым потомком
                else
                {
                    if (currentNode.right != null) currentNode.right.root = currentNode.root;
                    currentNode.root.left = currentNode.right;
                    currentNode.right = tree.right;
                    currentNode.left = tree.left;
                    tree.left.root = currentNode;
                    tree.right.root = currentNode;
                    currentNode.root = tree.root;
                    if (tree == tree.root.left) tree.root.left = currentNode;
                    else tree.root.right = currentNode;
                    return true;
                }
            }
            return false;
        }

        private void Print(BinaryTree<T> node)
        {
            if (node == null) return;
            Print(node.left);
            listforPrint.Add(node.value);
            Console.Write(node + " ");
            if (node.right != null) Print(node.right);
        }
        public void Print()
        {
            listforPrint.Clear();
            Print(this);
            Console.WriteLine();
        }

        public override string ToString() => value.ToString();
    }
}
