class maxHeap {
	int n;
	vector<int> v;
public:
	maxHeap(vector<int>&);
	void push(int ele);
	void heapify(int);
	int pop();
	vector<int> HeapSort();
	void display();
};

// Creation of max heap using heapify function in O(n)
maxHeap::maxHeap(vector<int> &arr) {
	n = arr.size();
	v = arr;
	for (int i = n / 2 - 1; i >= 0; i--) heapify(i);
}

void maxHeap::push(int x) {
	v.push_back(x); n++;
	int i = n - 1;
	while (i > 0) {
		if (v[i] > v[(i - 1) / 2]) swap(v[i], v[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

// Create heap from ith node given that nodes below it already form a heap
void maxHeap::heapify(int i) {
	int largest = i;
	int l = 2 * i + 1, r = 2 * i + 2;

	if (l<n and v[l]>v[largest]) largest = l;
	if (r<n and v[r]>v[largest]) largest = r;

	if (largest != i) {
		swap(v[i], v[largest]);
		heapify(largest);
	}
}

int maxHeap::pop() {
	swap(v[0], v[n - 1]); n--;
	int ele = v.back(); v.pop_back();
	heapify(0);
	return ele;
}

vector<int> maxHeap::HeapSort() {
	vector<int> vSort;
	while (n > 0) vSort.push_back(pop());
	return vSort;
}

void maxHeap::display() {
	for (auto i : v) cout << i << " ";
	cout << endl;
}
