#pragma once

#include "entity/entity.hpp"


class Game;
class Platform;


class Transporter : public Entity<Transporter, 0> {
public:
    Transporter()
    {
        sprite_.set_texture_index(TextureMap::transporter);
        sprite_.set_origin({16, 22});
    }

    void set_position(const Vec2<Float>& new_pos)
    {
        Entity::set_position(new_pos);
        sprite_.set_position(new_pos);
    }
};
