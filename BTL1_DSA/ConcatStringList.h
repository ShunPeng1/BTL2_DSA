#ifndef __CONCAT_STRING_LIST_H__
#define __CONCAT_STRING_LIST_H__

#include "main.h"

struct CharALNode;
struct RefNode;
struct DelNode;

struct CharALNode {
    CharALNode* next;
    RefNode* referenceNode;
    string CharArrayList;

    CharALNode();
    CharALNode(string s, CharALNode* _next,RefNode *referenceNode);
};

struct RefNode {
    RefNode* next;
    CharALNode* original;
    int nReference;
    bool isDeleted;
    bool isHeadOrTail;
    RefNode(RefNode* _next, CharALNode* _original, int _nRef, bool _isHeadOrTail);

};

struct DelNode {
    DelNode* next;
    RefNode** chainRN;
    int nChainRN;
    DelNode(DelNode* _next, CharALNode* headCALN, CharALNode* tailCALN, int length);
    ~DelNode();
};
class ConcatStringList {
private:
    CharALNode* head, * tail;
    int nNode, nChar;
    bool isConcated, isTemporary;
public:
    class ReferencesList; // forward declaration
    class DeleteStringList; // forward declaration

    static ReferencesList refList;
    static DeleteStringList delStrList;

    bool isEmptyList() {
        return head == nullptr;
    }

    ConcatStringList();
    ConcatStringList(const char* s);
    ConcatStringList(const ConcatStringList&&);
    int length() const;
    char get(int) const;
    int indexOf(char) const;
    std::string toString() const;
    ConcatStringList concat(const ConcatStringList&) const;
    ConcatStringList subString(int, int) const;
    ConcatStringList reverse() const;
    ~ConcatStringList();


public:
    class ReferencesList {
        // TODO: may provide some attributes
        RefNode* headRef = nullptr, * tailRef = nullptr;
        int nNodeRef = 0;

        friend class ConcatStringList;
        friend class DeleteStringList;
    public:

        int size() const;
        int refCountAt(int index) const;
        std::string refCountsString() const;

        //Reference Additional Function
        void addFrontRefNode(CharALNode*, int, bool);
        void increaseNumOfRefAt(CharALNode*, int, bool);
        RefNode* getRNPointer(CharALNode*);
        void DeleteIfAll0();

        //Sort function
        void  mergeSort(RefNode**);
        RefNode* sortedMerge(RefNode* , RefNode* );
        void  frontBackSplit(RefNode*, RefNode**, RefNode**);
        bool compareRef(RefNode*, RefNode*);
    };

    class DeleteStringList {
        // TODO: may provide some attributes
        DelNode* headDel = nullptr, * tailDel = nullptr;
        int nNodeDel = 0;

        friend class ConcatStringList;
        friend class ReferencesList;

    public:
        int size() const;
        std::string totalRefCountsString() const;

        //Delete Additional Function

        int sumHeadAndTailNumOfRef(DelNode*) const;
        void addBackDelNode(DelNode*&);
        void loopToDeallocateNode();
        void deleteCharALNode(DelNode*);
    };
};

#endif // __CONCAT_STRING_LIST_H__