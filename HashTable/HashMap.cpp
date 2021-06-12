#include <vector>

// Design a HashMap without using any built-in hash table libraries.
// Implement the MyHashMap class:
// MyHashMap() initializes the object with an empty map.
// void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
// int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

using namespace std;

class MyHashMap {
private:
    vector<int> vec;
    vector<int> exist;
public:
    MyHashMap() {
        vec = vector<int>(1000001, 0);
        exist = vector<int>(1000001, 0);
    }
    
    void put(int key, int value) {
        vec[key] = value;
        exist[key] = 1;
    }
    
    int get(int key) {
        return exist[key] ? vec[key] : -1;
    }
    
    void remove(int key) {
        vec[key] = 0;
        exist[key] = 0;
    }
};