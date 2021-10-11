#include <iostream>
#include <map>
#include <vector>
// #include <pair>

using namespace std;

class Key {
public:
    Key () {
        cout<<"Key is constructed"<<endl;
    }

    Key (const Key& a) : a_(a.a_) {
        cout<<"Key copy assign"<<endl;
    }

    Key (Key&& a) : a_(std::move(a.a_)) {
        cout<<"Key move assign"<<endl;
    }

    Key (int a) : a_(a) {
        cout<<"Key constructed by int"<<endl;
    }

    bool operator < (const Key& a) const {
        return a_ < a.a_;
    }
    int a_ = 0;
};

class Value {
public:
    Value () {
        cout<<"Value is constructed by default"<<endl;
    }
    Value (const Value& v) : v_(v.v_) {
        cout<<"Value copy construc"<<endl;
    }
    Value (Value&& v) : v_(std::move(v.v_)) {
        cout<<"Value move construc"<<endl;
    }
    Value (int v) : v_(v) {
        cout<<"Value constructed by int"<<endl;
    }

    Value& operator =(const Value& v) {
        this->v_ = v.v_;
        cout<<"Value copy assign";
        return *this;
    }
    Value& operator =(Value&& v) {
        this->v_ = std::move(v.v_);
        cout<<"Value move assign";
        return *this;
    }
    int v_;
};

int main() {
    map<Key, Value> mp;
    cout<<"cp[0] = Value()"<<endl;
    mp[1] = Value();
    cout<<endl<<endl;

    pair<Key, Value> p{Key(), Value()};
    cout<<"pair constructed"<<endl;
    mp.insert(std::move(p));
    // pair的move 与正常 影响 Key Value的构建调用 copy assign 还是 move assign 完美转发 ?
    // 所以要避免 map的 潜在构造/赋值
    // map内使用pair 并且stl会在插入时在堆上构建节点 当没有move时，会进行copy assign，
    // 开销是 构造函数 + 构建pair时的copy/move assign + 插入的copy / move assign
    // [] 省了自己构建pair的开销
    // Todo 看下pair的实现 以及 完美转发  

}
