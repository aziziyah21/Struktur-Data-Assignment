#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x){
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else if(x < root->info){
        insertNode(root->left, x);
    } else if(x > root->info){
        insertNode(root->right, x);
    }
} 

address findNode(infotype x, address root){
    if(root == Nil)
    return Nil;
    if(root->info == x)
    return root;
    if(x < root->info)
    return findNode(x, root->left);
    return findNode(x, root->right);
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right); 
    }
}

int hitungJumlahNode(address root){
    if(root == Nil){
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root){
    if(root == Nil){
        return 0;
    }
    return root->info + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungKedalaman(address root, int start){
    if(root == Nil){
        return start - 1;
    }
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start +1);
    if(kiri > kanan){
        return kiri;
    }
    return kanan;
}

void printPreorder(address root){
    if(root != Nil){
        cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(address root){
    if(root != Nil){
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " - ";
    }
}