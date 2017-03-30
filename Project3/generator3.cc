#include <iostream>
#include <cstdlib> // for atoi
using namespace std;
int main(int argc, char* argv[])
{
if (argc != 2)
{
cerr << "Wrong number of arguments!" << endl;
return 1;
}
int n = atoi(argv[1]);

// Insert n/2 items in descending order
for(int i = n/4; i >= 1; i--) {
cout << "I " << i << endl;
}
for(int i = n/4; i >= 1; i--) {
cout << "F " << i << endl;
}
for(int i = n/4; i >= 1; i--) {
cout << "R " << i << endl;
}
for(int i = 1; i <= n/4; i++) {
cout << "I " << i << endl;
}
return 0;
}
