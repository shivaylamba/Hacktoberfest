//using BLOB
// <a onclick='download_file("my_file.html", dynamic_text())'>
function dynamic_text() {
  return YourText;
}

function download_file(name, contents, mime_type) {
  mime_type = mime_type || "text/html";

  var blob = new Blob([contents], { type: mime_type });

  var dlink = document.createElement("a");
  dlink.download = name;
  dlink.href = window.URL.createObjectURL(blob);
  dlink.onclick = function(e) {
    // revokeObjectURL needs a delay to work properly
    var that = this;
    setTimeout(function() {
      window.URL.revokeObjectURL(that.href);
    }, 1500);
  };

  dlink.click();
  dlink.remove();
}
