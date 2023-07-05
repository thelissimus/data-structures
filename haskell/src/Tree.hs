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
