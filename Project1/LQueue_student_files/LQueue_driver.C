/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "LQueue.h"
using namespace std;



void print(Queue q)
{ q.display(cout); }

int main(void)
{
   Queue q1;
	 Queue q3;
   cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

   cout << "How many elements to add to the queue? ";
   int numItems;
   cin >> numItems;
   for (int i = 1; i <= numItems; i++)
      q1.enqueue(100*i);

	//This is to Test merge_two_queues when q1.empty
 	for (int i = 1; i <= 10; i++)
	    q3.enqueue(110*i);
	//

	 int moveNum;
	 cout << "What value do you want to move front ?" <<endl;
	 cin >> moveNum;
	 q1.move_to_front(moveNum);
   cout << "Contents of queue q1 (via  print):\n";
   print(q1);
   cout << endl;


	 	//This is to Test merge_two_queues when q1.empty
	 cout << "Contents of queue q3 (via  print):\n";
	 print(q3);
	 cout << endl;
	 q1.merge_two_queues(q3);
	 cout << "Contents of queue q1 (via  print):\n";
	 print(q1);
	 cout << endl;
	 cout << "Contents of queue q3 (via  print):\n";
	 print(q3);
	 cout << endl;
	 //


   Queue q2;
   q2 = q1;
   cout << "Contents of queue q2 after q2 = q1 (via  print):\n";
   print(q2);
   cout << endl;

   cout << "Queue q2 empty? " << q2.empty() << endl;

   cout << "Front value in q2: " << q2.front() << endl;

   while (!q2.empty())
   {
     cout << "Remove front -- Queue contents: ";
     q2.dequeue();
     q2.display(cout);
   }
   cout << "Queue q2 empty? " << q2.empty() << endl;
   cout << "Front value in q2?" << endl << q2.front() << endl;
   cout << "Trying to remove front of q2: " << endl;
   q2.dequeue();
   //system("PAUSE");
   return 0;
}
