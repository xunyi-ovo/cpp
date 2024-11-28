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
    void test2(){
        vector<string> arr = {"xunyi", "666"};
        for (const auto &e : arr)
            cout << e << " ";
        cout << endl;
        vector<string> arr2(arr);
        for (const auto &e : arr2)
            cout << e << " ";
        cout << endl;
        arr[0] = "333";
        for (const auto &e : arr2)
            cout << e << " ";
        cout << endl;
                for (const auto &e : arr)
            cout << e << " ";
        cout << endl;
    }
}
int main(){
    xunyi::test2();
    return 0;
}