class Solution {
    HashSet<Integer> hs=new HashSet<>();
    int count=0;
    public void  countCompleteSubarray(HashSet<Integer> set){
        
        for(int i:hs){
            if(!set.contains(i)){
                return;
            }
        }
        count++;

    }

    public int countCompleteSubarrays(int[] nums) {
        int n = nums.length;

        for(int i=0;i<n;i++){
            hs.add(nums[i]);
        }

        // Generate and process each subarray
        for (int start = 0; start < n; start++) {
            HashSet<Integer> currentSubarray = new HashSet<>();
            for (int end = start; end < n; end++) {
                currentSubarray.add(nums[end]);
                
                // Pass the current subarray to the function
                countCompleteSubarray(currentSubarray);
            }
        }
        return count;
    }
}

