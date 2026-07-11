#pragma once
#include <cstdint>
#include <string>

namespace cbfbeyond::checker {
    struct RuntimeState {
        bool isCBFEnabled;
        int pollingRateHz;
        bool isExceedingVanilla;
        bool isInputThreadHealthy;
        bool isOverriddenByBot;
        uint64_t uptimeMs;
    };

    RuntimeState getState();
    std::string getStateSignature(const RuntimeState& state);
    bool verifyIntegrity();
}
