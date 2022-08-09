int getKthLargestElement(vector<int> &list, int k) {
    // add your logic here
	priority_queue<int> pq(list.begin(), list.end());
	while(k != 1){
		pq.pop();
		k--;
	}
	return pq.top();
}