import copy

from .PathFinding import PathFinding
from ..Pendings import Action


class FindPlayerBehaviour:
    def __init__(self, player):
        self.player = player

    def __del__(self):
        print("FIND DESTRUCTOR")

    def execute_strategy(self):
        if len(self.player.actionQueue) != 0:
            return Action.NONE
        if self.player.where_to_go is None:
            return Action.NONE
        direction = int(self.player.where_to_go)
        if direction == 0:
            return Action.NONE
        self.player.actionQueue = copy.deepcopy(PathFinding.find_instructions_to_direction(direction))
        print("FINDIIIIIIIIIIIIIIIIIIING: ", self.player.actionQueue)
        self.player.where_to_go = None
        return Action.NONE
