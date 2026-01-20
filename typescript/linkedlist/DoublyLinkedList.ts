
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

    public isEmpty() : boolean {
        return this.count === 0;
    }

    public size() : number {
        return this.count;
    }

    public prepend(data:T) : void {
        const newNode = new _Node<T>(data);
        if (this.isEmpty()){
            this.head = newNode;
            this.tail = newNode;
        }
        else{
            newNode.next = this.head;
            this.head!.prev = newNode;
            this.head = newNode;
        }
        this.count++;
    }

    public append(data:T) : void {
        const newNode = new _Node<T>(data);
        if(this.isEmpty()){
            this.head = newNode;
            this.tail = newNode;

        }
        else{
            newNode.prev = this.tail;
            this.tail!.next = newNode;
            this.tail = newNode;
        }
        this.count++;
    }

    public insertAt(data:T, index:number) : void {
        if(index < 0 || index > this.count){
            throw new Error("Index out of bounds");
        }
        if(index === 0){
            this.prepend(data);
            return;
        }
        else if( index === this.count){
            this.append(data);
            return;
        }
        else{
            const newNode = new _Node<T>(data);
            let current = this.head!;
            for(let i = 0; i < index - 1; i++){
                current = current.next!;
            }
            newNode.prev = current;
            newNode.next = current.next;
            current.next = newNode;
            current.next!.prev = newNode;
        }
        this.count++;
    }

    public removeHead() : T | null {
        return null;
    }

    public removeTail() : T | null {
        return null;
    }

    public removeAt(index:number) : T | null {
        return null;
    }

    public search(data:T) : number {
        return -1;
    }
}

