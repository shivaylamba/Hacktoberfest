#include <iostream>

using namespace std;

//structure for the alphabets
struct alphabet{
    char ch;
    int freq;
    alphabet* left;
    alphabet* right;
    alphabet(){}
    alphabet(alphabet* a){
        ch=a->ch;
        freq=a->freq;
        left=a->left;
        right=a->right;
    }
    alphabet(char ch, int freq){
        this->ch=ch;
        this->freq=freq;
        left= nullptr;
        right= nullptr;
    }
};

//return the index of the parent element
int parent(int n){
    return n%2==0?n/2-1:n/2;
}

//impose the min heap
void min_heapify(alphabet arr[], int i, int heap_size)
{
    int l=2*i+1,r=2*i+2,smallest=i;
    if(l<heap_size && arr[l].freq < arr[smallest].freq)
        smallest=l;
    if(r<heap_size && arr[r].freq < arr[smallest].freq)
        smallest=r;
    if(smallest!=i)
    {
        swap(arr[smallest],arr[i]);
        min_heapify(arr,smallest,heap_size);
    }
}

//create a min heap
void build_min_heap(alphabet arr[], int heapsize){
    for(int i=heapsize/2-1;i>=0;i--)
        min_heapify(arr,i,heapsize);
}

//extract the smallest element from the min priority queue
alphabet* heap_extract_min(alphabet arr[], int heapsize){
    alphabet *ma=(alphabet*)malloc(sizeof(alphabet));
    ma->freq=arr[0].freq;
    ma->ch=arr[0].ch;
    ma->left=arr[0].left;
    ma->right=arr[0].right;
    arr[0] = arr[heapsize-1];
    min_heapify(arr, 0, heapsize-1);
    return ma;
}

//insert an element into the priority queue
void insert(alphabet arr[], alphabet z, int n) {
    int i=n;
    arr[i]=z;
    while (i>0 && arr[parent(i)].freq>arr[i].freq){
        swap(arr[i], arr[parent(i)]);
        i=parent(i);
    }
}

//create the huffman tree
alphabet huffman_encoding(alphabet arr[], int n){
    int heapsize = n;
    for(int i=0;i<n-1;i++){
        alphabet z = (alphabet*)malloc(sizeof(alphabet));
        z.left = heap_extract_min(arr, heapsize);
        heapsize--;
        z.right = heap_extract_min(arr, heapsize);
        heapsize--;
        z.freq = z.left->freq + z.right->freq;
        insert(arr, z, heapsize);
        heapsize++;
    }
    return heap_extract_min(arr, heapsize);
}

int main() {
    int n=6;
    alphabet arr[n];
    arr[0]=alphabet('a', 45);
    arr[1]=alphabet('b', 13);
    arr[2]=alphabet('c', 12);
    arr[3]=alphabet('d', 16);
    arr[4]=alphabet('e', 9);
    arr[5]=alphabet('f', 5);
    build_min_heap(arr, n);
    //getting the root of the huffman tree
    alphabet root = huffman_encoding(arr, n);
    cout<<root.freq<<endl;
    string a="100011001101"; // cafe
    alphabet temp = root;
    //decoding the bits
    for(char i : a){
        if(i=='0')
            temp=temp.left;
        else
            temp=temp.right;
        if(temp.left == nullptr && temp.right == nullptr) {
            cout << temp.ch << " ";
            temp=root;
        }
    }
    return 0;
}