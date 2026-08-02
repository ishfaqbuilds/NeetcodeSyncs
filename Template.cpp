
// 1D Dynamic Problem "Climbing Stairs, House Robber, Coin Change, Min Cost Climbing Stairs, and LIS."
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> &nums)
{
    int n = nums.size();

    // Handle small inputs if necessary
    if (n == 0)
    {
        return 0;
    }

    // 1. Create DP array
    vector<int> dp(n, 0);

    // 2. Write base cases
    // dp[0] = ...;
    // dp[1] = ...;

    // 3. Build DP from smaller states
    for (int i = 1; i < n; i++)
    {
        // dp[i] = ...; Formula
    }

    // 4. Return the required answer
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << solve(nums);
    return 0;
}



// 2D Dynamic Problem "Unique Paths, LCS, palindromic substrings, and other grid or two string problems."
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solve(/* input parameters */)
{
    int rows = /* number of rows or first input size */;
    int cols = /* number of columns or second input size */;

    // 1. Create DP table
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    // 2. Write base cases
    // dp[0][...] = ...;
    // dp[...][0] = ...;

    // 3. Build DP table
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            // dp[i][j] = ...; Formula
        }
    }

    // 4. Return the required answer
    return dp[rows - 1][cols - 1];
}

int main()
{
    // Take input according to the problem

    cout << solve(/* arguments */);
    return 0;
}




// DFS Template
#include <iostream>
#include <vector>
using namespace std;

// DFS Function
void dfs(vector<vector<int>> &grid, int row, int col)
{
    // 1. Boundary Check
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
    {
        return;
    }

    // 2. Invalid Cell Check
    if (/* Invalid Cell */)
    {
        return;
    }

    // 3. Mark as Visited
    // grid[row][col] = ...

    // 4. Visit Neighbors
    dfs(grid, row - 1, col); // Up
    dfs(grid, row + 1, col); // Down
    dfs(grid, row, col - 1); // Left
    dfs(grid, row, col + 1); // Right
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }
    return 0;
}



// Merge Sort
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec, int low, int mid, int high)
{
    vector<int> temp;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (vec[i] <= vec[j]) temp.push_back(vec[i++]);
        else temp.push_back(vec[j++]);
    }

    while (i <= mid) temp.push_back(vec[i++]);
    while (j <= high) temp.push_back(vec[j++]);

    for (int k = 0; k < temp.size(); k++)
    {
        vec[low + k] = temp[k];
    }
}

void mergeSort(vector<int> &vec, int low, int high)
{
    if (low >= high) return;

    int mid = (low + high) / 2;

    mergeSort(vec, low, mid);
    mergeSort(vec, mid + 1, high);
    merge(vec, low, mid, high);
}

int main()
{
    vector<int> vec = {9, 3, 7, 5, 6, 4, 8, 2};
    mergeSort(vec, 0, vec.size() - 1);
    for (int x : vec)
    {
        cout << x << " ";
    }
    return 0;
}



// Quick Sort
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int low, int high)
{
    int pivot = nums[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (nums[j] < pivot)
        {
            i++;

            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i + 1], nums[high]);

    return i + 1;
}

void quickSort(vector<int>& nums, int low, int high)
{
    if (low >= high)
        return;

    int pivotIndex = partition(nums, low, high);

    quickSort(nums, low, pivotIndex - 1);
    quickSort(nums, pivotIndex + 1, high);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    quickSort(nums, 0, n - 1);

    for (int x : nums)
        cout << x << " ";

    return 0;
}


// Rotated Binary Search
#include <iostream>
#include <vector>

using namespace std;

int rotatedBinarySearch(vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        // Left half is sorted
        if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // Right half is sorted
        else
        {
            if (target > nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    cout << rotatedBinarySearch(nums, target);

    return 0;
}