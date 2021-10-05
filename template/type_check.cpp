#include <iostream>
#include <mutex>

template<typename T>
class Test {
public:
    Test ():tt_(0) {}
    Test (const T& t): tt_(t) {
        std::cout<<"calling Test const copy"<<std::endl;
    }

    Test (const Test<T>& t): tt_(t.getElem()) {
        if (tt_ < 1024) {
            std::cout<<"magic template instan : \
                compiler type check on instance"<<std::endl;
        }
    }

    T& getElem() {
        return tt_;
    }

    const T& getElem() const {
        return tt_;
    }

private:
    T tt_;

};

int main() {
    // std::cout<<"11111";
    Test<int> t1;
    Test<int> t2(t1);
    std::cout<<t2.getElem();
    // Test<std::mutex> p;
    /*
    *** 当传入mutex时 error，因为实例化时进行类型检查，mutex错误
    *** 
    */
}