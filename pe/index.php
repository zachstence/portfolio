<!DOCTYPE html>
<html>
  <head>
    <title>Portfolio - Project Euler</title>
    <meta charset="utf-8"/>
    <link rel="stylesheet" type="text/css" href="../style/pe.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="../style/highlight/highlight.pack.js"></script>
    <script>hljs.initHighlightingOnLoad();</script>
</head>

  <?php include "../head.php"; ?>
  <nav><?php include "../nav.php"; ?></nav>
  
  <body>
        
    <div class="main">
      <br>
      
      <div class="boxed">
        <h2><a id="link"><div id="title"></div></a></h2>
        <div id="problem"></div>
      </div>
      <div class="boxed">
        <div id="sol_desc"></div>
        <pre><code class="c++"><?php echo htmlspecialchars(file_get_contents("./001/001.cpp")); ?></code></pre>
        <!--<pre><code class="c++" id="sol_code"></code></pre>-->
        Answer: <code id="answer"></code>
      <script src="fill.js"></script>

    </div>
    
  </body>
  
</html>
