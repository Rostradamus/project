#include <iostream>
#include <cstdlib> // for atoi
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2){
    cerr << "Wrong number of arguments!" << endl;
    return 1;
  }

  int n = atoi(argv[1]);

  for(int i = 1; i <= n/4; i = i+2) {
    cout << "I " << i << endl;
  }

  for(int i = 2; i <= n/4; i = i+2) {
    cout << "F " << i << endl;
  }

  for(int i = n/4; i >= 1; i = i-2) {
    cout << "R " << i << endl;
  }
  for (int i = 1; i <= n/8; i ++) {
    cout << "F " << i << endl;
    cout << "F " << n/8 - i << endl;
  }
  return 0;
}
