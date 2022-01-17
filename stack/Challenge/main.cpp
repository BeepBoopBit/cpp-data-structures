#include "../stack.h"

int main(){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.pop() << std::endl;
    stack.push(4);
    stack.push(5);
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    return 0;
}