单调队列
	保证队列中的数字有顺序
	一般用deque实现（双端队列）
	
	队列一般要保存下标（而不是要比较大小的数字） 
	单调减队列：
	deque<int> dq; 
	for(int i = 1; i <= n; i++)
	{
		while(队首的人需要退役) dq.pop_front();
		while(要加入的人比队尾的人厉害) dq.pop_back();
		dq.push_back(要加入的人);
		//最厉害的人在队首 
	}
	时间复杂度O(n) 
