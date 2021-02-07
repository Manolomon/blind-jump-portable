#pragma once

#include "blind_jump/entity/entity.hpp"
#include "function.hpp"
#include "platform/platform.hpp"


class StaticEffect : public Entity {
public:
    using UpdateCallback =
        Function<16,
                 void(Platform&, Game&, const Microseconds&, StaticEffect&)>;

    StaticEffect(
        const Vec2<Float>& position,
        Microseconds interval,
        u16 texture_start,
        u8 frame_count,
        UpdateCallback update_callback =
            [](Platform&, Game&, const Microseconds&, StaticEffect&) {});

    void update(Platform&, Game&, Microseconds dt);

    Sprite& sprite()
    {
        return sprite_;
    }

private:
    UpdateCallback update_callback_;
    Microseconds timer_;
    const Microseconds interval_;
    u16 texture_start_;
    const u8 frame_count_;
};
