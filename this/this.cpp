#include "iostream"
#include "vector"

using namespace std;

// ub?
// google v8自己的jit编译器后端
// Todo 待看
class Instr {
public:
    // static constexpr int a = 8;
    int TestThis() {
        // cout<<"this "<<this<<endl;
        // cout<< *this<<endl;
        return *reinterpret_cast<int*>(this);
    }
};

struct B {
    int a;
    char q;
    char n;
};

int main() {
    Instr ins;
    cout<<typeid(Instr).name()<<endl;
    // cout<<ins.TestThis()<<endl;
    cout<<(int*)(&ins)<<endl;
    // cout<<&ins<<endl;
    cout<<*reinterpret_cast<int*>(&ins)<<endl;
    cout<<*reinterpret_cast<char*>(&ins)<<endl;
    // 这里不会空指针吗  还是说这个地址是class内
    // 还是说不同指针寻址规则不一样?
    long long a = 11;
    // 1569325056

    *reinterpret_cast<int*>(&ins) = std::move(a);
    // cout<<ins.TestThis()<<endl;
    cout<<*reinterpret_cast<char*>(&ins)<<endl;
    // cout<<&ins<<endl;

    // sizeof为1 是为了区分该class不同实例 标准规定完整对象大小为正数
    // cout<<sizeof(ins)<<endl;
    // cout<<sizeof(int)<<endl;
    // cout<<sizeof(B)<<endl;
    // cout<<&ins.a<<endl;
}
