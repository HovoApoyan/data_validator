//
// Created by hovo on 5/26/22.
//

#include <iostream>
#include <tuple>

#ifndef DATA_VALIDATOR_TYPES_H
#define DATA_VALIDATOR_TYPES_H

namespace validator {

    class ITypes {
    public:
        virtual bool validation(class IVisitor *) = 0;

        virtual ~ITypes() {}
    };


    class Int : public ITypes {
    public:
        typedef int data_type;

        Int(data_type min, data_type max);

        bool validation(IVisitor *) override;

        std::tuple<data_type, bool> verification(const data_type &val) const;

    private:
        data_type _min;
        data_type _max;
    };
}

#endif //DATA_VALIDATOR_TYPES_H