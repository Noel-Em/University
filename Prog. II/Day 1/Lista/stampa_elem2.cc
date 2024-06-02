#include <iostream>

struct Element {
    int value;
    Element* next = nullptr;
};

typedef Element* List;

void stampalista(List list) {
    while(list != nullptr) {
        std::cout << list->value << " ";
        list = list->next;
    }
}

int main() {
    List head = new Element;
    Element* secondEl;
    secondEl->value = 7;
    head->value = 3;
    head->next = secondEl;

    stampalista(head);
}