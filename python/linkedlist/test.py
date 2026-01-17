from linkedlist1 import LinkedList

def main():
    ll = LinkedList()
    ll.append(10)
    ll.append(20)
    ll.append(30)

    assert ll.size() == 3
    assert not ll.is_empty()
    assert ll.search(2)

    ll.delete_head()
    print("List after deleting head: ")
    ll.display()

    assert ll.size() == 2

    print("All tests passed")

    if __name__ == "__main__":
        main()
