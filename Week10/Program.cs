using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Week10
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTree<int> root = null;
            BinaryTree<int> Btree=new BinaryTree<int>(21,root);
            Btree.Add(52);
            Btree.Add(23);
            Btree.Print();
            Console.WriteLine(Btree.Search(23));
            Btree.Delete(52);
            Btree.Print();
            Console.ReadKey();
        }
    }
}
