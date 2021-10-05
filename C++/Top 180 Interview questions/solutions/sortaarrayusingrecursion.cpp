void sort(vector<int>& arr)
{
	if(arr.size()==1)
		return;
	int temp = arr[arr.size() - 1];
	arr.pop_back();
	sort(v);
	insert(v,temp);
}
void insert(vector<int>& arr, int temp)
{
	if(arr[arr.size()-1] <= temp)
	{
		arr.push_back(temp);
	}
	int val = arr[arr.size()-1];
	arr.pop_back();
	insert(arr,temp);
	ar.push_back(val);
}