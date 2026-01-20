"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var DoublyLinkedList_1 = require("./DoublyLinkedList"); // <-- match your filename exactly
function assert(condition, message) {
    console.assert(condition, message);
}
function show(label, list) {
    // If you added toString(), this prints the list nicely.
    // Otherwise it prints the label only.
    if (typeof list.toString === "function") {
        console.log("".concat(label, ": ").concat(list.toString()));
    }
    else {
        console.log(label);
    }
}
function main() {
    console.log("Running DoublyLinkedList tests...");
    var dll = new DoublyLinkedList_1.DoublyLinkedList();
    // --- Empty list checks ---
    assert(dll.isEmpty(), "Expected list to start empty");
    assert(dll.size() === 0, "Expected size to start at 0");
    assert(dll.search(10) === false, "Expected search on empty list to be false");
    assert(dll.removeHead() === null, "Expected removeHead on empty list to return null");
    assert(dll.removeTail() === null, "Expected removeTail on empty list to return null");
    // --- Append / Prepend ---
    dll.append(10);
    dll.append(20);
    dll.prepend(5);
    assert(dll.size() === 3, "Expected size 3 after 3 inserts");
    assert(dll.search(20) === true, "Expected 20 to be found");
    assert(dll.search(999) === false, "Expected 999 not to be found");
    show("After append/append/prepend", dll);
    // --- insertAt ---
    // Current should be: 5, 10, 20
    dll.insertAt(15, 2); // insert at index 2 -> 5, 10, 15, 20
    assert(dll.size() === 4, "Expected size 4 after insertAt");
    assert(dll.search(15) === true, "Expected 15 to be found after insertAt");
    show("After insertAt(15, 2)", dll);
    // --- removeHead ---
    var rh = dll.removeHead();
    assert(rh === 5, "Expected removeHead to return 5");
    assert(dll.size() === 3, "Expected size 3 after removeHead");
    show("After removeHead()", dll);
    // --- removeTail ---
    var rt = dll.removeTail();
    assert(rt === 20, "Expected removeTail to return 20");
    assert(dll.size() === 2, "Expected size 2 after removeTail");
    show("After removeTail()", dll);
    // --- removeAt (middle) ---
    // Now should be: 10, 15
    var ra = dll.removeAt(1); // removes 15
    assert(ra === 15, "Expected removeAt(1) to return 15");
    assert(dll.size() === 1, "Expected size 1 after removeAt");
    show("After removeAt(1)", dll);
    // --- Edge case: single node removal ---
    // Now should be: 10
    var last = dll.removeAt(0);
    assert(last === 10, "Expected removeAt(0) to return 10 for last element");
    assert(dll.isEmpty(), "Expected list empty after removing last element");
    assert(dll.size() === 0, "Expected size 0 after removing last element");
    show("After removing last element", dll);
    // --- Bounds tests (should throw) ---
    var threw = false;
    try {
        dll.removeAt(0);
    }
    catch (_a) {
        threw = true;
    }
    assert(threw, "Expected removeAt(0) on empty list to throw");
    threw = false;
    try {
        dll.insertAt(123, -1);
    }
    catch (_b) {
        threw = true;
    }
    assert(threw, "Expected insertAt with negative index to throw");
    console.log("✅ All tests finished.");
}
main();
