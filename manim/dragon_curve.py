from manim import * 
import numpy as np 

# manim -pql dragon_curve.py DragonCurve

class DragonCurve(Scene): 
    def construct(self):

        title = Text(
            font_size=36,
            color=WHITE
        )

        title.to_edge(UP)

        self.play(Write(title))