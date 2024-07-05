module HALParsing where

import Control.Applicative
import Jaarse

data Datum
  = Atom String
  | List [Datum]
  | DottedList [Datum] Datum
  | LitNumber Integer

instance Show Datum where
  show (Atom name) = name
  show (List contents) = "(" ++ unwordsList contents ++ ")"
  show (DottedList head tail) =
    "(" ++ unwordsList head ++ " . " ++ show tail ++ ")"
  show (LitNumber n) = show n

symbol :: Parser Char
symbol = oneOf "!#$%&|*+-/:<=>?@^_~"

-- This is kinda ugly but it works
atom :: Parser Datum
atom = do
  first <- letter <|> symbol
  rest <- many (letter <|> digit <|> symbol)
  return . Atom $ first : rest

commonList :: Parser Datum
commonList = lexeme . between (char '(') (char ')') $ dottedList <|> list

string :: Parser Datum
string = do
  x <- between (char '"') (char '"') (many (noneOf "\""))
  return . Atom $ "\"" ++ x ++ "\""

number :: Parser Datum
number = LitNumber <$> nat

expr :: Parser Datum
expr =
  atom
    <|> string
    <|> number
    <|> quoted
    <|> commonList

exprs :: Parser [Datum]
exprs = lexeme . many . lexeme $ expr

-- TODO: Test
list :: Parser Datum
list = List <$> many (lexeme expr)

-- TODO: Test
dottedList :: Parser Datum
dottedList = DottedList <$> some (lexeme expr) <*> (char '.' >> spaces >> expr)

-- TODO: Test
quoted :: Parser Datum
quoted = do
  char '\''
  x <- expr
  return $ List [Atom "quote", x]

unwordsList :: Show a => [a] -> String
unwordsList = unwords . map show
