#include <vector>

// Design a HashSet without using any built-in hash table libraries.
// Implement MyHashSet class:
// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

using namespace std;

class MyHashSet {
private:
    vector<int> vec;;
public:
    MyHashSet() {
        vec = vector<int>(1000001, 0);
    }
    
    void add(int key) {
        vec[key] = 1;
    }
    
    void remove(int key) {
        vec[key] = 0;
    }
    
    bool contains(int key) {
        return vec[key] ? true : false;
    }
};