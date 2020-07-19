#pragma once

#include "collision.hpp"
#include "entity/entity.hpp"
#include <optional>


class LaserExplosion;
class AlliedOrbShot;
class Player;
class Laser;


class TheFirstExplorer : public Entity {
public:
    TheFirstExplorer(const Vec2<Float>& position);

    const Sprite& get_shadow() const
    {
        return shadow_;
    }

    static constexpr bool multiface_sprite = true;
    static constexpr bool has_shadow = true;

    constexpr bool is_allied()
    {
        return false;
    }

    void make_allied(bool)
    {
    }

    void update(Platform& pf, Game& game, Microseconds dt);

    std::array<const Sprite*, 2> get_sprites() const
    {
        std::array<const Sprite*, 2> ret;
        ret[0] = &sprite_;
        ret[1] = &head_;
        return ret;
    }

    const HitBox& hitbox() const
    {
        return hitbox_;
    }

    void on_collision(Platform&, Game&, Player&)
    {
    }

    void on_collision(Platform&, Game&, LaserExplosion&);
    void on_collision(Platform&, Game&, AlliedOrbShot&);
    void on_collision(Platform&, Game&, Laser&);

    void on_death(Platform&, Game&);

private:
    void injured(Platform&, Game&, Health amount);

    enum class State {
        sleep,
        still,
        draw_weapon,

        big_laser_shooting,
        big_laser1,
        big_laser2,
        big_laser3,

        small_laser_prep,
        small_laser,

        done_shooting,
        prep_dash,
        dash,
        after_dash,

        final_form
    } state_ = State::sleep;

    bool second_form() const;
    bool third_form() const;

    Sprite head_;
    Sprite shadow_;
    HitBox hitbox_;
    Microseconds timer_;
    Microseconds timer2_;
    Vec2<Float> speed_;
    int chase_player_;
    int dashes_remaining_;
    FadeColorAnimation<Microseconds(9865)> fade_color_anim_;

    // The enemy fires scattershot spreads of bullets, and we want to leave a
    // gap for the player to navigate through. It just wouldn't fun to play if
    // you're facing a wall of bullets, and no amount of skill allows you to
    // dodge!
    //
    // This is an angle away from the bullet's direction vector, not an
    // cartesian angle away from the rightwards x-axis.
    Angle bullet_spread_gap_;
    Vec2<Float> scattershot_target_;
};
