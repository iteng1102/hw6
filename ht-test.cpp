#include "ht.h"
#include "hash.h"
#include <unordered_map>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <functional>
using namespace std;
int main()
{
    DoubleHashProber<std::string, MyStringHash > dh;
    HashTable<
        std::string, 
        int, 
        DoubleHashProber<std::string, MyStringHash >, 
        std::hash<std::string>, 
        std::equal_to<std::string> > ht;

    // This is just arbitrary code. Change it to test whatever you like about your 
    // hash table implementation.
    /*for(size_t i = 0; i < 10; i++){
        std::stringstream ss;
        ss << "hi" << i;
        ht.insert({ss.str(), i});
    }
    if( ht.find("hi1") != nullptr ){
        cout << "Found hi1" << endl;
        ht["hi1"] += 1;
        cout << "Incremented hi1's value to: " << ht["hi1"] << endl;
    }
    if( ht.find("doesnotexist") == nullptr ){
        cout << "Did not find: doesnotexist" << endl;
    }
    cout << "HT size: " << ht.size() << endl;
    ht.remove("hi7");
    ht.remove("hi9");
    cout << "HT size: " << ht.size() << endl;
    if( ht.find("hi9") != nullptr ){
        cout << "Found hi9" << endl;
    }
    else {
        cout << "Did not find hi9" << endl;
    }
    ht.insert({"hi7",17});
    cout << "size: " << ht.size() << endl; */
    /*for(size_t i = 0; i < 100; i++){
        string key = "key " + to_string(i);
        ht.insert({key, i});
        std::cout << "inserted " << i+1 << std::endl;
    }

    for (size_t i = 0; i<100; i+=3){
        ht.remove("key" + to_string(i));
        cout << "removed " << i+1 << std::endl;
    }*/

    for(int i = 0; i < 5; i++) {
        string key = "key " + to_string(i);;
        ht.insert({key, i});
    }
    return 0;
}
