//
//  main.cpp
//  Tree
//
//  Created by kidd on 2018/6/26.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


void InitBiTree(BiTree &T){
    T = NULL;
}

void CreateBiTree(BiTree &T){
    
    char ch;
    cin>>ch;
    
    if(ch == '0'){
        T = NULL;
    }else{
        T = (BiTree)malloc(sizeof(BiTNode)); // 生成根结点
        if(!T){
            cout<< "生成根结点错误" <<endl;
            return;
        }
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    
}


//前序递归遍历
void PreOrder(BiTree &T){
    if (T != NULL) {
        cout<< T->data << " ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//前序非递归遍历
void PreOrder_Two(BiTree T){
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty()) {
        if (p) {
            cout<< p->data <<" ";
            s.push(p);
            p = p->lchild;
        }else{
            p = s.top();
            p = p->rchild;
            s.pop();
        }
    }
}

//中序遍历
void InOrder(BiTree T){
    if (T != NULL) {
        InOrder(T->lchild);
        cout<< T->data << " ";
        InOrder(T->rchild);
    }
}

//中序非递归遍历
void InOrder_Two(BiTree T){
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lchild;
        }else{
            p = s.top();
            cout<< p->data <<" ";
            p = p->rchild;
            s.pop();
        }
    }
}

//后序遍历
void PostOrder(BiTree T){
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout<< T->data << " ";
    }
}

//后序非递归遍历
void PostOrder_Two(BiTree T){
    stack<BiTree> s;
    BiTree p = T;
    BiTree r = NULL;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lchild;
        }else{
            p = s.top();
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
                s.push(p);
                p = p->lchild;
            }else{
                cout<< p->data << " ";
                r = p;
                s.pop();
                p = NULL;
            }
        }
    }
}

//层次遍历
void LevelOrder(BiTree T){
    queue<BiTree> q;
    BiTree p = T;
    
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->lchild != NULL) {
            q.push(p->lchild);
        }
        if (p->rchild != NULL) {
            q.push(p->rchild);
        }
    }
}


int main(int argc, const char * argv[]) {
    BiTree Tree1;
    InitBiTree(Tree1);
    cout<< "开始创建二叉树.." << endl;
    CreateBiTree(Tree1);
    
    cout << "1.前序遍历" << endl;
    PreOrder(Tree1);
    cout << endl;
    cout << "1.前序非递归遍历" << endl;
    PreOrder_Two(Tree1);
    cout << endl;
    cout << "2.中序遍历" << endl;
    InOrder(Tree1);
    cout << endl;
    cout << "2.中序非递归遍历" << endl;
    InOrder_Two(Tree1);
    cout << endl;
    cout << "3.后序遍历" << endl;
    PostOrder(Tree1);
    cout << endl;
    cout << "3.后序非递归遍历" << endl;
    PostOrder_Two(Tree1);
    cout << endl;
    cout << "4.层次遍历" << endl;
    LevelOrder(Tree1);
    return 0;
}
