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
        <h2><a href="https://projecteuler.net/problem=1">Problem 1: Multiples of 3 and 5</a></h2>
        <p>If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.<br>Find the sum of all the multiples of 3 or 5 below 1000.</p>
      </div>
      
      <div class="boxed">
        <p>I first solved this problem September 1st, 2014 in my AP Computer Science class in highschool. I do not have the original code I wrote, but I have redone the solution and included it below.</p>
        
        <p>This is a very simple and classic problem, commonly referred to as the "Fizz-Buzz test" used in job interviews in order to weed out applicants. More optimization could be done to make the program run faster, but I prefer this very clear solution.</p>
         
        <div class="code-snippet">
          <pre><code><xmp><?php include "001.cpp" ?></xmp></code></pre>
        </div>
        
        Answer: <code>233168</code>
        
      </div>
      
    </div>
    
  </body>
  
</html>
