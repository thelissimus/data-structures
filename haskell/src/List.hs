{-# LANGUAGE InstanceSigs #-}

module List where

data List a
  = Cons a (List a)
  | Nil
  deriving (Show)

instance Semigroup (List a) where
  (<>) :: List a -> List a -> List a
  Nil <> b = b
  (Cons h t) <> b = Cons h (t <> b)

instance Monoid (List a) where
  mempty :: List a
  mempty = Nil

instance Foldable List where
  foldr :: (a -> b -> b) -> b -> List a -> b
  foldr _ z Nil = z
  foldr f z (Cons h t) = f h (foldr f z t)

instance Functor List where
  fmap :: (a -> b) -> List a -> List b
  fmap _ Nil = Nil
  fmap f (Cons h t) = Cons (f h) (fmap f t)

instance Applicative List where
  pure :: a -> List a
  pure a = Cons a Nil

  (<*>) :: List (a -> b) -> List a -> List b
  fs <*> xs = foldMap (`fmap` xs) fs

instance Monad List where
  return :: a -> List a
  return = pure

  (>>=) :: List a -> (a -> List b) -> List b
  xs >>= f = foldMap f xs
