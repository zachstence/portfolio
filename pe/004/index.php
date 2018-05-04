<!DOCTYPE html>
<html>
  <head>
    <title>CS 2308</title>
    <meta charset="utf-8"/>
    <link rel="stylesheet" type="text/css" href="../../style/pe.css">
  </head>
  
  <?php include "../../head.php"; ?>
  <nav><?php include "../../nav.php"; ?></nav>
  
  <body>
     
    <div class="main">
      
      <br>
      
      <div class="boxed">
        <h2><a href="https://projecteuler.net/problem=4">Problem 4: Largest palindrome product</a></h2>
        <p>A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.<br>Find the largest palindrome made from the product of two 3-digit numbers.</p>
      </div>
      
      <div class="boxed">
        <p>I first solved this problem October 1st, 2014 in my AP Computer Science class in highschool. I do not have the original code I wrote, but I have redone the solution and included it below.</p>
 
        <p>I solved this problem by first writing a function to check whether or not a positive integer is a palindrome. The function first converts the integer to a string, then uses C++11 iterators to check to make sure each number starting at the front and back is equal. Then in main, I iterate through all possible products (starting at 999 * 999 to find the max sooner), and store the maximum palindrome.</p>
               
        <div class="code-snippet">
          <pre><code><xmp><?php include "004.cpp"; ?></xmp></code></pre>
        </div>
        
        Answer: <code>906609</code>
        
      </div>
      
    </div>
    
  </body>
  
</html>

