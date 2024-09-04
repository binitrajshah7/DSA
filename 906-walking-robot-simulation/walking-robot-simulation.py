class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        x, y = 0,0
        direction = [[0, 1],[1,0],[0,-1],[-1,0]] # N, E, S, W
        # set comprehension
        obs = {tuple(o) for o in obstacles}
        d = 0
        result = 0

        for c in commands:
            # turn right
            if c == -1:
                d = (d+1)%4

            # turn left
            elif c == -2:
                d = (d-1)%4
            
            # move c magnitude from x, y
            else:
                dx, dy = direction[d]
                for _ in range(c):
                    if (x + dx, y + dy) in obs:
                        break
                    x, y = x + dx, y + dy
                    result = max(result, x*x + y*y)

        return result
