var url_string = window.location.href;
var url = new URL(url_string);

var param = url.searchParams.get("problem");

if (param == null) {
  console.log("No problem specified - loading problem lsiting page");
} else {
  var problemNum = parseInt(param);
  var problemStr = problemNum.toString().padStart(3, "0");
  var dir = "./" + problemStr + "/";

  $.getJSON("001-616.json", function(json) {
    var problem = json[problemNum];

    var title = problem["title"];
    var url = problem["url"];
    var number = problem["number"];

    var info = problem["info"];
    var solved = info["solved"];
    var publish = info["publish"];
    var difficulty = info["difficulty"];

    var content = problem["content"];
    var text = content["text"];
    var html = content["html"];

    var files = problem["files"];
    var images = problem["images"];

    document.getElementById("title").innerHTML = "Problem " + number + ": " + title;
    document.getElementById("link").href = url;
    document.getElementById("link").target = "_blank"; 
    document.getElementById("problem").innerHTML = html;

    function loadFile(filePath) {
      var result = null;
      var xmlhttp = new XMLHttpRequest();
      xmlhttp.open("GET", filePath, false);
      xmlhttp.send();
      if (xmlhttp.status==200) {
        result = xmlhttp.responseText;
      }
      return result;
    }

//    console.log(loadFile("./test.txt"));
    
    var code = "ERR: 404 FILE NOT FOUND";
    var code_path = dir + problemStr + ".cpp";
    $.ajax({
        url: code_path,
        async: false,
        success: function(file) { code = file; }
    });
    
    var desc = "ERR: 404 FILE NOT FOUND";
    var desc_path = dir + problemStr + "_desc.html";
    $.ajax({
        url: desc_path,
        async: false,
        success: function(file) { desc = file; }
    });
    
    var answer = "ERR: 404 FILE NOT FOUND";
    var answer_path = dir + problemStr + "_ans.txt";
    $.ajax({
        url: answer_path,
        async: false,
        success: function(file) { answer = file; }
    });

    document.getElementById("sol_desc").innerHTML = desc;
    document.getElementById("sol_code").innerHTML = code;
    document.getElementById("answer").innerHTML = answer;
  });
  
}
