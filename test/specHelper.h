#pragma once

#include <string.h>
#include <iostream>

#include <spdlog/spdlog.h>
#include <bandit/bandit.h>
#include <snowhouse/snowhouse.h>

using namespace bandit;
using namespace snowhouse;

namespace SpecHelper {
    int runBandit(int argc, char *argv[]);
}

// Put any common code for specs here
