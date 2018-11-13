#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class Fibonacci {
 public:
  static int get(int n) {
    assert(n >= 0);
    vector<int> fib;
    if(n < 2) {
        return n;
    }else{
        fib.push_back(0);
        fib.push_back(1);
        for(int i = 2; i < n + 1; i++){
             fib.push_back(fib[i-1] + fib[i-2]);
        }
    }
    return fib[n];
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  return 0;
}

