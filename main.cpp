#include <iostream>
#include "types.h"
#include "visitor.h"

bool validator::Int::validation(Visitor *v) {
    v->visit(this);
}

int main() {
    using namespace validator;

    Types *type = new Int(10, 20);

    int input = 155;
    TypeVisitor type_visitor(input);

    auto is_valid = type->validation(&type_visitor);

    if (!is_valid)
        input = type_visitor.value;

    std::cout << "input value: " << input << std::endl;

    return 0;
}
