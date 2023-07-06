from Drones import drones
import numpy as np
## vasarhelyi guidance law class ##
class vasarhelyi(drones):
    def __init__(self, v_min=None, r=None, **kwargs):
        super().__init__(**kwargs)
        if v_min is None:
            v_min = 0.1
        self.v_min = v_min
        if r is None:
            r = 10
        self.r = r

    def relative_position(self):
        # calculate relative position of drones
        relative_position = np.zeros((self.size, self.size, 2))
        for i in range(self.size):
            for j in range(self.size):
                relative_position[i, j] = self.position[i] - self.position[j]
        return relative_position
    
    def relative_distance(self):
        # calculate relative distance of drones
        relative_distance = np.zeros((self.size, self.size))
        for i in range(self.size):
            for j in range(self.size):
                relative_distance[i, j] = np.linalg.norm(self.position[i] - self.position[j])
        return relative_distance
    
    def neighbours(self):
        # calculate neighbours of drones
        neighbours = np.zeros((self.size, self.size))
        relative_distance = self.relative_distance()
        for i in range(self.size):
            for j in range(self.size):
                if relative_distance[i, j] <= self.r:
                    neighbours[i, j] = 1
        return neighbours - np.identity(self.size), sum(neighbours) -1 # - np.identity(self.size) to remove self from neighbours
    
    def relative_velocity(self):
        # calculate relative velocity of drones
        relative_velocity = np.zeros((self.size, self.size, 2))
        for i in range(self.size):
            for j in range(self.size):
                relative_velocity[i, j] = self.velocity[i] - self.velocity[j]
        return relative_velocity
    
    def relative_speed(self):
        # calculate relative speed of drones
        relative_speed = np.zeros((self.size, self.size))
        for i in range(self.size):
            for j in range(self.size):
                relative_speed[i, j] = np.linalg.norm(self.velocity[i] - self.velocity[j])
        return relative_speed
    
    # unit vector of relative position
    def unit_position_vector(self):
        unit_position_vector = np.zeros((self.size, self.size, 2))
        for i in range(self.size):
            for j in range(self.size):
                unit_position_vector[i, j] = (self.position[i] - self.position[j]) / np.linalg.norm(self.position[i] - self.position[j])
        return unit_position_vector
    
    # unit vector of relative velocity
    def unit_velocity_vector(self):
        unit_velocity_vector = np.zeros((self.size, self.size, 2))
        for i in range(self.size):
            for j in range(self.size):
                unit_velocity_vector[i, j] = (self.velocity[i] - self.velocity[j]) / np.linalg.norm(self.velocity[i] - self.velocity[j])
        return unit_velocity_vector
    
    # Repulsion and attraction velocity
    def repulsion_attraction_velocity(self):
        repulsion_attraction_velocity = np.zeros((self.size, 2))
        neighbours, number_of_neighbours = self.neighbours()
        relative_distance = self.relative_distance()
        unit_position_vector = self.unit_position_vector()
        for i in range(self.size):
            for j in range(self.size): # can add attraction velocity
                if np.linalg.norm(self.position[i] - self.position[j]) <= self.r0_rep:
                    repulsion_attraction_velocity[i] += neighbours[i, j] * unit_position_vector[i, j] * (self.r0_rep - relative_distance[i, j]) * self.p_rep
        return repulsion_attraction_velocity
    
    # Alignment velocity
    def alignment_velocity(self):
        relative_position = self.relative_position()
        relative_velocity = self.relative_velocity()
        unit_velocity_vector = self.unit_velocity_vector()
        # D ---> ideal breaking curve
        r = r - self.r0_fric
        a = self.a0_fric
        p = self.p_fric
        D = np.zeros((self.size, 2))
        if r <= 0:
            D = np.zeros((self.size, 2))
        elif r > 0 and r < a/p:
            D = r * p
        else:
            D = np.sqrt(2 * a * r - a**2 / p**2)
        
        v_fricmax = np.ones((self.size, self.size))*self.v_fric
        v_fricmax[v_fricmax > self.v_fric] = D[v_fricmax > self.v_fric]
        
        alignment_velocity = np.zeros((self.size, 2))
        for i in range(self.size):
            for j in range(self.size):
                alignment_velocity[i] += self.C_fric*(relative_velocity[i, j] - v_fricmax[i, j]*unit_velocity_vector[i, j])
        return alignment_velocity
    
    # Walls repulsion virtual shill agent
    # def walls_repulsion_velocity(self):
    #     # Add arena repulsion effect
    #     # On each axis we have the two repulsions
    #     for axis in range(2):
    #         # On each axis there is two forces (each side of the arena)
    #         for side in range(2):
    #             # If the drone is on the right side of the arena
    #             if self.position[:, axis].max() > self.arena_size[axis]:
    #                 # Calculate the repulsion force
    #                 self.repulsion_attraction_velocity[:, axis] -= self.p_rep * (self.position[:, axis] - self.arena_size[axis])
    #             # If the drone is on the left side of the arena
    #             elif self.position[:, axis].min() < 0:
    #                 # Calculate the repulsion force
    #                 self.repulsion_attraction_velocity[:, axis] -= self.p_rep * (self.position[:, axis])
        
            

    

    