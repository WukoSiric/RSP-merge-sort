#include <iostream> 
#include <queue> 
#include <vector>
#include <cmath> 
std::vector<int> merge(std::vector<int> numbers, int low, int middle, int high) {
    std::queue<int> first_half;
    std::queue<int> second_half;

    for (int i = low; i <= middle; i++) {
        first_half.push(numbers[i]);
    }

    for (int i = middle+1; i <= high; i++) {
        second_half.push(numbers[i]);
    }

    int i = low; 
    while(!(first_half.empty() || second_half.empty())) {
        if (first_half.front() <= second_half.front()) {
            numbers[i++] = first_half.front(); 
            first_half.pop();
        } else {
            numbers[i++] = second_half.front(); 
            second_half.pop();
        }
    }

    while (!first_half.empty()) {
        numbers[i++] = first_half.front(); 
        first_half.pop();
    }

    while (!second_half.empty()) {
        numbers[i++] = second_half.front(); 
        second_half.pop();
    }

    return numbers;
}

std::vector<int> mergesort(std::vector<int> numbers, int low, int high) {
    int middle;
    if (low < high) {
        middle = std::floor((low+high)/2);
        numbers = mergesort(numbers, low, middle);
        numbers = mergesort(numbers, middle+1, high);
        return merge(numbers, low, middle, high);
    }
    return numbers;
}

int main() {
    // Test program
    std::vector<int> numbers = {5, 2, 4, 6, 1, 3};
    numbers = mergesort(numbers, 0, numbers.size()-1);
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
