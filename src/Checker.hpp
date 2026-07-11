#include <ClickBeyondFrames/Checker.hpp>
#include <Geode/loader/Mod.hpp>

#include <functional>
#include <sstream>

namespace cbfbeyond::checker {
    RuntimeState getState() {
        return {
            false,
            1000,
            true,
            true,
            false,
            0
        };
    }

    std::string getStateSignature(const RuntimeState& state) {
        std::ostringstream s;
        s << state.isCBFEnabled << ':'
          << state.pollingRateHz << ':'
          << state.isExceedingVanilla << ':'
          << state.isInputThreadHealthy << ':'
          << state.isOverriddenByBot << ':'
          << state.uptimeMs;
        return std::to_string(std::hash<std::string>{}(s.str()));
    }

    bool verifyIntegrity() {
        auto mod = Mod::get();
        if (!mod) return false;
        return !mod->hasUnresolvedDependencies();
    }
}
