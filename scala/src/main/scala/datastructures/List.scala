package datastructures

import datastructures.fp.*

enum List[+A]:
  case Cons(head: A, tail: List[A])
  case Nil

export List.*

given Functor[List] with
  def map[A, B](fa: List[A])(f: A => B): List[B] = fa match
    case Cons(h, t) => Cons(f(h), map(t)(f))
    case Nil        => Nil
