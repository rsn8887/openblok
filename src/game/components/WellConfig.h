#pragma once

#include "LockDelayType.h"
#include "rotations/SRS.h"

#include <memory>


// All values are in number of frames (60Hz)
struct WellConfig {
    unsigned short starting_gravity;
    unsigned short shift_normal;
    unsigned short shift_turbo;
    bool instant_harddrop;
    LockDelayType lock_delay_type;
    unsigned short lock_delay;
    bool tspin_enabled;
    bool tspin_allow_wallblock;
    bool tspin_allow_wallkick;
    std::unique_ptr<RotationFn> rotation_fn;

    WellConfig() {
        starting_gravity = 64,
        shift_normal = 14,
        shift_turbo = 4,
        instant_harddrop = true,
        lock_delay_type = LockDelayType::EXTENDED,
        lock_delay = 30,
        tspin_enabled = true,
        tspin_allow_wallblock = true,
        tspin_allow_wallkick = true,
        rotation_fn = std::make_unique<Rotations::SRS>();
    };
};
