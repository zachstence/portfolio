<!DOCTYPE html>
<html>
  <head>
    <title>Portfolio - Home</title>
    <meta charset="utf-8"/>
    <link rel="stylesheet" type="text/css" href="style/home.css">
  </head>
  
  <body>
    <?php include "head.php"; ?>
    <?php include "nav.php"; ?>
  
    <div class="main">
      
      <div id="homepage-intro">
      
        <div class="crop"><img src="portrait.jpg" alt="Portrait"></div>
        <div class="text">
          <p>I am in the progress of making this simple website as a way to keep track of all things I do involing computer science: homework assignments, coding challenges, and most importantly personal projects. This website will link to my various professional profiles (LinkedIn, GitHub, etc.) and will also have my resume and other information that may be important to employers.</p>
          <p>Aside from that, this website serves as a way for me to learn/practice HTML, PHP, and CSS; and keep me busy in my free time.</p>
          <p>All of the code for this website is available on <a href="https://www.github.com/zachstence/Portfolio" target="_blank">my GitHub</a>!</p>
        </div>
        
      </div>
      <hr> 
      <h2>Website Sections</h2>
      <ul>
        <li>Home - The homepage of my website, this page!</li>
        <li>CS 2308 - All of the assignments I did for "Foundations of Computer Science II" at Texas State</li>
        <li>CS 2318 - All of the assignments I did for "Assembly Language" at Texas State</li>
        <li>CS 3358 - All of the assignments I did for "Data Structures and Algorithms" at Texas State</li>
        <li>Project Euler - All Project Euler problems I have solved complete with explanations</li>
        <li>Personal Projects - A summary of projects I am working on myself with links to code on GitHub</li>
      </ul>
      
      <h2>Other Documents and Links</h2>
      <div id="info-buttons">
        <a class="button" id="resume"   href="2018.06.05_resume.pdf"                       target="_blank">Resume</a></li>
        <a class="button" id="linkedin" href="https://www.linkedin.com/in/zachary-stence/" target="_blank">LinkedIn: zachary-stence</a></li>
        <a class="button" id="github"   href="https://www.github.com/zachstence"           target="_blank">GitHub: zachstence</a></li>
        <a class="button" id="email"    href="mailto:zms22@txstate.edu"                    target="_blank">zms22@txstate.edu</a></li>
      </div>

    </div>
  </body>
</html>
