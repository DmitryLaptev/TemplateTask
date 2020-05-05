using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Queue
{
    public class Queue<T>
    {
        private T[] Ptr;
        private int Size;
        private int Head;
        private int Tail;
        private int Count;
        public Queue(int Size)
        {
            this.Size = Size;
            Ptr = new T[Size];
            Head = 0;
            Tail = -1;
            Count = 0;
        }
        public Queue(ref Queue<T> q)
        {
            Size = q.Size;
            Ptr = new T[Size];
            q.Ptr.CopyTo(this.Ptr, Size + q.Size);
            Head = q.Head;
            Tail = q.Tail;
            Count = q.Count;
        }
        public bool IsFull()
        {
            if (Count == Size) return true;
            else return false;
        }
        public void Push(T value)
        {
            if (!IsFull())
            {
                Tail++;
                Count++;
                Ptr[Tail] = value;
            }
            else throw new ArgumentException("Queue is Full");
        }
        public bool IsEmpty()
        {
            if (Tail == 0) return true;
            else return false;
        }
        public T Pop()
        {
            if (!IsEmpty())
            {
                Head++;
                Count--;
                return Ptr[Head];
            }
            else throw new ArgumentException("Queue is Empty");
        }
        public static Queue<T> Union(Queue<T> q1, Queue<T> q2)
        {
            Queue<T> q3 = new Queue<T>(q1.Size + q2.Size);
            int CountQ = 0, ind = q1.Head;
            while (CountQ < q1.Count)
            {
                q3.Push(q1.Ptr[ind]);
                ++CountQ;
                ind++;
                ind %= q1.Size;
            }
            ind = q2.Head;
            CountQ = 0;
            while (CountQ < q2.Count)
            {
                q3.Push(q2.Ptr[ind]);
                ++CountQ;
                ind++;
                ind %= q2.Size;
            }
            return q3;
        }
        public void Print()
        {
            for (int i = Head; i <= Tail; i++)
            {
                Console.Write("{0} ", Ptr[i]);
            }
            Console.WriteLine();
        }
    }
}
