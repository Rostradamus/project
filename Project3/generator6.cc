#include <iostream>
#include <cstdlib> // for atoi
using namespace std;
int main(int argc, char* argv[])
{
if (argc != 2) // remember, argv[0] is the program name
{
cerr << "Wrong number of arguments!" << endl;
return 1;
}
int n = atoi(argv[1]);

//insert n numbers of elements
for(int i = 1; i <= n/2; i++) {
  cout << "I " << i << endl;
}
for (int i = 1000; i >= 1; i--) {
  cout << "I " << (n/2) + i << endl;
}
for(int i = n/2; i <= n; i++) {
cout << "I " << i << endl;
}
return 0;
}
