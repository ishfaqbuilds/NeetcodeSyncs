class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int maxPile = 0;
        for (int i = 0; i < piles.size(); i++) 
        {
            if (piles[i] > maxPile) 
            {
                maxPile = piles[i];
            }
        }

        int left = 1;
        int right = maxPile;
        int k = right;

        while(left<=right)
        {
            int speed = left + (right - left)/2;
            int hoursNeeded = 0;
            for(int i = 0; i < piles.size(); i++)
            {
                int pile = piles[i];
                int hoursTook;
                if(pile % speed == 0)
                {
                    hoursTook = pile / speed;
                }
                else
                {
                    hoursTook = (pile / speed) + 1;
                }
                hoursNeeded = hoursNeeded + hoursTook;
            }

            if(hoursNeeded <= h)
            {
                k = speed;
                right = speed - 1;
            }
            else
            {
                left = speed + 1;
            }
        }
        return k;
    }
};
