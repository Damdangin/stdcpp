#include <iostream>
#include <windows.h>

#if 0
void study011() {
    int v;
    int result = 0;

    for (int i=1; i<=5; i++) {
        std::cout<<i<<"번째 정수 입력: ";
        std::cin>>v;
        result += v;
    }
    std::cout<<result;
}
#endif

void study012() {
    // char name[100];
    // char phone[100];
    std::string name;
    std::string phone;

    std::cout<<"이름: ";
    std::cin>>name;
    std::cout<<"전화번호: ";
    std::cin>>phone;

    std::cout<<"이름은 "<<name<<"이고, 전화번호는 "<<phone<<"입니다.";
}

int main(void) {
    SetConsoleOutputCP(65001);

    study012();

    return 0;
}