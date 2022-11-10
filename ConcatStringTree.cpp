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
#define HC HashConfig

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

    
    TempStruct obj;
    this->root = postorder(otherS.root, obj, TempStruct::executeFunc);
    delete otherS.root;

    this->createParentAndChildAncestor();    
    
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
                root->left = nullptr;
                root->right = nullptr;
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
    result.createParentAndChildAncestor();
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

void CST::createParentAndChildAncestor() const{
    
    struct TempStruct{   
        PTNode *target;
        static void ancestorFunc(CSTNode * root, TempStruct &result){
            if(!root->ancestor.findPTNode(root->ancestor.root,result.target->id)){
                PTNode *ptnode = new PTNode(result.target->data, result.target->id,0,nullptr,nullptr);
                root->ancestor.insert(root->ancestor.root,ptnode);
            } 
        }  
    };
    
    PTNode *ptnode = new PTNode(this->root, 0,0,nullptr,nullptr);
    ptnode->newID();

    TempStruct obj{ptnode};

    this->root->parent.insert(this->root->parent.root, ptnode);
    
    CSTNode * left = this->root->left , *right = this->root->right;
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

//HashConfig SECTION
HC::HC(int _p = 0, double _c1 = 0, double _c2 = 0, double _lambda= 0 , double _alpha= 0 , int _initSize= 0):
    p(_p), c1(_c1), c2(_c2), lambda(_lambda), alpha(_alpha), initSize(_initSize)
{

}

//LitString SECTION
LS::LS(CSTNode *_data ,string _s , int _reference): data(_data),s(_s), reference(_reference)
{

}

LS::~LS(){
    if(reference == 0) delete data;
}

//LitStringHash SECTION
LSH::LSH(const HashConfig &_config){
    config = _config;
    lastInsertedIndex = -1;
    litHash = new LS*[config.initSize];
    FOR(i,0,config.initSize){
        litHash[i] = nullptr;
    }
}

LSH::~LSH(){
    if(numOfElement) return ;
}

ll LSH::hashFunc(string s){
    ll result = 0, currP = 1;
    FOR(i,0,s.size()){
        result+= ((ll)s[i])*currP;
        currP *= config.p; 
    }
    result = result% ((ll)config.initSize);
    return (int) result;
}

int LSH::probingFunc(int hashedValue, long long i){
    return ((int)( (double)hashedValue + config.c1*(double)i+ config.c2*(double)(i*i)+config.initSize))%config.initSize; 
}

void LSH::rehash(){
    int nSize = config.alpha* (double)config.initSize;
    LitString **nHash = new LitString*[nSize];
    FOR(i,0,config.initSize){
        LitString *current = litHash[i];
        LitString *nLitString = new LitString(current->data, current->s, current->reference);
        nHash[i] = nLitString;
        delete current;
    }
    delete []litHash;
    litHash = nHash;
}

CSTNode* LSH::insert(string s){
    
    if(numOfElement == config.initSize){
        throw runtime_error("No possible slot");
    }
    ll index = hashFunc(s), hashedValue = index;

    FOR(i,0,config.initSize){
        index = probingFunc(hashedValue, i); 
        if(litHash[index] == NULL || litHash[index]->s == s){
            break;
        }
    }

    if((double)numOfElement/(double)config.initSize > config.lambda) rehash();

    if(litHash[index] == nullptr){
        CSTNode *cstnode = new CSTNode(0, (int)s.size(), s, nullptr, nullptr);
        litHash[index] = new LS(cstnode, s, 1);
        numOfElement++;
        lastInsertedIndex = index;
        return cstnode;
    }
    else{
        litHash[index]->reference++;
        return litHash[index]->data;
    }

}

void LSH::remove(string s) {
    int index = hashFunc(s), hashedValue = index;
    for (long long i = 0; litHash[index]->s != s; i++) {
        index = probingFunc(hashedValue, i);
    }
    if (litHash[index] == NULL) {
        throw runtime_error("NO STRING FOUND");
        return;
    }
    cout << "litHash[index] " << litHash[index]->s << " = " << litHash[index]->reference << endl;

    litHash[index]->reference--;
    if(litHash[index]->reference == 0){
        
        delete litHash[index];
        numOfElement--;
        if(numOfElement == 0){
            delete [] litHash;
            lastInsertedIndex = -1;
        }
    }
    

}

int LSH::getLastInsertedIndex() const{
    return lastInsertedIndex;
}

string LSH::toString() const{
    string result = "LitStringHash[";
    FOR(i,0,config.initSize){
        if(result.back() == ')') result+= ";";
        result+= "(";
        if(litHash[i]!= nullptr && litHash[i]->reference!=0){
            result+= "litS=\""+ litHash[i]->s+"\"";
        }
        result+= ")";
    }

    result+= "]";
    return result;
}

//ReducedConcatStringTree SECTION
RCST::RCST(const char * _s, LitStringHash * _litStringHash){
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

RCST::RCST(CSTNode * _root = nullptr, LitStringHash * _litStringHash = nullptr, bool _isTemporay = false, bool _isShallowNorCopy = false):
   CST(_root, _isTemporay, _isShallowNorCopy), litStringHash(_litStringHash)
{

}

RCST::RCST(RCST && otherS){
    this->root = nullptr;
    this->litStringHash = otherS.litStringHash;
    this->isShallowNorDeep = false;
    this->isTemporary = false;
    if (otherS.isShallowNorDeep) {//is return from concat so we shallow copy
        (this->root) = (otherS.root);
        return;
    }

    //is return from the reverse or substring so we deep copy
        
    struct TempStruct{    
        
        LitStringHash *litStringHash;
        static CSTNode* executeFunc(CSTNode * root, TempStruct &result, CSTNode*left, CSTNode *right){
            CSTNode *cstnode = nullptr;
            if(root->left == nullptr && root->right == nullptr){//is string node
                cstnode = result.litStringHash->insert(root->data);
            }
            else{
                cstnode = new CSTNode();
                *(cstnode) = *(root);
                cstnode->left = left;
                cstnode->right = right;
            }

            if(root->left) delete root->left;
            if(root->right) delete root->right;

            return cstnode;
        }
    };

    
    TempStruct obj{this->litStringHash};
    this->root = postorder(otherS.root, obj, TempStruct::executeFunc);
    delete otherS.root;

    this->createParentAndChildAncestor();    
    
}

RCST::~RCST(){
    if(isTemporary) return;
    
    struct TempStruct{   
        int target;
        LitStringHash *litStringHash;

        static void ancestorFunc(CSTNode * root, TempStruct &result){
            if (root->ancestor.findPTNode(root->ancestor.root, result.target)) {
                root->ancestor.deleteNode(root->ancestor.root, result.target);

            }
        }  
        static CSTNode* deleteFunc(CSTNode * root, TempStruct &result, CSTNode* left, CSTNode *right){
            if (root->left == nullptr && root->right == nullptr && root->data != "") {
                result.litStringHash->remove(root->data);

            }
            else if (root->ancestor.size() + root->parent.size() == 0){//is non-string node
                
                root->left = nullptr;
                root->right = nullptr;
                delete root;
            }
            return nullptr;
        }  
    };
    
    int  deletingId = root->myId;
    root->parent.deleteNode(root->parent.root, deletingId);
    
    TempStruct obj{deletingId, litStringHash};
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

    postorder(root, obj, TempStruct::deleteFunc);
    if(root->ancestor.size() + root->parent.size() == 0){
        root = nullptr;
    }
    
    isTemporary = true;
}


ReducedConcatStringTree RCST::concat(const ReducedConcatStringTree& otherS) const {

    CSTNode* cstnode = new CSTNode(this->length(), this->root->length + otherS.length(), "", this->root, otherS.root);
    RCST result(cstnode, this->litStringHash, true, true);

    //parentTree
    result.createParentAndChildAncestor();
    return (RCST&&)result;
}

ReducedConcatStringTree RCST::subString(int from, int to) const{
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

    RCST result(tempRoot, litStringHash, true, false);
    //result.root = tempRoot;
    //result.isTemporary = true;
    //result.isShallowNorDeep =false;

    //cout<<result.toStringPreOrder()<<endl;
    return (RCST&&) result;

}

ReducedConcatStringTree RCST::reverse() const{
    
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

    RCST result(tempRoot, litStringHash, true, false);
    //result.root = tempRoot;
    //result.isTemporary = true;
    //result.isShallowNorDeep =false;

    //cout<<result.toStringPreOrder()<<endl;
    return (RCST&&) result;

}


void RCST::createParentAndChildAncestor() const{
    
    struct TempStruct{   
        PTNode *target;
        static void ancestorFunc(CSTNode * root, TempStruct &result){
            if(!root->ancestor.findPTNode(root->ancestor.root,result.target->id)){
                PTNode *ptnode = new PTNode(result.target->data, result.target->id,0,nullptr,nullptr);
                root->ancestor.insert(root->ancestor.root,ptnode);
            } 
        }  
    };
    
    PTNode *ptnode = new PTNode(this->root, 0,0,nullptr,nullptr);
    ptnode->newID();

    TempStruct obj{ptnode};

    this->root->parent.insert(this->root->parent.root, ptnode);
    
    CSTNode * left = this->root->left , *right = this->root->right;
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

//*/


    

