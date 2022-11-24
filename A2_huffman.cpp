#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
    char a;
    int data;
    Node *left, *right;
    
    Node(int data, char a){
        this -> a = a;
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

class compare{
    public:
    int operator()(Node* a, Node* b){
        return a -> data > b -> data;
    }
};

void preorder(Node* head, string code){
    if(head == NULL) return;
    
    if(head -> a != ' '){
        cout<<head->a<<" = "<<code<<endl;
    }
    
    preorder(head -> left, code + "0");
    preorder(head -> right, code + "1");
}
void huffman(vector<int>& arr, vector<int>& freq){
    priority_queue<Node*, vector<Node*>, compare> mh;
    
    int n = freq.size();
    
    for(int i = 0; i < n; i++){
        Node* temp = new Node(freq[i], arr[i]);
        mh.push(temp);
    }
    
    while(mh.size() >= 2){
        auto l = mh.top();
        mh.pop();
        auto r = mh.top();
        mh.pop();
        
        Node* temp = new Node((l -> data + r -> data), ' ');
        
        temp -> left = l;
        temp -> right = r;
        mh.push(temp);
    }
    
    auto temp = mh.top();
    mh.pop();
    
    string code = "";
    preorder(temp, code);
}

int main()
{
    vector<int> arr { 'a', 'b', 'c', 'd', 'e', 'f' };
    vector<int> freq { 5, 9, 12, 13, 16, 45 };
    
    huffman(arr, freq);
    return 0;
}
