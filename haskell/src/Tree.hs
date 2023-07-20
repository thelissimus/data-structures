{-# LANGUAGE InstanceSigs #-}

module Tree where

data Tree a
  = Node a (Tree a) (Tree a)
  | Leaf
  deriving (Eq, Show)

instance Functor Tree where
  fmap :: (a -> b) -> Tree a -> Tree b
  fmap _ Leaf = Leaf
  fmap f (Node a l r) = Node (f a) (fmap f l) (fmap f r)

instance Foldable Tree where
  foldr :: (a -> b -> b) -> b -> Tree a -> b
  foldr _ z Leaf = z
  foldr f z (Node a l r) = foldr f (f a (foldr f z r)) l
