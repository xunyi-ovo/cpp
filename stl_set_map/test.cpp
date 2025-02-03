#include "my_set.h"
#include "my_map.h"
void test1(){
    xunyi::set<int> st;
    for(int i=1;i<20;++i)
    st.insert(i);

    for(auto e:st){
        cout<<e<<" ";
    }
    cout<<endl;
    xunyi::set<int,my_greater<int>> st2;
    for(int i=20;i>0;i-=3){
        st2.insert(i);
    }
    for(auto e:st2){
        cout<<e<<" ";
    }
    cout<<endl;
}
void test2(){
    xunyi::map<string,int,my_greater<string>> word_count;
    word_count.insert(make_pair("into the leaves",13));
    word_count.insert(make_pair("gone with leaves",13));
    word_count.insert(make_pair("i",1));
    word_count.insert(make_pair("love",4));
    word_count.insert(make_pair("you",3));
    auto iter = word_count.begin();
    while(iter!=word_count.end()){
        cout<<iter->first<<" "<<iter->second<<endl;
        ++iter;
    }

}
int main(){
    test2();
    //test1();
    return 0;
}