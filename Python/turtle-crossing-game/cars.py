from turtle import Turtle
import random 
COLORS=["yellow","red","purple","green","orange","blue"]

STARTING_MOVE_DISTANCE=5
MOVE_INCREMENT=10

class Cars:

    def __init__(self):

        self.cars_list=[]
        self.car_speed=STARTING_MOVE_DISTANCE

    def create_car(self):
        new_car=Turtle(shape='square')
        new_car.shapesize(stretch_wid=1,stretch_len=2)
        new_car.color(random.choice(COLORS))
        new_car.pu()
        new_car.car_y = random.randint(-250,250)
        new_car.car_x = 300
        new_car.seth(180)
        new_car.goto(new_car.car_x,new_car.car_y)
        self.cars_list.append(new_car)

    def move_car(self):
        for car in self.cars_list:
            car.fd(self.car_speed)

    def level_up(self):
        self.car_speed += MOVE_INCREMENT

    