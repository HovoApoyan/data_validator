//
// Created by hovo on 5/26/22.
//

#include "types.h"

#ifndef DATA_VALIDATOR_VISITOR_H
#define DATA_VALIDATOR_VISITOR_H


namespace validator {

    class IVisitor {
    public:
        virtual bool visit(Int *) {};

        virtual ~IVisitor() {}
    };


    template<class T>
    class TypeVisitor : public IVisitor {
    public:
        T value;

        TypeVisitor(T val)
                : value(val) {

        }

        bool visit(Int *obj) override {
            auto [new_value, is_valid] = obj->verification(value);

            if (is_valid) value = new_value;

            return is_valid;
        }
    };
}

#endif //DATA_VALIDATOR_VISITOR_H
