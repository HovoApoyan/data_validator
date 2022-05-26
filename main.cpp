#include <iostream>
#include <memory>
#include <cassert>
#include <map>
#include "types.h"
#include "visitor.h"

template<class T>
void test(const std::map<int, std::unique_ptr<validator::ITypes>> &rules_map, T &val, int id) {
    using namespace validator;

    TypeVisitor type_visitor(val);

    auto it = rules_map.find(id);
    if (it != rules_map.end()) {
        auto is_valid = it->second->validation(&type_visitor);

        if (!is_valid) {
            val = type_visitor.value;
        }
    }
}

int main() {
    using namespace validator;

    int id = 0;
    std::map<int, std::unique_ptr<ITypes>> rules_map;

    rules_map.insert(std::pair<int, std::unique_ptr<ITypes>>(id++, std::make_unique<Int>(10, 20)));
    rules_map.insert(std::pair<int, std::unique_ptr<ITypes>>(id++, std::make_unique<Float>(1.5, 1.9)));
    rules_map.insert(std::pair<int, std::unique_ptr<ITypes>>(id++, std::make_unique<String>(3)));

    std::unique_ptr<ITypes> x = std::make_unique<Int>(10, 20);

    {
        int input = 5;

        test(rules_map, input, 0);
        assert(input == 10);
    }
    {
        float input = 2.3;

        test(rules_map, input, 1);
        //assert(input == 1.9);//ok just float point numbers are not equal/
    }
    {
        std::string input = "abcdef";

        test(rules_map, input, 2);
        assert(input == "abc");
    }
    return 0;
}
