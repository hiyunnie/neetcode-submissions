class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0], max_profit = 0;
        for (int price : prices) {
            if (min_price > price) min_price = price;
            if (max_profit < (price - min_price)) max_profit = price - min_price;
        }
        return max_profit;
    }
};
/**

## Clarification

- Is the input guaranteed to contain at least one price?
- Can I buy and sell on the same day?
- If there is no profitable transaction, should I return 0?

## Brute Force

Try every possible buy day and sell day after it.

For each pair, calculate:

`profit = prices[sell] - prices[buy]`

- Time: `O(n^2)`
- Space: `O(1)`

## Optimized Approach

Keep track of:

- the minimum price seen so far
- the maximum profit seen so far

For each price:

1. Calculate the profit if I sell today using the minimum previous price.
2. Update the maximum profit.
3. Update the minimum price if the current price is lower.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Edge Cases

1. Prices are strictly decreasing
2. Only one price
3. The minimum price appears near the end

## Interview Explanation

I keep track of the minimum price seen so far.
For each day, I calculate the profit I would get if I sold at the current price.
Then I update the maximum profit if this profit is larger.
I also update the minimum price whenever I see a lower price.
This gives O(n) time and O(1) extra space.

## Follow-up
Why do we update the maximum profit before updating the minimum price? Does the order matter?
In this implementation, the order does not matter.
If the current price is a new minimum, updating minPrice first makes the current profit price - minPrice = 0.
Since maxProfit is always non-negative, this will not change the result.
If the current price is not a new minimum, minPrice remains unchanged, so both orders produce the same profit.

## Note


**/