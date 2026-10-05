# DSA-NOTES: Things To Fix

## LinkedList.h
- [ ] `insertAtPos`: check the range first (below 1 and above size + 1) and throw instead of silently doing nothing
- [ ] `insertAtPos`: stop leaking the extra node at position 1 and position size + 1
- [ ] `insertBeforeTarget`: stop leaking the new node when the target is not found
- [ ] Copy protection (copying a list causes a double free)

## doubly_linkedList.h
- [ x ] `deleteByData`: crashes when the target is the head
- [ x ] `deleteByData`: crashes when the target is the tail
- [ x ] `deleteByData`: breaks on a single-node list
- [ x ] `deleteByData`: `head` and `tail` are never updated
- [ x ] Write the destructor (every node leaks right now)
- [ x ] `insertAtPos`: decide how an empty list behaves and match the singly and circular lists (same rule, same exception type)
- [ ] Copy protection

## circular_linkedList.c++
- [ x ] `display` crashes on an empty list
- [ x ] Write the destructor (a circular list never reaches null, so think about the stop condition)
- [ x ] Remove the "Inserted" print from `insertAtFront`
- [ x ] Remove the pointer-address output from `display`
- [ x ] Include `<stdexcept>`
- [ x ] Add an include guard and move `main()` out of the file
- [ ] Copy protection

## stack_using_linkedlist.h
- [ x ] `peek` error message still says "Can't pop"
- [ ] Copy protection

## queue_using_linkedList.h
- [ x ] Add `#pragma once`
- [ x ] Include `<stdexcept>`
- [ x ] Move `main()` out of the header
- [ x ] Fix the comment about nulling the pointer (the local variable disappears anyway; the pointer that matters is the one stored in the object)

## Repo-wide
- [ ] Every file defines its own `Node` (and three define `Stack`), so two headers can't be included together
- [ ] README: list all files and mark only what is really finished (the stack `clear()` was marked done before it worked)
