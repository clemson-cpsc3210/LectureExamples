***REMOVED***
 * A stack data structure support multipop operation.
 * 
 * Author: Guoxi Liu
 * Clemson University
 * Date: 01/23/2023
***REMOVED***

***REMOVED***
#include <vector>

***REMOVED***
 * Use STL vector to implement stack structure.
***REMOVED***
class Stack
***REMOVED***
***REMOVED***
    std::vector<int> st;

public:
    // add an element to the top of the stack
    void push(int num) ***REMOVED***
        st.push_back(num);
***REMOVED***

    // remove the top element from the stack
    void pop() ***REMOVED***
        if (!st.empty()) st.pop_back();
***REMOVED***

    // remove k elements from the top of the stack 
    void multipop(int k) ***REMOVED***
        while (!st.empty() && k > 0) ***REMOVED***
            st.pop_back();
            k--;
    ***REMOVED***
***REMOVED***

***REMOVED***
        std::cout << "stack size " << st.size() << ", [ ";
        for (size_t i = 0; i < st.size(); i++) ***REMOVED***
            std::cout << st[i] << " ";
    ***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***

***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***
    Stack stack;
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.print();
    stack.pop();
    stack.print();
    stack.push(5);
    stack.push(6);
    stack.print();
    stack.multipop(3);
    stack.print();

***REMOVED***
***REMOVED***