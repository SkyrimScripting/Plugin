#include "specHelper.h"

#include "SkyrimScripting/EventRegistry.h"

go_bandit([](){
    describe("EventRegistry", [](){
        it("Can add stuffs", [&](){
            // use the singleton for now...
            auto& registry = SkyrimScripting::EventRegistry::GetSingleton();

            AssertThat(registry.GetCountOfRegistrationsForEvent("Foo"), Equals(0));
            AssertThat(registry.GetCountOfRegistrationsForEvent("hello"), Equals(0));

            registry.Register("hello", {});
            registry.Register("hello", {});
            registry.Register("hello", {});

            AssertThat(registry.GetCountOfRegistrationsForEvent("Foo"), Equals(0));
            AssertThat(registry.GetCountOfRegistrationsForEvent("hello"), Equals(3));
        });
    });
});
