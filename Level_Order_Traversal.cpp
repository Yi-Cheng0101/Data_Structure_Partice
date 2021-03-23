#include <queue>
#include <cstdio>

struct Node{
  int data;
  Node *right,*left;
};

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

