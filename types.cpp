//
// Created by hovo on 5/26/22.
//

#include "types.h"


namespace validator {

    Int::Int(data_type min, data_type max)
            : _min(min),
              _max(max) {

    }

    std::tuple<Int::data_type, bool> Int::verification(const data_type &val) const {
        data_type new_val = val;
        bool is_valid = true;

        if (val < _min) {
            new_val = _min;
            is_valid = false;
            std::cout << "min\n";
        } else if (val > _max) {
            new_val = _max;
            is_valid = false;
            std::cout << "max\n";
        } else {
            std::cout << "nothing\n";
        }

        return {new_val, is_valid};
    }
}