
class _Node<T> {
    public data : T;
    public next : _Node<T> | null;
    public prev : _Node<T> | null;

    constructor(data:T){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

export class DoublyLinkedList<T> {
    private head : _Node<T> | null;
    private tail : _Node<T> | null;
    private count : number;

    constructor() {
        this.head = null;
        this.tail = null;
        this.count = 0;
    }
}