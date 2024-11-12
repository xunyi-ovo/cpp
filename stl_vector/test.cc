#include "vector.h"
#include <iostream>
using namespace std;
namespace xunyi{
    void test1(){
        vector<int> v;
        v.push_back(1);
    }
}
int main(){
    xunyi::test1();
    return 0;
}