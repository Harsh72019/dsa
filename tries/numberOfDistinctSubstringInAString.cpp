#include<bits/stdc++.h>
using namespace std;


struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string s) {
        Node* node = root;
        for (int i = 0; i < s.size(); i++) {
            if (!node->containsKey(s[i])) {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->setEnd();
    }
    
    bool search(string s) {
        Node* node = root;
        for (int i = 0; i < s.size(); i++) {
            if (!node->containsKey(s[i])) {
                return false;
            }
            node = node->get(s[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

class Solution {	
public:
    int countDistinctSubstring(string s) {
        int len = s.size();
        Node* root = new Node(); 
        int counter = 0;
        
        for(int i = 0; i < len; i++) {
            Node* node = root; 
            for(int j = i; j < len; j++) {
                if(!node->containsKey(s[j])) {
                    counter++;
                    node->put(s[j], new Node());
                }
                node = node->get(s[j]);
            }
        }
        
        return counter + 1; 
    }
};
