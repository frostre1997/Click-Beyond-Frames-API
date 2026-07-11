#include <Geode/loader/Mod.hpp>
#include <ClickBeyondFrames/API.hpp>

namespace cbfbeyond::dev {
    bool isInstalled() {
        return Mod::get() != nullptr;
    }

    std::string getVersion() {
        if (auto mod = Mod::get()) {
            return mod->getVersion().toString();
        }
        return "unknown";
    }
}
