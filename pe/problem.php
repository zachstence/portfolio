<!DOCTYPE html>
<html>
  <head>
    <?php echo "<title>PE - Problem " . $_GET["problem"] . "</title>\n"; ?>
    <meta charset="utf-8"/>
    <link rel="stylesheet" type="text/css" href="../style/pe_problem.css">
    <script src="../style/highlight/highlight.pack.js"></script>
    <script>hljs.initHighlightingOnLoad();</script>
  </head>
  
  <?php include "../head.php"; ?>
  <?php include "../nav.php"; ?>

  <body>
    <div class="main">
    <?php
      $json = file_get_contents("./001-616.json");
      $problems = json_decode($json);
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

      echo "<div class=\"boxed\">"; 
      $problemStr = str_pad($problemNum, 3, "0", STR_PAD_LEFT);
      $dir = "./problems/" . $problemStr . "/";
      $desc = $dir . $problemStr . "_desc.html";
      $code = $dir . $problemStr . ".cpp";
      $ans = $dir . $problemStr . "_ans.txt";
      echo file_get_contents($desc);
      echo "<pre><code class=\"c++\">" . htmlspecialchars(file_get_contents($code)) . "</code></pre>";
      echo "<p>Answer: <code>" . file_get_contents($ans) . "</code></p>";
    ?>
    </div>
  </body>

</html>
