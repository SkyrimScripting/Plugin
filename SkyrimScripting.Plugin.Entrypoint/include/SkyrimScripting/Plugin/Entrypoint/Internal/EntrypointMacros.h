#pragma once

#include <global_macro_functions.h>

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