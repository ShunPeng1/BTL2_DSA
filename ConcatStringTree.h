#ifndef __CONCAT_STRING_TREE_H__
#define __CONCAT_STRING_TREE_H__

#include "main.h"

struct CSTNode{
    int leftLength;
    int length;
    int numNode;
    string data;
    
    CSTNode *left; 
    CSTNode *right;
    CSTNode *alternative = nullptr;
    CSTNode(int,int,int,string, CSTNode *, CSTNode * );
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
    int numNode() const;
    char get(int index);
    int indexOf(char c);
    string toStringPreOrder() const;
    string toString() const;
    ConcatStringTree concat(const ConcatStringTree & otherS) const;
    ConcatStringTree subString(int from, int to) const;
    ConcatStringTree reverse() const;

    int getParTreeSize(const string & query) const;
    string getParTreeStringPreOrder(const string & query) const;
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
void postorder(CSTNode* node, T &result, void (*executeFunc) (CSTNode *, T &) )
{
    if (node == nullptr)
        return;
 
    /* then recur on left subtree */
    postorder(node->left, result, executeFunc);
    
    /* now recur on right subtree */
    postorder(node->right, result, executeFunc);
    
    executeFunc(node , result);
}

#endif // __CONCAT_STRING_TREE_H__