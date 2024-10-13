inductive Vec (α : Type u) : Nat → Type u where
| nil : Vec α 0
| cons : α → Vec α n → Vec α (n + 1)
deriving Repr

namespace Vec

def length {α : Type u} {n : Nat} (_ : Vec α n) : Nat := n

def map {α : Type u} {β : Type v} {n : Nat} (f : α → β) : Vec α n → Vec β n
| cons x xs => cons (f x) (map f xs)
| nil => nil

def append {α : Type u} {n m : Nat} : Vec α n → Vec α m → Vec α (m + n)
| cons x xs, r => cons x (append xs r)
| nil, r => r

theorem nil_append {α : Type u} (as : Vec α 0) : append nil as = as := rfl
theorem cons_append {α : Type u} (a : α) (as bs : Vec α n) : append (cons a as) bs = cons a (append as bs) := rfl

def head {α : Type u} {n : Nat} : Vec α (n + 1) → α
| cons x _ => x

def tail {α : Type u} {n : Nat} : Vec α (n + 1) → Vec α n
| cons _ xs => xs

def reverse {α : Type u} {n : Nat} (xs : Vec α n) : Vec α n := loop xs nil
where
  loop {n m : Nat} : Vec α n → Vec α m → Vec α (n + m)
  | nil, acc => by rwa [Nat.zero_add]
  | @cons _ n x xs, acc => by
    have := loop xs (cons x acc)
    rwa [Nat.add_comm, Nat.add_left_comm]

end Vec
