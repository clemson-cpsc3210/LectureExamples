***REMOVED***
 * Compute the factorial of a given integer n.
 * 
 * Author: Guoxi Liu
 * Clemson University
 * Date: 01/23/2023
***REMOVED***

#include <assert.h>
***REMOVED***

***REMOVED***
 * Compute the factorial using recursion.
***REMOVED***
int compute_factorial_recursion(int n)
***REMOVED***
    assert(n > 0);
    if (n == 1) return n;
    return n * compute_factorial_recursion(n - 1);
***REMOVED***


***REMOVED***
 * Compute the factorial using for loop.
***REMOVED***
int compute_factorial_for_loop(int n)
***REMOVED***
    assert(n > 0);
    int res = 1;
    for (int i = 2; i <= n; i++) ***REMOVED***
        res *= i;
***REMOVED***
    return res;
***REMOVED***

***REMOVED***
 * Main function.
***REMOVED***
int main(int argc, char *argv[])
***REMOVED***
    int version = 1, num = 0;
    std::cout << "Select the version you want to use to compute factorial: " << std::endl;
    std::cout << "1. Recursion " << std::endl; 
    std::cout << "2. For loop " << std::endl;
    std::cout << "Please input your selection and press Enter: ";

    std::cin >> version;
    assert(version == 1 || version == 2);

    std::cout << "Please input the number n: ";
    if (version == 1) ***REMOVED***
        while (std::cin >> num) ***REMOVED***
            std::cout << compute_factorial_recursion(num) << std::endl;
            std::cout << "Please input the number n: ";
    ***REMOVED***
***REMOVED***
    else ***REMOVED***
        while (std::cin >> num) ***REMOVED***
            std::cout << compute_factorial_for_loop(num) << std::endl;
            std::cout << "Please input the number n: ";
    ***REMOVED***
***REMOVED***

    // Bonus question: what is the largest number n for this program get the correct factorial?

***REMOVED***
***REMOVED***
