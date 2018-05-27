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
      
        <?php
          $json = file_get_contents("./001-616.json");
          $problems = json_decode($json);
          
          if (isset($_GET["problem"])) {
            $param = $_GET["problem"];
            $problemNum = (int)$param;
            
            $problem = $problems->$problemNum;
            
            $title = $problem->title;
            $url = $problem->url;
            echo "<div class=\"boxed\">";
            echo "<a href=\"" . $url . "\" target=\"_blank\"><h2>Problem " . $problemNum . ": " . $title . "</h2></a>";
            
            $content = $problem->content;
            $html = $content->html;
            echo $html;

            echo "</div>";
            
            
            $problemStr = str_pad($problemNum, 3, "0", STR_PAD_LEFT);
            $dir = "./" . $problemStr . "/";
            $desc = $dir . $problemStr . "_desc.html";
            $code = $dir . $problemStr . ".cpp";
            $ans = $dir . $problemStr . "_ans.txt";
            echo "<div class=\"boxed\">"; 
            echo file_get_contents($desc);
            echo "<pre><code class=\"c++\">" . htmlspecialchars(file_get_contents($code)) . "</code></pre>";
            echo "Answer: <code>" . file_get_contents($ans) . "</code>";
            
          } else {
            echo "No problem specified - Loading problem listing page";
            $problemNum = 0;
          }
        ?>

    </div>
    
  </body>
  
</html>
