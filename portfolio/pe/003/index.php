<!DOCTYPE html>
<html>
  <head>
    <title>CS 2308</title>
    <meta charset="utf-8"/>
    <link rel="stylesheet" type="text/css" href="../pestyle.css">
    <link rel="stylesheet" type="text/css" href="../../globals.css">
  </head>
  
  <?php include "/home/Students/zms22/public_html/portfolio/head.php"; ?>

  <nav> 
    <?php include "/home/Students/zms22/public_html/portfolio/nav.php"; ?>
  </nav>
  
  <body>
     
    <div class="main">
      
      <br>
      
      <div class="boxed">
        <h2><a href="https://projecteuler.net/problem=3">Problem 3: Largest prime factor</a></h2>
        <p>The prime factors of 13195 are 5, 7, 13 and 29.<br>What is the largest prime factor of the number 600851475143 ?</p>
      </div>
      
      <div class="boxed">
        <p>I first solved this problem September 15th, 2014 in my AP Computer Science class in highschool. I do not have the original code I wrote, but I have redone the solution and included it below.</p>
        
        <p>To solve this problem I first wrote a simple function to check whether a given number is prime or composite. It works by iterating through all possible divisors of a number, and if none divide it, it is prime. From there I iterate through numbers starting at the square root of 600851475143 and breaking at the first prime divisor.</p>
         
        <div class="code-snippet">
          <pre><code><xmp><?php include "003.cpp"; ?></xmp></code></pre>
        </div>
        
        Answer: <code>6857</code>
        
      </div>
      
    </div>
    
  </body>
  
</html>

