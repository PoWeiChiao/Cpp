#include <vector>

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// Implement the MinStack class:

//     MinStack() initializes the stack object.
//     void push(val) pushes the element val onto the stack.
//     void pop() removes the element on the top of the stack.
//     int top() gets the top element of the stack.
//     int getMin() retrieves the minimum element in the stack.

using namespace std;

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if (min.empty()) min.push_back(val);
        else val < min.back() ? min.push_back(val) : min.push_back(min.back());
    }
    
    void pop() {
        if (!stack.empty()) stack.pop_back();
        if (!min.empty()) min.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min.back();
    }
private:
    vector<int> stack;
    vector<int> min;
};