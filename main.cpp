#include "ConcatStringTree.h"

#define CST ConcatStringTree
#define RCST ReducedConcatStringTree



void tc1()
{ 
    ConcatStringTree s1("acbbcab");
    cout << s1.length() << endl;
    cout << s1.get(1) << endl;
    try {
        cout << "char at index 10: " << s1.get(10) << endl;
    }
    catch (const out_of_range& ofr) {
        cout << "Exception out_of_range: " << ofr.what() << endl;
    }
    cout << s1.indexOf('b') << endl;
}

void tc2()
{
    ConcatStringTree s1("Hello");
    ConcatStringTree s2(",_t");
    ConcatStringTree s3 = s1.concat(s2);
    cout << s3.toStringPreOrder() << endl;
    cout << s3.toString() << endl;
    cout << s3.subString(5, 6).toString() << endl;
    cout << s3.reverse().toString() << endl;
}

void tc3()
{
    ConcatStringTree* s1 = new ConcatStringTree("a");
    
    cout << s1->getParTreeSize("") << endl;
    cout << s1->getParTreeStringPreOrder("") << endl;
    ConcatStringTree* s2 = new ConcatStringTree("b");
    
    cout << s2->getParTreeSize("") << endl;
    cout << s2->getParTreeStringPreOrder("") << endl;
    ConcatStringTree* s3 = new ConcatStringTree(s1->concat(*s2));

    cout << s3->getParTreeSize("") << endl;
    cout << s3->getParTreeStringPreOrder("") << endl;
    
    cout << s3->getParTreeSize("l") << endl;
    cout << s3->getParTreeStringPreOrder("l") << endl;
    
    ConcatStringTree* s4 = new ConcatStringTree(s3->reverse());

    cout << s4->getParTreeSize("") << endl;
    cout << s4->getParTreeStringPreOrder("") << endl;

    cout << s4->getParTreeSize("l") << endl;
    cout << s4->getParTreeStringPreOrder("l") << endl;

    delete s1;
    delete s2;
    delete s3;
    delete s4;
}

void tc4()
{
    HashConfig hashConfig(
        2,
        0.5,
        0.5,
        0.75,
        2.0,
        4
    );
    LitStringHash* litStringHash = new LitStringHash(hashConfig);
    ReducedConcatStringTree* s1 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree* s2 = new ReducedConcatStringTree("bb", litStringHash);

    cout << s1->toString() << endl;
    cout << s2->toString() << endl;

    
    cout << litStringHash->getLastInsertedIndex() << endl;
    ReducedConcatStringTree* s3 = new ReducedConcatStringTree("bb", litStringHash);

    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;
    
    delete s3;
    
    cout << litStringHash->getLastInsertedIndex() << endl;
    delete s1;
    
    cout << litStringHash->getLastInsertedIndex() << endl;
    delete s2;
    
    cout << litStringHash->getLastInsertedIndex() << endl;
    delete litStringHash;
}
//*/
void tc5()
{
    ConcatStringTree s1("Hello");
    cout << "Please focus to id: " << s1.getParTreeStringPreOrder("") << endl;
    ConcatStringTree s2("an-nyeong-ha-se-yo");
    cout << "Please focus to id: " << s2.getParTreeStringPreOrder("") << endl;
    ConcatStringTree s3("nee how");
    cout << "Please focus to id: " << s3.getParTreeStringPreOrder("") << endl;
}
//*/

void tc6(){
    ConcatStringTree s1("Hello");
    ConcatStringTree s2(",_t");
    ConcatStringTree s3 = s1.concat(s2);
    cout << s3.toStringPreOrder() << endl;
    cout << s3.toString() << endl;
    cout << s3.subString(5, 6).toString() << endl;
    cout << s3.reverse().toString() << endl;
}


void tc11(){
    
    CST *s1 = new CST("Hello"), *s2 = new CST("World");
    cout<<s1->get(0)<<endl;
    cout<<s1->get(1)<<endl;
    cout<<s1->get(2)<<endl;
    cout<<s1->get(3)<<endl;
    cout<<s1->get(4)<<endl;
    cout<<s1->indexOf('H')<<endl;
    cout<<s1->indexOf('e')<<endl;
    cout<<s1->indexOf('l')<<endl;
    cout<<s1->indexOf('l')<<endl;
    cout<<s1->indexOf('o')<<endl;
    cout<<s1->indexOf('a')<<endl;
    cout<<s1->toStringPreOrder()<<endl;
    cout<<s1->toString()<<endl;

    CST *s3 = new CST( s1->concat(*s2));
    cout<<endl<<endl;
    cout<<s3->get(5)<<endl;
    cout<<s3->get(6)<<endl;
    cout<<s3->get(7)<<endl;
    cout<<s3->get(8)<<endl;
    cout<<s3->get(9)<<endl;
    cout<<s3->indexOf('W')<<endl;
    cout<<s3->indexOf('o')<<endl;
    cout<<s3->indexOf('r')<<endl;
    cout<<s3->indexOf('l')<<endl;
    cout<<s3->indexOf('d')<<endl;
    cout<<s3->indexOf('a')<<endl;
    cout<<s3->toStringPreOrder()<<endl;
    cout<<s3->toString()<<endl;

    cout<<s3->getParTreeSize("")<<endl;
    cout<<s3->getParTreeStringPreOrder("")<<endl;
    cout<<s3->getParTreeSize("l")<<endl;
    cout<<s3->getParTreeStringPreOrder("l")<<endl;
    cout<<endl<<endl;

    delete s1;
    
    cout<<s3->getParTreeSize("")<<endl;
    cout<<s3->getParTreeStringPreOrder("")<<endl;
    cout<<s3->getParTreeSize("l")<<endl;
    cout<<s3->getParTreeStringPreOrder("l")<<endl;
    delete s2;
    delete s3;
    

}
void tc12(){
    
    CST *s1 = new CST("Hello"), *s2 = new CST("World");

    CST *s3 = new CST (s1->concat(*s2));
    
    CST *s4 = new CST( s3->subString(1,9));
    CST *s6 = new CST(s3->subString(1,4));
    cout<<"s4 = "<<s4->toStringPreOrder()<<endl;
    cout<<"s6 = "<<s6->toStringPreOrder()<<endl;

    CST *s5 = new CST(s4->reverse());
    CST *s7 = new CST(s6->reverse());
    cout<<"s5 = "<<s5->toStringPreOrder()<<endl;
    cout<<"s7 = "<<s7->toStringPreOrder()<<endl;

    delete s7;
    delete s5;
    delete s6;
    delete s4;
    delete s3;
    delete s2;
    delete s1;


}


void tc15(){
        ConcatStringTree *sA = new CST("ABC"), *sB = new CST("DEF"), *sC = new CST("GHI");

        ConcatStringTree *s1 = new CST( sA->concat(*sB)); // ABCDEF

        ConcatStringTree *s2 = new CST (sB->concat(*sC)); // DEFGHI

        ConcatStringTree *s3 = new CST (s1->concat(*s2)); // ABCDEFDEFGHI


        cout << s3->toString() << endl; // BCDEFDEFGH

        cout << s3->getParTreeSize("") << endl;
        cout << s3->getParTreeStringPreOrder("") << endl; 
        cout << s3->getParTreeSize("l") << endl;
        cout << s3->getParTreeStringPreOrder("l") << endl;
        cout << s3->getParTreeSize("r") << endl;
        cout << s3->getParTreeStringPreOrder("r") << endl;
        cout << s3->getParTreeSize("rl") << endl;
        cout << s3->getParTreeStringPreOrder("rl") << endl;
        cout << s3->getParTreeSize("lr") << endl;
        cout << s3->getParTreeStringPreOrder("lr") << endl;
        cout << s3->getParTreeSize("ll") << endl;
        cout << s3->getParTreeStringPreOrder("ll") << endl;
        cout << s3->getParTreeSize("rr") << endl;
        cout << s3->getParTreeStringPreOrder("rr") << endl;
        
        ConcatStringTree *s4 = new CST (s3->subString(1, s3->length()-1));
        
        ConcatStringTree *s5 = new CST (s3->reverse());

        
        delete s1;
        cout<<"\ndelete s1 \n";
        cout << s3->getParTreeSize("l") << endl;
        cout << s3->getParTreeStringPreOrder("l") << endl;
        
        delete s2;
        cout<<"\ndelete s2 \n";
        cout << s3->getParTreeSize("r") << endl;
        cout << s3->getParTreeStringPreOrder("r") << endl;

        delete sA;
        cout<<"\ndelete sA \n";
        cout << s3->getParTreeSize("ll") << endl;
        cout << s3->getParTreeStringPreOrder("ll") << endl;

        delete sC;
        cout<<"\ndelete sC \n";
        cout << s3->getParTreeSize("rr") << endl;
        cout << s3->getParTreeStringPreOrder("rr") << endl;        
        
        cout << s3->getParTreeSize("") << endl;
        cout << s3->getParTreeStringPreOrder("") << endl; 
        cout << s3->getParTreeSize("l") << endl;
        cout << s3->getParTreeStringPreOrder("l") << endl;
        cout << s3->getParTreeSize("r") << endl;
        cout << s3->getParTreeStringPreOrder("r") << endl;
        cout << s3->getParTreeSize("rl") << endl;
        cout << s3->getParTreeStringPreOrder("rl") << endl;
        cout << s3->getParTreeSize("lr") << endl;
        cout << s3->getParTreeStringPreOrder("lr") << endl;
        cout << s3->getParTreeSize("ll") << endl;
        cout << s3->getParTreeStringPreOrder("ll") << endl;
        cout << s3->getParTreeSize("rr") << endl;
        cout << s3->getParTreeStringPreOrder("rr") << endl;
        
        delete sB;
        cout<<"\ndelete sB \n";
        cout << s3->getParTreeSize("lr") << endl;
        cout << s3->getParTreeStringPreOrder("lr") << endl;

        delete s3;
        cout<<"delete s3 \n";
        
        delete s4;
        delete s5;
}

void tc16(){
    ConcatStringTree *t1 = new ConcatStringTree("Hello");
    ConcatStringTree *t2 = new ConcatStringTree(",_t");
    ConcatStringTree *t3 = new ConcatStringTree("his_is");
    ConcatStringTree *t4 = new ConcatStringTree("_an");

    //ConcatStringTree s1 = t1->concat(*t2).concat(*t3).concat(*t4);
    ConcatStringTree * v1 = new ConcatStringTree( t1->concat(*t2));
    ConcatStringTree s1 = v1->concat(*t3);
    delete v1;

    delete t1;
    delete t2;
    delete t3;
    delete t4;

    ConcatStringTree *t5 = new ConcatStringTree("_assign");
    ConcatStringTree *t6 = new ConcatStringTree("ment.");
    ConcatStringTree s2 = t5->concat(*t6);

    delete t5; delete t6;
    ConcatStringTree s3 = s1.concat(s2);

    cout << s3.reverse().toStringPreOrder() << endl;
    cout << s3.reverse().toString() << endl;

    cout << s3.subString(1,5).toStringPreOrder() << endl;
    cout << s3.subString(3,10).toStringPreOrder() << endl;
    cout << s3.subString(5,15).toStringPreOrder() << endl;

    cout << s3.subString(1,5).reverse().toStringPreOrder() << endl;
    cout << s3.subString(3,10).reverse().toStringPreOrder() << endl;
    cout << s3.subString(5,15).reverse().toStringPreOrder() << endl;

    cout << s3.getParTreeStringPreOrder("llr") << endl;
    cout << s3.getParTreeSize("llr") << endl;

    cout << s3.getParTreeStringPreOrder("rl") << endl;
    cout << s3.getParTreeSize("rl") << endl; 
}

void tc17(){
    CST sA("Hello"), sB(",_t"), sC("his_is"), sD("_an");
    CST s1 = sA.concat(sB), s2 = sC.concat(sD), s3 = s1.concat(s2);

    
    cout<<"s1 = "<<s1.toStringPreOrder()<<endl;
    cout<<"s2 = "<<s2.toStringPreOrder()<<endl;    
    cout<<"s3 = "<<s3.toStringPreOrder()<<endl;
    cout<<"s3 = "<<s3.toString()<<endl;
    
    CST s4 = s3.subString(1,10);
    
    cout<<"s4 = "<<s4.toStringPreOrder()<<endl;
    cout<<"s4 = "<<s4.toString()<<endl;

    CST s5 = s4.reverse();
    cout<<"s5 = "<<s5.toStringPreOrder()<<endl;
    cout<<"s5 = "<<s5.toString()<<endl;
}

void tc18(){
    CST sA("Hello"), sB(",_t"), sC("his_is"), sD("_an");
    CST s1 = sA.concat(sB), s2 = sC.concat(sD), s3 = s1.concat(s2);

    
    cout<<"s1 = "<<s1.toStringPreOrder()<<endl;
    cout<<"s1 = "<<s1.toString()<<endl; 
    
    cout<<"s2 = "<<s2.toStringPreOrder()<<endl;    
    cout<<"s2 = "<<s2.toString()<<endl; 

    cout<<"s3 = "<<s3.toStringPreOrder()<<endl;
    cout<<"s3 = "<<s3.toString()<<endl; 
    
    CST s4 = s3.subString(7,s3.length()-5);
    
    cout<<"s4 = "<<s4.toStringPreOrder()<<endl;
    cout<<"s4 = "<<s4.toString()<<endl; 
    
    CST s5 = s4.reverse();
    cout<<"s5 = "<<s5.toStringPreOrder()<<endl;
    cout<<"s5 = "<<s5.toString()<<endl; 
    
    
    CST s6 = s3.reverse();
    
    cout<<"s6 = "<<s6.toStringPreOrder()<<endl;
    cout<<"s6 = "<<s6.toString()<<endl; 
    
    CST s7 = s6.subString(0, s6.length());
    cout<<"s7 = "<<s7.toStringPreOrder()<<endl;
    cout<<"s7 = "<<s7.toString()<<endl; 

}

void tc19(){
    ConcatStringTree *t1 = new ConcatStringTree("Doraemon,");
    ConcatStringTree *t2 = new ConcatStringTree("Luke,");
    ConcatStringTree *t3 = new ConcatStringTree("Jerry,");
    ConcatStringTree *t4 = new ConcatStringTree("Than Don Dat Viet");
    ConcatStringTree *s0 = new ConcatStringTree(t1->concat(*t4));
    ConcatStringTree s1 = s0->concat(*t3);
    ConcatStringTree s2 = s1.concat(*t2);

    delete t1;
    delete t3;
    delete s0;
    cout << s1.getParTreeStringPreOrder("ll") << endl;
    delete t2;
    delete t4;
}

void tc20(){
    ConcatStringTree *t1 = new ConcatStringTree("Doraemon,");
    ConcatStringTree *t2 = new ConcatStringTree("Luke,");
    ConcatStringTree *t3 = new ConcatStringTree("Jerry,");
    ConcatStringTree *t4 = new ConcatStringTree("Than Don Dat Viet");

    ConcatStringTree s1 = t1->concat(*t4).concat(*t3).concat(*t2);

    delete t1;
    delete t3;

    cout << s1.getParTreeSize("llr") << endl;
    cout << s1.getParTreeSize("lr") << endl;
    cout << s1.getParTreeSize("lll") << endl;
    try{cout << s1.getParTreeSize("rr") << endl;}catch(...){cout << "NULL catched!\n";}

    cout << s1.getParTreeStringPreOrder("llr") << endl;
    cout << s1.getParTreeStringPreOrder("lr") << endl;
    cout << s1.getParTreeStringPreOrder("lll") << endl;
    
    delete t2;
    delete t4;
}

void tc22()
{
    ConcatStringTree *t1 = new ConcatStringTree("Doraemon,");
    ConcatStringTree *t2 = new ConcatStringTree("Luke,");
    ConcatStringTree *t3 = new ConcatStringTree("Jerry,");
    ConcatStringTree *t4 = new ConcatStringTree("Than Don Dat Viet");

    ConcatStringTree s1 = t4->concat(*t2).concat(*t1).concat(*t3);
    delete t1;
    delete t2;
    delete t3;
    delete t4;

    ConcatStringTree s2 = s1.subString(1,7).concat(s1.subString(6,9)).reverse().reverse();

    cout << s2.toStringPreOrder() << endl;
    cout << s2.toString() << endl;
}

void tc23()
{
    ConcatStringTree *t1 = new ConcatStringTree("Doraemon,");
    ConcatStringTree *t2 = new ConcatStringTree("Luke,");
    ConcatStringTree *t3 = new ConcatStringTree("Jerry,");
    ConcatStringTree *t4 = new ConcatStringTree("Than Don Dat Viet");

    ConcatStringTree s1 = t1->concat(*t4).concat(*t3).concat(*t2);

    delete t1;
    delete t3;

    cout << s1.getParTreeSize("llr") << endl;
    cout << s1.getParTreeSize("lr") << endl;
    cout << s1.getParTreeSize("lll") << endl;
    try{cout << s1.getParTreeSize("rr") << endl;}catch(...){cout << "NULL catched!\n";}

    cout << s1.getParTreeStringPreOrder("llr") << endl;
    cout << s1.getParTreeStringPreOrder("lr") << endl;
    cout << s1.getParTreeStringPreOrder("lll") << endl;
    
    delete t2;
    delete t4;
}

void tc24()
{
    // Example in the spec
    ConcatStringTree *t1 = new ConcatStringTree("Hello");
    ConcatStringTree *t2 = new ConcatStringTree(",_t");
    ConcatStringTree *t3 = new ConcatStringTree("his_is");
    ConcatStringTree *t4 = new ConcatStringTree("_an");

    ConcatStringTree s1 = t1->concat(*t2);
    ConcatStringTree s2 = t3->concat(*t4);

    delete t1;
    delete t2;
    delete t3;
    delete t4;

    ConcatStringTree s3 = s1.concat(s2).subString(1,8);

    cout << s3.toStringPreOrder() << endl;
}


void tc25(){
    CST *s0 = new CST("Hello"), *sB = new CST(",_t"), *sC = new CST("his_is"), *sD = new CST("_an");
    CST *s1 = new CST(s0->concat(*sB)), *s2 = new CST(sC->concat(*sD)), *s3 = new CST(s1->concat(*s2));

    cout<<"s1 : "<<s3->getParTreeStringPreOrder("l")<<endl;
    cout<<"s0 : "<<s3->getParTreeStringPreOrder("ll")<<endl;
    delete s1;
    cout<<"Deleted s1\n";
    cout<<"s1 : "<<s3->getParTreeStringPreOrder("l")<<endl;
    cout<<"s0 : "<<s3->getParTreeStringPreOrder("ll")<<endl;

    delete s0;
    cout<<"Deleted s0\n";
    cout<<"s1 : "<<s3->getParTreeStringPreOrder("l")<<endl;
    cout<<"s0 : "<<s3->getParTreeStringPreOrder("ll")<<endl;

    //Some more delete 
    delete s3;
    delete sB;
    delete sC;
    delete s2;
    delete sD;
}

void tc38() {
    ConcatStringTree* t1 = new ConcatStringTree("Hello");
    ConcatStringTree* t2 = new ConcatStringTree(",_t");
    ConcatStringTree* t3 = new ConcatStringTree("his_is");
    ConcatStringTree* t4 = new ConcatStringTree("_an");

    ConcatStringTree s1 = t1->concat(*t2).concat(*t3);

    delete t1;
    delete t2;
    delete t3;
    delete t4;

    ConcatStringTree* t5 = new ConcatStringTree("_assign");
    ConcatStringTree* t6 = new ConcatStringTree("ment.");
    ConcatStringTree s2 = t5->concat(*t6);

    delete t5;
    delete t6;

    ConcatStringTree s3 = s1.concat(s2);

    cout << s3.reverse().toStringPreOrder() << endl;
    cout << s3.reverse().toString() << endl;
    

    cout << s3.subString(1,5).toStringPreOrder() << endl;
    cout << s3.subString(3,10).toStringPreOrder() << endl;
    cout << s3.subString(5,15).toStringPreOrder() << endl;

    cout << s3.subString(1,5).reverse().toStringPreOrder() << endl;
    cout << s3.subString(3,10).reverse().toStringPreOrder() << endl;
    cout << s3.subString(5,15).reverse().toStringPreOrder() << endl;

    cout << s3.getParTreeStringPreOrder("llr") << endl;
    cout << s3.getParTreeSize("llr") << endl;

    cout << s3.getParTreeStringPreOrder("rl") << endl;
    cout << s3.getParTreeSize("rl") << endl;
    
}

void tc47() {
    CST* s0 = new CST("0123456789");
 
    int sum = 0;
    for (int i = 9; i >= 0; i--) {
        sum += s0->indexOf((char)'0' + i);
    }
    cout << "SUM = " << sum << endl;
 
 
    for (int i = 9; i >= 0; i--) {
        cout << s0->get(i);
    }
    cout << endl;
    cout << endl;
 
 
 
    CST* s2 = new CST
    (s0->subString(0, 1).concat(
        (s0->subString(1, 2).concat(
            (s0->subString(2, 3).concat(
                (s0->subString(3, 4).concat(
                    (s0->subString(4, 5).concat(
                        (s0->subString(5, 6).concat(
                            (s0->subString(6, 7).concat(
                                (s0->subString(7, 8).concat(
                                    (s0->subString(8, 9).concat(
                                        (s0->subString(9, 10)))
                                        .subString(0, 2)))
                                    .subString(0, 3)))
                                .subString(0, 4)))
                            .subString(0, 5)))
                        .subString(0, 6)))
                    .subString(0, 7)))
                .subString(0, 8)))
            .subString(0, 9)))
        .subString(0, 10));
 
    //Literally s0 == s2 = "0123456789" but take extra effort for no reason
    cout << "s2: " << s2->toString() << endl;
    cout << "s2: " << s2->toStringPreOrder()<<endl;

    sum = 0;
    for (int i = 9; i >= 0; i--) {
        sum += s2->indexOf((char)'0' + i);
    }
    cout << "SUM = " << sum << endl;
 
 
    for (int i = 9; i >= 0; i--) {
        cout << s2->get(i);
    }
 
    cout << endl;
    cout << "AT 10th index" << s2->indexOf(10) << endl;
 
 
    cout << endl;
    CST* s3 = new CST(s2->reverse());
    cout << "s3: " << s3->toString() << endl;
    cout << "s3: " <<s3->toStringPreOrder()<<endl;
    sum = 0;
    for (int i = 9; i >= 0; i--) {
        sum += s3->indexOf((char)'0' + i);
    }
    cout << "SUM = " << sum << endl;
 
 
    for (int i = 9; i >= 0; i--) {
        cout << s3->get(i);
    }
 
    cout << endl;
    
    cout << endl;
    CST* s4 = new CST(s2->subString(0,s2->length()));
    cout << "s4: " << s4->toString() << endl;
    cout << "s4: " <<s4->toStringPreOrder()<<endl;
    sum = 0;
    for (int i = 9; i >= 0; i--) {
        sum += s4->indexOf((char)'0' + i);
    }
    cout << "SUM = " << sum << endl;
 
 
    for (int i = 9; i >= 0; i--) {
        cout << s3->get(i);
    }
 
    delete s4;
    delete s3;
    delete s2;
    delete s0;
    //_CrtDumpMemoryLeaks();
}

void tc103(){
    CST * s1 = new CST("a");
    CST * s2 = new CST("b");
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    CST * s3 = new CST(s2->concat(*s1));
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    
    CST * s4 = new CST(s2->concat(*s1));
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    
    CST * s5 = new CST(s2->concat(*s1));
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    
    CST * s6 = new CST(s2->concat(*s1));
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    
    
    CST * s7 = new CST(s2->concat(*s1));
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    
    CST * s8 = new CST(s2->concat(*s1));
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    

    CST * s9 = new CST(s2->concat(*s1));
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    

    CST * s10 = new CST(s2->concat(*s1));
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    
    
    delete s5;
    cout <<s2->getParTreeStringPreOrder("")<<endl;

    delete s4;
    cout <<s2->getParTreeStringPreOrder("")<<endl;

    delete s6;
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    
    delete s10;
    cout <<s2->getParTreeStringPreOrder("")<<endl;

    delete s9;
    cout <<s2->getParTreeStringPreOrder("")<<endl;

    delete s8;
    cout <<s2->getParTreeStringPreOrder("")<<endl;

    delete s7;
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    
    delete s3;
    cout <<s2->getParTreeStringPreOrder("")<<endl;
    
    delete s2;

    delete s1;
}


void tc200() {
    HashConfig hashConfig(
        2,
        0.5,
        0.5,
        0.75,
        2.0,
        4
    );
    LitStringHash* litStringHash = new LitStringHash(hashConfig);
    ReducedConcatStringTree* s1 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree* s2 = new ReducedConcatStringTree("bb", litStringHash);

    cout << s1->toString() << endl;
    cout << s2->toString() << endl;


    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;
    ReducedConcatStringTree* s3 = new ReducedConcatStringTree("bb", litStringHash);

    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    ReducedConcatStringTree* s4 = new ReducedConcatStringTree(s1->concat(*s2));
    cout << "create s4\n";
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    ReducedConcatStringTree* s5 = new ReducedConcatStringTree(s4->reverse());
    cout << "create s5\n";
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    ReducedConcatStringTree* s6 = new ReducedConcatStringTree(s4->subString(0,s5->length()));
    cout << "create s6\n";
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;



    delete s4;
    cout << "delete s4\n";
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;


    delete s5;
    cout << "delete s5\n";
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;


    delete s6;
    cout << "delete s6\n";
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    delete s3;
    cout << "delete s3\n";
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;
    
    delete s1;
    cout << "delete s1\n";
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;
    
    delete s2;
    cout << "delete s2\n";
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;
    delete litStringHash;
}


void tc201() {
    HashConfig hashConfig(
        2,
        0.5,
        0.5,
        0.75,
        2.0,
        4
    );
    LitStringHash* litStringHash = new LitStringHash(hashConfig);
    ReducedConcatStringTree* s1 = new ReducedConcatStringTree("ABAB", litStringHash);
    cout<<"s1 = " << s1->toString() << endl;
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    ReducedConcatStringTree* s2 = new ReducedConcatStringTree("BAB", litStringHash);
    cout<<"s2 = " << s2->toString() << endl;
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    ReducedConcatStringTree* s3 = new ReducedConcatStringTree("BABA", litStringHash);    
    cout<<"s3 = " << s3->toString() << endl;
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    ReducedConcatStringTree* s4 = new ReducedConcatStringTree(s1->concat(*s2));
    cout<<"s4 = " << s4->toString() << endl;
    cout<<"s4 = " << s4->toStringPreOrder() << endl;
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    ReducedConcatStringTree* s5 = new ReducedConcatStringTree(s4->concat(*s3));
    cout<<"s5 = " << s5->toString() << endl;
    cout<<"s5 = " << s5->toStringPreOrder() << endl;
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    ReducedConcatStringTree* s6 = new ReducedConcatStringTree(s5->subString(2, s5->length()-2));
    cout<<"s6 = " << s6->toString() << endl;
    cout<<"s6 = " << s6->toStringPreOrder() << endl;
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    ReducedConcatStringTree* s7 = new ReducedConcatStringTree(s5->reverse());
    cout<<"s7 = " << s7->toString() << endl;
    cout<<"s7 = " << s7->toStringPreOrder() << endl;
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    
    delete s1;
    cout << "delete s1\n";
    cout << litStringHash->toString() << endl;

    delete s2;
    cout << "delete s2\n";
    cout << litStringHash->toString() << endl;
    

    delete s4;
    cout << "delete s4\n";
    cout << litStringHash->toString() << endl;

    
    delete s7;
    cout << "delete s7\n";
    cout << litStringHash->toString() << endl;

    delete s5;
    cout << "delete s5\n";
    cout << litStringHash->toString() << endl;


    delete s6;
    cout << "delete s6\n";
    cout << litStringHash->toString() << endl;

    delete s3;
    cout << "delete s3\n";
    cout << litStringHash->toString() << endl;

    delete litStringHash;
}


void tc342(){
    HashConfig hashConfig(
        2,
        0.5,
        0.5,
        0.75,
        2.0,
        4
    );
    LitStringHash* litStringHash = new LitStringHash(hashConfig);
    RCST *s0 = new RCST("a", litStringHash);
    RCST *s1 = new RCST("a", litStringHash);  
    RCST *s2 = new RCST("a", litStringHash);    


    cout << s0->getParTreeStringPreOrder("") << endl;
    cout << s1->getParTreeStringPreOrder("") << endl;
    cout << s2->getParTreeStringPreOrder("") << endl;
    delete s0;

    cout << s1->getParTreeStringPreOrder("") << endl;
    cout << s2->getParTreeStringPreOrder("") << endl;

    delete s1;
    

    cout << s2->getParTreeStringPreOrder("") << endl;

    delete s2;
    delete litStringHash;

}

void tc367(){
    HashConfig hashConfig(11,0.901578,0.606372,0.713767,1.62496,4);
        LitStringHash litStringHash(hashConfig);

        ReducedConcatStringTree s1("6BZRfvt3GfPwQi9MC", &litStringHash);
        ReducedConcatStringTree s2("11", &litStringHash);
        ReducedConcatStringTree s3("vKmGhiG", &litStringHash);

        cout << litStringHash.toString() << endl;
        cout << litStringHash.getLastInsertedIndex() << endl;

}

void tc301(){

    HashConfig hashConfig(8, 0.567125, 0.260537, 0.958892, 1.66552, 4);
    LitStringHash litStringHash(hashConfig);

    ReducedConcatStringTree s1("6ZAOZ", &litStringHash);
    ReducedConcatStringTree s2("QLMW4v", &litStringHash);
    ReducedConcatStringTree s3("p2lIeVjW", &litStringHash);
    cout<< litStringHash.toString() << endl;
    try
    {
        ReducedConcatStringTree s4("fEmB22OXMBjl", &litStringHash);
        
        cout<< litStringHash.toString() << endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout<< litStringHash.toString() << endl;
}

void tc331(){
    
    HashConfig hashConfig(8, 0.567125, 0.260537, 0.958892, 1.66552, 4);
    LitStringHash litStringHash(hashConfig);

    ReducedConcatStringTree *s1 = new RCST("6ZAOZ", &litStringHash);
    cout<< litStringHash.toString() << endl;
    cout<< litStringHash.getLastInsertedIndex() << endl;
    ReducedConcatStringTree *s2= new RCST("QLMW4v", &litStringHash);
    
    cout<< litStringHash.toString() << endl;
    cout<< litStringHash.getLastInsertedIndex() << endl;
    ReducedConcatStringTree *s3= new RCST("p2lIeVjW", &litStringHash);
    
    cout<< litStringHash.toString() << endl;
    cout<< litStringHash.getLastInsertedIndex() << endl;
    try
    {
        
        ReducedConcatStringTree *s4= new RCST("NLK", &litStringHash);
        
        cout<< litStringHash.toString() << endl;
        cout<< litStringHash.getLastInsertedIndex() << endl;
    
        delete s4;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    delete s1;
    delete s2;
    delete s3;
}




void tc333(){
    
    HashConfig hashConfig(1, 2, 0, 0.9, 1.35, 3);
    LitStringHash litStringHash(hashConfig);

    ReducedConcatStringTree *s1 = new RCST("A", &litStringHash);
    cout<< litStringHash.toString() << endl;
    cout<< litStringHash.getLastInsertedIndex() << endl;
    ReducedConcatStringTree *s2= new RCST("C", &litStringHash);
    
    cout<< litStringHash.toString() << endl;
    cout<< litStringHash.getLastInsertedIndex() << endl;
    ReducedConcatStringTree *s3= new RCST("E", &litStringHash);
    
    cout<< litStringHash.toString() << endl;
    cout<< litStringHash.getLastInsertedIndex() << endl;
    

    delete s1;
    delete s2;
    delete s3;
}

void tc350() {

    HashConfig hashConfig(
        2,
        0.5,
        0.5,
        0.75,
        2.0,
        4
    );
    LitStringHash* litStringHash = new LitStringHash(hashConfig);
    ReducedConcatStringTree* s1 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree* s2 = new ReducedConcatStringTree("bb", litStringHash);

    ReducedConcatStringTree* s3 = new ReducedConcatStringTree(s1->concat(*s2));

    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    delete s3;

    cout << litStringHash->getLastInsertedIndex() << endl;
    delete s1;

    cout << litStringHash->getLastInsertedIndex() << endl;
    delete s2;

    cout << litStringHash->getLastInsertedIndex() << endl;
    delete litStringHash;
}

void tc351() {

    HashConfig hashConfig(
        2,
        0.5,
        0.5,
        0.75,
        2.0,
        4
    );
    LitStringHash* litStringHash = new LitStringHash(hashConfig);
    ReducedConcatStringTree* s1 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree* s2 = new ReducedConcatStringTree("b", litStringHash);
    ReducedConcatStringTree* s3 = new ReducedConcatStringTree("b", litStringHash);
    ReducedConcatStringTree* s4 = new ReducedConcatStringTree("c", litStringHash);

    ReducedConcatStringTree* s5 = new ReducedConcatStringTree(s1->concat(*s2));
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;
    
    ReducedConcatStringTree* s6 = new ReducedConcatStringTree(s3->concat(*s4));
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    ReducedConcatStringTree* s7 = new ReducedConcatStringTree(s5->concat(*s6));
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;


    cout << "s7 = " << s7->getParTreeSize("") << endl;
    cout << "s5 = " << s7->getParTreeSize("l") << endl;
    cout << "s1 = " << s7->getParTreeSize("ll") << endl;
    cout << "s2 = " << s7->getParTreeSize("lr") << endl;
    cout << "s6 = " << s7->getParTreeSize("r") << endl;
    cout << "s3 = " << s7->getParTreeSize("rl") << endl;
    cout << "s4 = " << s7->getParTreeSize("rr") << endl;


    cout << "s7 = " << s7->getParTreeStringPreOrder("") << endl;
    cout << "s5 = " << s7->getParTreeStringPreOrder("l") << endl;
    cout << "s1 = " << s7->getParTreeStringPreOrder("ll") << endl;
    cout << "s2 = " << s7->getParTreeStringPreOrder("lr") << endl;
    cout << "s6 = " << s7->getParTreeStringPreOrder("r") << endl;
    cout << "s3 = " << s7->getParTreeStringPreOrder("rl") << endl;
    cout << "s4 = " << s7->getParTreeStringPreOrder("rr") << endl;


    delete s4;
    cout << "DELETEING s4\n";
    cout << litStringHash->toString() << endl;

    cout << "s7 = " << s7->getParTreeStringPreOrder("") << endl;
    cout << "s5 = " << s7->getParTreeStringPreOrder("l") << endl;
    cout << "s1 = " << s7->getParTreeStringPreOrder("ll") << endl;
    cout << "s2 = " << s7->getParTreeStringPreOrder("lr") << endl;
    cout << "s6 = " << s7->getParTreeStringPreOrder("r") << endl;
    cout << "s3 = " << s7->getParTreeStringPreOrder("rl") << endl;
    cout << "s4 = " << s7->getParTreeStringPreOrder("rr") << endl;

    delete s1;

    cout << "DELETEING s1\n";
    cout << litStringHash->toString() << endl;

    cout << "s7 = " << s7->getParTreeStringPreOrder("") << endl;
    cout << "s5 = " << s7->getParTreeStringPreOrder("l") << endl;
    cout << "s1 = " << s7->getParTreeStringPreOrder("ll") << endl;
    cout << "s2 = " << s7->getParTreeStringPreOrder("lr") << endl;
    cout << "s6 = " << s7->getParTreeStringPreOrder("r") << endl;
    cout << "s3 = " << s7->getParTreeStringPreOrder("rl") << endl;
    cout << "s4 = " << s7->getParTreeStringPreOrder("rr") << endl;
    
    delete s2;

    cout << "DELETEING s2\n";
    cout << litStringHash->toString() << endl;

    cout << "s7 = " << s7->getParTreeStringPreOrder("") << endl;
    cout << "s5 = " << s7->getParTreeStringPreOrder("l") << endl;
    cout << "s1 = " << s7->getParTreeStringPreOrder("ll") << endl;
    cout << "s2 = " << s7->getParTreeStringPreOrder("lr") << endl;
    cout << "s6 = " << s7->getParTreeStringPreOrder("r") << endl;
    cout << "s3 = " << s7->getParTreeStringPreOrder("rl") << endl;
    cout << "s4 = " << s7->getParTreeStringPreOrder("rr") << endl;

    delete s3;

    cout << "DELETEING s3\n";
    cout << litStringHash->toString() << endl;

    cout << "s7 = " << s7->getParTreeStringPreOrder("") << endl;
    cout << "s5 = " << s7->getParTreeStringPreOrder("l") << endl;
    cout << "s1 = " << s7->getParTreeStringPreOrder("ll") << endl;
    cout << "s2 = " << s7->getParTreeStringPreOrder("lr") << endl;
    cout << "s6 = " << s7->getParTreeStringPreOrder("r") << endl;
    cout << "s3 = " << s7->getParTreeStringPreOrder("rl") << endl;
    cout << "s4 = " << s7->getParTreeStringPreOrder("rr") << endl;

    delete s5;

    cout << "DELETEING s5\n";
    cout << litStringHash->toString() << endl;

    cout << "s7 = " << s7->getParTreeStringPreOrder("") << endl;
    cout << "s5 = " << s7->getParTreeStringPreOrder("l") << endl;
    cout << "s1 = " << s7->getParTreeStringPreOrder("ll") << endl;
    cout << "s2 = " << s7->getParTreeStringPreOrder("lr") << endl;
    cout << "s6 = " << s7->getParTreeStringPreOrder("r") << endl;
    cout << "s3 = " << s7->getParTreeStringPreOrder("rl") << endl;
    cout << "s4 = " << s7->getParTreeStringPreOrder("rr") << endl;

    delete s6;

    cout << "DELETEING s6\n";
    cout << litStringHash->toString() << endl;

    cout << "s7 = " << s7->getParTreeStringPreOrder("") << endl;
    cout << "s5 = " << s7->getParTreeStringPreOrder("l") << endl;
    cout << "s1 = " << s7->getParTreeStringPreOrder("ll") << endl;
    cout << "s2 = " << s7->getParTreeStringPreOrder("lr") << endl;
    cout << "s6 = " << s7->getParTreeStringPreOrder("r") << endl;
    cout << "s3 = " << s7->getParTreeStringPreOrder("rl") << endl;
    cout << "s4 = " << s7->getParTreeStringPreOrder("rr") << endl;

    delete s7;
    cout << litStringHash->toString() << endl;

    delete litStringHash;
}


void tc352() {

    HashConfig hashConfig(
        2,
        0.5,
        0.5,
        0.75,
        2.0,
        4
    );
    LitStringHash* litStringHash = new LitStringHash(hashConfig);
    ReducedConcatStringTree* s1 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree* s2 = new ReducedConcatStringTree("b", litStringHash);

    ReducedConcatStringTree* s4 = new ReducedConcatStringTree("c", litStringHash);

    ReducedConcatStringTree* s5 = new ReducedConcatStringTree(s1->concat(*s2));
    
    ReducedConcatStringTree* s6 = new ReducedConcatStringTree(s2->concat(*s4));

    ReducedConcatStringTree* s7 = new ReducedConcatStringTree(s5->concat(*s6));
    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    cout << "s7 = " << s7->getParTreeStringPreOrder("") << endl;
    cout << "s5 = " << s7->getParTreeStringPreOrder("l") << endl;
    cout << "s1 = " << s7->getParTreeStringPreOrder("ll") << endl;
    cout << "s2 = " << s7->getParTreeStringPreOrder("lr") << endl;
    cout << "s6 = " << s7->getParTreeStringPreOrder("r") << endl;
    cout << "s2 = " << s7->getParTreeStringPreOrder("rl") << endl;
    cout << "s4 = " << s7->getParTreeStringPreOrder("rr") << endl;
    
    delete s4;
    delete s1;
    delete s2;
    delete s5;
    delete s6;
    delete s7;
    delete litStringHash;
}


void tc358()
{
	HashConfig h = HashConfig(9, 0.738121, 0.74752, 0.745705, 1.56618, 7);
	LitStringHash* lsh = new LitStringHash(h);

	ReducedConcatStringTree* r0 = new ReducedConcatStringTree("8tXNY6", lsh);
	ReducedConcatStringTree* r1 = new ReducedConcatStringTree("zmJTUgylXufHci5qO", lsh);
	ReducedConcatStringTree* r2 = new ReducedConcatStringTree("vOiC3PK", lsh);
	ReducedConcatStringTree* r3 = new ReducedConcatStringTree("Znvo", lsh);
	ReducedConcatStringTree* r4 = new ReducedConcatStringTree("2p41S", lsh);
	ReducedConcatStringTree* r5 = new ReducedConcatStringTree("1zDn1LyRJvlAH6PyYn", lsh);
	ReducedConcatStringTree* r6 = new ReducedConcatStringTree("WvOK", lsh);
	ReducedConcatStringTree* r7 = new ReducedConcatStringTree("Bp1mVx5eMYzTU6", lsh);
	ReducedConcatStringTree* r8 = new ReducedConcatStringTree("K", lsh);
	ReducedConcatStringTree* r9 = new ReducedConcatStringTree("IeyRAEVM7Wv3k3LI", lsh);

	ReducedConcatStringTree* r10 = new ReducedConcatStringTree("xWTALZbWJup6glGxKHAu", lsh);
	cout << lsh->toString() << endl;
	cout << lsh->getLastInsertedIndex() << endl;

	ReducedConcatStringTree* r11 = new ReducedConcatStringTree("q0Swy1SoGaS24Tr", lsh);
	cout << lsh->toString() << endl;
	cout << lsh->getLastInsertedIndex() << endl;

	delete r0;
	delete r1;
	delete r2;
	delete r3;
	delete r4;
	delete r5;
	delete r6;
	delete r7;
	delete r8;
	delete r9;
	delete r10;
	delete lsh;
}

int main() {

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

    tc1();
    tc11();
    tc12();
    tc15();
    tc16();
    tc17();
    tc18();
    tc19();
    tc2();
    tc20();
    tc22();
    tc23();
    tc24();
    tc25();
    tc3();
    tc38();
    tc342();
    tc367();
    tc350();
    tc351();
    tc352();
    tc103();
   
    tc351();

    _CrtDumpMemoryLeaks();
    return 0;
}