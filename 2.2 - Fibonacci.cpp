#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class Fibonacci {
 public:
  static int get_last_digit(int n) {
    assert(n >= 0);
    vector<int> fib;
    if(n < 2) {
        return n;
    }else{
        fib.push_back(0);
        fib.push_back(1);
        for(int i = 2; i < n; i++){
             fib.push_back((fib[i-1] + fib[i-2]) % 10);
        }
    }
    return fib[n];
  }
  static int get(int n) {
      assert(n >= 0);
      vector<int> fib(3);
      if(n < 2) {
          return n;
      }else{
          fib[0] = 0;
          fib[1] = 1;
          for(int i = 2; i < n + 1; i++){
               fib.push_back(fib[i-1] + fib[i-2]);
          }
      }
      return fib[n];
   }
   static int get_remainder(long long n, int m) {
      assert(n >= 1);
      assert(m >= 2);

      vector<int> delimeters;
      delimeters.push_back(0);
      delimeters.push_back(1);
      int period = 0;
      for(int i = 2; i < n + 1; i++){
    	  delimeters.push_back((delimeters[i-1] + delimeters[i-2]) % m);
    	  period++;
    	  if(delimeters[i] == 1 && delimeters[i-1] == 0){
    		  return delimeters[n % period];
    	  }
      }

      return delimeters[n];
    }
   static int get_remainder_no_period(long long n, int m) {
         assert(n >= 1);
         assert(m >= 2);

         vector<int> delimeters;
         delimeters.push_back(0);
         delimeters.push_back(1);
         for(int i = 2; i < n + 1; i++){
       	  delimeters.push_back((delimeters[i-1] + delimeters[i-2]) % m);
         }
         return delimeters[n];
       }

};

