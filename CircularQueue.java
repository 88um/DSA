package ilstu.edu;



public class CircularQueue<E> {
	private int capacity;
	private int front;
	private int rear;
	private int size;
	private E[] data;
	
	public CircularQueue() {
		this.data = (E[]) new Object[5];
		this.capacity = 5;
		this.front = 0;
		this.size =0;
		this.rear = this.capacity-1;
	}
	
	
	
	public boolean offer(E item) {
		if (size == capacity) {
			//reallocate
		}
		size++;
		rear = (rear+1) % capacity;
		data[rear] = item;
		return true;
	}
	
	public E poll() {
		E d = null;
		if (size == 0) {
			return null;
		}
		d = data[front];
		front= (front+1)%capacity;
		size--;
		return d;
	}
	
}
