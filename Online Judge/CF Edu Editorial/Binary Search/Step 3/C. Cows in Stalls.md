Problem Overview: Given n stalls positioned along a line and k cows, the goal is to place the cows in the stalls such that the minimum distance between any two cows is maximized.

Key Intuition: 
1. Placing Cows Far Apart: The goal is to place the cows in such a way that the smallest distance between any two cows is as large as possible. This ensures that the cows are placed as far apart as possible.
2. Binary Search on Distance:
   - You can think of the possible minimum distances between cows and use binary search to find the largest one that works.
   - The smallest possible distance between any two cows is 1 (they could be adjacent), and the largest possible distance is the difference between the smallest and largest stall positions (e.g., stalls[n-1] - stalls[0]).
3. Check function : 
 For a given distance d (midpoint in the binary search), you can check if it is possible to place all k cows such that the distance between any two cows is at least d. This can be done greedily by placing the first cow in the first stall and then placing the next cow in the first stall that is at least d units away from the last one.

 Steps in the Solution:
 Binary Search on the Answer: Use binary search to try different distances, and for each distance
   - Greedily place cows in the stalls.
   - If it's possible to place all cows with at least that distance, try a larger distance.
   - If it's not possible, try a smaller distance.

   Video : https://youtu.be/H9LoqW-gGk0?si=A9Mli66w5ol2TBXQ
