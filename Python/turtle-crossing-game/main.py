import time
from player_sprite import Player_sprite
from cars import Cars
from scoreboard import Scoreboard
from turtle import Screen



screen = Screen()
screen.title("TURTLE CROSS THE ROAD")
screen.setup(width=600, height=600)
screen.bgcolor('white')
screen.tracer(0)

player_sprite=Player_sprite()
cars=Cars()
scoreboard=Scoreboard()
screen.listen()
screen.onkey(key='Up', fun=player_sprite.move_up)

game_is_on = True
i = 0

while game_is_on:
    
    time.sleep(0.1)
    screen.update()
    
    
    if i%6 == 1:
        cars.create_car()
    
    cars.move_car()
    i += 1

    #detecting finish line reached
    if player_sprite.is_at_finish_line():
        scoreboard.increase_level()
        cars.level_up()
        player_sprite.go_to_start()

    #detecting collision with car
    for car in cars.cars_list:
        if car.distance(player_sprite) < 20:
            scoreboard.game_over()
            game_is_on = False


screen.exitonclick()