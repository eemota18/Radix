/*Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */
#include "radix.h"
#include <iostream>
#include <algorithm>
#include <thread>

RadixSort::RadixSort(const unsigned int cores) {
 //int ununsed = 0; // to fail complier warming test, remove
    this->cores = cores;
}

void sortMethod(std::vector<unsigned int> &list){
                std::sort(list.begin(),list.end(),[](const unsigned int& a,const unsigned int& b){
                return std::to_string(a) < std::to_string(b);
            });

}

void RadixSort::msd(std::vector<std::reference_wrapper<std::vector<unsigned int>>> &lists) {

                    
    std::vector<std::thread*> threads;
    unsigned int total = 0;
    for (std::vector<unsigned int> &list : lists) {
        threads.push_back(new std::thread{[&list]{
            std::sort(list.begin(),list.end(),[](const unsigned int& a,const unsigned int& b){
                return std::to_string(a) < std::to_string(b);
            });

        }});   
    
        total++;
        if(threads.size() == cores || total == lists.size()){
            for(std::thread *thread : threads)
                thread->join();
            threads.clear();
    }

    }
}
