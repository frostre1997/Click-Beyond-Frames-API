# Click Beyond Frames API

[![Geode](https://img.shields.io/badge/Geode-v1.8.0-blue)](https://geode-sdk.org)
[![GD](https://img.shields.io/badge/GD-2.208-brightgreen)](https://geometrydash.com)
[![Platform](https://img.shields.io/badge/Platform-Android%20%7C%20Windows%20%7C%20macOS-lightgrey)](https://geode-sdk.org)

Standalone API headers for the **Click Beyond Frames** mod.

---

## What's Inside?

This repository contains **only header files** that allow other mods to interact with Click Beyond Frames.

| Header | Purpose |
| :--- | :--- |
| `API.hpp` | Dev presence – tells other mods this mod exists. |
| `Checker.hpp` | Anti‑cheat state – retrieve runtime data for verification. |

---

## Installation (for Developers)

Add this as a dependency in your `mod.json`:

```json
{
    "dependencies": {
        "yourname.click-beyond-frames-api": {
            "version": ">=v1.0.0",
            "required": false
        }
    }
}
```

Then include the headers in your mod:

```cpp
#include <ClickBeyondFrames/API.hpp>     // Dev presence
#include <ClickBeyondFrames/Checker.hpp> // Anti-cheat state
```

---

## Usage Examples

1. Check if Click Beyond Frames is installed

```cpp
if (clickbeyondframes::dev::isInstalled()) {
    log::info("Click Beyond Frames is present!");
    auto version = clickbeyondframes::dev::getVersion();
    log::info("Version: {}", version);
}
```

2. Get runtime state (for anti-cheat / verification)

```cpp
auto state = clickbeyondframes::checker::getState();

if (state.isExceedingVanilla) {
    log::warn("Polling rate exceeds 480 TPS!");
}

if (!state.isInputThreadHealthy) {
    log::error("CBF input thread is not running!");
}
```

3. Verify integrity (flags debug builds)

```cpp
if (! clickbeyondframes::checker::verifyIntegrity()) {
    log::error("Mod is running in debug mode!");
}
```

4. Get a cryptographic signature

```cpp
auto state = clickbeyondframes::checker::getState();
auto signature = clickbeyondframes::checker::getStateSignature(state);
// Send signature to your server to validate
```

---

## Building

This is an API‑only mod. Build it to ensure the headers are registered with Geode:

```bash
geode build
```

---

## Notes for Mod Developers

- Do not require this API unless your mod absolutely needs Click Beyond Frames. Use "required": false.
- The API functions are guaranteed stable – they will not break across versions.

---

## License

MIT – Use freely.

---

## Credits

- Geode SDK team
- Geometry Dash community

---

Check. Beyond. Frames.
