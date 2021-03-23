#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = value;
    return node;
}

int search(int in[], int strt, int end, int vaule){
    int i;
    for(i = strt; i <= end; i++){
        if(in[i] == vaule)
            break;
    }
    return i;
}

Node* buildUtil(int in[], int post[], int inStrt, int inEnd, int* pIndex){
    if(inStrt > inEnd)
        return NULL;
    
    Node* node = newNode(post[*pIndex]);
    (*pIndex)--;
    
    if(inStrt == inEnd)
        return node;
    
    int iIndex = search(in ,inStrt ,inEnd ,node->data);
    node->right = buildUtil(in, post, iIndex+1, inEnd, pIndex);
    node->left  = buildUtil(in, post, inStrt, iIndex-1, pIndex);
    
    return node;
}


void Levelorder(Node* node){

        std::queue<Node*> q;
        q.push(node);
                                               
        while (!q.empty()){

            Node *current = q.front();
            q.pop();
            std::cout << current->data << " ";
            
            if (current->left != NULL){
                q.push(current->left);
            }
            if (current->right != NULL){
                q.push(current->right);
            }
        }
}


int main(){
    
    int in[] = {4,8,2,5,1,6,3,7};
    int post[] = {8,4,5,2,6,7,3,1};
    int n = sizeof(in) / sizeof(in[0]);
    int pIndex = n - 1;
    
    Node* root = buildUtil(in, post, 0, n-1, &pIndex);
    
    cout << "Level order of the constructed tree : \n";
    Levelorder(root);
    return 0;
}


