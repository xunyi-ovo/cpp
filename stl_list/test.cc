#include "list.h"
using namespace std;
template<class T>
void show_list(const xunyi::List<T>& ls){
    for(auto e:ls){
        cout<<e<<" ";
    }
    cout<<endl;
}
void test1(){
    xunyi::List<int> ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    ls.push_back(5);

    xunyi::List<int> ls2;
    ls2.push_back(6);
    show_list(ls);
    show_list(ls2);
    ls2 = ls;
    show_list(ls2);


}
void test2(){
    xunyi::List<int> ls = {1,2,3};
}
int main()
{
    test2();
    return 0;
}
