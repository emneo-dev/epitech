# Epitech JAM 2020 N2

from pygame import mouse
from app.loading import *
from math import sqrt, pow
from app.player import Player

class Artwork:
    def __init__(self, x=200, y=200, path_to_sprite="app/img/handshake.png", taken=False):
        self.x = x
        self.y = y
        self.sprite = load_image(path_to_sprite)
        self.taken = taken

    def isPicked(self, player):
        if (player.x >= self.x and player.y >= self.y and player.x <= (self.x + (int(self.sprite.get_size()[0]))) and player.y <= (self.y + (int(self.sprite.get_size()[1])))):
            if self.taken == False:
                player.totalObjects += 1
            self.taken = True