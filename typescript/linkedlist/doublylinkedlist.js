"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.DoublyLinkedList = void 0;
var _Node = /** @class */ (function () {
    function _Node(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
    return _Node;
}());
var DoublyLinkedList = /** @class */ (function () {
    function DoublyLinkedList() {
        this.head = null;
        this.tail = null;
        this.count = 0;
    }
    DoublyLinkedList.prototype.isEmpty = function () {
        return this.count === 0;
    };
    DoublyLinkedList.prototype.size = function () {
        return this.count;
    };
    DoublyLinkedList.prototype.toString = function () {
        var parts = [];
        var current = this.head;
        while (current !== null) {
            parts.push(String(current.data));
            current = current.next;
        }
        return parts.join(" <-> ");
    };
    DoublyLinkedList.prototype.prepend = function (data) {
        var newNode = new _Node(data);
        if (this.isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            newNode.next = this.head;
            this.head.prev = newNode;
            this.head = newNode;
        }
        this.count++;
    };
    DoublyLinkedList.prototype.append = function (data) {
        var newNode = new _Node(data);
        if (this.isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            newNode.prev = this.tail;
            this.tail.next = newNode;
            this.tail = newNode;
        }
        this.count++;
    };
    DoublyLinkedList.prototype.insertAt = function (data, index) {
        if (index < 0 || index > this.count) {
            throw new Error("Index out of bounds");
        }
        if (index === 0) {
            return this.prepend(data);
        }
        else if (index === this.count) {
            return this.append(data);
        }
        else {
            var newNode = new _Node(data);
            var current = this.head;
            for (var i = 0; i < index - 1; i++) {
                current = current.next;
            }
            var right = current.next; // save the node that was originally after current
            newNode.prev = current;
            newNode.next = right;
            current.next = newNode;
            right.prev = newNode;
            this.count++;
        }
    };
    DoublyLinkedList.prototype.removeHead = function () {
        if (this.isEmpty()) {
            return null;
        }
        var temp = this.head;
        var tempData = temp.data;
        this.head = temp.next;
        if (this.head) {
            this.head.prev = null;
        }
        else {
            this.tail = null;
        }
        temp.next = null;
        temp.prev = null;
        this.count--;
        return tempData;
    };
    DoublyLinkedList.prototype.removeTail = function () {
        if (this.isEmpty()) {
            return null;
        }
        var temp = this.tail;
        var tempData = temp.data;
        this.tail = this.tail.prev;
        if (this.tail) {
            this.tail.next = null;
        }
        else {
            this.head = null;
        }
        temp.next = null;
        temp.prev = null;
        this.count--;
        return tempData;
    };
    DoublyLinkedList.prototype.removeAt = function (index) {
        if (index < 0 || index >= this.count) {
            throw new Error("Index out of bounds");
        }
        if (index === 0) {
            return this.removeHead();
        }
        else if (index === this.count - 1) {
            return this.removeTail();
        }
        else {
            var temp = this.head;
            for (var i = 0; i < index; i++) {
                temp = temp.next;
            }
            var left = temp.prev;
            var right = temp.next;
            left.next = right;
            right.prev = left;
            temp.next = null;
            temp.prev = null;
            this.count--;
            return temp.data;
        }
    };
    DoublyLinkedList.prototype.search = function (key) {
        var current = this.head;
        var index = 0;
        while (current != null) {
            if (current.data === key) {
                return true;
            }
            current = current.next;
        }
        return false;
    };
    return DoublyLinkedList;
}());
exports.DoublyLinkedList = DoublyLinkedList;
