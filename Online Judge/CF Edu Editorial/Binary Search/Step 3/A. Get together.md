Problem Idea:

You are given n people on a straight line, each with a known position and speed. The goal is to find the minimum time it takes for all 
people to gather at one point, regardless of where that point is. Each person can move at their respective speed, and we need to calculate 
how quickly they can all meet.

Intuition:
1. Time Constraint: The more time we allow (monotonic), the farther a person can move. So, the problem is essentially asking to minimize the time such
 that all people can overlap at a single position.
2. Movement Range: For each person, given a specific time t, they can reach a position within a range of [xi - vi * t, xi + vi * t]. 
This range expands as t increases.
3. Finding Overlap: For all people to meet at one point, the ranges for all individuals must overlap. This means, for any given time t,
 we need to check if the intersection of all the ranges is non-empty. If so, the people can gather; otherwise, more time is required.
4. Binary Search on Time:
   - We can binary search on time to find the minimum possible value of t where the ranges intersect.
   - Start with a small time (low = 0) and a very large time (high = 1e9) and gradually refine the time.
   - At each midpoint of the binary search, check if the ranges intersect. If they do, reduce the upper bound (high); otherwise,
     increase the lower bound (low).
5. Stopping Condition:
The binary search stops after 100 iterations, as iterating 100 times provides sufficient precision for this problem. At the end of the iterations, 
the midpoint is considered the minimum time needed for all people to gather. This approach avoids precision issues and ensures convergence within
 a reasonable number of steps.