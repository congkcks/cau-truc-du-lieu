#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Node {
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq, Node* l = NULL, Node* r = NULL) {
        this->left = l;
        this->right = r;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

class HuffmanTree {
private:
    Node* root;
    unordered_map<char, string> codes;

    void printCodes(struct Node* root, string str) {
        if (!root)
            return;

        if (root->data != '$')
            codes[root->data] = str;

        printCodes(root->left, str + "0");
        printCodes(root->right, str + "1");
    }

public:
    HuffmanTree(string data) {
       unordered_map<char, unsigned> freqMap;
       for (char c : data)
           freqMap[c]++;
           
       priority_queue<Node*, vector<Node*>, compare> minHeap;

       for (auto pair : freqMap)
          minHeap.push(new Node(pair.first, pair.second));

       while (minHeap.size() != 1) {
          Node *left = minHeap.top(); minHeap.pop();
          Node *right = minHeap.top(); minHeap.pop();
          unsigned sum = left->freq + right->freq;
          minHeap.push(new Node('$', sum, left, right));
       }

       root = minHeap.top();
       printCodes(root, "");
    }

    string encode(string input) {
        string output = "";
        for (char c : input) {
            output += codes[c];
        }
        return output;
    }

    string decode(string input) {
        string output = "";
        Node* currentNode = root;
        for (char c : input) {
            if (c == '0')
                currentNode = currentNode->left;
            else
                currentNode = currentNode->right;

            if (currentNode->left == NULL && currentNode->right == NULL) {
                output += currentNode->data;
                currentNode = root;
            }
        }
        return output;
    }
};

int main() {
    string str = "ABABBCBBDEEEABABBAEEDDCCABBBCDEEDCBCCCCDBBBCAAA";

    HuffmanTree huff(str);
    
    string encodedStr = huff.encode(str);
    cout << "Chuoi sau khi nen: " << encodedStr << endl;

    string decodedStr = huff.decode(encodedStr);
    cout << "Chu?i sau khi giai nen: " << decodedStr << endl;

    return 0;
}
