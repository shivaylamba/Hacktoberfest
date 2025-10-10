from manim import *


class hacktoberfest(Scene):
    def construct(self):
        logo = SVGMobject(
            "/home/dakota/bootdev/hacktoberfest/logo.svg",
            fill_opacity=0.8,
            height=10,
            width=10,
        ).shift(UP * 0.5)
        t = Text("Happy Hacking!", weight=NORMAL).next_to(logo, DOWN)
        self.play(Write(logo), Write(t))
