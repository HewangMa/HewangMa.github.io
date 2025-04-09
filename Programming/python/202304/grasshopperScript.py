from ghpythonlib.componentbase import executingcomponent as component
import Grasshopper, GhPython
import System
import Rhino
import rhinoscriptsyntax
import math


class MyComponent(component):

    def RunScript(self, pointsList1, pointsList2, pointsList3, pointsList4, pointsList5):
        # sample script to show how to use this component and the rhinoscriptsyntax
        """Constructs a sinusoidal series of circles.
          Inputs:
            x: The number of circles. (integer)
            y: The radius of each circle. (float)
          Outputs:
            a: The list of circles. (list of circle)
            b: The list of radii. (list of float)
        """

        # if x is None:
        #    x = 24    # if nothing is connected to x, set x to something (24).
        # if y is None:
        #    y = 0.3    # if nothing is connected to y, set y to 0.3.
        #
        # circles = []            # create a list. We will add IDs to it later on.
        # radii = []              # ...and create another one.
        #
        # for i in range(int(x)):
        #    pt = (i, math.cos(i), 0)             # a tuple (here for a point).
        #    id1 = rs.AddCircle(pt, y)
        #    circles.append(id1)
        #    endPt = rs.PointAdd(pt, (0, 0.3, 0)) # move the point by the vector.
        #    id2 = rs.AddLine(pt, endPt)
        #    radii.append(id2)

        # a = circles
        # b = radii

        if pointsList1 == None: pointsList1 = [tuple(0, 0, 0)]
        if pointsList2 == None: pointsList2 = []
        if pointsList3 == None: pointsList3 = []
        if pointsList4 == None: pointsList4 = []
        if pointsList5 == None: pointsList5 = []

        Result1 = pointsList1
        mostLeft = pointsList1[0][0]
        mostRight = pointsList1[-1][0]
        print(mostLeft)
        print(mostRight)

        # return outputs if you have them; here I try it for you:
        return (Result2, Result3, Result4, Result5)
