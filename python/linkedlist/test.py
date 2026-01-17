from linkedlist1 import LinkedList

def main():
    ll = LinkedList()
    ll.append(10)
    ll.append(20)
    ll.append(30)
    print("Initial list:")
    print(ll)
    # basic checks
    assert ll.size() == 3
    assert not ll.is_empty()

    #searching list
    assert ll.search(20)
    assert not ll.search(40)

    #Delete head and make sure that the list updates correctly
    removed = ll.delete_head()
    assert removed == 10
    assert ll.size() == 2

    print("list after deleting head")
    print(ll)

    print("Prepending 5 and 1 to the list")
    ll.prepend(5)
    ll.prepend(1)
    print(ll)

    assert ll.size() == 4

    ll.insert_at(2,15)
    assert ll.size() == 5
    assert ll.search(15)
    print("list after inserting 15 at position 2 (starting from 0)")
    print(ll)
    print("list after deleting at position 1 (starting from 0)")
    ll.delete_at(1)
    print(ll)

    print("All tests passed")

if __name__ == "__main__":
    main()
