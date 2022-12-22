#pragma once

#include <functional>

namespace SkyrimScripting::Plugin::Internal {

    /*
     * Lazy way to run arbitrary function on startup by providing a function.
     * Defined by macros or inline functions.
     */
    struct FunctionRunner {
        FunctionRunner(std::function<void()> fn) { fn(); }
    };
}
