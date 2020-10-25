let compressionStrength = 0.2;
document.querySelector(".increaseStrength").addEventListener("click", (e) => {
  compressionStrength -= 0.1;
  if (compressionStrength < 0.0) compressionStrength = 1.0;
  document.querySelector(".progress").style.width =
    (compressionStrength / 1) * 100 + "%";
  displayCompressImage(files);
});
document.querySelector(".decreaseStrength").addEventListener("click", (e) => {
  compressionStrength += 0.1;
  if (compressionStrength > 1.0) compressionStrength = 0.0;
  document.querySelector(".progress").style.width =
    (compressionStrength / 1) * 100 + "%";
  displayCompressImage(files);
});
