from linkedlist1 import LinkedList

def main():
    ll = LinkedList()
    ll.append(10)
    ll.append(20)
    ll.append(30)

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

    print("All tests passed")

if __name__ == "__main__":
    main()
