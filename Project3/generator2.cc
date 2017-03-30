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

  //insert n/2 numbers of elements
  for(int i = 1; i <= n/4; i++) {
    cout << "I " << i << endl;
  }
  //insert some numbers from the n/2
  for (int i = 4/n; i >= 1; i--) {
    cout << "R " << i << endl;
  }
  for (int i = 4/n; i <= n/2; i++) {
    cout << "I " << i << endl;
  }
  //insert numbers from the n/2
  for(int i = n/2; i >= n/4; i--) {
    cout << "I " << i << endl;
  }
  return 0;
}
