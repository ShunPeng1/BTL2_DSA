#include "ConcatStringTree.h"

void tc11(){
    
    ConcatStringTree s1("Hello"), s2("World");
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

    ConcatStringTree s3 = s1.concat(s2);
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
    
    ConcatStringTree s1("Hello"), s2("World");
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

    ConcatStringTree s3 = s1.concat(s2);
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

int main() {
    
    ConcatStringTree s1("Hello"), s2("World");
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

    ConcatStringTree s3 = s1.concat(s2);
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

    ConcatStringTree s4 = s3.subString(1,9);
    ConcatStringTree s6 = s3.subString(1,4);
    cout<<"s4 = "<<s4.toStringPreOrder()<<endl;
    cout<<"s6 = "<<s6.toStringPreOrder()<<endl;

    ConcatStringTree s5 = s4.reverse();
    ConcatStringTree s7 = s6.reverse();
    cout<<"s5 = "<<s5.toStringPreOrder()<<endl;
    cout<<"s7 = "<<s7.toStringPreOrder()<<endl;

    return 0;
}