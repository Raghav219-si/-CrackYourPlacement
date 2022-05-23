int ans(int ar[], int n, int m){
	
	if(n == 0 || m == 0)
		return 0;
	else if(n < m)
		return -1;

	sort(ar, ar+n);
	int i = 0, k = m-1, ans = INT_MAX;
	while(k < n){
		ans = min(ans, ar[k]-ar[i]);
		i++;
		k++;
	}

	return ans;
}