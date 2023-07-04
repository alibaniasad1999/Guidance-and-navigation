## crating drone class and its methods
import numpy as np
from scipy.integrate import odeint
class drones:
    def __init__(self, size=None, position=None, velocity=None, dt=None):
        if size is None:
            size = 10
        self.size = size
        if position is None:
            position = np.random.uniform(0, 100, size=(size, 2)) # random position x y for dronesz in xy plane
        self.position = position
        if velocity is None:
            velocity = np.zeros((size, 2))
        self.velocity = velocity
        if dt is None:
            dt = 0.01
        self.dt = dt

    def differential_equation(self, position, t):
        return self.velocity


    def update(self): # solve the differential equation
        # reshape the position and velocity arrays into a single vector for odeint
        # self.position = self.position.reshape(self.size*2)
        # self.velocity = self.velocity.reshape(self.size*2)
        # solve the differential equation
        self.position = self.position + self.dt * self.velocity
        # reshape the position and velocity arrays back into their original shapes
        self.position = self.position.reshape(self.size, 2)
        return self.position

    

    

