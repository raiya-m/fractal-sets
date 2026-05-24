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

        # fact! manim always uses 3d vectors even when the scene is 2d. we'll start with a single horizontal line segment.

        points = [
            np.array([-2.0, 0.0, 0.0]),
            np.array([2.0, 0.0, 0.0])
        ]

        curve = self.make_curve(points) # pass through our points

        self.play(Create(curve))

        self.wait(0.5)

        # each generation doubles our complexity. 
        
        for i in range (0, 13): 
            points = self.next_dragon(points)

            new_curve = self.make_curve(points)

            new_curve.set_color_by_gradient(
                PINK,
                PURPLE,
                BLUE
            )

            # generation label at bottom 

            label = Text(
                f"Generation {i}",
                font_size=24,
                color=WHITE
            )

            label.to_edge(DOWN)