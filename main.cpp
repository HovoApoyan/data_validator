#include <iostream>
#include <cassert>
#include "types.h"
#include "visitor.h"


int main() {
    using namespace validator;

    {
        ITypes *type = new Int(10, 20);

        int input = 155;
        TypeVisitor type_visitor(input);

        auto is_valid = type->validation(&type_visitor);

        if (!is_valid) {
            input = type_visitor.value;
        }

        assert(input == 20);
    }

    {
        ITypes *type = new String(3);

        std::string input = "abcdef";
        TypeVisitor type_visitor(input);

        auto is_valid = type->validation(&type_visitor);

        if (!is_valid) {
            input = type_visitor.value;
        }

        assert(input == "abc");
    }
    return 0;
}
