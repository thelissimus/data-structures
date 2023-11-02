inductive LinkedList (α : Type) : Nat → Type
| Cons : α → LinkedList α n → LinkedList α (Nat.succ n)
| Nil : LinkedList α Nat.zero

namespace LinkedList

def length {α : Type} {n : Nat} (_ : LinkedList α n) : Nat := n

def map {α β : Type} {n : Nat} (f : α → β) : LinkedList α n → LinkedList β n
| Cons x xs => Cons (f x) (map f xs)
| Nil => Nil

def append {α : Type} {n m: Nat} : LinkedList α n → LinkedList α m → LinkedList α (m + n)
| Cons x xs, r => Cons x (append xs r)
| Nil, r => r

end LinkedList
