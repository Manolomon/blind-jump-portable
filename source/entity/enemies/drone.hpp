#pragma once


#include "collision.hpp"
#include "enemy.hpp"
#include "entity/entity.hpp"


class LaserExplosion;
class Player;
class Laser;


class Drone : public Enemy {
public:
    Drone(const Vec2<Float>& pos);

    void on_collision(Platform&, Game&, LaserExplosion&);
    void on_collision(Platform&, Game&, Laser&);

    void update(Platform&, Game&, Microseconds);

    enum class State {
        sleep,
        inactive,
        idle1,
        dodge1,
        idle2,
        dodge2,
        idle3,
        dodge3,
        idle4,
        rush,
    };

    inline State state()
    {
        return state_;
    }

    void on_collision(Platform&, Game&, Player&);

    void on_death(Platform&, Game&);

private:

    void injured(Platform&, Game&, Health amount);

    State state_;

    Microseconds timer_;

    Vec2<Float> step_vector_;
    FadeColorAnimation<Microseconds(9865)> fade_color_anim_;
};
