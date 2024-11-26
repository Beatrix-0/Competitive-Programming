This problem is about dividing an array into k segments in such a way that the largest sum of elements in any of the segments is minimized.

Key Insights:
 - Objective: Minimize the maximum sum of elements in any segment.
 - Constraint: The array must be divided into exactly k non-empty contiguous segments.

Intuition: 
 - Binary Search on the Answer: The idea is to perform a binary search on the possible values of the maximum segment sum. The minimum possible   value for the maximum segment sum is the largest single element in the array (because at least one segment must contain that element). The maximum possible value is the sum of the entire array (if we only create one segment). We can think of a target maximum sum and then try to "greedily" divide the array into k or fewer segments such that the sum of each segment is less than or equal to this target. If we can split the array with a given maximum sum, then that value is a candidate for the solution, and we can try smaller sums. Otherwise, we need to increase the maximum allowed sum.

 - Greedy Segmentation: For a fixed maximum sum, traverse through the array and keep accumulating elements in a segment. If adding the next element exceeds the maximum allowed sum, start a new segment. Count how many segments are required for a given maximum sum. If the number of segments exceeds k, the maximum sum is too small.

Plan: 
1. Binary Search: Search for the smallest possible value of the maximum sum.
2. Check Feasibility: For each candidate maximum sum, check if the array can be divided into k or fewer segments without any segment sum exceeding that candidate value.

Video : https://youtu.be/t9B3bQTlGPE?si=zL-HFxH5URu3Lsde