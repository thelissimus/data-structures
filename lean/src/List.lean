inductive LList (α : Type) : Nat → Type
| Cons : α → LList α n → LList α (n + 1)
| Nil : LList α 0

namespace LList

def map {α β : Type} (f : α → β) : LList α n → LList β n
| Cons x xs => Cons (f x) (map f xs)
| Nil => Nil

end LList
