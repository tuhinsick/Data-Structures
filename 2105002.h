#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

FILE *ofp = fopen("out.txt", "w");

class Node
{
    public : 
    int data;
    Node *left;
    Node *right; 
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};


class BST
{
    Node *root;

    Node *insertHelp(Node *root, int d)
    {
        if (root == NULL)
        {
            root = new Node(d);
        }

        else if (d > root->data)
        {
            root->right = insertHelp(root->right, d);
        }

        else
        {
            root->left = insertHelp(root->left, d);
        }

        return root;
    }

    int findMin(Node *root)
    {
        if (root->left == NULL)
        {
            return root->data;
        }

        else
        {
            findMin(root->left);
        }
    }

    Node *deleteHelp(Node *root, int d)
    {
        if (root == NULL)
        {
            return root;
        }

        if (root->data == d)
        {
            // 0 child
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }

            else if (root->left != NULL && root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            else if (root->right != NULL && root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            else if (root->right != NULL && root->left != NULL)
            {
                int max = findMin(root->right);
                root->data = max;
                root->right = deleteHelp(root->right, max);
            }
        }

        if (d > root->data)
        {
            root->right = deleteHelp(root->right, d);
        }

        else
        {
            root->left = deleteHelp(root->left, d);
        }
    }

    void printBSTHelp(Node *root)
    {

        if (root == NULL)
        {
            return;
        }

        fprintf(ofp, "%d", root->data);
        if (root->left == NULL && root->right == NULL)
        {
            return;
        }
        fprintf(ofp, "(");
        printBSTHelp(root->left);
        fprintf(ofp, ",");
        printBSTHelp(root->right);
        fprintf(ofp, ")");
    }

    bool searchHelp(Node *root, int d)
    {
        if (root == NULL)
        {
            return false;
        }

        else if (d == root->data)
        {
            return true;
        }

        else if (d > root->data)
        {
            searchHelp(root->right, d);
        }

        else
        {
            searchHelp(root->left, d);
        }
    }

    void PreorderHelp(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        fprintf(ofp, "%d ", root->data);
        PreorderHelp(root->left);
        PreorderHelp(root->right);
    }

    void InorderHelp(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        InorderHelp(root->left);
        fprintf(ofp, "%d ", root->data);
        InorderHelp(root->right);
    }

    void PostorderHelp(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        PostorderHelp(root->left);
        PostorderHelp(root->right);
        fprintf(ofp, "%d ", root->data);
    }

    public : 

      BST(){
        root = NULL;
      }

      void printBST(){
        fprintf(ofp,"(");
        printBSTHelp(root);
        fprintf(ofp,")\n");
      }

      void insert(int item){
        root = insertHelp(root,item);
      }

      void deleteBST(int item){
        bool x = searchHelp(root,item);
        if(x == 0){
            //fprintf(ofp,"element not found\n");
            return;
        }

        else{
            root = deleteHelp(root,item);
        }



      }

      bool search(int item){
        bool x = searchHelp(root,item);
        return x;
      }

      void Preorder(){
        PreorderHelp(root);
      }

      void Postorder(){
        PostorderHelp(root);

      }

      void Inorder(){
        InorderHelp(root);
      }
};