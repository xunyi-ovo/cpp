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
        vector<int> v1 = {1,2,3};
        show(v1);
    }
}
int main(){
    xunyi::test1();
    return 0;
}