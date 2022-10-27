package singlelinkedlist;

public class Node {
	
	private int valor;
	private Node next;
	
	public Node(int valor) {
		this.valor = valor;
		this.next = null;
		
	}
	
	public int getValor(){
		return this.valor;
	}
	
	public Node getNext() {
		return this.next;
	}
	
	public void setValor(int valor) {
		this.valor = valor;
	}
	
	public void setNext(Node next) {
		this.next = next;
	}
	
	public String toString() {
		return valor + "";
	}

}
