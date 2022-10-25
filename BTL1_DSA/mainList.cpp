#include "ConcatStringList.h"

void tc1() {
    ConcatStringList s1("Hello,_world");
    // test length
    cout << "s1's length: " << s1.length() << endl;
    // test get
    cout << "char at index 2: " << s1.get(2) << endl;
    try {
        cout << "char at index 22: " << s1.get(22) << endl;
    }
    catch (out_of_range & ofr) {
        cout << "Exception out_of_range: " << ofr.what() << endl;
    }
    // test indexOf
    cout << "in s1, index of 'o': " << s1.indexOf('o') << endl;
    cout << "in s1, index of 'a': " << s1.indexOf('a') << endl;
    // test toString
    cout << "s1 toString: " << s1.toString() << endl;
}

void tc13(){
    ConcatStringList * s1 = new ConcatStringList("Hello");
    ConcatStringList * s2 = new ConcatStringList(s1->reverse());

    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
}

void tc2() {
    {
    ConcatStringList s1("Hello,");
    ConcatStringList s2("_this_is");
    ConcatStringList s3("_an_assignment");
    ConcatStringList s0("banh tan thuan");
    // test concat
    ConcatStringList s4 = s1.concat(s2);
    cout << "s4: " << s4.toString() << endl;

    cout<< ConcatStringList::refList.refCountsString()<<endl;
    cout<< ConcatStringList::delStrList.totalRefCountsString()<<endl;
    ConcatStringList s5 = s0.concat(s3);
    cout << "s5: " << s5.toString() << endl;

    cout<< ConcatStringList::refList.refCountsString()<<endl;
    cout<< ConcatStringList::delStrList.totalRefCountsString()<<endl;
    // test subString
    ConcatStringList s6 = s5.subString(5,7);
    cout << "s6: " << s6.toString() << endl;
    
    cout<< ConcatStringList::refList.refCountsString()<<endl;
    cout<< ConcatStringList::delStrList.totalRefCountsString()<<endl;
    // test reverse
    ConcatStringList s7 = s5.reverse();
    cout << "s7: " << s7.toString() << endl;
    
    cout<< ConcatStringList::refList.refCountsString()<<endl;
    cout<< ConcatStringList::delStrList.totalRefCountsString()<<endl;
    }
    
    
    cout<< ConcatStringList::refList.refCountsString()<<endl;
    cout<< ConcatStringList::delStrList.totalRefCountsString()<<endl;
}


void tc20() {
    ConcatStringList s1("A");
    ConcatStringList s2("B");
    ConcatStringList s3("C");

    // test concat
    ConcatStringList s4 = s1.concat(s2);
    cout << "s4: " << s4.toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;

    ConcatStringList s5 = s4.subString(0,2);
    cout << "s5: " << s5.toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;


    ConcatStringList s6 = s5.concat(s3);
    cout << "s6: " << s6.toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;

    
    ConcatStringList s7 = s6.reverse();
    cout << "s7: " << s7.toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;
}

void tc26() {
    ConcatStringList s1("A");
    ConcatStringList s2("B");
    ConcatStringList s3("C");

    // test concat
    ConcatStringList s4 = s1.concat(s2);
    cout << "s4: " << s4.toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;

    ConcatStringList s5 = s4.subString(0,2);
    cout << "s5: " << s5.toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;


    ConcatStringList s6 = s5.concat(s3);
    cout << "s6: " << s6.toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;

    
    ConcatStringList s7 = s6.reverse();
    cout << "s7: " << s7.toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;

    
    ConcatStringList s8 = s6.reverse().reverse();
    cout << "s8: " << s8.toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;

    
    ConcatStringList s9 = s6.subString(0,3);
    cout << "s9: " << s9.toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;

    
    ConcatStringList s10 = s6.subString(0,3).subString(0,3);
    cout << "s10: " << s10.toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;
}

void tc21() {
    
    ConcatStringList *s1 = new ConcatStringList("ABC");
    ConcatStringList *s2 = new ConcatStringList("DEF");

    ConcatStringList *s4 = new ConcatStringList(s1->concat(*s2));
    cout << "s4: " << s4->toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;
    cout<< ConcatStringList::delStrList.totalRefCountsString()<<endl;

    ConcatStringList *s5 = new ConcatStringList(s4->subString(1,5).subString(1,2));
    cout << "s5: " << s5->toString() << endl;
    cout<< ConcatStringList::refList.refCountsString()<<endl;
    cout<< ConcatStringList::delStrList.totalRefCountsString()<<endl;
    
    delete s5;
    cout<<"Delete s5\n";
    cout<< ConcatStringList::refList.refCountsString()<<endl;
    cout<< ConcatStringList::delStrList.totalRefCountsString()<<endl;

    delete s4;
    cout<<"Delete s4\n";
    cout<< ConcatStringList::refList.refCountsString()<<endl;
    cout<< ConcatStringList::delStrList.totalRefCountsString()<<endl;
    
    delete s2;
    cout<<"Delete s2\n";
    cout<< ConcatStringList::refList.refCountsString()<<endl;
    cout<< ConcatStringList::delStrList.totalRefCountsString()<<endl;
    
    delete s1;
    cout<<"Delete s1\n";
    cout<< ConcatStringList::refList.refCountsString()<<endl;
    cout<< ConcatStringList::delStrList.totalRefCountsString()<<endl;

}

void tc22() {
    ConcatStringList s1("Hello,");

    ConcatStringList s2("_this_is");
    ConcatStringList s3("_an_assignment");
    ConcatStringList s4("_new_string_");
    
    ConcatStringList s11 = s1.reverse();
    cout << "s11: " << s11.toString() << endl;
    cout<<"Current Ref 1\n";
     

    ConcatStringList s111 = s11.reverse();
    cout << "s111: " << s111.toString() << endl;
    cout<<"Current Ref 2\n";
     

    ConcatStringList s1111 = s111.reverse();
    cout << "s1111: " << s1111.toString() << endl;
    cout<<"Current Ref 3\n";
     
}

void tc23() {
    ConcatStringList s1("Hello,");

    ConcatStringList s2("_this_is");
    ConcatStringList s3("_an_assignment");
    
    ConcatStringList s11 = s1.reverse();
    cout << "s11: " << s11.toString() << endl;
    cout<<"Current Ref 1\n";
     

    ConcatStringList s111 = s11.reverse();
    cout << "s111: " << s111.toString() << endl;
    cout<<"Current Ref 2\n";
     

    // ConcatStringList s110 = s111.subString(2,5);
    // cout << "s110: " << s110.toString() << endl;
    // cout << "s111: " << s111.toString() << endl;
    // cout<<"Current Ref 3\n";
    //  

    
    ConcatStringList s100 = s111.subString(2,5).subString(1,2);
    cout << "s100: " << s100.toString() << endl;
    cout << "s111: " << s111.toString() << endl;
    cout<<"Current Ref 4\n";
     

}

void tc24() {
    ConcatStringList s1("Hello,");
    ConcatStringList s2("_this_is");
    ConcatStringList s3("_an_assignment");
    ConcatStringList s4("_which_no_one_like");

    ConcatStringList s11 = s1.reverse();
    cout << "s11: " << s11.toString() << endl;
    cout<<"Current Ref 1\n";
     

    ConcatStringList s111 = s11.reverse();
    cout << "s111: " << s111.toString() << endl;
    cout<<"Current Ref 2\n";
     
    
    ConcatStringList s100 = s111.subString(2,4);
    cout << "s100: " << s100.toString() << endl;
    
    
    ConcatStringList s5 = s1.concat(s2);
    cout << "s5: " << s5.toString() << endl;


    ConcatStringList s6 = s3.concat(s4).concat(s100);
    cout << "s6: " << s6.toString() << endl;

    cout<<"Current Ref 4\n";
     
    
    cout <<"refList.size() = " << ConcatStringList::refList.size() << endl;
    cout <<"refList.refCountAt(0) = "<< ConcatStringList::refList.refCountAt(0) << endl;
    cout <<"refList.refCountAt(1) = "<< ConcatStringList::refList.refCountAt(1) << endl;
    cout <<"refList.refCountAt(2) = "<< ConcatStringList::refList.refCountAt(2) << endl;
    cout <<"refList.refCountAt(3) = "<< ConcatStringList::refList.refCountAt(3) << endl;
    cout <<"refList.refCountAt(4) = "<< ConcatStringList::refList.refCountAt(4) << endl;
    cout <<"refList.refCountAt(5) = "<< ConcatStringList::refList.refCountAt(5) << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
}

void tc25() {
    ConcatStringList s1("Hello,");
    ConcatStringList s2("_this_is");
    ConcatStringList s3("_an_assignment");
    ConcatStringList s4("_which_no_one_like");
    
    ConcatStringList s100 = s1.subString(2,4);
    cout << "s100: " << s100.toString() << endl;
    cout<<"Current Ref 1\n";
     
    
    ConcatStringList s5 = s1.concat(s2);
    cout << "s5: " << s5.toString() << endl;
    cout<<"Current Ref 2\n";
     

    ConcatStringList s6 = s3.concat(s4).concat(s100);
    cout << "s6: " << s6.toString() << endl;
    cout<<"Current Ref 3\n";
     
    
    cout <<"refList.size() = " << ConcatStringList::refList.size() << endl;
    cout <<"refList.refCountAt(0) = "<< ConcatStringList::refList.refCountAt(0) << endl;
    cout <<"refList.refCountAt(1) = "<< ConcatStringList::refList.refCountAt(1) << endl;
    cout <<"refList.refCountAt(2) = "<< ConcatStringList::refList.refCountAt(2) << endl;
    cout <<"refList.refCountAt(3) = "<< ConcatStringList::refList.refCountAt(3) << endl;
    cout <<"refList.refCountAt(4) = "<< ConcatStringList::refList.refCountAt(4) << endl;
    cout <<"refList.refCountAt(5) = "<< ConcatStringList::refList.refCountAt(5) << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
}

void tc31() {
    ConcatStringList * s1 = new ConcatStringList("Hello,");
    ConcatStringList * s2 = new ConcatStringList("_this_is");
    ConcatStringList * s3 = new ConcatStringList(s1->concat(*s2));
    ConcatStringList * s4 = new ConcatStringList(s3->subString(0, 14));
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout << ConcatStringList::refList.size() << endl;
    cout << ConcatStringList::refList.refCountAt(0) << endl;
 
    delete s4;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    delete s3;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    delete s2;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    delete s1;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
}
 
void tc32() {
    ConcatStringList * s1 = new ConcatStringList("Hello,");
    ConcatStringList * s2 = new ConcatStringList("_this_is");
    ConcatStringList * s3 = new ConcatStringList("_an_assignment");
    ConcatStringList * s4 = new ConcatStringList(s1->concat(*s2));
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout << ConcatStringList::refList.size() << endl;
    cout << ConcatStringList::refList.refCountAt(0) << endl;
    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout << ConcatStringList::refList.size() << endl;
    cout << ConcatStringList::refList.refCountAt(0) << endl;
    cout << "---After deleting s4---" << endl;
    delete s4;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout << ConcatStringList::refList.size() << endl;
    cout << ConcatStringList::refList.refCountAt(0) << endl;
    
    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout << ConcatStringList::refList.size() << endl;
    cout << ConcatStringList::refList.refCountAt(0) << endl;
    cout << "---After deleting s3---" << endl;
    delete s3;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout << ConcatStringList::refList.size() << endl;
}
 
void tc33(){
    ConcatStringList * s1 = new ConcatStringList("Hello,");
    ConcatStringList * s2 = new ConcatStringList(s1->reverse());
 
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    
    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
}

void tc34() {
    ConcatStringList * s1 = new ConcatStringList("Hello");
    ConcatStringList * s2 = new ConcatStringList("_world");
    ConcatStringList * s4 = new ConcatStringList("_LOL");
    ConcatStringList * s3 = new ConcatStringList(s1->concat(*s2));

    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    
    cout << "---After deleting s3---" << endl;
    delete s3;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s4---" << endl;
    delete s4;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

}
void tc35() {
    ConcatStringList * s1 = new ConcatStringList("Hello");
    ConcatStringList * s2 = new ConcatStringList("_world");
    ConcatStringList * s4 = new ConcatStringList("_LOL");

    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    
    cout << "---After deleting s4---" << endl;
    delete s4;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

}

void tc36() {
    ConcatStringList * s1 = new ConcatStringList("Hello,");
    ConcatStringList * s2 = new ConcatStringList("_this_is");
    ConcatStringList * s3 = new ConcatStringList(s1->concat(*s2));
    ConcatStringList * s4 = new ConcatStringList(s3->reverse());

    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout << ConcatStringList::refList.size() << endl;
    cout << ConcatStringList::refList.refCountAt(0) << endl;
    delete s4;
    
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    delete s3;
    
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    delete s2;
    
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    delete s1;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
}

void tc37() {
    ConcatStringList * s1 = new ConcatStringList("Hello,");
    ConcatStringList * s2 = new ConcatStringList("_this_is");
    ConcatStringList * s3 = new ConcatStringList(s1->concat(*s2));
    ConcatStringList * s4 = new ConcatStringList(s3->reverse());
    ConcatStringList * s5 = new ConcatStringList(s4->subString(3,9));
    ConcatStringList * s6 = new ConcatStringList(s4->concat(*s5));

    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout <<"Ref size"<< ConcatStringList::refList.size() << endl;
    cout <<"Ref at 0"<< ConcatStringList::refList.refCountAt(0) << endl;
    cout <<"Del size "<< ConcatStringList::delStrList.size() << endl;

    cout<<"After Delete s6\n";
    delete s6;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout <<"Ref size"<< ConcatStringList::refList.size() << endl;
    cout <<"Ref at 0"<< ConcatStringList::refList.refCountAt(0) << endl;
    cout <<"Del size "<< ConcatStringList::delStrList.size() << endl;

    cout<<"After Delete s3\n";
    delete s3;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout <<"Ref size"<< ConcatStringList::refList.size() << endl;
    cout <<"Ref at 0"<< ConcatStringList::refList.refCountAt(0) << endl;
    cout <<"Del size "<< ConcatStringList::delStrList.size() << endl;

    cout<<"After Delete s1\n";
    delete s1;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout <<"Ref size"<< ConcatStringList::refList.size() << endl;
    cout <<"Ref at 0"<< ConcatStringList::refList.refCountAt(0) << endl;
    cout <<"Del size "<< ConcatStringList::delStrList.size() << endl;

    cout<<"After Delete s5\n";
    delete s5;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout <<"Ref size"<< ConcatStringList::refList.size() << endl;
    cout <<"Ref at 0"<< ConcatStringList::refList.refCountAt(0) << endl;
    cout <<"Del size "<< ConcatStringList::delStrList.size() << endl;

    cout<<"After Delete s2\n";
    delete s2;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout <<"Ref size"<< ConcatStringList::refList.size() << endl;
    cout <<"Ref at 0"<< ConcatStringList::refList.refCountAt(0) << endl;
    cout <<"Del size "<< ConcatStringList::delStrList.size() << endl;

    cout<<"After Delete s4\n";
    delete s4;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout <<"Ref size"<< ConcatStringList::refList.size() << endl;
    cout <<"Del size "<< ConcatStringList::delStrList.size() << endl;
}

void tc38() {
    ConcatStringList * s1 = new ConcatStringList("Hello,");
    ConcatStringList * s2 = new ConcatStringList(s1->reverse());

    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout <<"Ref size"<< ConcatStringList::refList.size() << endl;
    cout <<"Ref at 0"<< ConcatStringList::refList.refCountAt(0) << endl;
    cout <<"Del size "<< ConcatStringList::delStrList.size() << endl;

    cout<<"After Delete s2\n";
    delete s2;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout <<"Ref size"<< ConcatStringList::refList.size() << endl;
    cout <<"Ref at 0"<< ConcatStringList::refList.refCountAt(0) << endl;
    cout <<"Del size "<< ConcatStringList::delStrList.size() << endl;

    cout<<"After Delete s1\n";
    delete s1;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    cout <<"Ref size"<< ConcatStringList::refList.size() << endl;
    cout <<"Del size "<< ConcatStringList::delStrList.size() << endl;

}

void tc28() {
    ConcatStringList* s1 = new ConcatStringList("Hello,");
    ConcatStringList* s2 = new ConcatStringList("_this_is");
    ConcatStringList* s3 = new ConcatStringList("_an_assignment");
    ConcatStringList* s4 = new ConcatStringList("_Yamete Kudasai_");
    ConcatStringList* s5 = new ConcatStringList("Vo Hoang Nhat Khang");
 
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
 
    ConcatStringList* s7 = new ConcatStringList(s1->concat(*s2));
    cout << s7->toString() << '\n';
    ConcatStringList* s8 = new ConcatStringList(s7->reverse());
    cout << s8->toString() << '\n';
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    
    ConcatStringList* s9 = new ConcatStringList(s3->concat(*s4));
    cout << "s9 HERE : "<<s9->toString() << '\n';
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    ConcatStringList* s10 = new ConcatStringList(s9->subString(2, 14).subString(5, 9));
    cout << "s10 HERE : "<< s10->toString() << '\n';
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
 
    ConcatStringList* s11 = new ConcatStringList(s5->reverse());
    cout << s11->toString() << '\n';
    ConcatStringList* s12 = new ConcatStringList(s11->subString(2, 9));
    cout << s12->toString();
 
    delete s12;
 
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    delete s11;
 
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    delete s10;
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    delete s9;
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    delete s8;
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    delete s7;
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    delete s5;
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    delete s4;
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    delete s3;
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    delete s2;
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    delete s1;
    cout << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString() << '\n';
    cout<<"End process\n";
}


void tc3() {
    ConcatStringList * s1 = new ConcatStringList("Hello");
    ConcatStringList * s2 = new ConcatStringList("_world");
    ConcatStringList * s3 = new ConcatStringList(s1->concat(*s2));

    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s3---" << endl;
    delete s3;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
}


void tc30() {
    cout << endl;
    ConcatStringList* s0 = new ConcatStringList("XYZ");
    cout << "s0: " << s0->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size()<<endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s1 = new ConcatStringList("ABC");
    cout << "s1: " << s1->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s2 = new ConcatStringList("DEF");
    cout << "s2: " << s2->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s3 = new ConcatStringList("GHI");
    cout << "s3: " << s3->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s4 = new ConcatStringList(s1->concat(*s2));
    cout << "s4: " << s4->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s5 = new ConcatStringList(s4->reverse().concat(*s3));
    cout << "s5: " << s5->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s6 = new ConcatStringList(s5->reverse().reverse());
    cout << "s6: " << s6->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    
    cout << endl;
    ConcatStringList* s7 = new ConcatStringList(s5->subString(1,8));
    cout << "s7: " << s7->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    
    cout << endl;
    ConcatStringList* s8 = new ConcatStringList(s5->subString(1, 8).subString(1,5).subString(2,3));
    cout << "s8: " << s8->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s9 = new ConcatStringList(s6->concat(s5->reverse().subString(4,5)).reverse());
    cout << "s9: " << s9->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s10 = new ConcatStringList(s0->reverse().concat((s0->reverse().concat(s0->reverse()).reverse())));
    cout << "s10: " << s10->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << "---After deleting s0---" << endl;
    delete s0;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s3---" << endl;
    delete s3;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s4---" << endl;
    delete s4;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s5---" << endl;
    delete s5;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s6---" << endl;
    delete s6;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s7---" << endl;
    delete s7;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s8---" << endl;
    delete s8;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s9---" << endl;
    delete s9;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    
    cout << endl;
    cout << "---After deleting s10---" << endl;
    delete s10;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
}


void tc39() {
    cout << endl;
    ConcatStringList* s0 = new ConcatStringList("");
    cout << "s0: " << s0->toString() <<" , length ="<<s0->length()<< endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size()<<endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s1 = new ConcatStringList("");
    cout << "s1: " << s1->toString()<<" , length ="<<s1->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s2 = new ConcatStringList("");
    cout << "s2: " << s2->toString() <<" , length ="<<s2->length()<< endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s3 = new ConcatStringList("123456789");
    cout << "s3: " << s3->toString()<<" , length ="<<s3->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s4 = new ConcatStringList(s0->concat(*s1));
    cout << "s4: " << s4->toString()<<" , length ="<<s4->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s5 = new ConcatStringList(s0->reverse());
    //s5 is "" so head and tail is the same
    cout << "s5: " << s5->toString()<<" , length ="<<s5->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s6 = new ConcatStringList(s4->reverse());
    //s6 is  "" -> "" so there are different head and tail
    cout << "s6: " << s6->toString()<<" , length ="<<s6->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s7 = new ConcatStringList(s2->concat(*s3));
    //s7 is "" -> "123456789" so head is "" and tail is "123456789"
    cout << "s7: " << s7->toString()<<" , length ="<<s7->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s8 = new ConcatStringList(s7->reverse());
    //s8 is "987654321" -> "" so head is "987654321" and tail is ""
    cout << "s8: " << s8->toString()<<" , length ="<<s8->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s9 = new ConcatStringList(s7->subString(0,9));
    //s9 still get the empty string so ""->"123456789"
    cout << "s9: " << s9->toString()<<" , length ="<<s9->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s10 = new ConcatStringList(s9->reverse());
    //try reverse it why not "987654321" ->""
    cout << "s10: " << s10->toString()<<" , length ="<<s10->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s11 = new ConcatStringList(s8->subString(0,9));
    //s11 still get the empty string so "987654321" -> ""
    cout << "s11: " << s11->toString()<<" , length ="<<s11->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s12 = new ConcatStringList(s11->reverse());
    //reverse it why not ""->"123456789"
    cout << "s12: " << s12->toString()<<" , length ="<<s12->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s13 = new ConcatStringList(s12->concat(*s10));
    //s13 is "" -> "123456789" -> "987654321" -> "" 
    cout << "s13: " << s13->toString()<<" , length ="<<s13->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s14 = new ConcatStringList(s13->subString(0,18));
    //s14 is "" -> "123456789" -> "987654321" -> "" 
    cout << "s14: " << s14->toString()<<" , length ="<<s14->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout<<"s14: '9' is at "<<s14->indexOf('9')<<" index and at index 9 is "<<s14->get(9)<<" , so they are equal "<<(s14->indexOf(s14->get(9))==9)<<endl;

    cout << endl;
    ConcatStringList* s15 = new ConcatStringList(s13->reverse());
    //s14 is "987654321" -> ""  -> "" -> "123456789"
    cout << "s15: " << s15->toString()<<" , length ="<<s15->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout<<"s15: '1' is at "<<s15->indexOf('1')<<" index and at index 1 is "<<s15->get(1)<<" , so they are equal "<<(s15->indexOf(s15->get(1))==1)<<endl;

    cout << "---After deleting s15---" << endl;
    delete s15;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << "---After deleting s14---" << endl;
    delete s14;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s13---" << endl;
    delete s13;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s12---" << endl;
    delete s12;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s11---" << endl;
    delete s11;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    
    cout << "---After deleting s10---" << endl;
    delete s10;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s9---" << endl;
    delete s9;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s8---" << endl;
    delete s8;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s7---" << endl;
    delete s7;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    
    cout << "---After deleting s6---" << endl;
    delete s6;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s0---" << endl;
    delete s0;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s3---" << endl;
    delete s3;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s4---" << endl;
    delete s4;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s5---" << endl;
    delete s5;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

}



void tc47() {
    cout << endl;
    ConcatStringList* s0 = new ConcatStringList("0123456789");
    cout << "s0: " << s0->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
 
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
 
 
 
    ConcatStringList* s2 = new ConcatStringList
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
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
 
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
    ConcatStringList* s3 = new ConcatStringList(s2->reverse());
    cout << "s3: " << s3->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
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
 
    cout << "---After deleting 3---" << endl;
    delete s2;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
 
    cout << endl;
    cout << "---After deleting 0---" << endl;
    delete s0;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
 
    //_CrtDumpMemoryLeaks();
 
    cout << endl;
    cout << "---After deleting s2---" << endl;
    delete s3;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
 
    //_CrtDumpMemoryLeaks();
}
 

void tc30v2() {
    cout << endl;
    ConcatStringList* s0 = new ConcatStringList("XYZ");
    cout << "s0: " << s0->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size()<<endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s1 = new ConcatStringList("ABC");
    cout << "s1: " << s1->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s2 = new ConcatStringList("DEF");
    cout << "s2: " << s2->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s3 = new ConcatStringList("GHI");
    cout << "s3: " << s3->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s4 = new ConcatStringList(s1->concat(*s2));
    cout << "s4: " << s4->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    try{
        int sum = 0;
        for(int i =0 ; i<s4->length(); i++){
            sum+= s4->indexOf(s4->get(i));
        }

        cout<<"s4 sum = "<<sum+s4->indexOf('A')<<endl;
    }
    catch(exception &a){
        a.what();
    }

    try{
        int sum = 0;
        for(int i =0 ; i<s1->length(); i++){
            sum+= s1->indexOf(s1->get(i));
        }
        //s1 after concat
        cout<<"s1 sum = "<<sum+s1->indexOf(s4->get(s4->length()-1))<<endl;
    }
    catch(exception &a){
        a.what();
    }

    try{
        int sum = 0;
        for(int i =0 ; i<s2->length(); i++){
            sum+= s2->indexOf(s2->get(i));
        }

        cout<<"s2 sum = "<<sum+s2->indexOf(s4->get(s4->length()-1))<<endl;
    }
    catch(exception &a){
        a.what();
    }

   

    cout << endl;
    ConcatStringList* s5 = new ConcatStringList(s4->reverse().concat(*s3));
    try{
        int sum = 0;
        for(int i =0 ; i<s5->length(); i++){
            sum+= s5->indexOf(s5->get(i));
        }

        cout<<"s5 sum = "<<sum+s3->indexOf(s3->get(0))<<endl;
    }
    catch(exception &a){
        a.what();
    }
    cout << "s5: " << s5->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s6 = new ConcatStringList(s5->reverse().reverse());
    cout << "s6: " << s6->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    try{
        int sum = 0;
        for(int i =0 ; i<s6->length(); i++){
            sum+= s6->indexOf(s6->get(i));
        }

        cout<<"s6 sum = "<<sum+s6->indexOf(s6->get(0))<<endl;
    }
    catch(exception &a){
        a.what();
    }

    cout << endl;
    ConcatStringList* s7 = new ConcatStringList(s5->subString(1,8));
    cout << "s7: " << s7->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    try{
        int sum = 0;
        for(int i =0 ; i<s7->length(); i++){
            sum+= s7->indexOf(s7->get(i));
        }

        cout<<"s7 sum = "<<sum+s7->indexOf(s7->get(0))<<endl;
    }
    catch(exception &a){
        a.what();
    }

    cout << endl;
    ConcatStringList* s8 = new ConcatStringList(s5->subString(1, 8).subString(1,5).subString(2,3));
    cout << "s8: " << s8->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    try{
        int sum = 0;
        for(int i =0 ; i<s8->length(); i++){
            sum+= s8->indexOf(s8->get(i));
        }

        cout<<"s8 sum = "<<sum+s8->indexOf(s8->get(0))<<endl;
    }
    catch(exception &a){
        a.what();
    }

    cout << endl;
    ConcatStringList* s9 = new ConcatStringList(s6->concat(s5->reverse().subString(4,5)).reverse());
    cout << "s9: " << s9->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    try{
        int sum = 0;
        for(int i =0 ; i<s9->length(); i++){
            sum+= s9->indexOf(s9->get(i));
        }

        cout<<"s9 sum = "<<sum+s9->indexOf(s9->get(0))<<endl;
    }
    catch(exception &a){
        a.what();
    }

    cout << endl;
    ConcatStringList* s10 = new ConcatStringList(s0->reverse().concat((s0->reverse().concat(s0->reverse()).reverse())));
    cout << "s10: " << s10->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    try{
        int sum = 0;
        for(int i =0 ; i<s10->length(); i++){
            sum+= s10->indexOf(s10->get(i));
        }

        cout<<"s10 sum = "<<sum+s10->indexOf(s10->get(0))<<endl;
    }
    catch(exception &a){
        a.what();
    }

    cout << "---After deleting s0---" << endl;
    delete s0;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s3---" << endl;
    delete s3;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s4---" << endl;
    delete s4;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s5---" << endl;
    delete s5;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s6---" << endl;
    delete s6;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s7---" << endl;
    delete s7;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s8---" << endl;
    delete s8;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s9---" << endl;
    delete s9;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    
    cout << endl;
    cout << "---After deleting s10---" << endl;
    delete s10;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
}


int main() {
    tc30v2();
    return 0;
}