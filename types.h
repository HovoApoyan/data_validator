//
// Created by hovo on 5/26/22.
//

#include <iostream>
#include <tuple>

#ifndef DATA_VALIDATOR_TYPES_H
#define DATA_VALIDATOR_TYPES_H

namespace validator {

    class Types {
    public:
        virtual bool validation(class Visitor *) = 0;
    };


    class Int : public Types {
    public:
        typedef int data_type;

        Int(data_type min, data_type max);

        bool validation(Visitor *) override;

        std::tuple<data_type, bool> verification(const data_type &val) const;

    private:
        data_type _min;
        data_type _max;
    };
}

#endif //DATA_VALIDATOR_TYPES_H