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
/*
void tc3()
{
    ConcatStringTree* s1 = new ConcatStringTree("a");
    ConcatStringTree* s2 = new ConcatStringTree("b");
    ConcatStringTree* s3 = new ConcatStringTree(s1->concat(*s2));

    cout << s3->getParTreeSize("l") << endl;
    cout << s3->getParTreeStringPreOrder("l") << endl;
    cout << s3->getParTreeSize("") << endl;
    cout << s3->getParTreeStringPreOrder("") << endl;
    
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
void tc11(){
    
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
        ConcatStringTree s3 = s1.concat(s2).subString(0, s2.length());
        cout << s3.toStringPreOrder()<<endl;
        
        ConcatStringTree s4 = s3.reverse();
        cout << s4.toStringPreOrder()<<endl;
        cout << "\n";
}

void tc15(){
      ConcatStringTree sA("ABC"), sB("DEF"), sC("GHI");

        ConcatStringTree s1 = sA.concat(sB); // ABCDEF

        ConcatStringTree s2 = sB.concat(sC); // DEFGHI

        ConcatStringTree s3 = s1.concat(s2); // ABCDEFDEFGHI

        ConcatStringTree s4 = s3.subString(1, s3.length()-1);

        ConcatStringTree s5 = s3.reverse();

        cout << s4.toString() << endl; // BCDEFDEFGH

        cout << s5.toString() << endl; // IHGFEDFEDCBA
}
void tc17(){
    CST sA("Hello"), sB(",_t"), sC("his_is"), sD("_an");
    CST s1 = sA.concat(sB), s2 = sC.concat(sD), s3 = s1.concat(s2);

    
    cout<<"s1 = "<<s1.toStringPreOrder()<<endl;
    cout<<"s2 = "<<s2.toStringPreOrder()<<endl;    
    cout<<"s3 = "<<s3.toStringPreOrder()<<endl;
    
    CST s4 = s3.subString(1,10);
    
    cout<<"s4 = "<<s4.toStringPreOrder()<<endl;

    CST s5 = s4.reverse();
    cout<<"s5 = "<<s5.toStringPreOrder()<<endl;

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
    tc15();
    return 0;
}