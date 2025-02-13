#include "hash.h"
#include "unordered_Map.h"
#include "unordered_Set.h"
int main(){
    unordered_Map<string,int> ht;
    ht.insert({"hello",8});
    ht.insert({"what",3});
    ht.insert({"a",1});
    ht.insert({"day",6});
    return 0;
}