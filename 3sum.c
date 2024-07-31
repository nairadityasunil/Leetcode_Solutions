#include <stdio.h>
#include <stdlib.h>

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes);
int main()
{

    int nums[] = {-9, -5, 14, 10, 12, 12, -1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;
    int **result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    return 0;
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{

    // Sorting the array to avoid duplicates
    // Sorting using bubble sort

    int temp; // Temperory variable for swapping

    // This loop is to count the number of passes
    for (int i = 0; i < numsSize - 1; i++)
    {
        // Loop for swapping
        for (int j = 0; j < numsSize - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                // Swapping the values to sort the array
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    // The array is sorted

    int count_rows = 0; // Count number of triplets

    // Dynamic 2d array to store triplets
    returnColumnSizes = (int **)malloc(1 * sizeof(int *)); // Initially only 1 row created which will be dynamically reallocated

    *(returnSize) = 0; // initial row count

    for (int i = 0; i < numsSize - 2; i++)
    {
        for (int j = i + 1; j < numsSize - 1; j++)
        {
            for (int k = j + 1; k < numsSize; k++)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    // Triplet found
                    if (count_rows == 0) // if the return array does not contain any row
                    {
                        returnColumnSizes[*(returnSize)] = (int *)malloc(3 * sizeof(int)); // Creating 3 columns to store the triplets
                        returnColumnSizes[*(returnSize)][0] = nums[i];
                        returnColumnSizes[*(returnSize)][1] = nums[j];
                        returnColumnSizes[*(returnSize)][2] = nums[k];
                        *(returnSize) += 1;
                        count_rows++;
                    }
                    else // Atleast 1 row present in the 2d array
                    {
                        int duplicate = 0; // Used as boolean to check if the duplicate row is found
                        for (int l = 0; l < *(returnSize); l++)
                        {
                            if (returnColumnSizes[l][0] == nums[i] && returnColumnSizes[l][1] == nums[j] && returnColumnSizes[l][2] == nums[k])
                            {
                                // Duplicate row found
                                duplicate = 1;
                                break;
                            }
                        }

                        if (!duplicate)
                        {
                            // If no duplicate is found
                            returnColumnSizes = (int **)realloc(returnColumnSizes, (count_rows + 1) * sizeof(int *));
                            returnColumnSizes[*(returnSize)][0] = nums[i];
                            returnColumnSizes[*(returnSize)][1] = nums[j];
                            returnColumnSizes[*(returnSize)][2] = nums[k];
                            *(returnSize) += 1;
                            count_rows++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            printf("%d\n", returnColumnSizes[i][j]);
        }
    }

    return returnColumnSizes;
}