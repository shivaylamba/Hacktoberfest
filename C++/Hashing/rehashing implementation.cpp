//Implement a hashmap
//separate chaining technique
#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class Node{
	public:
		string key;
		T value;
		Node<T>*next;
		
		Node(string key,T val){
			this->key=key;
			val=value;
			next=NULL;
			
		}
		~Node(){
			if(next!=NULL){
				delete next;
			}
		}
	
};
template<typename T>
class Hashtable{
	Node<T>** table; //pointer to an array of pointers
	int current_size;
	int table_size;
	
	int hashfn(string key){
		int idx=0;
		int p=1;
		for(int j=0;j<key.length();j++){
			idx=idx+(key[j]*p)%table_size;
			idx=idx%table_size;
			p=(p*27)%table_size;
		}
		return idx;
	}
	void rehash(){
		Node<T>** old_table=table;
		int old_table_size=table_size;
		table_size=2*table_size;  //approximation find the next prime number
		table=new Node<T>*[table_size];
		for(int i=0;i<table_size;i++){
			table[i]=NULL;
			
		}
		current_size=0;
		//shift the elements from old table to new table
		for(int i=0;i<old_table_size;i++){
			Node<T>*temp=old_table[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp=temp->next;
			}
			if(old_table[i]!=NULL){
				delete old_table[i];
				
			}
		}
		delete[] old_table;
		
		
	}
public:
	Hashtable(int ts=7){
		table_size=ts;
		table=new Node<T>*[table_size];
		current_size=0;
		for(int i=0;i<table_size;i++){
			table[i]=NULL;
		}
	}
	
	void insert(string key,T value){
		int idx=hashfn(key);
		Node<T>*n=new Node<T>(key,value);
		//insert at the head of the linked list with id=idx
		n->next=table[idx];
		table[idx]=n;
		current_size++;
		
		//rehash
		float load_factor=current_size/(1.0*table_size);
		if(load_factor>0.75){
			rehash();
		}
		
		
		
	}
	void print(){
		for(int i=0;i<table_size;i++){
			cout<<"bucket"<<i<<"->";
			Node<T>*temp=table[i];
			while(temp!=NULL){
				cout<<temp->key<<"->";
				temp=temp->next;
				
			}
			cout<<endl;
		}
	}
	/*
	T search(string key){
		
		
	}
	void erase(string key){
		
		
	}*/
};
int main(){
	Hashtable<int>price_menu;
	price_menu.insert("Burger",120);
	price_menu.insert("Pepsi",60);
	price_menu.insert("Momos",40);
	price_menu.insert("Pizza",180);
	price_menu.insert("Fries",120);
	price_menu.print();
	
}
