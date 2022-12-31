#include <bits/stdc++.h>
using namespace std;


map<int, bool> m_composite_b, m_ge_bf, composite_b;
map<tuple<int,int>,bool> ge_bf, m_multi_bbf,m_add_bbf;
map<tuple<int,int,int>, bool> m_multi_bbb,multi_bbf,m_add_bbb,multi_bbb,add_bbb,add_bbf;

bool m_rule_1(){
    auto iter = m_composite_b.begin();
    bool flag = false;
    while(iter!=m_composite_b.end()){
        if(!m_ge_bf[iter->first] ){
            m_ge_bf[iter->first] = true;
            flag = true;
        }
        iter++;
    }
    return flag;
}
bool m_rule_2(){
    auto it1 = m_composite_b.begin();
    auto it2 = ge_bf.begin();
    bool flag = false;
    while(it1!=m_composite_b.end()){
        it2 = ge_bf.begin();
        while(it2!=ge_bf.end()){
            if(it1->first == get<0>(it2->first) && get<1>(it2->first) >= 2 && !m_ge_bf[get<1>(it2->first)]){
                flag = true;
                m_ge_bf[get<1>(it2->first)] = true;
            }
            it2++;
        }
        it1++;
    }
    return flag;
}
bool m_rule_3(){
    auto it1 = m_composite_b.begin();
    auto it2 = ge_bf.begin();
    auto it3 = ge_bf.begin();
    bool flag = false;
    while(it1!=m_composite_b.end()){
         it2 = ge_bf.begin();
        while(it2!=ge_bf.end()){
            it3 = ge_bf.begin();
            while(it3!=ge_bf.end()){
                if(it1->first==get<0>(it2->first) && get<1>(it2->first)==get<0>(it3->first) &&
                get<1>(it2->first)>=2 && get<1>(it3->first) >= 2){
                    if(!m_multi_bbb[make_tuple(get<1>(it2->first),get<1>(it3->first),it1->first)]){
                        flag=true;
                        m_multi_bbb[make_tuple(get<1>(it2->first),get<1>(it3->first),it1->first)]=true;
                    }
                    
                }
                it3++;
            }
            it2++;
        }
        it1++;
    }
    return flag;
}
bool m_rule_4(){
    auto iter = m_ge_bf.begin();
    bool flag = false;
    while(iter!=m_ge_bf.end()){
        if(iter->first >= 1){
            if(!m_ge_bf[iter->first - 1]){
                m_ge_bf[iter->first - 1] = true;
                flag = true;
                iter = m_ge_bf.begin();
                continue;
            }
            
        }
        iter++;
    }
    return flag;
}
bool m_rule_5(){
    auto it1 = m_multi_bbb.begin();
    bool flag = false;
    while(it1!=m_multi_bbb.end()){
        if(get<0>(it1->first)>=1 && !m_multi_bbf[make_tuple(get<0>(it1->first) - 1, get<1>(it1->first))]){
            m_multi_bbf[make_tuple(get<0>(it1->first) - 1, get<1>(it1->first))] = true;
            flag = true;
            it1 = m_multi_bbb.begin();
        }
        it1++;
    }
    return flag;
}
bool m_rule_6(){
    auto it1 = m_multi_bbb.begin();
    auto it2 = multi_bbf.begin();
    bool flag = false;
    while(it1!=m_multi_bbb.end()){
        it2 = multi_bbf.begin();
        while(it2!=multi_bbf.end()){
            if(get<0>(it1->first)==(get<0>(it2->first)+1) && get<1>(it1->first)==get<1>(it2->first)
            && !m_add_bbb[make_tuple(get<2>(it2->first), get<1>(it2->first),get<2>(it1->first))]){
                flag = true;
                m_add_bbb[make_tuple(get<2>(it2->first), get<1>(it2->first),get<2>(it1->first))] = true;
            }
            it2++;
        }
        it1++;
    }
    return flag;
}
bool m_rule_7(){
    auto iter = m_multi_bbf.begin();
    bool flag = false;
    while(iter!=m_multi_bbf.end()){
        if(get<0>(iter->first)>=1 && !m_multi_bbf[make_tuple(get<0>(iter->first)-1, get<1>(iter->first))]){
            m_multi_bbf[make_tuple(get<0>(iter->first)-1, get<1>(iter->first))] = true;
            flag = true;
            iter = m_multi_bbf.begin();
            continue;
        }
        iter++;
    }
    return flag;
}
bool m_rule_8(){
    auto it1 = m_multi_bbf.begin();
    auto it2 = multi_bbf.begin();
    bool flag = false;
    while(it1!=m_multi_bbf.end()){
        it2 = multi_bbf.begin();
        while(it2!=multi_bbf.end()){
            if(get<0>(it1->first)>=1 && get<0>(it1->first)-1 == get<0>(it2->first) &&get<1>(it1->first) == get<1>(it2->first)
            && !m_add_bbf[make_tuple(get<2>(it2->first),get<1>(it2->first))]){
                flag = true;
                m_add_bbf[make_tuple(get<2>(it2->first),get<1>(it2->first))] = true;
            }
            it2++;
        }
        it1++;
    }
    return flag;
}
bool m_rule_9(){
    auto iter = m_add_bbb.begin();
    bool flag = false;
    while(iter!=m_add_bbb.end()){
            if(get<0>(iter->first)>=1 && get<2>(iter->first)>=1 &&
             !m_add_bbb[make_tuple(get<0>(iter->first)-1,get<1>(iter->first),get<2>(iter->first)-1)]){
                m_add_bbb[make_tuple(get<0>(iter->first)-1,get<1>(iter->first),get<2>(iter->first)-1)] = true;
                flag = true;
                iter = m_add_bbb.begin();
                continue;
            }
        iter++;
    }
    return flag;
}
bool m_rule_10(){
    auto iter = m_add_bbf.begin();
    bool flag = false;
    while(iter!=m_add_bbf.end()){
        if(get<0>(iter->first)>=1  &&
        !m_add_bbf[make_tuple(get<0>(iter->first)-1,get<1>(iter->first))]){
                m_add_bbf[make_tuple(get<0>(iter->first)-1,get<1>(iter->first))] = true;
                flag = true;
                iter = m_add_bbf.begin();
                continue;
        }
        iter++;
    }
    return flag;
}

bool rule_1(){
    auto itr1 = m_composite_b.begin();
    auto itr2 = ge_bf.begin();    
    auto itr3 = ge_bf.begin();
    auto itr4 = multi_bbb.begin();
    bool flag = false;
    while(itr1!=m_composite_b.end()){
        itr2 = ge_bf.begin();
        while(itr2!=ge_bf.end()){
            itr3 = ge_bf.begin();
            while(itr3!=ge_bf.end()){
                itr4 = multi_bbb.begin();
                while(itr4!=multi_bbb.end()){
                    if(itr1->first==get<0>(itr2->first)
                    && get<1>(itr2->first)>=2
                    && get<1>(itr3->first)>=2
                    && get<1>(itr2->first)==get<0>(itr3->first)
                    && get<1>(itr3->first)==get<1>(itr4->first)
                    && get<0>(itr3->first)==get<0>(itr4->first)
                    && itr1->first == get<2>(itr4->first)
                    && !composite_b[itr1->first]){
                        composite_b[itr1->first] = true;
                        flag =true;
                    }
                    itr4++;
                }
                itr3++;
            }
            itr2++;
        }
        itr1++;
    }
    return flag;
}
bool rule_2(){
    bool flag = false;
    auto itr = m_ge_bf.begin();
    while(itr!=m_ge_bf.end()){
        if(!ge_bf[make_tuple(itr->first,itr->first)]){
            ge_bf[make_tuple(itr->first,itr->first)]=true;
            flag=true;
        }
        itr++;
    }
    return flag;
}
bool rule_3(){
    bool flag = false;
    auto itr1 = m_ge_bf.begin();
    auto itr2 = ge_bf.begin();
    while(itr1!=m_ge_bf.end()){
        itr2 = ge_bf.begin();
        while(itr2!=ge_bf.end()){
            if(itr1->first == (get<0>(itr2->first)+1)
            && !ge_bf[make_tuple(itr1->first,get<1>(itr2->first))]){
                ge_bf[make_tuple(itr1->first,get<1>(itr2->first))]=true;
                flag=true;
                itr2 = ge_bf.begin();
                continue;
            }
            itr2++;
        }

        itr1++;
    }
    return flag;
}
bool rule_4(){
    bool flag = false;
    auto itr = m_multi_bbb.begin();
    while(itr!=m_multi_bbb.end()){
        if(get<0>(itr->first)==0
        && get<0>(itr->first)==get<2>(itr->first)
        && !multi_bbb[make_tuple(0,get<1>(itr->first),0)]){
            multi_bbb[make_tuple(0,get<1>(itr->first),0)]=true;
            flag=true;
        }
        itr++;
    }
    return flag;
}
bool rule_5(){
    auto itr1 = m_multi_bbb.begin();
    auto itr2 = multi_bbf.begin();    
    auto itr3 = add_bbb.begin();
    bool flag = false;
    while(itr1!=m_multi_bbb.end()){
        itr2 = multi_bbf.begin();
        while(itr2!=multi_bbf.end()){
            itr3 = add_bbb.begin();
            while(itr3!=add_bbb.end()){
                    if(get<0>(itr1->first)==get<0>(itr2->first)+1
                    && get<1>(itr1->first)== get<1>(itr2->first)
                    && get<1>(itr1->first)== get<1>(itr3->first)
                    && get<2>(itr2->first)== get<0>(itr3->first)
                    && get<2>(itr1->first)== get<2>(itr3->first)
                    && !multi_bbb[make_tuple(get<0>(itr1->first),get<1>(itr1->first),get<2>(itr3->first))]){
                        multi_bbb[make_tuple(get<0>(itr1->first),get<1>(itr1->first),get<2>(itr3->first))] = true;
                        flag =true;
                    }
                
                itr3++;
            }
            itr2++;
        }
        itr1++;
    }
    return flag;
}
bool rule_6(){
    bool flag = false;
    auto itr = m_multi_bbf.begin();
    while(itr!=m_multi_bbf.end()){
        if( get<0>(itr->first) == 0
            && !multi_bbf[make_tuple(0,get<1>(itr->first),0)]){
            multi_bbf[make_tuple(0,get<1>(itr->first),0)]=true;
            flag=true;
        }
        itr++;
    }
    return flag;
}
bool rule_7(){
    auto itr1 = m_multi_bbf.begin();
    auto itr2 = multi_bbf.begin();    
    auto itr3 = add_bbf.begin();
    bool flag = false;
    while(itr1!=m_multi_bbf.end()){
        itr3 = add_bbf.begin();
        while(itr3!=add_bbf.end()){
            itr2 = multi_bbf.begin(); 
            while(itr2!=multi_bbf.end()){
                    if(get<0>(itr1->first)==get<0>(itr2->first)+1
                    && get<1>(itr1->first)== get<1>(itr2->first)
                    && get<1>(itr1->first)== get<1>(itr3->first)
                    && get<2>(itr2->first)== get<0>(itr3->first)
                    && !multi_bbf[make_tuple(get<0>(itr1->first),get<1>(itr1->first),get<2>(itr3->first))]){
                        multi_bbf[make_tuple(get<0>(itr1->first),get<1>(itr1->first),get<2>(itr3->first))] = true;
                        flag =true;
                        itr2=multi_bbf.begin();
                        continue;
                    }
                
                itr2++;
            }
            itr3++;
        }
        itr1++;
    }
    return flag;
}
bool rule_8(){
    bool flag = false;
    auto itr = m_add_bbb.begin();
    while(itr!=m_add_bbb.end()){
        if( get<0>(itr->first) == 0
            && get<1>(itr->first)==get<2>(itr->first) 
            &&!add_bbb[make_tuple(0,get<1>(itr->first),get<1>(itr->first))]){
            add_bbb[make_tuple(0,get<1>(itr->first),get<1>(itr->first))]=true;
            flag=true;
        }
        itr++;
    }
    return flag;
}
bool rule_9(){
    bool flag = false;
    auto itr = m_add_bbf.begin();
    while(itr!=m_add_bbf.end()){
        if( get<0>(itr->first) == 0
            &&!add_bbf[make_tuple(0,get<1>(itr->first),get<1>(itr->first))]){
            add_bbf[make_tuple(0,get<1>(itr->first),get<1>(itr->first))]=true;
            flag=true;
        }
        itr++;
    }
    return flag;
}
bool rule_10(){
    bool flag = false;
    auto itr1 = m_add_bbb.begin();
    auto itr2 = add_bbb.begin();
    while(itr1!=m_add_bbb.end()){
        itr2 = add_bbb.begin();
        while(itr2!=add_bbb.end()){
            if(get<0>(itr1->first)==get<0>(itr2->first)+1
            && get<1>(itr1->first)==get<1>(itr2->first)
            && get<2>(itr1->first)==get<2>(itr2->first)+1
            && !add_bbb[itr1->first]
            ){
                add_bbb[itr1->first]=true;
                flag=true;
                itr2 = add_bbb.begin();
                continue;
            }
            itr2++;
        }
        itr1++;
    }
    return flag;
}
bool rule_11(){
    bool flag = false;
    auto itr1 = m_add_bbf.begin();
    auto itr2 = add_bbf.begin();
    while(itr1!=m_add_bbf.end()){
        itr2 = add_bbf.begin();
        while(itr2!=add_bbf.end()){
            if(get<0>(itr1->first)==get<0>(itr2->first)+1
            && get<1>(itr1->first)==get<1>(itr2->first)
            && !add_bbf[make_tuple(get<0>(itr1->first),get<1>(itr1->first),get<2>(itr2->first)+1)]
            ){
                add_bbf[make_tuple(get<0>(itr1->first),get<1>(itr1->first),get<2>(itr2->first)+1)]=true;
                flag=true;
                itr2 = add_bbf.begin();
                continue;
            }
            itr2++;
        }
        itr1++;
    }
    return flag;
}

int main(){
    bool flag=true;
    m_composite_b[5] = true;
    while(flag){
        flag=false;
        if(
                m_rule_1()
            ||  m_rule_2()
            ||  m_rule_3()
            ||  m_rule_4()
            ||  m_rule_5()
            ||  m_rule_6()
            ||  m_rule_7()
            ||  m_rule_8()
            ||  m_rule_9()
            ||  m_rule_10()
            ||  rule_1()
            ||  rule_2()
            ||  rule_3()
            ||  rule_4()
            ||  rule_5()
            ||  rule_6()
            ||  rule_7()
            ||  rule_8()
            ||  rule_9()
            ||  rule_10()
            ||  rule_11()
        ) flag = true;
        
    }

{ cout << "m_composite_b" << endl;
    auto itr = m_composite_b.begin();
    while(itr!=m_composite_b.end()){
            cout << "m_composite_b(";
            cout << itr->first << "), ";
            itr++;
    } cout << endl;
}
{ cout << "m_ge_bf" << endl;
    auto itr = m_ge_bf.begin();
    while(itr!=m_ge_bf.end()){
            cout << "m_ge_bf(";
            cout << itr->first << "), ";
            itr++;
    } cout << endl;
} 
{ cout << "composite_b" << endl;
    auto itr = composite_b.begin();
    while(itr!=composite_b.end()){
            cout << "composite_b(";
            cout << itr->first << "), " ;
            itr++;
    } cout << endl;    
}

{ cout << "ge_bf" << endl;
    auto itr = ge_bf.begin();
    while(itr!=ge_bf.end()){
            cout << "ge_bf(";
            cout << get<0>(itr->first) << "," << get<1>(itr->first) << "), ";
            itr++;
    } cout << endl;
}
{ cout << "m_multi_bbf" << endl;
    auto itr = m_multi_bbf.begin();
    while(itr!=m_multi_bbf.end()){
            cout << "m_multi_bbf(";
            cout << get<0>(itr->first) << "," << get<1>(itr->first) << "), ";
            itr++;
    } cout << endl;
}
{ cout << "m_add_bbf" << endl;
    auto itr = m_add_bbf.begin();
    while(itr!=m_add_bbf.end()){
            cout << "m_add_bbf(";
            cout << get<0>(itr->first) << "," << get<1>(itr->first) << "), ";
            itr++;
    } cout << endl;
}

{ cout << "m_multi_bbb" << endl;
    auto itr = m_multi_bbb.begin();
    while(itr!=m_multi_bbb.end()){
            cout << "m_multi_bbb(";
            cout << get<0>(itr->first) << "," << get<1>(itr->first) << "," << get<2>(itr->first) << "), " ;
            itr++;
    } cout << endl;
}
{ cout << "multi_bbf" << endl;
    auto itr = multi_bbf.begin();
    while(itr!=multi_bbf.end()){
            cout << "multi_bbf(";
            cout << get<0>(itr->first) << "," << get<1>(itr->first) << "," << get<2>(itr->first) << "), " ;
            itr++;
    } cout << endl;
}
{ cout << "m_add_bbb" << endl;
    auto itr = m_add_bbb.begin();
    while(itr!=m_add_bbb.end()){
            cout << "m_add_bbb(";
            cout << get<0>(itr->first) << "," << get<1>(itr->first) << "," << get<2>(itr->first) << "), " ;
            itr++;
    } cout << endl;
}
{ cout << "multi_bbb" << endl;
    auto itr = multi_bbb.begin();
    while(itr!=multi_bbb.end()){
            cout << "multi_bbb(";
            cout << get<0>(itr->first) << "," << get<1>(itr->first) << "," << get<2>(itr->first) << "), " ;
            itr++;
    } cout << endl;
}
{ cout << "add_bbb" << endl;
    auto itr = add_bbb.begin();
    while(itr!=add_bbb.end()){
            cout << "add_bbb(";
            cout << get<0>(itr->first) << "," << get<1>(itr->first) << "," << get<2>(itr->first) << "), " ;
            itr++;
    } cout << endl;
}
{ cout << "add_bbf" << endl;
    auto itr = add_bbf.begin();
    while(itr!=add_bbf.end()){
            cout << "add_bbf(";
            cout << get<0>(itr->first) << "," << get<1>(itr->first) << "," << get<2>(itr->first) << "), " ;
            itr++;
    } cout << endl;
}

    return 0;
}