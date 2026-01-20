
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

    public toString(): string {
    const parts: string[] = [];
    let current = this.head;

    while (current !== null) {
        parts.push(String(current.data));
        current = current.next;
    }

    return parts.join(" <-> ");
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
            return this.prepend(data);
        }
        else if( index === this.count){
            return this.append(data);
        }
        else{
            const newNode = new _Node<T>(data);
            let current = this.head!;
            for(let i = 0; i < index - 1; i++){
                current = current.next!;
            }
            const right = current.next!;   // save the node that was originally after current

            newNode.prev = current;
            newNode.next = right;

            current.next = newNode;
            right.prev = newNode;
            this.count++;
        }
    }

    public removeHead() : T | null {
        if(this.isEmpty()){
            return null;
        }
        const temp = this.head!;
        const tempData = temp.data;

        this.head = temp.next;

        if(this.head){
            this.head!.prev = null;
        }else{
            this.tail = null;
        }
        
        temp.next = null;
        temp.prev = null;

        this.count--;
        return tempData;
    }

    public removeTail() : T | null {
        if(this.isEmpty()){
            return null;
        }
        const temp = this.tail!;
        const tempData = temp.data;

        this.tail = this.tail!.prev;

        if(this.tail){
            this.tail!.next = null;
        }else{
            this.head = null;
        }
        temp.next = null;
        temp.prev = null;

        this.count--;
        return tempData;
    }

    public removeAt(index:number) : T | null {
         if(index < 0 || index >= this.count){
            throw new Error("Index out of bounds");
        }
        if(index === 0){
            return this.removeHead();
        }
        else if( index === this.count-1){
            return this.removeTail();
        }
        else{
            let temp = this.head!;
            for(let i = 0; i < index; i++){
                temp = temp.next!;
            }
            const left = temp.prev!;
            const right = temp.next!;

            left.next = right;
            right.prev = left;

            temp.next = null;
            temp.prev = null;
            this.count--;
            return temp.data;
        }

    }

    public search(key:T) : boolean{
        let current = this.head;
        let index = 0;
        while(current != null){
            if(current.data === key){
                return true;
            }
            current = current.next!;
        }
        return false
    }
}

