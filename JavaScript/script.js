<html>
  <head>
    <title>Time</title>
  </head>
  <body>
    <span id="time"></span>
    <script>
      function display_time() {
        var x = new Date();
        var ampm = x.getHours() <= 12 ? " AM" : " PM";

        var x1 = x.getMonth() + 1 + "/" + x.getDate() + "/" + x.getFullYear();
        var x1;
        x1 =
          x1 +
          " - " +
        x.getHours() + ":" + x.getMinutes() + ":" + x.getSeconds() + ":" + ampm;
        document.getElementById("time").innerHTML = x1;
        refresh_time();
      }

      function refresh_time() {
        var refresh = 1000; // Refresh rate in milli seconds
        mytime = setTimeout("display_time()", refresh);
      }
      refresh_time();
    </script>
  </body>
</html>
