/*
https://leetcode.com/problems/contains-duplicate/

There are many ways to thing about this problem.

solution 1: most initutive way is to pick element and 
check in rest of array if same element exist. This should be 
done for all elements. Thus we will be traversing the whole 
array every time we pick element of array.
TIME: O(N^2)
SPACE: O(1)

solution 2: bottle neck is every element is checked twice in 
solution 1. so we need to remove this bottle neck by creating hash
for element visited in array. every time we pick an element in array,
we check if it is present in hash, if not it is unique element seen till now.
so at any point of time at ith index , the array 0 to ith have unique element,
and i+1th to end, is unexplored. if we reach the end of array, 
then all element are unique, else we found the duplicate and return without further exploring.
TIME: O(N)
SPACE: O(N)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> hash;
        for (auto item: nums){
            if (hash.find(item) != hash.end()) return true;
            else hash[item]++;
        }
        return false;
    }
};
