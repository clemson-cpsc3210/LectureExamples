/**
 * Clearable table structure using vector. 
*/

#include <iostream>
#include <vector>

class ClearableTable
{
private:
    int idx;    // current index
    int N;      // upper bounds
    std::vector<int> vec;   // vector
    
public:
    ClearableTable(int N) {
        this->N = N;
    }

    void add(int e) {
        if(vec.size() < N)
            vec.push_back(e);
    }

    void clear() {
        size_t n = vec.size();
        for (size_t i = 0; i < n; i++)
            vec.pop_back();
    }
 
    void print() {
        std::cout << "table size " << vec.size() << ", [ ";
        for (size_t i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
};

/**
 * Main entry. 
*/
int main(int argc, char const *argv[])
{
    ClearableTable ct(20);
    ct.add(5); ct.add(9); ct.add(13);
    ct.print();
    ct.clear();
    ct.print();
    ct.add(1); ct.add(4); ct.add(7); ct.add(10);
    ct.print();
    ct.clear();
    ct.print();
    return 0;
}
