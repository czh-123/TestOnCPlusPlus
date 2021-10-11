#include <iostream>
#include <vector>
#include <unistd.h>
#include <unordered_map>
#include <functional>

using namespace std;

template<class Map>
class SolWithType{
public:
    SolWithType () {}

    // 需要调用者配合
    void dealVec(vector<int>& vec, Map& map) {
        Map locale;
        if (vec.empty()) {
        return ;
        }
        for (const auto& elem : vec) {
            if (locale.find(elem) == locale.end()) {
                locale[elem]++;
            }
        }
        for (auto& p : locale) {
            map[p.first]++;
        }
    }

};

class Sol{
public:
    Sol () = delete;
    // 需要调用者配合
    // 好处是省去打Map了
    // 声明为static 比较好
    template<typename Map>
    static void dealVec(vector<int>& vec, Map& map) {
        Map locale;
        if (vec.empty()) {
        return ;
        }
        for (const auto& elem : vec) {
            if (locale.find(elem) == locale.end()) {
                locale[elem]++;
            }
        }
        for (auto& p : locale) {
            map[p.first]++;
        }
    }

    template<typename Func>
    static void funcVec(vector<int>& vec, Func& fun) {
        for (auto& p : vec) {
            fun(p);
        }
    }
};

ostream& operator << (ostream& os, unordered_map<int, int>& map) {
    for (auto& p : map) {
        cout<<p.first<<"  "<<p.second<<endl;
    }
    cout<<endl;
    return os;
}

ostream& operator << (ostream& os, vector<int>& map) {
    for (auto& p : map) {
        cout<<p<<"  ";
    }
    cout<<endl;
    return os;
}

int main() {
    unordered_map<int, int> map;
    vector<int> vec1{1,2,1,2};
    SolWithType<unordered_map<int, int>> sol;
    sol.dealVec(vec1, map);
    cout<<map;
    
    Sol::dealVec(vec1, map);
    cout<<map;

    auto func = [] (int& num) {
        num += 1;
    };
    Sol::funcVec(vec1, func);
    cout<<vec1;

}