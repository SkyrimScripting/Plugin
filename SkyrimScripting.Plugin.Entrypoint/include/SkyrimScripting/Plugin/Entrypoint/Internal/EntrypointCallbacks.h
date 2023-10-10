#pragma once

#include <SKSE/SKSE.h>

#include <functional>
#include <vector>

namespace SkyrimScripting::Plugin::Entrypoint {

    class EntrypointCallbacks {
        std::vector<std::function<bool(const SKSE::LoadInterface*)>> _preInitHighPriorityCallbacks;
        std::vector<std::function<bool(const SKSE::LoadInterface*)>> _preInitCallbacks;
        std::vector<std::function<bool(const SKSE::LoadInterface*)>> _preInitLowPriorityCallbacks;

        std::vector<std::function<bool(const SKSE::LoadInterface*)>> _postInitHighPriorityCallbacks;
        std::vector<std::function<bool(const SKSE::LoadInterface*)>> _postInitCallbacks;
        std::vector<std::function<bool(const SKSE::LoadInterface*)>> _postInitLowPriorityCallbacks;

        std::vector<std::function<void()>> _initHighPriorityCallbacks;
        std::vector<std::function<void()>> _initCallbacks;
        std::vector<std::function<void()>> _initLowPriorityCallbacks;

    public:
        static EntrypointCallbacks& GetSingleton() {
            static EntrypointCallbacks instance;
            return instance;
        }

        /* Register Pre Init */

        void RegisterPreInitHighPriorityCallback(
            std::function<bool(const SKSE::LoadInterface*)> callback
        ) {
            _preInitHighPriorityCallbacks.push_back(callback);
        }
        void RegisterPreInitCallback(std::function<bool(const SKSE::LoadInterface*)> callback) {
            _preInitCallbacks.push_back(callback);
        }
        void RegisterPreInitLowPriorityCallback(
            std::function<bool(const SKSE::LoadInterface*)> callback
        ) {
            _preInitLowPriorityCallbacks.push_back(callback);
        }

        /* Register Post Init */

        void RegisterPostInitHighPriorityCallback(
            std::function<bool(const SKSE::LoadInterface*)> callback
        ) {
            _postInitHighPriorityCallbacks.push_back(callback);
        }
        void RegisterPostInitCallback(std::function<bool(const SKSE::LoadInterface*)> callback) {
            _postInitCallbacks.push_back(callback);
        }
        void RegisterPostInitLowPriorityCallback(
            std::function<bool(const SKSE::LoadInterface*)> callback
        ) {
            _postInitLowPriorityCallbacks.push_back(callback);
        }

        /* Register Post Post Init */

        void RegisterInitHighPriorityCallback(std::function<void()> callback) {
            _initHighPriorityCallbacks.push_back(callback);
        }
        void RegisterInitCallback(std::function<void()> callback) {
            _initCallbacks.push_back(callback);
        }
        void RegisterInitLowPriorityCallback(std::function<void()> callback) {
            _initLowPriorityCallbacks.push_back(callback);
        }

        /* Run Pre Init */

        bool RunPreInitHighPriorityCallbacks(const SKSE::LoadInterface* skse) {
            for (auto& callback : _preInitHighPriorityCallbacks)
                if (!callback(skse)) return false;
            return true;
        }
        bool RunPreInitCallbacks(const SKSE::LoadInterface* skse) {
            for (auto& callback : _preInitCallbacks)
                if (!callback(skse)) return false;
            return true;
        }
        bool RunPreInitLowPriorityCallbacks(const SKSE::LoadInterface* skse) {
            for (auto& callback : _preInitLowPriorityCallbacks)
                if (!callback(skse)) return false;
            return true;
        }

        /* Run Post Init */

        bool RunPostInitHighPriorityCallbacks(const SKSE::LoadInterface* skse) {
            for (auto& callback : _postInitHighPriorityCallbacks)
                if (!callback(skse)) return false;
            return true;
        }
        bool RunPostInitCallbacks(const SKSE::LoadInterface* skse) {
            for (auto& callback : _postInitCallbacks)
                if (!callback(skse)) return false;
            return true;
        }
        bool RunPostInitLowPriorityCallbacks(const SKSE::LoadInterface* skse) {
            for (auto& callback : _postInitLowPriorityCallbacks)
                if (!callback(skse)) return false;
            return true;
        }

        /* Run Post Post Init */

        void RunHighPriorityCallbacks() {
            for (auto& callback : _initHighPriorityCallbacks) callback();
        }
        void RunCallbacks() {
            for (auto& callback : _initCallbacks) callback();
        }
        void RunLowPriorityCallbacks() {
            for (auto& callback : _initLowPriorityCallbacks) callback();
        }
    };
}
