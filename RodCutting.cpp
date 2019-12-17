/**
 * RodCutting Problem
 * Lab 7
 * 
 * Michael Solwold
 */

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Method that uses dynamic programming to calculate the maximum value that can be obtained
 * from  a rod of length n given set of rod prices
 * 
 * @param int[] prices
 * @param int n
 * 
 * @return int optimal price of sale
 */
int cutRod(int prices[], int n, int maxRod, int results[])
{
    // Base case for not using the rod of max length
    if (maxRod <= 0)
        return 0;

    // If a result is already stored (Dynamic Programming \(o_o)/ )
    if (results[n] != -1)
        return results[n];

    else
    {
        // If I use the max length rod available
        int useMax = n >= maxRod ? prices[maxRod-1] + 
            cutRod(prices, n-maxRod, maxRod, results) : cutRod(prices, n, maxRod - 1, results);

        // If I do not use the max length rod
        int noMax = cutRod(prices, n, maxRod - 1, results);

        // Store the largest value
        results[n] = max(useMax, noMax);
    }
    return results[n];
}

/**
 * Creates the results array and calls the cutRod function
 * @param int[] prices array
 * @param int length of rod that is being created
 * @param int largest rod in price array
 */
void cutRodHelper(int prices[], int n, int maxRod)
{
    // Results array, can calculate best way to make a size 12 rod
    int results [12];

    for (int i = 0; i < 12; i++)
        results[i] = -1;

    cout << "Cut a Rod of length " << n << ": $" << cutRod(prices, n, maxRod, results) << endl << endl;
}

int main()
{
    // Max Rod that I can use to create n
    int maxRod = 8;

    // * Test Case 1
    int prices1 [8] = {1, 5, 8, 9, 10, 17, 17, 20};

    cutRodHelper(prices1, 4, maxRod);

    // * Test Case 2
    int prices2 [8] = {1, 5, 8, 9, 10, 17, 17, 20};

    cutRodHelper(prices2, 0, maxRod);
    
    // * Test Case 3
    int prices3 [8] = {0, 0, 8, 9, 10, 17, 17, 20};

    cutRodHelper(prices3, 4, maxRod);

    return 0;
}