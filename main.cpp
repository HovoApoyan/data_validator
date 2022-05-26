#include <iostream>
#include <cassert>
#include "types.h"
#include "visitor.h"


int main() {
    using namespace validator;

    ITypes *type = new Int(10, 20);

    int input = 155;
    TypeVisitor type_visitor(input);

    auto is_valid = type->validation(&type_visitor);

    if (!is_valid) {
        input = type_visitor.value;
    }

    assert(input == 20);

    std::cout << "input value: " << input << std::endl;

    return 0;
}
