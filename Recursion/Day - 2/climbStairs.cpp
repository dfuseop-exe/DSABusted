int countDistinctWayToClimbStair(long long nStairs)
{
    if(nStairs < 0)
        return 0;
    if(nStairs == 0)
        return 1;
    
    //recursive relation
    long long ans = countDistinctWayToClimbStair(nStairs-1) + 
        countDistinctWayToClimbStair(nStairs-2);
    
    return ans;
}