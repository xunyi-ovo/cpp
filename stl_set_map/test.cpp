#include "my_set.h"
#include "my_map.h"

int main(){
    xunyi::set<int> st;
    for(int i=1;i<999;++i)
    st.insert(i);

    for(auto e:st){
        cout<<e<<" ";
    }
    return 0;
}