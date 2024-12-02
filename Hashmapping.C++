#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    //creation of map
    map<string,int>m;

    //insertion
    //1
    pair<string,int> p= make_pair("Neeraj",7);
    m.insert(p);

    //2
    pair<string,int> pair2("love",2);
    m.insert(pair2);

    //3
    m["Neeraj"]=1;

    //search
    cout <<m["Neeraj"] <<endl;
    cout <<m.at("love") <<endl;

    //to cheack presence
    cout <<m.count("love") <<endl;

    //erase
    m.erase("love"); 
    cout<<m.size() << endl;
     
    for(auto i:m){
        cout<<i.first << " " << i.second << endl;
    }

    //itereator
    map<string,int> :: iterator it = m.begin();

    while(it!=m.end()){
        cout << it->first <<" " << it->second <<endl;

    }
    return 0;
}
