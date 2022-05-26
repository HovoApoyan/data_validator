//
// Created by hovo on 5/26/22.
//

#include "types.h"
#include "visitor.h"


namespace validator {

    Int::Int(const data_type &min, const data_type &max)
            : _min(min),
              _max(max) {

    }

    std::tuple<Int::data_type, bool> Int::verification(const data_type &val) const {
        data_type new_val;
        bool is_valid = false;

        if (val < _min) {
            new_val = _min;
        } else if (val > _max) {
            new_val = _max;
        } else {
            is_valid = true;
        }

        return {new_val, is_valid};
    }

    bool validator::Int::validation(IVisitor *v) {
        return v->visit(this);
    }


    Float::Float(const data_type &min, const data_type &max)
            : _min(min),
              _max(max) {

    }

    std::tuple<Float::data_type, bool> Float::verification(const data_type &val) const {
        data_type new_val;
        bool is_valid = false;

        if (val < _min) {
            new_val = _min;
        } else if (val > _max) {
            new_val = _max;
        } else {
            is_valid = true;
        }

        return {new_val, is_valid};
    }

    bool validator::Float::validation(IVisitor *v) {
        return v->visit(this);
    }


    String::String(size_t length)
            : _length(length) {

    }

    std::tuple<String::data_type, bool> String::verification(const data_type &val) {
        data_type new_val;
        bool is_valid = false;

        if (val.size() > _length) {
            new_val = std::string(val.begin(), val.begin() + _length);
        } else {
            is_valid = true;
        }

        return {new_val, is_valid};
    }

    bool validator::String::validation(IVisitor *v) {
        return v->visit(this);
    }
}