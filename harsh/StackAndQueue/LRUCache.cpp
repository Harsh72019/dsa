#include <bits/stdc++.h>
using namespace std;

struct DLL
{
    int key;
    int value;
    DLL *next;
    DLL *prev;
    DLL(int k, int v)
    {
        this->key = k;
        this->value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
private:  
    int capacity;
    unordered_map<int , DLL*> cache;
    DLL * head;
    DLL * tail;
    
  void remove(DLL* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtFront(DLL* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new DLL(-1, -1);
        tail = new DLL(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key)
    {
        if(cache.find(key) != cache.end())
        {
            DLL * node = cache[key];
            remove(node);
            insertAtFront(node);
            return node->value;
        }
    }
    void put(int key, int value)
    {
        if(cache.find(key) != cache.end())
        {
            DLL * node = cache[key];
            remove(node);
            node->value = value;
            insertAtFront(node);
        }
        else
        {
            if(cache.size() == capacity)
            {
                DLL * nodeToBeRemoved = tail->prev;
                remove(nodeToBeRemoved);
                cache.erase(nodeToBeRemoved->key);
                delete nodeToBeRemoved;
            }
            DLL * newNode = new DLL(key, value);
            cache[key] = newNode;
            insertAtFront(newNode);
        }
    }
};