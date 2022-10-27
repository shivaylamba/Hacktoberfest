package singlelinkedlist;

public class SingleLinkedListIterativa {
	
	private Node head;
	private Node aux;
	private Node current;
	
	public SingleLinkedListIterativa() {
		this.head = null;
		this.aux = null;
	}
	
	public void insert(int valor) {
		if(isEmpty()) {
			head = new Node(valor);
			aux = head;
		} else {
			if(aux.getNext() == null) {
				Node newNode = new Node(valor);
				aux.setNext(newNode);
				aux = newNode;
			}
		}
	}
	
	public void remove(int valor) {
		if (!isEmpty()) {
			current = head;
			if (valor == head.getValor()) {
				head = current.getNext();
			} else if (valor == aux.getValor()) {
				
			} else {
				while (current.getNext() != null) {
					if (current.getValor() == valor) {
						Node toRemove = current.getNext();
						current.setNext(toRemove.getNext());
						return;
					}
					current = current.getNext();
				}
			}

		}
	}
	
	public boolean search(int valor) {
		if(isEmpty()) {
			return false;
		} else {
			current = head;
			while(current != null) {
				if(current.getValor() == valor) {
					return true;
				} 
				current = current.getNext();
			}
			return false;
		}
	}
	
	public int size() {
		if(!isEmpty()) {
			int contador = 1;
			current = head;
			while(current.getNext() != null) {
				contador += 1;
				current = current.getNext();
			}
			return contador;
		}
		return 0;
	}
	
	public boolean isEmpty() {
		if(head == null) {
			return true;
		}
		return false;
	}
	
	public int getHead() {
		return head.getValor();
	}
	
	public int getAux() {
		return aux.getValor();
	}
	
	public String toString(){
        String retStr = "Contents:\n";

		current = head;
        while(current != null){
            retStr += current.getValor() + "\n";
            current = current.getNext();

        }

        return retStr;
    }

}
