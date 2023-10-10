#pragma once

// #include <global_macro_functions.h>

#pragma once

#include <functional>

namespace _GlobalMacroFunctions {
    struct FunctionRunner {
        FunctionRunner(std::function<void()> func) { func(); }
    };
}

#if defined(COMPILATION_UNIT_NAME)
    #define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME COMPILATION_UNIT_NAME
#elif defined(COMPILATION_UNIT)
    #define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME COMPILATION_UNIT
#else
    #define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME defaultCompilationUnit
#endif

#define _GLOBAL_MACRO_FUNCTIONS_CONCAT_SIMPLE(a, b) a##b

#define _GLOBAL_MACRO_FUNCTIONS_CONCAT(a, b) _GLOBAL_MACRO_FUNCTIONS_CONCAT_SIMPLE(a, b)

#ifndef COMPILATION_UNIT_CONSTANT
    #define COMPILATION_UNIT_CONSTANT(name) \
        _GLOBAL_MACRO_FUNCTIONS_CONCAT(name, _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME)
#endif

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count) \
    _GlobalMacroFunctions::FunctionRunner _GLOBAL_MACRO_FUNCTIONS_CONCAT(                         \
        COMPILATION_UNIT_CONSTANT(                                                                \
            _GLOBAL_MACRO_FUNCTIONS_CONCAT(__globalMacroFunctions__functionRunner__, symbol)      \
        ),                                                                                        \
        count                                                                                     \
    )

#define _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME(symbol) \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, __COUNTER__)

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(count) \
    _GlobalMacroFunctions::FunctionRunner _GLOBAL_MACRO_FUNCTIONS_CONCAT(           \
        COMPILATION_UNIT_CONSTANT(__globalMacroFunctions__functionRunner__), count  \
    )

#define _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_RUNNER_VARIABLE_NAME \
    _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(__COUNTER__)

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)      \
    _GLOBAL_MACRO_FUNCTIONS_CONCAT(                                                    \
        COMPILATION_UNIT_CONSTANT(                                                     \
            _GLOBAL_MACRO_FUNCTIONS_CONCAT(__globalMacroFunctions__function__, symbol) \
        ),                                                                             \
        count                                                                          \
    )

#define _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME(symbol) \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, __COUNTER__)

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME_FROM_COUNT(count)          \
    _GLOBAL_MACRO_FUNCTIONS_CONCAT(                                          \
        COMPILATION_UNIT_CONSTANT(__globalMacroFunctions__function__), count \
    )

#define _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME(count) \
    _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME_FROM_COUNT(__COUNTER__)

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_RUN_BODY(count)                                        \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME_FROM_COUNT(count)();         \
    _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(count){[]() { \
        _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME_FROM_COUNT(count)();                 \
    }};                                                                                \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME_FROM_COUNT(count)

#define _GLOBAL_MACRO_FUNCTIONS_RUN() _GLOBAL_MACRO_FUNCTIONS_RUN_BODY(__COUNTER__)()

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_RUN_NAMED_BODY(symbol, count)                                  \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)();   \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){ \
        []() {                                                                                 \
            _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)          \
            ();                                                                                \
        }};                                                                                    \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)

#define _GLOBAL_MACRO_FUNCTIONS_RUN_NAMED(symbol) \
    _GLOBAL_MACRO_FUNCTIONS_RUN_NAMED_BODY(symbol, __COUNTER__)()

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_FUNCTION_BODY(registrationFunction, count)    \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME_FROM_COUNT(count)();             \
    _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(count){[]() {     \
        registrationFunction(_GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME_FROM_COUNT(count)); \
    }};                                                                                    \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME_FROM_COUNT(count)

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_FUNCTION(registrationFunction) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_FUNCTION_BODY(registrationFunction, __COUNTER__)

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_BODY(                              \
    symbol, registrationFunction, count                                                        \
)                                                                                              \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)();   \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){ \
        []() {                                                                                 \
            registrationFunction(                                                              \
                _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)      \
            );                                                                                 \
        }};                                                                                    \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION(symbol, registrationFunction) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_BODY(                             \
        symbol, registrationFunction, __COUNTER__                                         \
    )

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN_BODY(                      \
    symbol, registrationFunction, returnType, count                                                \
)                                                                                                  \
    inline returnType _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(); \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){     \
        []() {                                                                                     \
            registrationFunction(                                                                  \
                _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)          \
            );                                                                                     \
        }};                                                                                        \
    inline returnType _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN(  \
    symbol, registrationFunction                                          \
)                                                                         \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN_BODY( \
        symbol, registrationFunction, returnType, __COUNTER__             \
    )

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_FUNCTION_WITH_ARGUMENTS_BODY(                 \
    registrationFunction, count, ...                                                       \
)                                                                                          \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME_FROM_COUNT(count)(__VA_ARGS__);  \
    _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(count){[]() {     \
        registrationFunction(_GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME_FROM_COUNT(count)); \
    }};                                                                                    \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_FUNCTION_NAME_FROM_COUNT(count)

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_FUNCTION_WITH_ARGUMENTS(registrationFunction, ...) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_FUNCTION_WITH_ARGUMENTS_BODY(                          \
        registrationFunction, __COUNTER__, __VA_ARGS__                                          \
    )

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS_BODY(               \
    symbol, registrationFunction, count, ...                                                   \
)                                                                                              \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(     \
        __VA_ARGS__                                                                            \
    );                                                                                         \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){ \
        []() {                                                                                 \
            registrationFunction(                                                              \
                _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)      \
            );                                                                                 \
        }};                                                                                    \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(  \
    symbol, registrationFunction, ...                                        \
)                                                                            \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS_BODY( \
        symbol, registrationFunction, __COUNTER__, __VA_ARGS__               \
    )

//////////////////////////////////////////////////////////////////////////////////////////////

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN_AND_ARGUMENTS_BODY(      \
    symbol, registrationFunction, returnType, count, ...                                         \
)                                                                                                \
    inline returnType _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)( \
        __VA_ARGS__                                                                              \
    );                                                                                           \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){   \
        []() {                                                                                   \
            registrationFunction(                                                                \
                _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)        \
            );                                                                                   \
        }};                                                                                      \
    inline returnType _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)

#define _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN_AND_ARGUMENTS(  \
    symbol, registrationFunction, returnType, ...                                       \
)                                                                                       \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN_AND_ARGUMENTS_BODY( \
        symbol, registrationFunction, returnType, __COUNTER__, __VA_ARGS__              \
    )

//////////////////////////////////////////////////////////////////////////////////////////////

#include "EntrypointCallbacks.h"  // IWYU pragma: keep

/* Register Pre Init */

#define __SKSEPlugin_PreInit_HighPriority__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN_AND_ARGUMENTS(                       \
        scopeSymbol,                                                                         \
        SkyrimScripting::Plugin::Entrypoint::EntrypointCallbacks::GetSingleton() \
            .RegisterPreInitHighPriorityCallback,                                                             \
        bool, \
        const SKSE::LoadInterface*                                                                          \
    )

#define _SKSEPlugin_PreInit_HighPriority_ __SKSEPlugin_PreInit_HighPriority__(DEFAULT)

#define __SKSEPlugin_PreInit__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN_AND_ARGUMENTS(                       \
        scopeSymbol,                                                                         \
        SkyrimScripting::Plugin::Entrypoint::EntrypointCallbacks::GetSingleton() \
            .RegisterPreInitCallback,                                                             \
        bool, \
        const SKSE::LoadInterface*                                                                          \
    )

#define _SKSEPlugin_PreInit_ __SKSEPlugin_PreInit__(DEFAULT)

#define __SKSEPlugin_PreInit_LowPriority__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN_AND_ARGUMENTS(                       \
        scopeSymbol,                                                                         \
        SkyrimScripting::Plugin::Entrypoint::EntrypointCallbacks::GetSingleton() \
            .RegisterPreInitLowPriorityCallback,                                                             \
        bool, \
        const SKSE::LoadInterface*                                                                          \
    )

#define _SKSEPlugin_PreInit_LowPriority_ __SKSEPlugin_PreInit_LowPriority__(DEFAULT)

/* Register Post Init */

#define __SKSEPlugin_PostInit_HighPriority__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN_AND_ARGUMENTS(                       \
        scopeSymbol,                                                                         \
        SkyrimScripting::Plugin::Entrypoint::EntrypointCallbacks::GetSingleton() \
            .RegisterPostInitHighPriorityCallback,                                                             \
        bool, \
        const SKSE::LoadInterface*                                                                          \
    )

#define _SKSEPlugin_PostInit_HighPriority_ __SKSEPlugin_PostInit_HighPriority__(DEFAULT)

#define __SKSEPlugin_PostInit__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN_AND_ARGUMENTS(                       \
        scopeSymbol,                                                                         \
        SkyrimScripting::Plugin::Entrypoint::EntrypointCallbacks::GetSingleton() \
            .RegisterPostInitCallback,                                                             \
        bool, \
        const SKSE::LoadInterface*                                                                          \
    )

#define _SKSEPlugin_PostInit_ __SKSEPlugin_PostInit__(DEFAULT)

#define __SKSEPlugin_PostInit_LowPriority__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_RETURN_AND_ARGUMENTS(                       \
        scopeSymbol,                                                                         \
        SkyrimScripting::Plugin::Entrypoint::EntrypointCallbacks::GetSingleton() \
            .RegisterPostInitLowPriorityCallback,                                                             \
        const SKSE::LoadInterface*                                                                          \
    )

/* Register Post Post Init */

#define __SKSEPlugin_Init_HighPriority__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION(                       \
        scopeSymbol,                                                                         \
        SkyrimScripting::Plugin::Entrypoint::EntrypointCallbacks::GetSingleton() \
            .RegisterInitHighPriorityCallback                                                             \
    )()

#define _SKSEPlugin_Init_HighPriority_ __SKSEPlugin_Init_HighPriority__(DEFAULT)

#define __SKSEPlugin_Init__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION(                       \
        scopeSymbol,                                                                         \
        SkyrimScripting::Plugin::Entrypoint::EntrypointCallbacks::GetSingleton() \
            .RegisterInitCallback                                                             \
    )()

#define _SKSEPlugin_Init_ __SKSEPlugin_Init__(DEFAULT)

#define __SKSEPlugin_Init_LowPriority__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION(                       \
        scopeSymbol,                                                                         \
        SkyrimScripting::Plugin::Entrypoint::EntrypointCallbacks::GetSingleton() \
            .RegisterInitLowPriorityCallback                                                             \
    )()

#define _SKSEPlugin_Init_LowPriority_ __SKSEPlugin_Init_LowPriority__(DEFAULT)