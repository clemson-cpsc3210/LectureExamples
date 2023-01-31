***REMOVED***
 * Compute the n-th Fibonacci number (n > 0).
 * Fibonacci sequence is given as: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 * 
 * Author: Guoxi Liu
 * Clemson University
 * Date: 01/23/2023
***REMOVED***

#include <assert.h>
***REMOVED***

***REMOVED***
 * Compute the fibonacci using recursion.
***REMOVED***
int compute_fibonacci_recursion(int n)
***REMOVED***
    assert(n > 0);
    if (n <= 2) return 1;
    return compute_fibonacci_recursion(n-1) + compute_fibonacci_recursion(n-2);
***REMOVED***


***REMOVED***
 * Compute the fibonacci using for loop.
***REMOVED***
int compute_fibonacci_for_loop(int n)
***REMOVED***
    assert(n > 0);
    int a1 = 1, a2 = 1, res = 1;
    for (int i = 2; i < n; i++) ***REMOVED***
        res = a1 + a2;
        a1 = a2;
        a2 = res;
***REMOVED***
    return res;
***REMOVED***

***REMOVED***
 * Main function.
***REMOVED***
int main(int argc, char *argv[])
***REMOVED***
    int version = 1, num = 0;
    std::cout << "Select the version you want to use to compute fibonacci: " << std::endl;
    std::cout << "1. Recursion " << std::endl; 
    std::cout << "2. For loop " << std::endl;
    std::cout << "Please input your selection and press Enter: ";

    std::cin >> version;
    assert(version == 1 || version == 2);

    std::cout << "Please input the number n: ";
    if (version == 1) ***REMOVED***
        while (std::cin >> num) ***REMOVED***
            std::cout << compute_fibonacci_recursion(num) << std::endl;
            std::cout << "Please input the number n: ";
    ***REMOVED***
***REMOVED***
    else ***REMOVED***
        while (std::cin >> num) ***REMOVED***
            std::cout << compute_fibonacci_for_loop(num) << std::endl;
            std::cout << "Please input the number n: ";
    ***REMOVED***
***REMOVED***

    // Bonus question: what is the largest n-th fibonacci number can this program compute?

***REMOVED***
***REMOVED***
