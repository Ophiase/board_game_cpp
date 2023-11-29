#pragma once

#include "engine/loot/LootAction.hpp"
#include "engine/loot/LootManager.hpp"
#include "graphics/Game.hpp"

class LootGame : public Game {
    protected:
        LootManager manager;
    public:
        LootGame(Launcher *launcher);
};