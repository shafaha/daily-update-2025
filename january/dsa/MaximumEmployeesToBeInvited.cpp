// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/?envType=daily-question&envId=2025-01-26

// The solution can be done with the Strongly connected components and topological sort algorithm
/*
    The number of the vertices is size of the array
    The number of the edges will always be size of the array
    since the every node is some to like then there must be cycle in the graph

    In the multiple component graph each compone tmust be having one cycle
    1. Number of the vertices = edges count
    2. out degree os 1
    3. All paths in every component leads to cycle
     4. Any arrangement which doesnot involve all the cycle elements will always be invalid
     5. if multipe person likes someone obly obe of then s=cab sut besude that person

    // conclusion:
    1. All the cycle with the length 2 can be included {
        cycle with the length 2 + maximum 2 tail going to it
    }
    2. if the cycle size is more than 2 then there will be only one cycle which can be included
*/
