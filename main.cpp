#include "ConcatStringTree.h"

#define CST ConcatStringTree

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
/*
void tc4()
{
    HashConfig hashConfig(
        2,
        0.5,
        0.5,
        0.75,
        2,
        4
    );
    LitStringHash* litStringHash = new LitStringHash(hashConfig);
    ReducedConcatStringTree* s1 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree* s2 = new ReducedConcatStringTree("bb", litStringHash);

    cout << s1->toString() << endl;
    cout << s2->toString() << endl;
    ReducedConcatStringTree* s3 = new ReducedConcatStringTree("bb", litStringHash);

    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;

    delete litStringHash;
    delete s3;
    delete s1;
    delete s2;
}

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
    
    CST s1("Hello"), s2("World");
    cout<<s1.get(0)<<endl;
    cout<<s1.get(1)<<endl;
    cout<<s1.get(2)<<endl;
    cout<<s1.get(3)<<endl;
    cout<<s1.get(4)<<endl;
    cout<<s1.indexOf('H')<<endl;
    cout<<s1.indexOf('e')<<endl;
    cout<<s1.indexOf('l')<<endl;
    cout<<s1.indexOf('l')<<endl;
    cout<<s1.indexOf('o')<<endl;
    cout<<s1.indexOf('a')<<endl;
    cout<<s1.toStringPreOrder()<<endl;
    cout<<s1.toString()<<endl;

    CST s3 = s1.concat(s2);
    cout<<endl<<endl;
    cout<<s3.get(5)<<endl;
    cout<<s3.get(6)<<endl;
    cout<<s3.get(7)<<endl;
    cout<<s3.get(8)<<endl;
    cout<<s3.get(9)<<endl;
    cout<<s3.indexOf('W')<<endl;
    cout<<s3.indexOf('o')<<endl;
    cout<<s3.indexOf('r')<<endl;
    cout<<s3.indexOf('l')<<endl;
    cout<<s3.indexOf('d')<<endl;
    cout<<s3.indexOf('a')<<endl;
    cout<<s3.toStringPreOrder()<<endl;
    cout<<s3.toString()<<endl;

    cout<<endl<<endl;

    CST s4 = s3.subString(1,9);
    CST s6 = s3.subString(1,4);
    cout<<"s4 = "<<s4.toStringPreOrder()<<endl;
    cout<<"s6 = "<<s6.toStringPreOrder()<<endl;

    CST s5 = s4.reverse();
    CST s7 = s6.reverse();
    cout<<"s5 = "<<s5.toStringPreOrder()<<endl;
    cout<<"s7 = "<<s7.toStringPreOrder()<<endl;

}
void tc14(){
    ConcatStringTree s1("Hello");
        ConcatStringTree s2 = s1.concat(s1).concat(s1);
        cout << s2.toStringPreOrder()<<endl;   
        cout<<s2.getParTreeSize("")<<endl;
        cout<<s2.getParTreeStringPreOrder("")<<endl;
        cout<<s2.getParTreeSize("ll")<<endl;
        cout<<s2.getParTreeStringPreOrder("ll")<<endl;

        ConcatStringTree s3 = s1.concat(s2).subString(0, s2.length());
        cout << s3.toStringPreOrder()<<endl;
            
        cout<<s3.getParTreeSize("")<<endl;
        cout<<s3.getParTreeStringPreOrder("")<<endl;
        cout<<s3.getParTreeSize("l")<<endl;
        cout<<s3.getParTreeStringPreOrder("l")<<endl;
        
        ConcatStringTree s4 = s3.reverse();
        cout << s4.toStringPreOrder()<<endl;
        
    cout<<s4.getParTreeSize("")<<endl;
    cout<<s4.getParTreeStringPreOrder("")<<endl;
    cout<<s4.getParTreeSize("l")<<endl;
    cout<<s4.getParTreeStringPreOrder("l")<<endl;
        cout << "\n";
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

void tc164(){
    //self concat
    CST s0("Hello");
    CST s1 = s0.concat(s0);
    
    cout<<"s1 = "<<s1.toStringPreOrder()<<endl;
    cout<<"s1 = "<<s1.toString()<<endl;
    

    CST s2 = s0.concat(s0);
    cout<<"s2 = "<<s2.toStringPreOrder()<<endl;
    cout<<"s2 = "<<s2.toString()<<endl; 
    
    
    CST s3 = s1.concat(s0);
    cout<<"s3 = "<<s3.toStringPreOrder()<<endl;
    cout<<"s3 = "<<s3.toString()<<endl; 

    
    CST s4 = s3.concat(s3);
    cout<<"s4 = "<<s4.toStringPreOrder()<<endl;
    cout<<"s4 = "<<s4.toString()<<endl; 



    CST s5 = s4.reverse();
    cout<<"s5 = "<<s5.toStringPreOrder()<<endl;
    cout<<"s5 = "<<s5.toString()<<endl; 

}


void tc165(){
    //self concat
    CST s0("Hello");
    CST s1 = s0.concat(s0);
    
    cout<<"s1 = "<<s1.toStringPreOrder()<<endl;
    cout<<"s1 = "<<s1.toString()<<endl;
    

    CST s2 = s0.concat(s0);
    cout<<"s2 = "<<s2.toStringPreOrder()<<endl;
    cout<<"s2 = "<<s2.toString()<<endl; 
    
    
    CST s3 = s1.concat(s0);
    cout<<"s3 = "<<s3.toStringPreOrder()<<endl;
    cout<<"s3 = "<<s3.toString()<<endl; 

    
    CST s4 = s3.concat(s3);
    cout<<"s4 = "<<s4.toStringPreOrder()<<endl;
    cout<<"s4 = "<<s4.toString()<<endl; 



    CST s5 = s4.reverse();
    cout<<"s5 = "<<s5.toStringPreOrder()<<endl;
    cout<<"s5 = "<<s5.toString()<<endl; 

    
    CST s6 = s5.subString(0,s5.length());
    cout<<"s6 = "<<s6.toStringPreOrder()<<endl;
    cout<<"s6 = "<<s6.toString()<<endl; 

    
    CST s7 = s4.concat(s5);
    cout<<"s7 = "<<s7.toStringPreOrder()<<endl;
    cout<<"s7 = "<<s7.toString()<<endl; 

    CST s8 = s7.concat(s7);
    cout<<"s8 = "<<s8.toStringPreOrder()<<endl;
    cout<<"s8 = "<<s8.toString()<<endl; 
    
    CST s9 = s8.reverse();
    cout<<"s9 = "<<s9.toStringPreOrder()<<endl;
    cout<<"s9 = "<<s9.toString()<<endl; 

    
    CST s10 = s9.concat(s9);
    cout<<"s10 = "<<s10.toStringPreOrder()<<endl;
    cout<<"s10 = "<<s10.toString()<<endl; 
}
void tc166(){
    //self concat
    CST s0("Hello");
    CST s1 = s0.concat(s0);
    
    cout<<"s1 = "<<s1.toStringPreOrder()<<endl;
    cout<<"s1 = "<<s1.toString()<<endl;
    

    CST s2 = s1.concat(s0);
    cout<<"s2 = "<<s2.toStringPreOrder()<<endl;
    cout<<"s2 = "<<s2.toString()<<endl; 
    
    
    CST s3 = s2.concat(s1);
    cout<<"s3 = "<<s3.toStringPreOrder()<<endl;
    cout<<"s3 = "<<s3.toString()<<endl; 

    
    CST s4 = s1.concat(s2);
    cout<<"s4 = "<<s4.toStringPreOrder()<<endl;
    cout<<"s4 = "<<s4.toString()<<endl; 


    CST s5 = s3.concat(s1);
    cout<<"s5 = "<<s5.toStringPreOrder()<<endl;
    cout<<"s5 = "<<s5.toString()<<endl; 

    
    CST s6 = s5.concat(s0);
    cout<<"s6 = "<<s6.toStringPreOrder()<<endl;
    cout<<"s6 = "<<s6.toString()<<endl; 

    CST s7 = s6.reverse();
    cout<<"s7 = "<<s7.toStringPreOrder()<<endl;
    cout<<"s7 = "<<s7.toString()<<endl; 

    CST s8 = s7.concat(s6);
    cout<<"s8 = "<<s8.toStringPreOrder()<<endl;
    cout<<"s8 = "<<s8.toString()<<endl; 
    
    CST s9 = s8.concat(s8);
    cout<<"s9 = "<<s9.toStringPreOrder()<<endl;
    cout<<"s9 = "<<s9.toString()<<endl; 

    
    CST s10 = s9.subString(s9.length()*1/4, s9.length()*3/4);
    cout<<"s10 = "<<s10.toStringPreOrder()<<endl;
    cout<<"s10 = "<<s10.toString()<<endl; 

    CST s11 = s10.subString(s10.length()*1/4, s10.length()*3/4);
    cout<<"s11 = "<<s11.toStringPreOrder()<<endl;
    cout<<"s11 = "<<s11.toString()<<endl; 

    CST s12 = s9.reverse();
    cout<<"s12 = "<<s12.toStringPreOrder()<<endl;
    cout<<"s12 = "<<s12.toString()<<endl; 

    
    CST s13 = s12.concat(s10);
    cout<<"s13 = "<<s13.toStringPreOrder()<<endl;
    cout<<"s13 = "<<s13.toString()<<endl;

    
    CST s14 = s13.concat(s13);
    cout<<"s14 = "<<s14.toStringPreOrder()<<endl;
    cout<<"s14 = "<<s14.toString()<<endl;
}

int main() {
    tc14();
    tc164();
    tc165();
    tc166();
    tc17();
    tc18();
    tc20();
    tc22();
    tc23();
    tc24();
    return 0;
}