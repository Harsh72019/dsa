#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key, val;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        Node* node = cache[key];
        remove(node);
        add(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        add(newNode);

        if (cache.size() > cap) {
            Node* lru = tail->prev; 
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};