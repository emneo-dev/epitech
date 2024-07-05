{-# LANGUAGE LambdaCase #-}

module Jaarse where

import Control.Applicative
import Data.Char (isAlpha, isDigit, isSpace)
import GHC.Exception.Type (Exception)
import Text.Read

newtype Parser a = Parser {runParser :: String -> Maybe (a, String)}

data Expression
  = Num Float
  | Add Expression Expression
  | Sub Expression Expression
  | Mul Expression Expression
  | Div Expression Expression
  | Pow Expression Expression
  deriving (Show)

makeFloat :: String -> Expression
makeFloat s = Num $ read s

blanks :: Parser String
blanks = spaces >> tabs

blank :: Parser Char
blank = space >> tab

spaces :: Parser String
spaces = myMany space

tabs :: Parser String
tabs = myMany tab

tab :: Parser Char
tab = char <=> (== '\t')

chainl1 :: Parser a -> Parser (a -> a -> a) -> Parser a
chainl1 p op = do
  a <- p
  rest a
  where
    rest a =
      do
        f <- op
        b <- p
        rest $ f a b
        <|> return a

chainr1 :: Parser a -> Parser (a -> a -> a) -> Parser a
chainr1 p op = do
  a <- p
  rest a
  where
    rest a =
      do
        f <- op
        b <- p
        rest $ f b a
        <|> return a

parseOpAddMinus :: Parser (Expression -> Expression -> Expression)
parseOpAddMinus =
  blanks
    *> ( Add <$ operand '+'
           <|> Sub <$ operand '-'
       )
    <* blanks

parseOpMulDiv :: Parser (Expression -> Expression -> Expression)
parseOpMulDiv =
  blanks
    *> ( Mul <$ operand '*'
           <|> Div <$ operand '/'
       )
    <* blanks

parseOpPow :: Parser (Expression -> Expression -> Expression)
parseOpPow =
  blanks
    *> ( Pow <$ operand '^'
       )
    <* blanks

expr :: Parser Expression
expr = chainl1 term parseOpAddMinus

term :: Parser Expression
term = chainl1 powed parseOpMulDiv

powed :: Parser Expression
powed = chainr1 factor parseOpPow

factor :: Parser Expression
factor =
  blanks *> operand '(' *> blanks *> expr <* blanks <* operand ')' <* blanks
    <|> num

num :: Parser Expression
num = Num <$> float

operand :: Char -> Parser Char
operand c = char <=> (== c)

nat :: Parser Int
nat = read <$> mySome digit

pluses :: Parser String
pluses = myMany plus

plus :: Parser Char
plus = char <=> (== '+')

baseFloat :: Parser Float
baseFloat = read <$ blanks <*> mySome digit <* blanks

negFloat :: Parser Float
negFloat = do
  blanks
  operand '-'
  blanks
  negate <$> float

posFloat :: Parser Float
posFloat = do
  blanks
  intPart <- mySome digit
  blanks -- I feel bad
  point
  blanks -- Wtf is this
  decPart <- mySome digit
  blanks
  return $ read $ intPart ++ "." ++ decPart

float :: Parser Float
float =
  plus *> float
    <|> negFloat
    <|> posFloat
    <|> baseFloat

option :: a -> Parser a -> Parser a
option a p = Parser $ \s -> case runParser p s of
  Nothing -> Just (a, s)
  Just (x, s') -> Just (x, s')

point :: Parser Char
point = char <=> (== '.')

digits :: Parser String
digits = mySome digit

char :: Parser Char
char = Parser $ \case
  [] -> Nothing
  (c : cs) -> Just (c, cs)

digit :: Parser Char
digit = char <=> isDigit

space :: Parser Char
space = char <=> isSpace

letter :: Parser Char
letter = char <=> isAlpha

myMany :: Parser a -> Parser [a]
myMany p = Parser $ \case
  [] -> Just ([], [])
  cs -> case runParser p cs of
    Nothing -> Just ([], cs)
    Just (x, rest) -> case runParser (myMany p) rest of
      Nothing -> Just ([x], rest)
      Just (xs, rest') -> Just (x : xs, rest')

mySome :: Parser a -> Parser [a]
mySome p = Parser $ \case
  [] -> Nothing
  cs -> case runParser p cs of
    Nothing -> Nothing
    Just (x, rest) -> case runParser (myMany p) rest of
      Nothing -> Just ([x], rest)
      Just (xs, rest') -> Just (x : xs, rest')

(<=>) :: Parser a -> (a -> Bool) -> Parser a
p <=> f = Parser $ \s -> case runParser p s of
  Nothing -> Nothing
  Just (a, s') -> if f a then Just (a, s') else Nothing

instance Applicative Parser where
  pure a = Parser $ \s -> Just (a, s)
  (Parser f) <*> (Parser g) = Parser $ \s -> case f s of
    Nothing -> Nothing
    Just (f', s') -> case g s' of
      Nothing -> Nothing
      Just (g', s'') -> Just (f' g', s'')
  (Parser f) *> (Parser g) = Parser $ \s -> case f s of
    Nothing -> Nothing
    Just (_, s') -> g s'
  (Parser f) <* (Parser g) = Parser $ \s -> case f s of
    Nothing -> Nothing
    Just (f', s') -> case g s' of
      Nothing -> Nothing
      Just (_, s'') -> Just (f', s'')

instance Functor Parser where
  fmap f (Parser p) = Parser $ \s -> case p s of
    Nothing -> Nothing
    Just (a, s') -> Just (f a, s')

instance Monad Parser where
  return = pure
  (Parser f) >>= g = Parser $ \s -> case f s of
    Nothing -> Nothing
    Just (r, s') -> runParser (g r) s'

instance Alternative Parser where
  empty = Parser $ const Nothing
  (Parser f) <|> (Parser g) = Parser $ \s -> case f s of
    Nothing -> g s
    res -> res
