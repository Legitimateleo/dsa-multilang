"use strict";
/**
 * @file linkedlist.ts
 * @brief Generic doubly linked list implementation.
 *
 * Provides a doubly linked list with head and tail pointers and
 * bidirectional node links. Designed for efficient insertion and
 * removal at both ends of the list.
 *
 * @author Leonardo Solorzano
 */
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
/**
 * Doubly linked list implementation.
 *
 * Maintains head/tail for O(1) prepend/append and O(1) deleteHead/deleteTail.
 * Tracks size in O(1) via `count`.
 */
var DoublyLinkedList = /** @class */ (function () {
    function DoublyLinkedList() {
        this.head = null;
        this.tail = null;
        this.count = 0;
    }
    /**
     * Check if the list is empty.
     * @returns true if empty, false otherwise
     */
    DoublyLinkedList.prototype.isEmpty = function () {
        return this.count === 0;
    };
    /**
     * Get the number of elements in the list.
     * @returns the size of the list
     */
    DoublyLinkedList.prototype.size = function () {
        return this.count;
    };
    /**
   * Useful for debugging.
   * @returns string representation of the list
   */
    DoublyLinkedList.prototype.toString = function () {
        var parts = [];
        var current = this.head;
        // Traverse the list
        while (current !== null) {
            parts.push(String(current.data));
            current = current.next;
        }
        // Join the parts with <-> to represent the doubly linked list
        return parts.join(" <-> ");
    };
    /**
     * Prepend data to the beginning of the list (O(1)).
     * @param data the data to prepend
     */
    DoublyLinkedList.prototype.prepend = function (data) {
        var newNode = new _Node(data);
        // If the list is empty, new node becomes both head and tail
        if (this.isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
        }
        // Otherwise, insert the new node at the head
        else {
            newNode.next = this.head;
            this.head.prev = newNode;
            this.head = newNode;
        }
        this.count++;
    };
    /**
   * Append data to the end of the list (O(1)).
   * @param data the data to append
   */
    DoublyLinkedList.prototype.append = function (data) {
        var newNode = new _Node(data);
        if (this.isEmpty()) {
            // First node becomes both head and tail
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            // Link new node after tail and update tail pointer
            newNode.prev = this.tail;
            this.tail.next = newNode;
            this.tail = newNode;
        }
        this.count++;
    };
    /**
   * Insert data at index pos.
   * Valid positions: 0..count inclusive.
   * @param data the data to insert
   * @param index the position to insert at
   */
    DoublyLinkedList.prototype.insertAt = function (data, index) {
        // Validate index
        if (index < 0 || index > this.count) {
            throw new Error("Index out of bounds");
        }
        // Handle insertion at head or tail
        if (index === 0) {
            return this.prepend(data);
        }
        else if (index === this.count) {
            return this.append(data);
        }
        // Insert in the middle
        else {
            var newNode = new _Node(data);
            var current = this.head;
            // Traverse to the desired index
            for (var i = 0; i < index - 1; i++) {
                current = current.next;
            }
            var right = current.next; // save the node that was originally after current
            // Link new node between current and right
            newNode.prev = current;
            newNode.next = right;
            // Link current to new node
            current.next = newNode;
            // Link right to new node
            right.prev = newNode;
            this.count++;
        }
    };
    /**
   * Remove and return the head value (O(1)).
   * @returns removed value, or null if empty
   */
    DoublyLinkedList.prototype.removeHead = function () {
        if (this.isEmpty()) {
            return null;
        }
        // Save the current head
        var temp = this.head;
        var tempData = temp.data;
        // Update head to the next node
        this.head = temp.next;
        // If head is not null, update its prev pointer
        if (this.head) {
            this.head.prev = null;
        }
        else {
            this.tail = null;
        }
        // Clean up
        temp.next = null;
        temp.prev = null;
        this.count--;
        return tempData;
    };
    /**
   * Remove and return the tail value (O(1) in a doubly linked list).
   * @returns removed value, or null if empty
   */
    DoublyLinkedList.prototype.removeTail = function () {
        if (this.isEmpty()) {
            return null;
        }
        // Save the current tail
        var temp = this.tail;
        var tempData = temp.data;
        // Update tail to the previous node
        this.tail = this.tail.prev;
        // If tail is not null, update its next pointer
        if (this.tail) {
            this.tail.next = null;
        }
        else {
            this.head = null;
        }
        // Clean up
        temp.next = null;
        temp.prev = null;
        this.count--;
        return tempData;
    };
    /**
   * Delete node at index pos and return its data.
   * @param index the position to remove
   */
    DoublyLinkedList.prototype.removeAt = function (index) {
        // Validate index
        if (index < 0 || index >= this.count) {
            throw new Error("Index out of bounds");
        }
        // Handle removal at head or tail
        if (index === 0) {
            return this.removeHead();
        }
        else if (index === this.count - 1) {
            return this.removeTail();
        }
        // Remove from the middle
        else {
            var temp = this.head;
            // Traverse to the desired index
            for (var i = 0; i < index; i++) {
                temp = temp.next;
            }
            // Unlink the node
            var left = temp.prev;
            var right = temp.next;
            // Link left to right
            left.next = right;
            right.prev = left;
            // Clean up
            temp.next = null;
            temp.prev = null;
            this.count--;
            return temp.data;
        }
    };
    /**
   * Linear search for a value.
   * @param key the value to search for
   */
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
