#include <iostream>
#include "Array.h"
#include <algorithm>


int main()
{
    Array<int> arr = { 1,2,3,4,6,7,8,9 };
    std::sort(arr.begin(), arr.end());
    arr.Pop_back();
    arr.Push_back(111);
    for (int i = 0; i < arr.Size(); ++i) {
        std::cout << arr[i] << std::endl;
    }
    arr.insert(15, 3);
    arr.erase(2);
    if (!arr.IsEmpty()) {
        std::sort(arr.begin(), arr.end());
    }
    for (const auto& el : arr) {
        std::cout << el << std::endl;
    }
    arr.clear();
    if (arr.IsEmpty()) {
        std::cout << arr.GetCapacity() << std::endl;
    }



    return 0;
}