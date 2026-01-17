

class Node:
    """Represents a single node in the singly linked list."""
    def __init__(self, data):
        self.data = data #stores the actual value
        self.next = None #pointer to the next node, initialized to none.

class LinkedList:
    """Represents the singly linked list itself."""
    def __init__(self):
        self.head = None #points to the first node
        self.tail = None #points to the last node
        self.count = 0 #number of nodes in the list
        
    def is_empty(self) -> bool:
        """Return True if the list has no nodes."""
        return self.head is None

    def size(self) -> int:
        """Return the number of nodes currently in the list."""
        return self.count

    def append(self,data) -> None:
        """Add data to the end of the list in O(1) time."""
        new_node = Node(data)
        if self.is_empty():
            # First node becomes both the head and tail
            self.head = new_node
            self.tail = new_node
        else:
            # Link the old tail to the new node
            self.tail.next = new_node
            self.tail = new_node
        self.count += 1

    def prepend(self, data) -> None:
        """Add data to the front of the list in O(1) time."""
        new_node = Node(data)


        if self.is_empty():
            #First node becomes head and tail
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        self.count += 1

    def __str__(self) -> str:
        """Return a readable representation like '1 -> 2 -> 3'."""
        current = self.head
        elements = []
        while current is not None:
            elements.append(str(current.data))
            current = current.next
        return "-> ".join(elements)

    def delete_head(self):
        """
        Remove the head node and return its data.

        :return: Removed value, or None if the list is empty.
        """
        if self.is_empty():
            return None
        removed_data = self.head.data
        self.head = self.head.next
        self.count -= 1

        # If list became empty, tail must also be None
        if self.head is None:
            self.tail = None

        return removed_data


    def delete_tail(self):
        """
        Remove the tail node and return its data.

        :return: Removed value, or None if the list is empty.
        """
        if self.is_empty():
            return None
        removed_data = self.tail.data
        if self.head == self.tail:
             # Single-node list: removing tail also clears head
            self.head = None
            self.tail = None
        else:
            # Walk to the node right before tail (O(n) in singly list)
            current = self.head
            while current.next != self.tail:
                current = current.next
            current.next = None
            self.tail = current
        self.count -= 1
        return removed_data

    def insert_at(self, pos: int, data) -> None:
        """Insert data at index pos. Raises IndexError if pos is invalid."""
        if pos < 0 or pos > self.count:
            raise IndexError("Invalid position")
        

        if pos == 0:
            self.prepend(data)

        elif pos == self.count:
            self.append(data)

        # Insert in the middle: walk to node before insertion point
        else:
            new_node = Node(data)
            current = self.head
            for _ in range(pos - 1):
                current = current.next
            new_node.next = current.next
            current.next = new_node
            self.count += 1

    def delete_at(self, pos: int):
        """
        Delete node at index pos and return its data.

        :return: Removed value.
        :raises IndexError: if pos is invalid.
        """
        if pos < 0 or pos >= self.count:
            raise IndexError("Invalid position")
        if pos == 0:
            self.delete_head()
        elif pos == self.count - 1:
            self.delete_tail()
        else:
            # Delete in the middle: walk to node before the target
            current = self.head
            for _ in range(pos - 1):
                current = current.next
            removed_data = current.next.data
            current.next = current.next.next
            self.count -= 1
            return removed_data

    def search(self, key) -> bool:
        """Return True if key exists in the list, False otherwise."""
        current = self.head
        while current is not None:
            if current.data == key:
                return True
            current = current.next
        return False
