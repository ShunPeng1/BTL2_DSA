#include "ConcatStringTree.h"

//ALL OF MY #DEFINE ARE FOR PERSONAL USE AND PREVENT PLAGIARISM TO SOME EXTENDS 

typedef long long ll;

#define INF 2147483647
#define INFLL 9223372036854775807
#define MOD1 1000000007
#define MOD9 998244353

#define FOR(i,a,n) for(ll i=a ; i<n ; i++)
#define FORR(i,n,a) for(ll i=a-1 ; i>=n ; i--)
#define FOREACH(x, c) for(auto &(x): (c) ) 

#define endl '\n'
#define ENDL cout<<'\n'
#define YES cout<<"YES"
#define NO cout<<"NO"

#define CST ConcatStringTree


CSTNode::CSTNode(int _leftLength=0, int _length = 0, int _numNode = 0, string _data = "", CSTNode *_left = nullptr, CSTNode *_right=nullptr ): 
    leftLength(_leftLength),
    numNode(_numNode),
    length(_length),
    data(_data),
    left(_left),
    right(_right)
{

}


CST::CST(CSTNode *_root = nullptr,  bool _isTemporary = false, bool _isShallowNorDeep = false): 
    root(_root),
    isTemporary(_isTemporary),
    isShallowNorDeep(_isShallowNorDeep)
{

}

CST::CST(const CST&& otherS) {
    this->root = nullptr;
    this->isShallowNorDeep = false;
    this->isTemporary = false;
    if (otherS.isShallowNorDeep) {//is return from concat so we shallow copy
        (this->root) = (otherS.root);
    }
    else {//is return from the reverse or substring so we deep copy
    
        
        struct TempStruct{

            static void executeFunc(CSTNode *a, int &result){

                CSTNode *tpNode = new CSTNode();
                *(tpNode) = *(a);
                a->alternative = tpNode;
                if(a->left!= nullptr) {
                    tpNode->left = a->left->alternative;
                    a->left->alternative = nullptr;
                    delete a->left;
                }
                if(a->right!= nullptr) {
                    tpNode->right = a->right->alternative;
                    a->right->alternative = nullptr;
                    delete a->right;
                }            
            }
        };
        int blank;
        postorder(otherS.root, blank, TempStruct::executeFunc);

        this->root = otherS.root->alternative;
        delete otherS.root;

    }
    
}

CST::CST(const char * s){
    int i = 0;
    string tp = "";
    while (s[i] != '\0') {
        tp += s[i];
        i++;
    }

    CSTNode* tpCSTN = new CSTNode(0, tp.size(), 0, tp, nullptr, nullptr);
    root = tpCSTN;

    isShallowNorDeep = false;
    isTemporary = false;

}

CST::~CST(){
    if(isTemporary) return;
}

int CST::length() const{
    return root->length;
}

int CST::numNode() const{
    return root->numNode;
}

char CST::get(int index){
    if (index < 0 || index >= length()) {
        throw out_of_range("Index of string is invalid!");
    }

    struct TempStruct{
        static bool accept(CSTNode *a, int &index){
            if(a->left== nullptr && a->right == nullptr) return true;
            else return false;   
        }
        static bool branchRight(CSTNode *a, int &index){
            if(index< a->leftLength){
                return false;
            }
            else{
                index -= a->leftLength;
                return true;
            }
        }
    };

    CSTNode *resultNode = searchNode(root, index, TempStruct::accept, TempStruct::branchRight);

    FOR(i,0,resultNode->length){
        if(i == index) return resultNode->data[i];
    }
    cout<<"GET() OVERBOUND \n";
    return '\0';
}

int CST::indexOf(char c){
    
    int currentIndex = 0;
    
    struct TempStruct{
        int index;
        char finding;
        bool isFound;
        static void executeFunc (CSTNode *a, TempStruct &result){
            if(result.isFound) return;
            int size = a->data.size();
            FOR(i,0,size){
                if( result.finding == a->data[i] ) {
                    result.index += i;
                    result.isFound = true ;
                    break;
                }
            }
            if(!result.isFound) result.index+=size;
            
        }
    };

    TempStruct tempObj {0,c};
    preorder(root, tempObj, TempStruct::executeFunc);

    if(tempObj.isFound) return tempObj.index;    
    else return -1;
}

string CST::toStringPreOrder() const{
    string result = "ConcatStringTree[";
    
    struct TempStruct{
        static void executeFunc (CSTNode *a, string &result){
            
            if(result.back() == ')') result+= ';';

            result+= "(LL=" + to_string( a->leftLength)+",L="+to_string(a->length)+",";
            if(a->data.size()!=0) result+="\"" + a->data+"\"";
            else result += "<NULL>";
            result += ')';
        }
    };

    preorder(root, result, TempStruct::executeFunc);
    result+= ']';
    return result;
}

string CST::toString() const{
    
    string result ;
    
    struct TempStruct{
        static void executeFunc (CSTNode *a, string &result){ 
            result+= a->data;
        }
    };
    preorder(root, result, TempStruct::executeFunc);

    return result;
}

ConcatStringTree CST::concat(const ConcatStringTree & otherS) const{

    CSTNode *node = new CSTNode(this->length(), this->root->length+ otherS.length(),
    this->root->numNode+otherS.numNode(),"", this->root, otherS.root);
    
    CST result(node, true, true);
    return (CST&&)result;
}


ConcatStringTree CST::subString(int from, int to) const{
    if (from <0 || to>length()) {
        throw out_of_range("Index of string is invalid!");
    }

    if (from >= to) {
        throw logic_error("Invalid range!");
    }

    struct TempStruct{
        int from;
        int to;
        int current;

        static void executeFunc(CSTNode *a, TempStruct &result){
            /*  
                Store answer to alternative, then postorder to collect those
            */ 
            if(!a->left && !a->right){//is string node
                string tpStr = "";
                FOR(i, 0, a->length) {
                    int currentPos = result.current + i;
                    if(currentPos >= result.from && currentPos < result.to) {
                        tpStr += a->data[i];
                    }
                }
                if(tpStr.size()!= 0){
                    CSTNode *tpNode = new CSTNode(0,tpStr.size(),1,tpStr);
                    a->alternative = tpNode;
                }
                result.current+= a->length;
            }
            else{//non-string node
                bool isAlternative  = false ;            
                CSTNode *tpNode = new CSTNode();

                if(a->left != nullptr && a->left->alternative!=nullptr){
                    tpNode->leftLength = a->left->alternative->length;
                    tpNode->left = a->left->alternative;
                    tpNode->length += a->left->alternative->length;
                    a->left->alternative = nullptr;
                    isAlternative = true;
                }
                if(a->right != nullptr && a->right->alternative!=nullptr){
                    tpNode->right = a->right->alternative;
                    tpNode->length += a->right->alternative->length;
                    a->right->alternative = nullptr;
                    isAlternative = true;
                }

                if(isAlternative){
                    a->alternative = tpNode;
                }
                else{
                    delete tpNode;
                }
            }
        }
    };

    TempStruct obj{from, to , 0};
    postorder(root, obj, TempStruct::executeFunc);

    CST result;
    result.root = root->alternative;
    result.isTemporary = true;
    result.isShallowNorDeep =false;

    //cout<<result.toStringPreOrder()<<endl;
    root->alternative = nullptr;
    return (CST&&) result;

}

ConcatStringTree CST::reverse() const{
    
    struct TempStruct{
        int from;
        int to;
        int current;

        static void executeFunc(CSTNode *a, TempStruct &result){
            /*  
                Store answer to alternative, then postorder to collect those
            */ 
            if(!a->left && !a->right){//is string node
                
                string tpStr = "";
                FORR(i, 0, a->length) {
                    tpStr += a->data[i];
                }

                CSTNode *tpNode = new CSTNode(0,tpStr.size(),1,tpStr);
                a->alternative = tpNode;
                
            }
            else{//non-string node
                bool isAlternative  = false ;            
                CSTNode *tpNode = new CSTNode();

                if(a->left != nullptr && a->left->alternative!=nullptr){
                    tpNode->right = a->left->alternative;
                    tpNode->length += a->left->alternative->length;

                    a->left->alternative = nullptr;
                    isAlternative = true;
                }
                if(a->right != nullptr && a->right->alternative!=nullptr){
                    tpNode->leftLength = a->right->alternative->length;
                    tpNode->left = a->right->alternative;
                    tpNode->length += a->right->alternative->length;

                    a->right->alternative = nullptr;
                    isAlternative = true;
                }

                if(isAlternative){
                    a->alternative = tpNode;
                }
                else{
                    delete tpNode;
                }
            }
        }
    };

    TempStruct obj;
    postorder(root, obj, TempStruct::executeFunc);

    CST result;
    result.root = root->alternative;
    result.isTemporary = true;
    result.isShallowNorDeep =false;

    //cout<<result.toStringPreOrder()<<endl;
    root->alternative = nullptr;
    return (CST&&) result;

}
/*
int CST::getParTreeSize(const string & query) const{

}
string CST::getParTreeStringPreOrder(const string & query) const{

}

*/