/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Dispatcher.hpp
*/

#ifndef ZAPPY_WORLD_HPP
#define ZAPPY_WORLD_HPP

#include <map>
#include <vector>
#include <functional>
#include "Player.hpp"
#include "PlayerManager.hpp"
#include "MapManager.hpp"

class Dispatcher {
public:
    Dispatcher();
    void dispatchCommand(const std::vector<std::string> &arg);
private:
    void seg(const std::vector<std::string> &input);
    std::map<std::string, std::function<void(const std::vector<std::string> &)>> actions;
};

#endif
