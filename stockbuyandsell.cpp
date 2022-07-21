int maximumProfit(vector<int> &prices){
    // Write your code here.
	int i,n=prices.size(),maxp=0,minp=prices[0];
	for(i=1;i<n;i++)
	{
		minp=min(prices[i],minp);
		maxp=max(prices[i]-minp,maxp);
	}
	return maxp;
}