from turtle import Turtle

ALIGNMENT = ("left")
FONT = ("Courier", 24, "normal")

class Scoreboard(Turtle):

    def __init__(self):

        super().__init__()
        self.level=1
        self.ht()
        self.pu()
        self.color('black')
        self.goto(-280, 250)
        self.update_scoreboard()

    def update_scoreboard(self):
        self.clear()
        self.write(f"Level: {self.level}", align=ALIGNMENT, font=FONT)

    def increase_level(self):
        self.level += 1
        self.update_scoreboard()

    def game_over(self):
        self.goto(0, 0)
        self.write(f"GAME OVER", align="center", font=FONT)