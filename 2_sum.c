int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) { // Checking value of 2 consecutive indices to see if they add up to target
                int *ptr;
                ptr = (int *) malloc(2*sizeof(int));
                ptr[0] = i;
                ptr[1] = j;
                *returnSize = 2;
                return ptr;
            }
        }
    }
    *returnSize = 0;
}