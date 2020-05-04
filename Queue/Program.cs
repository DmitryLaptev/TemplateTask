using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Queue
{
    class Program
    {
        static void Main(string[] args)
        {
            Queue<int> q = new Queue<int>(6);
            Queue<int> q1 = new Queue<int>(6);
            q.Push(7);
            q1.Push(13);
            q.Push(15);
            q1.Push(25);
            q.Push(56);
            q.Print();
            q1.Print();
            q.Pop();
            q.Print();
            Queue<int> qUnion = new Queue<int>(12);
            qUnion = qUnion.Union(q, q1);
            qUnion.Print();
            Console.ReadKey();
        }
    }
}
