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
    xunyi::List<int> ls1;
    ls1.push_back(1);
    ls1.push_back(2);
    ls1.push_back(3);
    ls1.push_back(4);
    ls1.push_back(5);

    xunyi::List<int> ls2;
    ls2.push_back(6);
    ls2 = ls1;
    xunyi::List<int> ls3 = {3,4,5};
    xunyi::List<int> ls4(ls1.begin(),ls1.end());
    show_list(ls1);
    show_list(ls2);
    show_list(ls2);
    show_list(ls3);
    show_list(ls4);
}

int main()
{
    test1();
    return 0;
}
