#pragma once

namespace PapyrusInterface {

    std::string HelloPapyrus(RE::StaticFunctionTag*) {
        return "Hello Papyrus!";
    }

    bool BIND(RE::BSScript::IVirtualMachine* vm) {
        vm->RegisterFunction("HelloPapyrus", "ExampleScript", HelloPapyrus);
        return true;
    }
}
