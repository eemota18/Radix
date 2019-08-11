#include <algorithm>
#include <iostream>
#include <iterator>
 

int main()
{
    std::vector<unsigned int> data = { 33, 54, 3, 135, 644, 3, 5, 13, 53, 502, 99 };
 
    std::sort(data.begin(),data.end(),[] (unsigned int a , unsigned int b) {
            return std::to_string(a) < std::to_string(b);
        });

    for(unsigned int i : data)
        std::cout<< i <<" " ;

    return 0;
}