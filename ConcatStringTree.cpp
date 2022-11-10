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
#define PT ParentsTree
#define LS LitString
#define LSH LitStringHash
#define RCST ReducedConcatStringTree

// CSTNode SECTION
CSTNode::CSTNode(int _leftLength=0, int _length = 0, string _data = "", CSTNode *_left = nullptr, CSTNode *_right=nullptr ): 
    leftLength(_leftLength),
    length(_length),
    data(_data),
    left(_left),
    right(_right)
{
}

// CST SECTION
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
        return;
    }

    //is return from the reverse or substring so we deep copy
        
    struct TempStruct{    
        PTNode *target;
        static CSTNode* executeFunc(CSTNode * root, TempStruct &result, CSTNode*left, CSTNode *right){
            CSTNode *cstnode = new CSTNode();
            *(cstnode) = *(root);
            cstnode->left = left;
            cstnode->right = right;

            if(root->left) delete root->left;
            if(root->right) delete root->right;

            return cstnode;
        }
    };

    
    
    //BUG
    TempStruct obj;
    this->root = postorder(otherS.root, obj, TempStruct::executeFunc);
    delete otherS.root;

    createParentAndChildAncestor(*this);    
    
}

CST::CST(const char * _s){
    int i = 0;
    string s = "";
    while (_s[i] != '\0') {
        s += _s[i];
        i++;
    }
    
    CSTNode* cstnode = new CSTNode(0, s.size(), s, nullptr, nullptr);
    PTNode * ptnode  = new PTNode(cstnode,0,0, nullptr, nullptr);
    ptnode->newID();
    cstnode->parent.insert(cstnode->parent.root, ptnode);
    
    root = cstnode;

    isShallowNorDeep = false;
    isTemporary = false;

}

CST::~CST(){
    if(isTemporary) return;
    
    struct TempStruct{   
        int target;
        static void ancestorFunc(CSTNode * root, TempStruct &result){
            if(root->ancestor.findPTNode(root->ancestor.root, result.target))
                root->ancestor.deleteNode(root->ancestor.root, result.target);

        }  
        static CSTNode* deleteFunc(CSTNode * root, TempStruct &result, CSTNode* left, CSTNode *right){
            
            if(root->ancestor.size() + root->parent.size() == 0){
                root->left = left;
                root->right = right;
                delete root;
            }


            return nullptr;

        }  
    };
    
    int  deletingId = root->myId;
    root->parent.deleteNode(root->parent.root, deletingId);
    
    TempStruct obj{deletingId};
    CSTNode * left = this->root->left , *right = this->root->right;
    if(left){
        if(left->parent.findPTNode(left->parent.root, deletingId)) 
            left->parent.deleteNode(left->parent.root, deletingId);

        preorder(left->left, obj, TempStruct::ancestorFunc);
        preorder(left->right, obj, TempStruct::ancestorFunc);
    }

    if(right){
        
        if(right->parent.findPTNode(right->parent.root, deletingId)) 
            right->parent.deleteNode(right->parent.root, deletingId);
        
        preorder(right->left, obj, TempStruct::ancestorFunc);
        preorder(right->right, obj, TempStruct::ancestorFunc);
    }

    if(root->ancestor.size() + root->parent.size() == 0){
        postorder(root, obj, TempStruct::deleteFunc);
        root = nullptr;
    }
}

int CST::length() const{
    return root->length;
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
    
    string result = "ConcatStringTree[\"";
    
    struct TempStruct{
        static void executeFunc (CSTNode *a, string &result){ 
            result+= a->data;
        }
    };
    preorder(root, result, TempStruct::executeFunc);
    result+= "\"]";
    return result;
}

ConcatStringTree CST::concat(const ConcatStringTree & otherS) const{

    CSTNode *cstnode = new CSTNode(this->length(), this->root->length+ otherS.length(),"", this->root, otherS.root);
    CST result(cstnode, true, true);

    //parentTree
    this->createParentAndChildAncestor(result);
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
        
        static CSTNode* executeFunc(CSTNode * root, TempStruct &result, CSTNode *left, CSTNode *right){
            if(root->left == nullptr && root->right == nullptr){//is string node
                string tpStr = "";
                FOR(i, 0, root->length) {
                    int currentPos = result.current + i;
                    if(currentPos >= result.from && currentPos < result.to) {
                        tpStr += root->data[i];
                    }
                }
                
                result.current+= root->length;

                if(tpStr.size()!= 0){
                    CSTNode *cstnode = new CSTNode(0,tpStr.size(),tpStr);
                    return cstnode;
                }
                else return nullptr;
            }
            else{//non-string node                
                if(left == nullptr && right == nullptr) return nullptr;

                int leftLength = 0, length = 0 ;
                if(left) {
                    leftLength = left->length;
                    length += left->length;
                }
                if(right) {
                    length += right->length;
                }
                CSTNode * nRoot = new CSTNode(leftLength, length, "", left, right);

                return nRoot;
            }
        }

    };
    
    TempStruct obj{from , to , 0};
    CSTNode * tempRoot = postorder(this->root, obj, TempStruct::executeFunc); 

    CST result;
    result.root = tempRoot;
    result.isTemporary = true;
    result.isShallowNorDeep =false;

    //cout<<result.toStringPreOrder()<<endl;
    return (CST&&) result;

}

ConcatStringTree CST::reverse() const{
    
    struct TempStruct{   
        static CSTNode* executeFunc(CSTNode * root, TempStruct &result, CSTNode *left, CSTNode *right){
            if(root->left == nullptr && root->right == nullptr){//is string node
                string tpStr = "";
                FORR(i, 0, root->length) {
                    tpStr += root->data[i];
                }

                CSTNode *cstnode = new CSTNode(0,tpStr.size(),tpStr);
                return cstnode;
            }
            else{//non-string node                
                if(left == nullptr && right == nullptr) return nullptr;

                int leftLength = 0, length = 0 ;
                if(right) {
                    leftLength = right->length;
                    length += right->length;
                }
                if(left) {
                    length += left->length;
                }
                CSTNode * nRoot = new CSTNode(leftLength, length, "", right, left);

                return nRoot;
            }  
        } 
    };
    
    TempStruct obj;
    CSTNode * tempRoot = postorder(this->root, obj, TempStruct::executeFunc); 

    CST result;
    result.root = tempRoot;
    result.isTemporary = true;
    result.isShallowNorDeep =false;

    //cout<<result.toStringPreOrder()<<endl;
    return (CST&&) result;

}

int CST::getParTreeSize(const string & query) const{
    CSTNode *roam = this->root;
    FOR(i,0,query.size()){
        if(query[i] == 'l'){
            if(roam->left == nullptr) throw runtime_error("Invalid query: reaching NULL");
            roam = roam->left;
        }
        else if(query[i] == 'r'){
            if(roam->right == nullptr) throw runtime_error("Invalid query: reaching NULL");
            roam = roam->right;
        }
        else{
            throw runtime_error("Invalid character of query");
        }
    }
    return roam->parent.size();
}

string CST::getParTreeStringPreOrder(const string & query) const{
    CSTNode *roam = this->root;
    FOR(i,0,query.size()){
        if(query[i] == 'l'){
            if(roam->left == nullptr) throw runtime_error("Invalid query: reaching NULL");
            roam = roam->left;
        }
        else if(query[i] == 'r'){
            if(roam->right == nullptr) throw runtime_error("Invalid query: reaching NULL");
            roam = roam->right;
        }
        else{
            throw runtime_error("Invalid character of query");
        }
    }
    return roam->parent.toStringPreOrder();
}

void CST::createParentAndChildAncestor(CST &cstObj) const{
    
    struct TempStruct{   
        PTNode *target;
        static void ancestorFunc(CSTNode * root, TempStruct &result){
            if(!root->ancestor.findPTNode(root->ancestor.root,result.target->id)){
                PTNode *ptnode = new PTNode(result.target->data, result.target->id,0,nullptr,nullptr);
                root->ancestor.insert(root->ancestor.root,ptnode);
            } 
        }  
    };
    
    PTNode *ptnode = new PTNode(cstObj.root, 0,0,nullptr,nullptr);
    ptnode->newID();

    TempStruct obj{ptnode};

    cstObj.root->parent.insert(cstObj.root->parent.root, ptnode);
    
    CSTNode * left = cstObj.root->left , *right = cstObj.root->right;
    if(left){
        if(!left->parent.findPTNode(left->parent.root, ptnode->id)) {
            
            PTNode *leftNode = new PTNode(ptnode->data, ptnode->id,0,nullptr,nullptr);
            left->parent.insert(left->parent.root, leftNode);
        }

        preorder(left->left, obj, TempStruct::ancestorFunc);
        preorder(left->right, obj, TempStruct::ancestorFunc);
    }

    if(right){
        
        if(!right->parent.findPTNode(right->parent.root,ptnode->id)){
            PTNode *rightNode = new PTNode(ptnode->data, ptnode->id,0,nullptr,nullptr);
            right->parent.insert(right->parent.root, rightNode);
        } 
        
        preorder(right->left, obj, TempStruct::ancestorFunc);
        preorder(right->right, obj, TempStruct::ancestorFunc);
    }
}

// PTNode SECTION
int PTNode::maxId = 0;
PTNode::PTNode( CSTNode* _data = nullptr, int _id = 0, int _height = 0, PTNode * _left = nullptr, PTNode* _right = nullptr):
    data(_data), id(_id), height(_height), left(_left), right(_right)
{
}

void PTNode::newID(){
    maxId++;
    if(maxId>= 10000000){
        throw overflow_error("Id is overflow!");
    }
    id = maxId; 
    this->data->myId = id;
}


//ParentTree SECTION
int PT::size() const{
    return numElement;
}

string PT::toStringPreOrder() const{
    string result = "ParentsTree[";
    
    struct TempStruct{
        static void executeFunc (PTNode *a, string &result){
            
            if(result.back() == ')') result+= ';';
            result+= "(id="+ to_string(a->id)+")";
        }
    };
    
    preorder(this->root, result, TempStruct::executeFunc); 
    result+= "]";
    return result;
}


//LitString SECTION
LS::LitString(CSTNode *_data,string _s , int _reference): data(_data),s(_s), reference(_reference)
{

}

LS::~LitString(){
    if(reference == 0) delete data;
}

//LitStringHash SECTION
LSH::LitStringHash(const HashConfig &_config){
    config = _config;
    litHash = new LS*[config.initSize];
    FOR(i,0,config.initSize){
        litHash[i] = nullptr;
    }
}

ll LSH::hashFunc(string s){
    ll result = 0;
    FOR(i,0,s.size()){
        result+= (ll)s[i]*(ll)config.p;
    }
    result = result% ((ll)config.initSize);
    return (int) result;
}

void LSH::rehash(){
    int nSize = config.alpha* (double)config.initSize;
    LitString **nHash = new LitString*[nSize];
    FOR(i,0,config.initSize){
        LitString *current = litHash[i];
        LitString *nLitString = new LitString(current->data, current->s, current->reference);
        nHash[i] = nLitString;
    }
    delete litHash;
    litHash = nHash;
}

CSTNode* LSH::insert(string s){
    
    if(numOfElement == config.initSize){
        throw runtime_error("No possible slot");
    }
    ll h = hashFunc(s);
    double hashedValue = h;

    FOR(i,0,config.initSize){
        h =((int)floor( hashedValue + config.c1*(double)i+ config.c2*(double)(i*i)+config.initSize))%config.initSize; 
        if(litHash[h] == NULL || litHash[h]->s == s){
            break;
        }
    }

    if((double)numOfElement/(double)config.initSize > config.lambda) rehash();

    if(litHash[h] == nullptr){
        CSTNode *cstnode = new CSTNode(0, (int)s.size(), s, nullptr, nullptr);
        litHash[h] = new LS(cstnode, s, 1);
        numOfElement++;
        return cstnode;
    }
    else{
        litHash[h]->reference++;
        return litHash[h]->data;
    }

}

//ReducedConcatStringTree SECTION
RCST::ReducedConcatStringTree(const char * _s, LitStringHash * _litStringHash){
    int i = 0;
    string s = "";
    while (_s[i] != '\0') {
        s += _s[i];
        i++;
    }

    litStringHash = _litStringHash;
    CSTNode *cstnode = litStringHash->insert(s);
    
    PTNode * ptnode  = new PTNode(cstnode,0,0, nullptr, nullptr);
    ptnode->newID();
    cstnode->parent.insert(cstnode->parent.root, ptnode);
    
    root = cstnode;

    isShallowNorDeep = false;
    isTemporary = false;

}


/*
 int SearchKey(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL)
            return -1;
         else
            return t[h]->v;
      }
      void Remove(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL) {
            if (t[h]->k == k)
               break;
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL) {
            cout<<"No Element found at key "<<k<<endl;
            return;
         } else {
            delete t[h];
         }
         cout<<"Element Deleted"<<endl;
      }

*/