#ifndef __CONCAT_STRING_TREE_H__
#define __CONCAT_STRING_TREE_H__

#include "main.h"

// forward declaration
struct CSTNode;
class ReducedConcatStringTree;

class PTNode {
public:   
    static int maxId;
    int id ;

    PTNode *left;
    PTNode *right;

    CSTNode* data;
    int height;

    PTNode( CSTNode*, int, int, PTNode *, PTNode*);
    void newID(int);
};

class ParentsTree
{
public:
    PTNode * root;
    int numElement = 0;

    int size() const;
    string toStringPreOrder() const;

    
    ParentsTree(){
        root = nullptr;
    }
    int calHeight(PTNode *p){

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
        return 1;

    }


    int balanceFactor(PTNode *n){
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

    PTNode * llrotation(PTNode *n){
        PTNode *p;
        PTNode *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;
        if(p == root) root = tp; 
        p->height = calHeight(p);
        tp->height = calHeight(tp);
        return tp; 
    }

    PTNode * rrrotation(PTNode *n){
        PTNode *p;
        PTNode *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;
        if(p == root) root = tp; 
        
        p->height = calHeight(p);
        tp->height = calHeight(tp);
        return tp; 
    }

    PTNode * rlrotation(PTNode *n){
        PTNode *p;
        PTNode *tp;
        PTNode *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp; 
        if(p == root) root = tp2; 
        
        p->height = calHeight(p);
        tp->height = calHeight(tp);
        tp2->height = calHeight(tp2);
        return tp2; 
    }

    PTNode * lrrotation(PTNode *n){
        PTNode *p;
        PTNode *tp;
        PTNode *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp; 
        
        if(p == root) root = tp2; 
        
        p->height = calHeight(p);
        tp->height = calHeight(tp);
        tp2->height = calHeight(tp2);
        return tp2; 
    }

    PTNode* insert(PTNode *r,PTNode* data){
        
        if(r==NULL){
            if(root == NULL) root = data; 

            data->height = 1;
            numElement++;
            return data;             
        }
        else{
            if(data->id < r->id)
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

    PTNode * deleteNode(PTNode *p, int dataId){

        if((p->left == NULL && p->right == NULL) ){
                if(p==this->root)
                    this->root = NULL;
            numElement--;
            delete p;
            return NULL;
        }

        PTNode *q;
        if(p->id < dataId){
            p->right = deleteNode(p->right,dataId);
        }
        else if(p->id > dataId){
            p->left = deleteNode(p->left,dataId);
        }
        else{
            if(p->left != NULL){
                q = inpre(p->left);
                p->id = q->id;
                p->data = q->data;
                p->left=deleteNode(p->left,q->id);
            }
            else{
                q = insuc(p->right);
                p->id = q->id;
                p->data = q->data;
                p->right = deleteNode(p->right,q->id);
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

    bool findPTNode(PTNode *p, int &findingId){
        if(p == nullptr) return false;

        if(p->id == findingId) return true;
        if(p->id < findingId){
            return findPTNode(p->right,findingId);
        }
         
        return findPTNode(p->left,findingId);
        
    }


    PTNode* inpre(PTNode* p){
        while(p->right!=NULL)
            p = p->right;
        return p;    
    }

    PTNode* insuc(PTNode* p){
        while(p->left!=NULL)
            p = p->left;

        return p;    
    }

    ~ParentsTree(){

    }
};


struct CSTNode{
    int leftLength;
    int length;
    string data;
    
    CSTNode *left; 
    CSTNode *right;

    int myId;
    class ParentsTree parent;
    //class AncestorList ancestor;
    class ParentsTree ancestor;
    
    CSTNode(int,int,string, CSTNode *, CSTNode * );
};

class ConcatStringTree {
protected:
    CSTNode *root;
    int numOfNode;
    bool isTemporary;
    bool isShallowNorDeep;

    //friend class ReducedConcatStringTree;
public:
    ConcatStringTree(const ConcatStringTree&& otherS);
    ConcatStringTree(CSTNode *_root, int, bool _isTemporary, bool _isShallowNorDeep);
    ConcatStringTree(const char * s);
    virtual ~ConcatStringTree();
    int length() const;
    char get(int index);
    int indexOf(char c);
    string toStringPreOrder() const;
    string toString() const;
    ConcatStringTree concat(const ConcatStringTree & otherS) const;
    ConcatStringTree subString(int from, int to) const;
    ConcatStringTree reverse() const;

    int getParTreeSize(const string & query) const;
    string getParTreeStringPreOrder(const string & query) const;

    virtual void createParentAndChildAncestor() const;
};



class HashConfig {
private:
    int p;
    double c1, c2;
    double lambda;
    double alpha;
    int initSize;

    friend class ReducedConcatStringTree;
    friend class LitStringHash;

public:
    HashConfig(int,double,double,double, double, int);
};

class LitString{
public:
    CSTNode *data;
    string s;
    int reference;

    LitString(CSTNode *,string, int);
    ~LitString();
};

class LitStringHash {
public:
    LitString **litHash;
    HashConfig config;
    int numOfElement = 0;

    int lastInsertedIndex = -1;

    LitStringHash(const HashConfig & hashConfig);
    ~LitStringHash();
    int getLastInsertedIndex() const;
    string toString() const;

    long long hashFunc(string, long long);
    long long probingFunc(LitString **&,string, long long, bool);
    void rehash();
    CSTNode* insert(string);
    //int searchKey();
    void remove(string);

};
class ReducedConcatStringTree : public ConcatStringTree { 
    LitStringHash * litStringHash;
public:

    ReducedConcatStringTree(ReducedConcatStringTree && other);
    ReducedConcatStringTree(const char * _s, LitStringHash * _litStringHash);
    ReducedConcatStringTree(CSTNode * , LitStringHash *, int, bool, bool);
    virtual ~ReducedConcatStringTree();

    
    ReducedConcatStringTree subString(int from, int to) const;
    ReducedConcatStringTree reverse() const;
    ReducedConcatStringTree concat(const ReducedConcatStringTree& otherS) const;
    void createParentAndChildAncestor() const;
};



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
void preorder(PTNode* node, T &result, void (*executeFunc) (PTNode *, T &) )
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