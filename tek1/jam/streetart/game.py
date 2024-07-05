import os, sys
import pygame
from pygame.locals import *
from app.player import Player
from app.artwork import Artwork
from app.loading import *
import random

if not pygame.font: print('Warning, fonts disabled')
if not pygame.mixer: print('Warning, sound disabled')

def main():
    """this function is called when the program starts.
       it initializes everything it needs, then runs in
       a loop until the function returns."""
    # Initialize Everything
    pygame.init()
    screen = pygame.display.set_mode((1980, 1020))
    pygame.display.set_caption("Game")
    pygame.mouse.set_visible(1)

    # Create The Backgound
    background = pygame.Surface(screen.get_size())
    background = background.convert()
    background = load_image("app/img/city.jpg")

    # Display The Background
    screen.blit(background, (0, 0))
    pygame.display.flip()

    # Prepare Game Objects
    clock = pygame.time.Clock()

    going = True

    good_music = pygame.mixer.music.load("app/music/sweden.mp3")
    pygame.mixer.music.play(1)

    random.seed()

    artworks = []
    artworks_paths = ["babyGraph.jpg", "banch.png", "Bike.jpg", "bonnetDane.png", "britishPhone.jpg", "cliff.jpg", "crocodile.jpg", "crossWalk.jpg", "flowerThower.jpg", "handshake.png", "hoose.jpg", "invader.jpg", "lock.jpg", "manInWall.png", "octelephant.png", "snail.jpg", "snake.jpg", "stair.jpg", "swimCity.jpg", "tree.jpg"]

    for i in range(100):
        artworks.append(Artwork(random.randint(0, 1920), random.randint(0, 1080), "app/img/" + random.choice(artworks_paths)))

    player = Player(200, 200)
    player.sprite = pygame.transform.scale(player.sprite, (int(player.sprite.get_size()[0] / 5), int(player.sprite.get_size()[1] / 5)))
    for artwork in artworks:
        artwork.sprite = pygame.transform.scale(artwork.sprite, (100, 100))

    white = (255, 255, 255)
    red = (255, 0, 0)
    blue = (0, 0, 128)

    font = pygame.font.Font('freesansbold.ttf', 60)
    menu = True
    fpsClock = pygame.time.Clock()
    TpsZero = pygame.time.get_ticks()
    score = font.render(str(player.totalObjects), True, red)
    title = font.render("Menu", True, red)
    score_precedent = font.render("Score", True, red)
    click_to_play = font.render("Click to launch game", True, red)
    while going:
        clock.tick(120)
        if menu == False:
            if ((pygame.time.get_ticks() - TpsZero) / 1000) >= 60:
                for i in range(100):
                    artworks.pop(99-i)
                for i in range(100):
                    artworks.append(Artwork(random.randint(0, 1920), random.randint(0, 1080), "app/img/" + random.choice(artworks_paths)))
                for artwork in artworks:
                    artwork.sprite = pygame.transform.scale(artwork.sprite, (100, 100))
                player.x = 200
                player.y = 200
                menu = True

            score = font.render(str(player.totalObjects), True, red)
            timer = font.render(str((pygame.time.get_ticks() - TpsZero) / 1000), True, blue)

            for event in pygame.event.get():
                if event.type == QUIT:
                    going = False
                elif event.type == KEYDOWN and event.key == K_ESCAPE:
                    going = False
                elif event.type == MOUSEBUTTONDOWN:
                    player.new_destination()
            # Game updates
            player.update()
            for artwork in artworks:
                artwork.isPicked(player)
            screen.blit(background, (0, 0))
            # Display sprites
            for artwork in artworks:
                if artwork.taken == False:
                    screen.blit(artwork.sprite, (artwork.x, artwork.y))
            screen.blit(player.sprite, (player.x - int(player.sprite.get_size()[0] / 2), player.y - int(player.sprite.get_size()[1] / 2)))
            screen.blit(score, (0, 0))
            screen.blit(timer, (120, 0))
        else:
            screen.fill(white)
            screen.blit(background, (0, 0))
            screen.blit(title, (0, 0))
            screen.blit(score_precedent, (0, 60))
            screen.blit(score, (0, 120))
            screen.blit(click_to_play, (0, 180))
            player.totalObjects = 0
            TpsZero = pygame.time.get_ticks()
            for event in pygame.event.get():
                if event.type == QUIT:
                    going = False
                elif event.type == KEYDOWN and event.key == K_ESCAPE:
                    going = False
                elif event.type == MOUSEBUTTONDOWN:
                    menu = False
        pygame.display.flip()

    pygame.quit()

if __name__ == "__main__":
    main()