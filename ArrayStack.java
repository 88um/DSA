package ilstu.edu;

public class ArrayStack<E> {
	private int top = -1;
	private int capacity;
	private int size;
	private E[] data;
	
	public ArrayStack() {
		this.capacity = 5;
		this.data = (E[]) new Object[this.capacity];
		this.size = 0;
	}
	
	public boolean empty() {
		return this.top == -1;
	}
	
	public E peek() {
		if (empty()) {
			return null;
		}
		return data[top];
	}
	
	public E pop() {
		if (empty()) {
			return null;
		}
		E data = peek();
		top--;
		return data;
	}
	
	public E push(E item) {
		if (top == this.data.length-1) {
			//reallocate
		}
		top++;
		data[top] = item;
		return item;
	}
}
