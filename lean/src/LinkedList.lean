inductive LinkedList (α : Type u) : Nat → Type u
| Nil : LinkedList α 0
| Cons : α → LinkedList α n → LinkedList α (n + 1)

infix:67 " :: " => LinkedList.Cons

namespace LinkedList

def length {α : Type} {n : Nat} (_ : LinkedList α n) : Nat := n

def map {α β : Type} {n : Nat} (f : α → β) : LinkedList α n → LinkedList β n
| x :: xs => (f x) :: (map f xs)
| Nil => Nil

def append {α : Type} {n m : Nat} : LinkedList α n → LinkedList α m → LinkedList α (m + n)
| x :: xs, r => x :: (append xs r)
| Nil, r => r

def head {α : Type} {n : Nat} : LinkedList α (n + 1) → α
| x :: _ => x

def tail {α : Type} {n : Nat} : LinkedList α (n + 1) → LinkedList α n
| _ :: xs => xs

def reverse' {α : Type} {n m : Nat} : LinkedList α n → LinkedList α m → LinkedList α (n + m) :=
  sorry

def reverse {α : Type} {n : Nat} : LinkedList α n → LinkedList α n :=
  λ xs => reverse' xs Nil

end LinkedList
