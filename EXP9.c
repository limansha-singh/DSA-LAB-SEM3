#include <iostream>
#include <stack>
#include <bits/stdc++.h>

void TowerOfHanoi(int numDisks, std::stack<int>& source, std::stack<int>& target, std::stack<int>& auxiliary) {
    int totalMoves = pow(2, numDisks) - 1;
    
    for (int move = 1; move <= totalMoves; move++) {
        if (move % 3 == 1) {
            if (!source.empty() && (auxiliary.empty() || source.top() < auxiliary.top())) {
                auxiliary.push(source.top());
                source.pop();
                std::cout << "Move disk from source to auxiliary" << std::endl;
            }
            else {
                source.push(auxiliary.top());
                auxiliary.pop();
                std::cout << "Move disk from auxiliary to source" << std::endl;
            }
        }
        else if (move % 3 == 2) {
            if (!source.empty() && (target.empty() || source.top() < target.top())) {
                target.push(source.top());
                source.pop();
                std::cout << "Move disk from source to target" << std::endl;
            }
            else {
                source.push(target.top());
                target.pop();
                std::cout << "Move disk from target to source" << std::endl;
            }
        }
        else {
            if (!auxiliary.empty() && (target.empty() || auxiliary.top() < target.top())) {
                target.push(auxiliary.top());
                auxiliary.pop();
                std::cout << "Move disk from auxiliary to target" << std::endl;
            }
            else {
                auxiliary.push(target.top());
                target.pop();
                std::cout << "Move disk from target to auxiliary" << std::endl;
            }
        }
    }
}

int main() {
    int numDisks;
    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;
    
    std::stack<int> source, target, auxiliary;
    
    // Initialize the source stack with disks
    for (int i = numDisks; i >= 1; i--) {
        source.push(i);
    }
    
    TowerOfHanoi(numDisks, source, target, auxiliary);
    
    return 0;
}
