package datastructures

import cats.kernel.Semigroup
import cats.kernel.Monoid
import cats.Functor

import datastructures.fp.*

enum List[+A]:
  case Cons(head: A, tail: List[A])
  case Nil

export List.*

given [A]: Semigroup[List[A]] with
  def combine(x: List[A], y: List[A]): List[A] = (x, y) match
    case (Nil, r)        => r
    case (Cons(h, t), r) => Cons(h, combine(t, r))

given [A]: Monoid[List[A]] with
  def combine(x: List[A], y: List[A]): List[A] = Semigroup[List[A]].combine(x, y)
  def empty: List[A]                           = Nil

given Functor[List] with
  def map[A, B](fa: List[A])(f: A => B): List[B] = fa match
    case Cons(h, t) => Cons(f(h), map(t)(f))
    case Nil        => Nil
