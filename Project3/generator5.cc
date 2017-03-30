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
  // Inserting n/2 items in descending order
  for(int i = n/8; i >= 1; i--) {
    cout << "I " << i << endl;
  }
  for (int i = n/4; i <= n/2; i++) {
    cout << "I " << i << endl;
  }
  for (int i = n/4; i >= n/8; i--) {
    cout << "I " << i << endl;
  }
  for (int i = n/4; i <= n/2; i++) {
    cout << "R " << i << endl;
  }
  for (int i = n/2; i >= 1; i--) {
    cout << "R " << i << endl;
  }
  return 0;
}
