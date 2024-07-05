# Epitech JAM 2020 N2

from pygame import mouse
from app.loading import *
from math import sqrt, pow
Vec2 = pygame.math.Vector2

class Player:
    def __init__(self, x=0, y=0, hp=100, path_to_sprite="app/img/player.png", canInteract=False, totalObjects=0):
        self.x = x
        self.y = y
        self.hp = hp
        self.sprite = load_image(path_to_sprite)
        self.canInteract = canInteract
        self.destination = (self.x, self.y)
        self.totalObjects = totalObjects

    def update(self):
        if (self.x < self.destination[0]):
            self.x = self.x + 1
        elif (self.x > self.destination[0]):
            self.x = self.x - 1
        if (self.y < self.destination[1]):
            self.y = self.y + 1
        elif (self.y > self.destination[1]):
            self.y = self.y - 1

    def new_destination(self):
        self.destination = mouse.get_pos()