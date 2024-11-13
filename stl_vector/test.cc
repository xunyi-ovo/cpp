#include "vector.h"
#include <iostream>
#include <list>
using namespace std;
namespace xunyi{
    void show(vector<int>& v){
        for(const auto& e:v) cout<<e<<" ";
        cout<<endl;
    }
    void test1(){
        vector<int> v1 = {1,2,3,4,5,6,7,8,9};
        vector<int> v2 = {66,6};
        show(v1);
        show(v2);
        v2 = v1;
        show(v2);
        v1[0] = 333;
        v1[3] = 333;
        show(v1);
        show(v2);

    }
}
int main(){
    xunyi::test1();
    return 0;
}