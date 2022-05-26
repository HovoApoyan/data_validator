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

        virtual bool visit(Float *) {};

        virtual bool visit(String *) {};

        virtual ~IVisitor() {}
    };


    template<class T>
    class TypeVisitor : public IVisitor {
    public:
        T value;

        explicit TypeVisitor(T val)
                : value(val) {

        }

        TypeVisitor &operator=(const T &val) {
            this->value = val;
            return *this;
        }

        bool visit(Int *obj) override {
            auto [new_value, is_valid] = obj->verification(value);

            if (!is_valid) value = new_value;

            return is_valid;
        }

        bool visit(Float *obj) override {
            auto [new_value, is_valid] = obj->verification(value);

            if (!is_valid) value = new_value;

            return is_valid;
        }
    };

    template<>
    class TypeVisitor<std::string> : public IVisitor {
    public:
        std::string value;

        TypeVisitor(const std::string &val)
                : value(val) {

        }

        bool visit(String *obj) override {
            auto [new_value, is_valid] = obj->verification(value);

            if (!is_valid) value = new_value;

            return is_valid;
        }
    };
}

#endif //DATA_VALIDATOR_VISITOR_H
