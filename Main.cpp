#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Node{
    char data;
    int freq;
    Node *left, *right;
};

struct compare{
    bool operator()(Node* l, Node* r){
        return l->freq > r->freq;
    }
};

Node* root;

Node* getNode(char data, int freq){
    Node* node = new Node();
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void buildHuffmanTree(string s, int freq[]){
    Node *left, *right, *top;
    priority_queue<Node*, vector<Node*>, compare> pq;

    for(int i = 0; i < s.size(); i++){
        pq.push(getNode(s[i], freq[i]));
    }

    while(pq.size() != 1){
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        top = getNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    root = pq.top();
}

void printPreOrder(Node* root, string str){
    if(root == NULL) return;

    if(root->data != '$') cout << root->data << " : " << str << endl;

    printPreOrder(root->left, str + "0");
    printPreOrder(root->right, str + "1");
}

void printHuffmanCodes(string s, int freq[]){
    buildHuffmanTree(s, freq);
    printPreOrder(root, "");
}

int main(){
    string s = "abcdef";
    int freq[] = {5, 9, 12, 13, 16, 45};

    printHuffmanCodes(s, freq);

    return 0;
}
