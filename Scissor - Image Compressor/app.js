const compress = new Compress();
const upload = document.querySelector(".container .uploader input");

let files;
let compressedImage = "";

upload.addEventListener(
  "change",
  (evt) => {
    document.querySelector(".header").style.height = "100%";
    setTimeout(() => {
      document.querySelector(".uploader").style.display = "none";
      document.querySelector(".editor").style.display = "grid";
    }, 600);
    const reader = new FileReader();
    reader.readAsDataURL(upload.files[0]);
    files = [...evt.target.files];
    reader.addEventListener("load", () => {
      document.querySelector(".originalImage").src = reader.result;
    });
    displayCompressImage(files);
    document.querySelector(".original-file-size").textContent =
      "Image Size: " + (files[0].size / 1000000).toFixed(2) + "MB";
  },
  false
);

function displayCompressImage(files) {
  compress
    .compress(files, {
      size: 4,
      quality: compressionStrength,
      maxWidth: 1920,
      maxHeight: 1920,
      resize: false,
    })
    .then((data) => {
      compressedImage = data[0].prefix + data[0].data;
      console.log(data[0]);
      document.querySelector(".header").style.height = "60px";
      document.querySelector(".compressedImage").src = compressedImage;
      document.querySelector(".compressed-file-size").textContent =
        "Image Size: " +
        data[0].endSizeInMb
          .toString()
          .substring(0, data[0].endSizeInMb.toString().indexOf(".") + 3) +
        "MB (-" +
        parseInt(data[0].sizeReducedInPercent) +
        "%)";
    });
}

document.querySelector(".download-btn").addEventListener("click", () => {
  download(compressedImage);
});
