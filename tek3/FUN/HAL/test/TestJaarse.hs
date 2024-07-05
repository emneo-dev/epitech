import Control.Monad (void)
import Jaarse
import Test.HUnit (Test (..), assertEqual, runTestTT)

testOneOf1, testOneOf2 :: Test
testOneOf1 =
  TestCase
    ( let r = runParser (oneOf "abc") "art"
       in assertEqual "testOneOf1" (Just ('a', "rt")) r
    )
testOneOf2 =
  TestCase
    ( let r = runParser (oneOf "abc") "zart"
       in assertEqual "testOneOf2" Nothing r
    )

testsOneOf :: Test
testsOneOf =
  TestList
    [ testOneOf1,
      testOneOf2
    ]

--------------------------------------------------------------------------------

testNat1, testNat2, testNat3, testNat4 :: Test
testNat1 =
  TestCase
    ( let r = runParser nat "123"
       in assertEqual "testNat1" (Just (123, "")) r
    )
testNat2 =
  TestCase
    ( let r = runParser nat "123a"
       in assertEqual "testNat2" (Just (123, "a")) r
    )
testNat3 =
  TestCase
    ( let r = runParser nat "a123"
       in assertEqual "testNat3" Nothing r
    )
testNat4 =
  TestCase
    ( let r = runParser nat "-123"
       in assertEqual "testNat4" Nothing r
    )

testNats :: Test
testNats =
  TestList
    [ testNat1,
      testNat2,
      testNat3,
      testNat4
    ]

--------------------------------------------------------------------------------

testChar1, testChar2, testChar3 :: Test
testChar1 =
  TestCase
    ( let r = runParser (char 'a') "art"
       in assertEqual "testChar1" (Just ('a', "rt")) r
    )
testChar2 =
  TestCase
    ( let r = runParser (char 'a') "zart"
       in assertEqual "testChar2" Nothing r
    )
testChar3 =
  TestCase
    ( let r = runParser (char 'a') ""
       in assertEqual "testChar3" Nothing r
    )

testChars :: Test
testChars =
  TestList
    [ testChar1,
      testChar2,
      testChar3
    ]

--------------------------------------------------------------------------------

testFloat1, testFloat2, testFloat3, testFloat4, testFloat5 :: Test
testFloat1 =
  TestCase
    ( let r = runParser float "123.456"
       in assertEqual "testFloat1" (Just (123.456, "")) r
    )
testFloat2 =
  TestCase
    ( let r = runParser float "123.456a"
       in assertEqual "testFloat2" (Just (123.456, "a")) r
    )
testFloat3 =
  TestCase
    ( let r = runParser float "a123.456"
       in assertEqual "testFloat3" Nothing r
    )
testFloat4 =
  TestCase
    ( let r = runParser float "-123.456"
       in assertEqual "testFloat4" (Just (-123.456, "")) r
    )
testFloat5 =
  TestCase
    ( let r = runParser float "-------+++++---++-+-++++++++------123.456"
       in assertEqual "testFloat5" (Just (123.456, "")) r
    )

testFloats :: Test
testFloats =
  TestList
    [ testFloat1,
      testFloat2,
      testFloat3,
      testFloat4,
      testFloat5
    ]

--------------------------------------------------------------------------------

testOption1, testOption2 :: Test
testOption1 =
  TestCase
    ( let r = runParser (option 'y' (char 'b')) "art"
       in assertEqual "testOption1" (Just ('y', "art")) r
    )
testOption2 =
  TestCase
    ( let r = runParser (option 'y' (char 'z')) "zart"
       in assertEqual "testOption2" (Just ('z', "art")) r
    )

testOptions :: Test
testOptions =
  TestList
    [ testOption1,
      testOption2
    ]

--------------------------------------------------------------------------------

testOptional1, testOptional2 :: Test
testOptional1 =
  TestCase
    ( let r = runParser (optional (char 'a')) "art"
       in assertEqual "testOptional1" (Just ((), "rt")) r
    )
testOptional2 =
  TestCase
    ( let r = runParser (optional (char 'b')) "zart"
       in assertEqual "testOptional2" (Just ((), "zart")) r
    )

testOptionals :: Test
testOptionals =
  TestList
    [ testOptional1,
      testOptional2
    ]

--------------------------------------------------------------------------------

testBetween1, testBetween2, testBetween3, testBetween4 :: Test
testBetween1 =
  TestCase
    ( let r = runParser (between (char '(') (char ')') (char 'a')) "art"
       in assertEqual "testBetween1" Nothing r
    )
testBetween2 =
  TestCase
    ( let r = runParser (between (char '(') (char ')') (char 'a')) "(a)"
       in assertEqual "testBetween2" (Just ('a', "")) r
    )
testBetween3 =
  TestCase
    ( let r = runParser (between (char '(') (char ')') (char 'a')) "(a)b"
       in assertEqual "testBetween3" (Just ('a', "b")) r
    )
testBetween4 =
  TestCase
    ( let r = runParser (between (char '(') (char ')') (char 'a')) "(aa)"
       in assertEqual "testBetween4" Nothing r
    )

testBetweens :: Test
testBetweens =
  TestList
    [ testBetween1,
      testBetween2,
      testBetween3,
      testBetween4
    ]

--------------------------------------------------------------------------------

tests :: Test
tests =
  TestList
    [ testsOneOf,
      testNats,
      testChars,
      testFloats,
      testOptions,
      testOptionals,
      testBetweens
    ]

main :: IO ()
main = void $ runTestTT tests
