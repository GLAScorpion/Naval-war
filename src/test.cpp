#include <iostream>
#include <vector>

struct B{

};
struct A : public B{

};

int main(void){
    std::vector<B*> v();
    return 0;
}