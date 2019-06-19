/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** PlayerManager.cpp
*/

#include <algorithm>
#include <iostream>
#include "PlayerManager.hpp"

void PlayerManager::pnw(const std::vector<std::string> &input)
{
    Position pos(std::stoi(input[1]), std::stoi(input[2]));
    auto orientation = static_cast<Orientation>(std::stoi(input[3]));

    players.emplace_back(parseId(input[0]), pos, orientation, std::stoi(input[4]), input[5]);
}

void PlayerManager::ppo(const std::vector<std::string> &input)
{
    auto &player = getPlayerById(parseId(input[0]));

    player.setPosition(Position(std::stoi(input[1]), std::stoi(input[2])));
    player.setOrientation(static_cast<Orientation>(std::stoi(input[3])));
}

void PlayerManager::plv(const std::vector<std::string> &input)
{
    auto &player = getPlayerById(parseId(input[0]));

    player.setLevel(std::stoi(input[1]));
}

void PlayerManager::pin(const std::vector<std::string> &input)
{
    if (input.size() == 10) {
        auto &player = this->getPlayerById(parseId(input[0]));

        player.setPosition(Position(std::stoi(input[1]), std::stoi(input[2])));
        for (int i = 3; i < 10; ++i) {
            player.setResource(static_cast<Resource >(i - 3), std::stoi(input[i]));
        }
    }
}

Player &PlayerManager::getPlayerById(int id)
{
    return *std::find_if(players.begin(), players.end(), [id](const Player &player) {
        return player.getId() == id;
    });
}

int PlayerManager::parseId(const std::string &s) const
{
    if (s[0] == '#')
        return std::stoi(s.substr(1));
    return std::stoi(s);
}

void PlayerManager::pic(const std::vector<std::string> &input)
{
    if (input.size() >= 4) {
        for (int i = 0; i <= input.size() - 4; i++) {
            auto &player = this->getPlayerById(std::stoi(input[i]));

            player.setIncanting(true);
        }
    }
}

std::vector<std::reference_wrapper<Player>> PlayerManager::getPlayersAtPosition(const Position &position)
{
    std::vector<std::reference_wrapper<Player>> player;

    for (auto &it : this->players) {
        if (it.getPosition().x == position.x && it.getPosition().y == position.y)
            player.push_back(it);
    }
    return player;
}

void PlayerManager::pie(const std::vector<std::string> &input)
{
    if (input.size() == 3) {
        auto player = this->getPlayersAtPosition(Position(std::stoi(input[0]), std::stoi(input[1])));

        for (auto &it: player) {
            it.get().setIncanting(false);
        }
    }
}

void PlayerManager::draw()
{
    for (auto &it : players)
        it.draw();
}