Simple example:

```cpp
#include <iostream>
#include <cassert>
#include "types.h"
#include "visitor.h"

int main() {
    using namespace validator;

    ITypes *type = new Int(10, 20);

    int val = 15;
    TypeVisitor type_visitor(val);
    
    auto is_valid = type->validation(&type_visitor);//succeed
    
    if (!is_valid) {
        val = type_visitor.value;
    }

    assert(val == 15);
    
    /* input value change to 35 */
    type_visitor = 35;
    
    is_valid = type->validation(&type_visitor);//failed

    if (!is_valid) {
        val = type_visitor.value;//set max value, because greater than max value
    }

    assert(val == 20);//
    return 0;
}

```