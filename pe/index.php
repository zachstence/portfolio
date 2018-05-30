<!DOCTYPE html>
<html>
  <head>
    <title>Portfolio - Project Euler</title>
    <meta charset="utf-8"/>
    <link rel="stylesheet" type="text/css" href="../style/pe.css">
    <script src="../style/highlight/highlight.pack.js"></script>
    <script>hljs.initHighlightingOnLoad();</script>
</head>

  <?php include "../head.php"; ?>
  <?php include "../nav.php"; ?>
  
  <body>
        
    <div class="main">
      <br>
      
        <?php
          if (isset($_GET["problem"])) {
            include "./problem.php";
          } else {
            include "./landing.php";
          }
        ?>

    </div>
    
  </body>
  
</html>
