from turtle import Turtle

STARTING_POSITION = (0 , -280)
MOVE_DISTANCE = 10
FINISH_LINE_Y = 280

class Player_sprite(Turtle):

    def __init__(self):
        super().__init__()
        self.shape('turtle')
        self.color('black')
        self.seth(90)
        self.pu()
        self.go_to_start()
        
    def move_up(self):
        self.fd(MOVE_DISTANCE)

    def go_to_start(self):
        self.goto(STARTING_POSITION)

    def is_at_finish_line(self):
        
        if self.ycor() > FINISH_LINE_Y:
            return True
        
        else:
            return False