#ifndef __CONCAT_STRING_TREE_H__
#define __CONCAT_STRING_TREE_H__

#include "main.h"


struct CSTNode{
    int leftLength;
    int length;
    string data;
    
    CSTNode *left; 
    CSTNode *right;
    CSTNode *alternative1 = nullptr;
    CSTNode *alternative2 = nullptr;

    
    CSTNode(int,int,string, CSTNode *, CSTNode * );
};

struct PTNode {
    struct PTNode *left;
    CSTNode* data;
    int height;
    struct PTNode *right;

};


class ParentsTree
{
private:
    
public:
    struct PTNode * root;
    static int maxIndex ;
    int index ;
    int size = 0 ;
    ParentsTree(){
        maxIndex++;
        if(maxIndex>= 10000000){
            throw overflow_error("Id is overflow!");
        }
        index = maxIndex;
        this->root = NULL;
    }
    int calHeight(struct PTNode *p){

            if(p->left && p->right){
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
            }
            else if(p->left && p->right == NULL){
               return p->left->height + 1;
            }
            else if(p->left ==NULL && p->right){
               return p->right->height + 1;
            }
            return 0;

    }

    int balanceFactor(struct PTNode *n){
            if(n->left && n->right){
                return n->left->height - n->right->height; 
            }
            else if(n->left && n->right == NULL){
                return n->left->height; 
            }
            else if(n->left== NULL && n->right ){
                return -n->right->height;
            }
            return 0;
    }

    struct PTNode * llrotation(struct PTNode *n){
        struct PTNode *p;
        struct PTNode *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp; 
    }

    struct PTNode * rrrotation(struct PTNode *n){
        struct PTNode *p;
        struct PTNode *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp; 
    }

    struct PTNode * rlrotation(struct PTNode *n){
        struct PTNode *p;
        struct PTNode *tp;
        struct PTNode *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp; 
        
        return tp2; 
    }

    struct PTNode * lrrotation(struct PTNode *n){
        struct PTNode *p;
        struct PTNode *tp;
        struct PTNode *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp; 
        
        return tp2; 
    }

    struct PTNode* insert(struct PTNode *r,CSTNode* data){
        
        if(r==NULL){
            struct PTNode *n;
            n = new struct PTNode;
            n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1; 

            size++;
            return r;             
        }
        else{
            if(data->leftLength < r->data->leftLength)
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }

        r->height = calHeight(r);

        if(balanceFactor(r)==2 && balanceFactor(r->left)==1){
            r = llrotation(r);
        }
        else if(balanceFactor(r)==-2 && balanceFactor(r->right)==-1){
            r = rrrotation(r);
        }
        else if(balanceFactor(r)==-2 && balanceFactor(r->right)==1){
            r = rlrotation(r);
        }
        else if(balanceFactor(r)==2 && balanceFactor(r->left)==-1){
            r = lrrotation(r);
        }        

        return r;

        }

    struct PTNode * deleteNode(struct PTNode *p,CSTNode* data){

        if(p->left == NULL && p->right == NULL){
                if(p==this->root)
                    this->root = NULL;
            delete p;
            return NULL;
        }

        struct PTNode *t;
        struct PTNode *q;
        if(p->data->leftLength < data->leftLength){
            p->right = deleteNode(p->right,data);
        }
        else if(p->data->leftLength > data->leftLength){
            p->left = deleteNode(p->left,data);
        }
        else{
            if(p->left != NULL){
                q = inpre(p->left);
                p->data = q->data;
                p->left=deleteNode(p->left,q->data);
            }
            else{
                q = insuc(p->right);
                p->data = q->data;
                p->right = deleteNode(p->right,q->data);
            }
        }

        if(balanceFactor(p)==2 && balanceFactor(p->left)==1){ p = llrotation(p); }                  
        else if(balanceFactor(p)==2 && balanceFactor(p->left)==-1){ p = lrrotation(p); }
        else if(balanceFactor(p)==2 && balanceFactor(p->left)==0){ p = llrotation(p); }
        else if(balanceFactor(p)==-2 && balanceFactor(p->right)==-1){ p = rrrotation(p); }
        else if(balanceFactor(p)==-2 && balanceFactor(p->right)==1){ p = rlrotation(p); }
        else if(balanceFactor(p)==-2 && balanceFactor(p->right)==0){ p = llrotation(p); }

        
        return p;
    }

    struct PTNode* inpre(struct PTNode* p){
        while(p->right!=NULL)
            p = p->right;
        return p;    
    }

    struct PTNode* insuc(struct PTNode* p){
        while(p->left!=NULL)
            p = p->left;

        return p;    
    }

    ~ParentsTree(){

    }
};




class ConcatStringTree {
    CSTNode *root;
    bool isTemporary;
    bool isShallowNorDeep;
public:
    ConcatStringTree(const ConcatStringTree&& otherS);
    ConcatStringTree(CSTNode *_root, bool _isTemporary, bool _isShallowNorDeep);
    ConcatStringTree(const char * s);
    ~ConcatStringTree();
    int length() const;
    char get(int index);
    int indexOf(char c);
    string toStringPreOrder() const;
    string toString() const;
    ConcatStringTree concat(const ConcatStringTree & otherS) const;
    ConcatStringTree subString(int from, int to) const;
    ConcatStringTree reverse() const;

    //int getParTreeSize(const string & query) const;
    //string getParTreeStringPreOrder(const string & query) const;
};

/*
class ReducedConcatStringTree; // forward declaration

class HashConfig {
private:
    int p;
    double c1, c2;
    double lambda;
    double alpha;
    int initSize;

    friend class ReducedConcatStringTree;
};

class ReducedConcatStringTree  {

public:
    class LitStringHash {
    public:
        LitStringHash(const HashConfig & hashConfig);
        int getLastInsertedIndex() const;
        string toString() const;
    };

public:
    static LitStringHash litStringHash;
};
*/

template <class T> 
CSTNode* searchNode(CSTNode* root, T& key, bool (*acceptFunc) (CSTNode*, T&) , bool (*branchRightFunc)(CSTNode*,T&))
{
    if (root == NULL || acceptFunc(root, key ))
       return root;
    
    if(branchRightFunc(root, key ))
       return searchNode(root->right, key, acceptFunc, branchRightFunc);
 
    return searchNode(root->left, key, acceptFunc, branchRightFunc);
}

template <class T> 
void preorder(CSTNode* node, T &result, void (*executeFunc) (CSTNode *, T &) )
{
    if (node == NULL)
        return;

    executeFunc(node , result);
 
    /* then recur on left subtree */
    preorder(node->left, result, executeFunc);
    
    /* now recur on right subtree */
    preorder(node->right, result, executeFunc);
}


template <class T> 
CSTNode* postorder(CSTNode* node, T &result, CSTNode* (*executeFunc) (CSTNode *, T &, CSTNode*, CSTNode*) )
{
    if (node == nullptr)
        return nullptr;
 
    /* then recur on left subtree */
    CSTNode * left = postorder(node->left, result, executeFunc);
    
    /* now recur on right subtree */
    CSTNode *right =  postorder(node->right, result, executeFunc);
    
    return executeFunc(node, result, left, right);
}

#endif // __CONCAT_STRING_TREE_H__