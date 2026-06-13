#ifndef STD_STACK_ADAPTER_H
#define STD_STACK_ADAPTER_H

#include <stack>

class StdStackAdapter {
private:
    std::stack<int> data;

public:
    bool f_isEmpty() const {
        return data.empty();
    }

    int f_size() const {
        return static_cast<int>(data.size());
    }

    void f_push(int value) {
        data.push(value);
    }

    bool f_top(int& value) const {
        if (f_isEmpty()) {
            return false;
        }
        value = data.top();
        return true;
    }

    bool f_pop(int& value) {
        if (f_isEmpty()) {
            return false;
        }
        value = data.top();
        data.pop();
        return true;
    }
};

#endif
